#include "daytimetcp.h"

int main(int argc,char **argv)
{
        if(argc!=3)
        {
                printf("usage: %s <IPaddress> <IPport>\n",argv[0]);
                return 0;
        }

        InetAddress serverAddr(argv[1],static_cast<unsigned short>(atoi(argv[2])));
        TcpStreamPtr tcpStreamPtr=TcpStream::connect(serverAddr);
        if(!tcpStreamPtr)
        {
                printf("Unable to connect %s\n",serverAddr.toIpPort().c_str());
                return 0;
        }
        int n;
        char recvline[MAXLINE+1];
        while((n=tcpStreamPtr->receiveAll(recvline,MAXLINE))>0)
        {
                recvline[n]=0;
                puts(recvline);
	}
	if(n<0)
	{
		printf("read error\n");
		return 0;
	}
	return 0;
}
