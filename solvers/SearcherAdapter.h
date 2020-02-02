//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SOLVERS_SEARCHERADAPTER_H_
#define ADVANCED1_EX4_SOLVERS_SEARCHERADAPTER_H_

#include "solver.h"
#include "../search/searcher.h"
#include "StringVectorProblem.h"
#include "../search/SearchSolution.h"

class SearcherAdapter : public Solver<StringVectorProblem, SearchSolution> {
  /**
   * adapter from searcher to solver
   */
   SearchSolution solve(StringVectorProblem problem) override ;
};

#endif //ADVANCED1_EX4_SOLVERS_SEARCHERADAPTER_H_
