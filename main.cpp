//
// Created by tomer on 26/01/2020.
//

#include "server/my_serial_server.h"
#include "server/my_test_client_handler.h"
#include "cache/file_cache_manager.h"
#include "solvers/StringReverser.h"
#include <unistd.h>
#include "MyClientHandler.h"
#include "SearcherAdapter.h"
#include "MyParallelServer.h"

int main(int argc, char** argv) {
  int port = 12345;
  string s;
  auto* server = new MyParallelServer();
  server->Open(port, new MyClientHandler(new SearcherAdapter, new FileCacheManager<StringVectorProblem, SearchSolution>()));
  cout << "press finish to close server" << endl;
  cin >> s;
  server->Stop();
}