all:client server
client:InetAddress.o Socket.o TcpStream.o
	g++ -std=c++11 -o client client.cpp InetAddress.o Socket.o TcpStream.o
server:InetAddress.o Socket.o TcpStream.o Acceptor.o
	g++ -std=c++11 -o server server.cpp InetAddress.o Socket.o TcpStream.o Acceptor.o
InetAddress.o:
	g++ -std=c++11 -c ../basic/InetAddress.cc
Socket.o:
	g++ -std=c++11 -c ../basic/Socket.cc
TcpStream.o:
	g++ -std=c++11 -c ../basic/TcpStream.cc
Acceptor.o:
	g++ -std=c++11 -c ../basic/Acceptor.cc
clean:
	rm *.o
