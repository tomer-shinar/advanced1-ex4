//
// Created by tomer on 26/01/2020.
//

#ifndef EX4_SERVER_MY_TEST_CLIENT_HANDLER_H_
#define EX4_SERVER_MY_TEST_CLIENT_HANDLER_H_

#include "client_handler.h"
#include <utility>
#include "../cache/file_cache_manager.h"
#include "../solvers/solver.h"


class MyTestClientHandler: public AbstractClientHandler {
 private:
  CacheManager<string, string>* cache;
  Solver<string, string>* slv;
 public:
  MyTestClientHandler(Solver<string, string>* slv, FileCacheManager<string, string>* cache) : slv(slv), cache(cache) {};
  void handleClient(int clientSocket) override;
};

#endif //EX4_SERVER_MY_TEST_CLIENT_HANDLER_H_
