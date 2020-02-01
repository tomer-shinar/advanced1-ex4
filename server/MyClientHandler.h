//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SERVER_MYCLIENTHANDLER_H_
#define ADVANCED1_EX4_SERVER_MYCLIENTHANDLER_H_

#include <Problem.h>
#include "client_handler.h"
#include "SearchSolution.h"
#include "file_cache_manager.h"
#include "solver.h"
#include "StringVectorProblem.h"

class MyClientHandler : public AbstractClientHandler {
private:
  CacheManager<StringVectorProblem, SearchSolution>* cache;
  Solver<StringVectorProblem, SearchSolution>* slv;
public:
  MyClientHandler(Solver<StringVectorProblem, SearchSolution>* slv, FileCacheManager<StringVectorProblem, SearchSolution>*
    cache) : slv(slv), cache(cache) {};
  void handleClient(int clientSocket) override;
};

#endif //ADVANCED1_EX4_SERVER_MYCLIENTHANDLER_H_
