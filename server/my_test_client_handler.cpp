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
  string line;
  StringSolution sol;
  while ((line = this->ReadFromClient(clientSocket)) != "end") {
    StringProblem prob(line);
    if (this->cache->InCache(prob))
      sol = this->cache->Get(prob);
    else {
      sol = this->slv->solve(prob);
      this->cache->Add(prob, sol);
    }
    string to_send = sol.ToString();
    to_send += "\n";
    int is_sent = send(clientSocket, to_send.c_str(), strlen(to_send.c_str()), 0);
  }
  close(clientSocket);
}