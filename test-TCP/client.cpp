#include <winsock2.h>
#include <ws2tcpip.h>
#include <iostream>
#include <fstream>

#pragma comment(lib, "ws2_32.lib")
#define PORT 5000
#define BUFFER_SIZE 1024

int main() {
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Connection failed: " << WSAGetLastError() << "\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    std::ofstream outFile("received.txt", std::ios::binary);
    char buffer[BUFFER_SIZE];
    int bytesReceived;

    while ((bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0)) > 0) {
        outFile.write(buffer, bytesReceived);
    }

    std::cout << "File received and saved as 'received.txt'.\n";

    outFile.close();
    closesocket(clientSocket);
    WSACleanup();
    return 0;
}
