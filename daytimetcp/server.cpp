#include "daytimetcp.h"
int main(int argc,char **argv)
{
        if(argc!=2)
        {
                printf("usage:%s <IPort>\n",argv[0]);
                return 0;
        }
        InetAddress clientAddr(atoi(argv[1]));
        std::unique_ptr<Acceptor> acceptor(new Acceptor(clientAddr));
        char buff[MAXLINE];
        while(true)
        {
                TcpStreamPtr tcpStreamPtr=acceptor->accept();
                if(tcpStreamPtr)
                {
                        time_t ticks=time(NULL);
                        snprintf(buff,sizeof buff,"%.24s\r\n",ctime(&ticks));
                        int len=strlen(buff);
                        int n=tcpStreamPtr->sendAll(buff,len);
                        InetAddress peerAddr=tcpStreamPtr->getPeerAddr();
                        printf("send to %s",peerAddr.toIpPort().c_str());
                        if(n==len)
                        {
                                printf(" sucessfully\n");
                        }
                        else
                        {
                                printf(" error\n");
			}
		}
	}
	return 0;
}
