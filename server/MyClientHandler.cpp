//
// Created by tomer on 01/02/2020.
//

#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include "MyClientHandler.h"

void MyClientHandler::handleClient(int clientSocket) {
  /**
   *
   */
  string line;
  vector<string> lines;
  SearchSolution sol;
  while ((line = this->ReadFromClient(clientSocket)) != "end") {
      lines.push_back(line);
  }
  StringVectorProblem prob(lines);
  if (this->cache->InCache(prob))
      sol = this->cache->Get(prob);
  else {
    sol = this->slv->solve(prob);
    this->cache->Add(prob, sol);
  }
  string to_send = sol.ToString();
  to_send += "\n";
  int is_sent = send(clientSocket, to_send.c_str(), strlen(to_send.c_str()), 0);
  close(clientSocket);
}