// Server side C++ program to demonstrate Socket programming
/*
Server
Initialize Winsock.
Create a socket.
Bind the socket.
Listen on the socket for a client.
Accept a connection from a client.
Receive and send data.
Disconnect.
*/

#include "TestServer.hxx"

int main() {

	//TestServer();

	TestServer2();	//using thread

	return 0;
}