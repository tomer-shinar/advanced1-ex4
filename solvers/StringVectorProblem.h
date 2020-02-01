//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SOLVERS_STRINGVECTORPROBLEM_H_
#define ADVANCED1_EX4_SOLVERS_STRINGVECTORPROBLEM_H_

#include <utility>
#include <vector>
#include "Problem.h"

class StringVectorProblem : Problem {
  /**
   * representing a problem of vector of strings
   */
 private:
  vector<string> vec;
 public:
  StringVectorProblem(vector<string> vec): vec(std::move(vec)) {};
  string hash() override;
  vector<string> GetVec();
};

#endif //ADVANCED1_EX4_SOLVERS_STRINGVECTORPROBLEM_H_
