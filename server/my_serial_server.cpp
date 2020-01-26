//
// Created by tomer on 25/01/2020.
//

#include "my_serial_server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void MySerialServer::Open(int port, ClientHandler* handler) {
  /**
   * open a serial server that listen to client send it to the client handler, and after the client handler finishes,
   * continue to the next client.
   * the server loop runs on another thread
   */
   this->continueAccepting = true;
   this->serverLoop = thread(&MySerialServer::RunServer, this, port, handler);
   this->serverLoop.detach();
}

void MySerialServer::RunServer(int port, ClientHandler* handler) {
  /**
   * runs the server loop of accepting client and handling it
   */
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(port);

  if (bind(sockfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
    throw "failed to bind";
  }

  struct timeval tv;
  tv.tv_sec = 3; // timeout
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);

  while (this->continueAccepting) {
    if (listen(sockfd, 10) == -1)
      throw "failed listen";
    int client_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket == -1)
      throw "failed accepting";
    handler->handleClient(client_socket);
  }
  close(sockfd);
}

void MySerialServer::Stop() {
  this->continueAccepting = false;
  this->serverLoop.join();
}
