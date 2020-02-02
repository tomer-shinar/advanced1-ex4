//
// Created by tomer on 02/02/2020.
//

#include "MyParallelServer.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void MyParallelServer::Open(int port, ClientHandler* handler) {
  /**
   * open a serial server that listen to client send it to the client handler, and after the client handler finishes,
   * continue to the next client.
   * the server loop runs on another thread
   */
  this->continueAccepting = true;
  RunServer(port, handler);
}

void MyParallelServer::RunServer(int port, ClientHandler* handler) {
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
  tv.tv_sec = 180; // timeout
  setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
  if (listen(sockfd, 12) == -1)
    throw "failed listen";
  while (this->continueAccepting) {
    cout << "here";

    int client_socket = accept(sockfd, (struct sockaddr *) &address, (socklen_t *) &address);
    if (client_socket == -1)
      this->Stop();

    thread* t = new thread([handler, client_socket]{handler->clone()->handleClient(client_socket);});
    t->detach();
    threads.push_back(t);
  }
  close(sockfd);
}

void MyParallelServer::Stop() {
  this->continueAccepting = false;
  //if (this->serverLoop.joinable())
    //this->serverLoop.join();
  for (thread* t: threads) {
    if (t->joinable())
      t->join();
  }
}