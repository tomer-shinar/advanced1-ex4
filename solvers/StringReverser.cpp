//
// Created by tomer on 26/01/2020.
//

#include <algorithm>
#include "StringReverser.h"

string StringReverser::solve(string problem) {
  /**
   * reverse a string and return it as the solution
   */
  reverse(problem.begin(), problem.end());
  return problem;
}