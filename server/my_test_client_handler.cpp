//
// Created by tomer on 26/01/2020.
//


#include "my_test_client_handler.h"
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>

void MyTestClientHandler::handleClient(int clientSocket) {
  /**
   *
   */
  string line, sol;
  while ((line = this->ReadFromClient(clientSocket)) != "end") {
    if (this->cache->InCache(line))
      sol = this->cache->Get(line);
    else {
      sol = this->slv->solve(line);
      this->cache->Add(line, sol);
    }
    sol += "\n";
    int is_sent = send(clientSocket, sol.c_str(), strlen(sol.c_str()), 0);
  }
  close(clientSocket);
}