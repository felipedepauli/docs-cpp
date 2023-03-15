#include <iostream>
#include <string>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

const int kPort = 8080;                     // Server port
const int kBufferSize = 1024;               // Size of buffer to receive messages
const char* kServerAddress = "127.0.0.1";   // Server IP address

int main() {
  int client_socket;                        // Client socket
  struct sockaddr_in server_address;        // Server address
  char buffer[kBufferSize];                 // Buffer to receive messages

  // Create client socket -----------------------------------------------------
  client_socket = socket(AF_INET, SOCK_STREAM, 0); // Explained in server.cpp
  if (client_socket < 0) {
    std::cerr << "Error: Failed to create client socket." << std::endl;
    return 1;
  }

  // Connect to server --------------------------------------------------------
  memset(&server_address, 0, sizeof(server_address)); // Explained in server.cpp
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(kPort);
  if (inet_pton(AF_INET, kServerAddress, &server_address.sin_addr) <= 0) {
    std::cerr << "Error: Invalid address or address not supported."
              << std::endl;
    return 1;
  }
  if (connect(client_socket, (struct sockaddr *)&server_address,
              sizeof(server_address)) < 0) {
    std::cerr << "Error: Failed to connect to server." << std::endl;
    return 1;
  }
    while(1) {

  // Send message to server
        std::cout << "Enter message to send to server: ";
        std::string message;
        std::cin >> message;
        if (send(client_socket, message.c_str(), message.length(), 0) < 0) {
            std::cerr << "Error: Failed to send message to server." << std::endl;
            return 1;
        }

        // Receive message from server
        memset(buffer, 0, kBufferSize);
        int bytes_received =
            recv(client_socket, buffer, kBufferSize - 1, 0);
        if (bytes_received < 0) {
            std::cerr << "Error: Failed to receive message from server." << std::endl;
            return 1;
        }

        // Print message from server
        std::cout << "Received message from server: " << buffer << std::endl;

        if (message == "quit") {
            break;
        }
    }
  // Close socket
  close(client_socket);

  return 0;
}
