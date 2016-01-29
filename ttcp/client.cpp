#include "ttcp.h"

int main(int argc,char **argv)
{
	if(argc!=5)
	{
		printf("usage:%s <IPaddress> <IPport> <number> <length>\n",argv[0]);
		return 0;	
	}
	
	InetAddress serverAddr(argv[1],atoi(argv[2]));
	TcpStreamPtr tcpStreamPtr=TcpStream::connect(serverAddr);
	if(!tcpStreamPtr)
	{
		printf("Unable to connect %s\n",serverAddr.toIpPort().c_str());
		return 0;
	}
	tcpStreamPtr->setTcpNoDelay(true);	
	struct Options option={atoi(argv[3]),atoi(argv[4])};
	struct SessionMessage sessionMessage={0,0};
	sessionMessage.number=htonl(option.number);
	sessionMessage.length=htonl(option.length);
	clock_t start=clock();	
	if(tcpStreamPtr->sendAll(&sessionMessage,sizeof sessionMessage)!=sizeof sessionMessage)
	{
		printf("Send error\n");
		return 0;
	}

	const int total_length=static_cast<int>(sizeof(int32_t)+  option.length);
	struct PayLoadMessage *payLoadMessage=static_cast<PayLoadMessage*>(::malloc(total_length));
	payLoadMessage->length=htonl(option.length);
	for(int i=0;i<option.length;++i)
	{
		payLoadMessage->data[i]="1234567890ABCDEF"[i%16];;
	}	
	
	double total_mb=option.number*option.length*1.0/1024/1024;
	printf("%.3f MiB in total\n", total_mb);
	for(int i=0;i<option.number;++i)
	{
		int nw=tcpStreamPtr->sendAll(payLoadMessage,total_length);
		assert(nw==total_length);

		int ack;
		int nr=tcpStreamPtr->receiveAll(&ack,sizeof ack);
		assert(nr==sizeof(ack));
		ack=ntohl(ack);
		assert(ack==total_length);
	}
	double elapsed=(clock()-start)/1000000.0;
	printf("%.3lf seconds\n%.3lf MiB/s\n", elapsed, total_mb / elapsed);
	return 0;
}
