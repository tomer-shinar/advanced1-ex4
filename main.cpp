//
// Created by tomer on 26/01/2020.
//

#include "server/my_serial_server.h"
#include "server/my_test_client_handler.h"
#include "cache/file_cache_manager.h"
#include "solvers/StringReverser.h"
#include <unistd.h>

int main(int argc, char** argv) {
  int port = 5400;
  string s;
  auto* server = new MySerialServer();
  server->Open(port, new MyTestClientHandler(new StringReverser(), new FileCacheManager<StringProblem, StringSolution>()));
  cout << "press enter to close server";
  cin >> s;
  server->Stop();
}