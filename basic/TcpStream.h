#pragma once
#include "Common.h"
#include "Socket.h"
#include <memory>
class InetAddress;
class TcpStream;
typedef std::unique_ptr<TcpStream> TcpStreamPtr;
//A blocking TCP stream
class TcpStream:Noncopyable
{
public:
	explicit TcpStream(Socket&& sock);
	~TcpStream()=default;
	TcpStream(TcpStream&&)=default;
	TcpStream& operator=(TcpStream&&)=default;
	static TcpStreamPtr connect(const InetAddress& serverAddr);
	static TcpStreamPtr connect(const InetAddress& serverAddr,const InetAddress& localAddr);
	
	
	InetAddress getPeerAddr() const;
	//NOT thread safe
	int receiveAll(void* buf,int len);
	int receiveSome(void* buf,int len);
	int sendAll(const void* buf,int len);
	int sendSome(const void* buf,int len);
	
	//thread safe
	void setTcpNoDelay(bool on);
	void shutdownWrite();
private:
	static TcpStreamPtr connectInternal(const InetAddress& serverAddr,const InetAddress* localAddr);
	Socket sock_;
};
