//
// Created by tomer on 25/01/2020.
//

#ifndef ADVANCED1_EX4_SERVER_SERVER_H_
#define ADVANCED1_EX4_SERVER_SERVER_H_

#include "client_handler.h"

namespace server_side {
  class Server {
   public:
    virtual void Open(int port, ClientHandler* handler) = 0;
    virtual void Stop() = 0;
  };
}

#endif //ADVANCED1_EX4_SERVER_SERVER_H_
