/*
1. Client
2. Initialize Winsock.
3. Create a socket.
4. Connect to the server.
5. Send and receive data.
6. Disconnect.

*/
#include <iostream>
#include <string>
#include <thread>

//windows Socket Headers
#include <winsock2.h>
#include <ws2tcpip.h>


//using namespace std;

//#pragma comment(lib, "Ws2_32.lib") //added Ws2_32.lib; in Project->Properties->Linker->Input->Additional Dependencies

void readDataFromSocket(SOCKET clientSocket) {
    //5. recieve data from socket
    while (1) {
        const int MAX_LEN = 200;
        char buffer[MAX_LEN];
        memset(buffer, '\0', MAX_LEN);
        int res = recv(clientSocket, buffer, MAX_LEN, 0);
        if (res < 0)
            printf("recv() failed, Error %ld\n", WSAGetLastError());
        else if (res > 0) //print data recieved from client
            std::cout << "Data Recieved from Server : " << buffer << std::endl;

        if (strcmp(buffer, "bye") == 0) {
            std::cout << "recieved bye - Closing Connection\n";
            break;
        }
    }
}

void sendDataToSocket(SOCKET clientSocket) {
    //4. Send data to socket
    while (1) {
        const int MAX_LEN = 200;
        char buffer[MAX_LEN];
        std::cout << "Please Enter Msg : ";
        std::cin.getline(buffer, MAX_LEN);
        int len = strlen(buffer);

      
        int byteCount = send(clientSocket, buffer, len, 0);
        if (byteCount < 0)    //(byteCount == SOCKET_ERROR)
            printf("send() failed, Error %ld\n", WSAGetLastError());
        else
            std::cout << "Data Sent to Server : " << buffer << std::endl;

        if (strcmp(buffer, "bye") == 0) {
            std::cout << "bye, Closing Connection\n";
            break;
        }
    }
}

void TestClient2()
{
    std::cout<<"Starting TestClient...\n";

    //Initialize Winsock
    WSADATA wsaData;
    int res = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (res != 0)
        printf("WSAStartup() failed, Error %ld\n", WSAGetLastError());
    else
        std::cout << "Initialized Winsock Successfull\n";


    //1. Create a client SOCKET for connecting to server
    SOCKET ClientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ClientSocket == INVALID_SOCKET) {
        printf("socket opening failed, Error %ld\n", WSAGetLastError());
        WSACleanup();
    }
    else
        std::cout << "Client Socket Creation Successfull\n";

    //2. fill address structure (Define the server address)
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &address.sin_addr.s_addr);
    //address.sin_addr.s_addr = INADDR_ANY; //Error, Not able to connect
    address.sin_port = htons(5555);

    //3. Forcefully attaching socket to the port 8080
    res = connect(ClientSocket, (sockaddr*)&address, sizeof(address));
    if (res == SOCKET_ERROR) {
        printf("connect() failed, Error %ld\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        ClientSocket = INVALID_SOCKET;
    }
    else
        std::cout << "Connection Successfull\n";

    std::cout << "ClientSocket : " << ClientSocket << std::endl;

    //while (1) {
        //4. Send data to socket
        std::thread t1(sendDataToSocket, ClientSocket);
        

        //5. recieve data from socket
        std::thread t2(readDataFromSocket, ClientSocket);
        
    //}
        t1.join();
        t2.join();

    //6. close the connection
    closesocket(ClientSocket);
}