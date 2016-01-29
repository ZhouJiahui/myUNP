all:InetAddress.o Socket.o TcpStream.o Acceptor.o

InetAddress.o:
	g++ -std=c++11 -o InetAddress.o -c InetAddress.cc 
Socket.o:
	g++ -std=c++11 -o Socket.o -c Socket.cc 
TcpStream.o:
	g++ -std=c++11 -o TcpStream.o -c TcpStream.cc 
Acceptor.o:
	g++ -std=c++11 -o Acceptor.o -c Acceptor.cc
clean:
	rm *.o
