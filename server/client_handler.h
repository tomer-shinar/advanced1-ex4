//
// Created by tomer on 25/01/2020.
//

#ifndef EX4_SERVER_CLIENT_HANDLER_H_
#define EX4_SERVER_CLIENT_HANDLER_H_

#include <iostream>

using namespace std;

class ClientHandler {
 public:
  virtual void handleClient(int clientSocket) = 0;
};

class AbstractClientHandler: ClientHandler {
 private:
  char buffer[1024] = {0};
  int bytesRead = 0;
 public:
  string ReadFromClient(int clientSocket);
  void FinishReading();
};

#endif //EX4_SERVER_CLIENT_HANDLER_H_
