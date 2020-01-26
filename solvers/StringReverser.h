//
// Created by tomer on 26/01/2020.
//

#ifndef EX4_SOLVERS_STRINGREVERSER_H_
#define EX4_SOLVERS_STRINGREVERSER_H_

#include "solver.h"
#include <iostream>

using namespace std;

class StringReverser : Solver<string, string> {
 public:
  string solve(string problem) override ;
};

#endif //EX4_SOLVERS_STRINGREVERSER_H_
