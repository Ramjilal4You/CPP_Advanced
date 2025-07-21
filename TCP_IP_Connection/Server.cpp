/// Server side C / C++ program to demonstrate Socket programming
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
//#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <sys/socket.h>
//#include <unistd.h>
#include <WinSock2.h>

#define PORT 8080
int main(int argc, char const* argv[])
{
    // Creating server socket file descriptor
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    char opt = '1';
    int res = setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,&opt, sizeof(opt));

    if (res) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in address;
    int addrlen = sizeof(address);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    size_t valread;
    
    
    // Forcefully attaching socket to the port 8080
    res = bind(server_fd, (struct sockaddr*)&address, sizeof(address) );

    if ( res < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    res = listen(server_fd, 3);
    if ( res < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    int client_fd = accept(server_fd, (struct sockaddr*)&address, &addrlen);
    if (client_fd < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    char buffer[1024] = { 0 };
    const char* hello = "Hello from server";

    valread = recv(client_fd, buffer, 1023, 1); // subtract 1 for the null terminator at the end

    printf("%s\n", buffer);

    send(client_fd, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    closesocket(client_fd);   // closing the connected socket
    
    closesocket(server_fd);   // closing the listening socket
    return 0;
}