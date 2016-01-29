#include "ttcp.h"
int main(int argc,char **argv)
{
	if(argc!=2)
	{
		printf("usage:%s <IPport>\n",argv[0]);
		return 0;
	}
	
	InetAddress clientAddr(atoi(argv[1]));
	std::unique_ptr<Acceptor> acceptor(new Acceptor(clientAddr));
	while(true)
	{
		TcpStreamPtr stream=acceptor->accept();
		struct SessionMessage sessionMessage={0,0};
		if(stream->receiveAll(&sessionMessage,sizeof sessionMessage)!=sizeof sessionMessage)
		{
			printf("read error\n");
			return 0;
		}
		sessionMessage.number=ntohl(sessionMessage.number);
		sessionMessage.length=ntohl(sessionMessage.length);
		printf("sessionMessage.number=%d sessionMessage.length=%d\n",sessionMessage.number,sessionMessage.length);	
		const int total_length=static_cast<int>(sizeof(int32_t)+sessionMessage.length);
		struct PayLoadMessage *payLoadMessage=static_cast<PayLoadMessage*>(::malloc(total_length));
		for(int i=0;i<sessionMessage.number;++i)
		{
			payLoadMessage->length=0;
			int nr=stream->receiveAll(&payLoadMessage->length,sizeof payLoadMessage->length);
			
			assert(nr==sizeof payLoadMessage->length);
			payLoadMessage->length=ntohl(payLoadMessage->length);
			nr=stream->receiveAll(&payLoadMessage->data,payLoadMessage->length);
			assert(nr==payLoadMessage->length);
		
			int ack=static_cast<int>(sizeof (payLoadMessage->length) + payLoadMessage->length);
			ack=htonl(ack);
			int nw=stream->sendAll(&ack,sizeof ack);
			assert(nw==sizeof ack);		
		}
		free(payLoadMessage);
	}
	
	return 0;
}
