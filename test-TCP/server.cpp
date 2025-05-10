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

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed: " << WSAGetLastError() << "\n";
        return 1;
    }

    listen(serverSocket, SOMAXCONN);
    std::cout << "Server listening on port " << PORT << "...\n";

    SOCKET clientSocket = accept(serverSocket, nullptr, nullptr);
    std::cout << "Client connected!\n";

    std::ifstream file("file.txt", std::ios::binary);
    if (!file) {
        std::cerr << "File not found.\n";
        closesocket(clientSocket);
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    char buffer[BUFFER_SIZE];
    while (!file.eof()) {
        file.read(buffer, BUFFER_SIZE);
        int bytesRead = file.gcount();
        send(clientSocket, buffer, bytesRead, 0);
    }

    std::cout << "File sent successfully.\n";

    file.close();
    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
