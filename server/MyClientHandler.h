//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SERVER_MYCLIENTHANDLER_H_
#define ADVANCED1_EX4_SERVER_MYCLIENTHANDLER_H_

#include "../solvers/Problem.h"
#include "client_handler.h"
#include "../search/SearchSolution.h"
#include "../cache/file_cache_manager.h"
#include "../solvers/solver.h"
#include "../solvers/StringVectorProblem.h"

class MyClientHandler : public AbstractClientHandler {
private:
  CacheManager<StringVectorProblem, SearchSolution>* cache;
  Solver<StringVectorProblem, SearchSolution>* slv;
public:
  MyClientHandler(Solver<StringVectorProblem, SearchSolution>* slv, CacheManager<StringVectorProblem, SearchSolution>*
    cache) : slv(slv), cache(cache) {};
  void handleClient(int clientSocket) override;
  ClientHandler* clone() override ;
};

#endif //ADVANCED1_EX4_SERVER_MYCLIENTHANDLER_H_
