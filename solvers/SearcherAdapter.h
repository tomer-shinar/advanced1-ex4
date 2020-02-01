//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SOLVERS_SEARCHERADAPTER_H_
#define ADVANCED1_EX4_SOLVERS_SEARCHERADAPTER_H_

#include "solver.h"
#include "searcher.h"
#include "StringVectorProblem.h"
#include "Solution.h"

class SearcherAdapter : Solver<StringVectorProblem, StringSolution> {
  /**
   * adapter from searcher to solver
   */
   StringSolution solve(StringVectorProblem problem) override ;

};

#endif //ADVANCED1_EX4_SOLVERS_SEARCHERADAPTER_H_
