#include <iostream>
#include <string>


#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>

//using namespace std;

#pragma comment(lib, "Ws2_32.lib")
#define PORT 8080

void log(std::string msg){ std::cout<<msg<<std::endl;}

int main() {
    log("Hello I'm test Client!!!");

    //1. create client socket
    int client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    //2. fill address structure (Define the server address)
    sockaddr_in address;
    address.sin_port = htons(PORT);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;

    //3. bind the server socket
    int res = bind(client_socket_fd, (sockaddr*)&address, sizeof(address));
    if(res<0)
        log("client bind falied");
    




  return 0;
}