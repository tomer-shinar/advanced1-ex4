//
// Created by tomer on 26/01/2020.
//

#include "cache/file_cache_manager.h"
#include "solvers/StringReverser.h"
#include "./server/MyClientHandler.h"
#include "./solvers/SearcherAdapter.h"
#include "./server/MyParallelServer.h"

int main(int argc, char** argv) {
  int port = 5600;
  if (argc > 1) {
    port = stoi(argv[1]);
  }
  string s;
  auto* server = new MyParallelServer();
  server->Open(port, new MyClientHandler(new SearcherAdapter, new FileCacheManager<StringVectorProblem, SearchSolution>()));
  cout << "press finish to close server" << endl;
  cin >> s;
  server->Stop();
}