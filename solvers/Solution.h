//
// Created by tomer on 26/01/2020.
//

#ifndef ADVANCED1_EX4_SOLVERS_SOLUTION_H_
#define ADVANCED1_EX4_SOLVERS_SOLUTION_H_

#include <fstream>
#include <utility>

using namespace std;

class Solution {
  /**
   * interface that every solution must implement
   */
 public:
  virtual void ReadFrom(ifstream &f) = 0;
  virtual void WriteTo(ofstream &f) = 0;
  virtual string ToString() = 0;
};

class StringSolution: public Solution {
 private:
  string s;
 public:
  StringSolution() {
    this->s = "";
  };
  explicit StringSolution(string s) : s(std::move(s)) {};
  virtual void ReadFrom(ifstream &f) {
    f >> this->s;
  }
  void WriteTo(ofstream &f) override {
    f << s;
  }
  string ToString() override {
    return this->s;
  }
};

#endif //ADVANCED1_EX4_SOLVERS_SOLUTION_H_
