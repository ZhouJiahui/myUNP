all:InetAddress.o Socket.o TcpStream.o

InetAddress.o:
	g++ -std=c++11 -o InetAddress.o -c InetAddress.cc Common.h
Socket.o:
	g++ -std=c++11 -o Socket.o -c Socket.cc Common.h
TcpStream.o:
	g++ -std=c++11 -o TcpStream.o -c TcpStream.cc TcpStream.h
clean:
	rm *.o
