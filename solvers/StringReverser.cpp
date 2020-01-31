//
// Created by tomer on 26/01/2020.
//

#include <algorithm>
#include "StringReverser.h"

StringSolution StringReverser::solve(StringProblem problem) {
  /**
   * reverse a string and return it as the solution
   */
   string s = problem.GetS();
  reverse(s.begin(), s.end());
  return StringSolution(s);
}