//
// Created by tomer on 25/01/2020.
//

#ifndef EX4_SERVER_CLIENT_HANDLER_H_
#define EX4_SERVER_CLIENT_HANDLER_H_

class ClientHandler {
 public:
  virtual handleClient(int clientSocket) = 0;
  virtual clone() {};
};

#endif //EX4_SERVER_CLIENT_HANDLER_H_
