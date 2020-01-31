//
// Created by tomer on 26/01/2020.
//

#ifndef ADVANCED1_EX4_SOLVERS_PROBLEM_H_
#define ADVANCED1_EX4_SOLVERS_PROBLEM_H_

#include <string>
#include <utility>

using namespace std;

class Problem {
  /**
   * class that every problem must implement
   */
 public:
  virtual string hash() = 0;
};

class StringProblem : public Problem {
 private:
  string s;
 public:
  explicit StringProblem(string s) : s(std::move(s)) {};
  string hash() override {
    /**
     * hash the string.
     */
    ::hash<string> hasher;
    return to_string(hasher(this->s));
  }
  string GetS() {return this->s;}
};

#endif //ADVANCED1_EX4_SOLVERS_PROBLEM_H_
