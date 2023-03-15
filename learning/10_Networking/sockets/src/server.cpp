#include <iostream>     // Manipulate input and output
#include <string>       // Manipulate strings in C++
#include <cstring>      // Manipulate strings in C
#include <sys/socket.h> // Create sockets          (methods)
#include <netinet/in.h> // Manipulate IP addresses (structures)
#include <arpa/inet.h>  // Manipulate IP addresses (inet_addr)
#include <unistd.h>     // Close sockets           (close)

// This code is a simple example of how to create a socket server in C++.
// The idea is that the server creates a socket, binds it to an IP address and to a port
// starts listening for incoming connections and, when a connection arrives,
// sends a message to the client and receives a message from the client.

const int kPort = 8080;       // Port to listen on
const int kBufferSize = 1024; // Size of buffer to receive messages

int main() {
  // Variables ---------------------------------------------------------------
  int server_socket, client_socket;                   // Server and client sockets
  struct sockaddr_in server_address, client_address;  // Server and client addresses
  int client_address_length = sizeof(client_address); // Length of client address
  char buffer[kBufferSize];                           // Buffer to receive messages

  // Create server socket ----------------------------------------------------
  server_socket = socket(AF_INET, SOCK_STREAM, 0);
  //  AF_INET: IPv4
  //  SOCK_STREAM: TCP
  //  0: Protocol (0 means use default protocol for AF_INET and SOCK_STREAM)
  if (server_socket < 0) {
    std::cerr << "Error: Failed to create server socket." << std::endl;
    return 1;
  }

  // Bind server socket to IP address and port --------------------------------
  memset(&server_address, 0, sizeof(server_address));   // Clear server address
  server_address.sin_family       = AF_INET;            // Socket is an IPv4 socket
  server_address.sin_addr.s_addr  = htonl(INADDR_ANY);  // Bind to any IP address - Any
                                                        // It's possible use an IP using inet_pton
  server_address.sin_port         = htons(kPort);       // Bind to port 8080

  if (bind(server_socket, (struct sockaddr *)&server_address,
           sizeof(server_address)) < 0) {
    std::cerr << "Error: Failed to bind server socket to IP address and port."
              << std::endl;
    return 1;
  }

  // Listen for incoming connections -----------------------------------------
  if (listen(server_socket, 5) < 0) { // 5 is the maximum number of pending connections
    std::cerr << "Error: Failed to listen for incoming connections." << std::endl;
    return 1;
  }

  // Accept incoming connections ---------------------------------------------
  client_socket = // Each client has a socket to communicate with the server
      accept(server_socket, (struct sockaddr *)&client_address,
             (socklen_t *)&client_address_length);
  if (client_socket < 0) {
    std::cerr << "Error: Failed to accept incoming connection." << std::endl;
    return 1;
  }

  // The communcation between the server and the client is done using the
  // client_socket. The server_socket is used only to accept incoming
  // connections.
  // The two methods used by the server to receive and to send messages are
  // recv and send, respectively. The first argument is the socket used to
  // communicate with the client, the second argument is the buffer where the
  // message will be stored, the third argument is the size of the buffer and
  // the fourth argument is a set of flags that can be used to modify the
  // behavior of the method. The value 0 means that no flags are used.


	while(1) {

		// Receive message from client ---------------------------------------------
		memset(buffer, 0, kBufferSize); // Clear the buffer
		int bytes_received =
			recv(client_socket, buffer, kBufferSize - 1, 0);
		if (bytes_received < 0) {
		std::cerr << "Error: Failed to receive message from client." << std::endl;
		return 1;
		}


		// Print message from client -----------------------------------------------
		std::cout << "Received message from client: " << buffer << std::endl;
		// Send message to client --------------------------------------------------
		std::string message = "I've received your message ;)";
		if (send(client_socket, message.c_str(), message.length(), 0) < 0) {
			std::cerr << "Error: Failed to send message to client." << std::endl;
			return 1;
		}
		if (buffer == "quit") {
			break;
		}

	}

  // Close sockets -----------------------------------------------------------
  close(client_socket);
  close(server_socket);

  return 0;
}
