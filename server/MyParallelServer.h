//
// Created by tomer on 02/02/2020.
//

#ifndef ADVANCED1_EX4_SERVER_MYPARALLELSERVER_H_
#define ADVANCED1_EX4_SERVER_MYPARALLELSERVER_H_

#include "server.h"
#include <thread>
#include <vector>

using namespace std;

class MyParallelServer: public server_side::Server {
 private:
  bool continueAccepting;
  thread serverLoop;
  vector<thread*> threads;
  void RunServer(int port, ClientHandler* handler);
 public:
  MyParallelServer() = default;
  void Open(int port, ClientHandler* handler) override;
  void Stop() override;
};

#endif //ADVANCED1_EX4_SERVER_MYPARALLELSERVER_H_
