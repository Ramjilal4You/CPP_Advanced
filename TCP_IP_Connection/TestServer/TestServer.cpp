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

#include <iostream>

#include <WinSock2.h>
#include <WS2tcpip.h>

//The #pragma comment indicates to the linker that the Ws2_32. lib file is needed.
//Use the Winsock API by including the Winsock 2 header files.
#pragma comment(lib, "Ws2_32.lib")  //load the Ws2_32.lib library


void TestServer()
{
    std::cout << "Starting TestServer...\n";

    //Initialize Winsock
    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2, 2);
    int wsaerr = WSAStartup(wVersionRequested, &wsaData);
    if (wsaerr != 0)
        printf("WSAStartup failed, Error %ld\n", WSAGetLastError());
    else
        std::cout << "Initialized Winsock Successfull\n";

    //1. Creating server socket file descriptor
    SOCKET ServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ServerSocket == INVALID_SOCKET)
        printf("socket opening failed, Error %ld\n", WSAGetLastError());
    else
        std::cout << "Socket Creation Successfull\n";

    //2. fill address structure (Define the server address)
    struct sockaddr_in address;
    address.sin_family = AF_INET;   //IP family type
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr.s_addr);
    //address.sin_addr.s_addr = INADDR_ANY;   //for All IP

    address.sin_port = htons(5555); //for port

    //3. Bind the socket with address
    int res = bind(ServerSocket, (struct sockaddr*)&address, sizeof(address));
    if (res < 0)
        printf("bind failed, Error %ld\n", WSAGetLastError());
    else
        std::cout << "bind socket Successfull\n";

    //4. Listen on the socket for a client.
    res = listen(ServerSocket, 1);
    if (res < 0)
        printf("listen failed, Error %ld\n", WSAGetLastError());
    else
        std::cout << "listening, Waiting for client Connections ...\n";

    //5. Accept a connection from a client.
    SOCKET ClientSocket = accept(ServerSocket, NULL, NULL);
    if (ClientSocket == INVALID_SOCKET)
        printf("accept failed, Error %ld\n", WSAGetLastError());
    else
        std::cout << "Accecpt clinet Successfull\n";

    std::cout << "ClientSocket : " << ClientSocket << std::endl;
    std::cout << "ServerSocket : " << ServerSocket << std::endl;

    while (1) {
        //6. Receive data from socket
        const int MAX_LEN = 200;
        char buffer[MAX_LEN]="";
        res = recv(ClientSocket, buffer, MAX_LEN, 0); // subtract 1 for the null terminator at the end
        if (res < 0)
            printf("recv() failed, Error %ld\n", WSAGetLastError());
        else if (res > 0) //print data recieved from client
            std::cout << "Data Recieved from Client : " << buffer << std::endl;
        else  //client terminated
            break;

        memset(buffer, 0, MAX_LEN);
        std::cout << "Please Enter Msg : ";
        std::cin.getline(buffer, MAX_LEN); //get msg from console
        int len = strlen(buffer);
        if (strcmp(buffer, "bye") == 0 || len == 0)
            break;

        //7. send data to socket
        res = send(ClientSocket, buffer, len, 0);
        if (res < 0)
            printf("send() failed, Error %ld\n", WSAGetLastError());
        else
            std::cout << "Data Sent to Client : " << buffer << std::endl;
            
    }

    closesocket(ClientSocket);   // closing the connected socket

    closesocket(ServerSocket);   // closing the listening socket
}