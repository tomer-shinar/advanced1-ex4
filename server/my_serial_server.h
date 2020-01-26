//
// Created by tomer on 25/01/2020.
//

#ifndef EX4_SERVER_MY_SERIAL_SERVER_H_
#define EX4_SERVER_MY_SERIAL_SERVER_H_

#include "server.h"
#include <thread>

using namespace std;

class MySerialServer: public server_side::Server {
 private:
  bool continueAccepting;
  thread serverLoop;
  void RunServer(int port, ClientHandler* handler);
 public:
  MySerialServer() = default;
  void Open(int port, ClientHandler* handler) override;
  void Stop() override;
};

#endif //EX4_SERVER_MY_SERIAL_SERVER_H_
