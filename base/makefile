all:InetAddress.o Socket.o

InetAddress.o:
	g++ -std=c++11 -o InetAddress.o -c InetAddress.cc Common.h
Socket.o:
	g++ -std=c++11 -o Socket.o -c Socket.cc Common.h

clean:
	rm *.o
