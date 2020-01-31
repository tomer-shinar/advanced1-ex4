//
// Created by tomer on 26/01/2020.
//

#ifndef EX4_SOLVERS_STRINGREVERSER_H_
#define EX4_SOLVERS_STRINGREVERSER_H_

#include "solver.h"
#include <iostream>
#include "Problem.h"
#include "Solution.h"

using namespace std;

class StringReverser : public Solver<StringProblem, StringSolution> {
 public:
  StringSolution solve(StringProblem problem) override ;
};

#endif //EX4_SOLVERS_STRINGREVERSER_H_
