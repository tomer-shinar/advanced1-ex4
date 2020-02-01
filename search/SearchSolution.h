//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_SEARCHSOLUTION_H_
#define ADVANCED1_EX4_SEARCH_SEARCHSOLUTION_H_

#include "Solution.h"

class SearchSolution : Solution{
 private:
  string path;
  int evaluated;
 public:
  SearchSolution(string path, int evaluated) : path(path), evaluated(evaluated) {};
  SearchSolution() : SearchSolution("", 0) {};
  virtual void ReadFrom(ifstream &f) {
    f >> this->path;
  }
  void WriteTo(ofstream &f) override {
    f << path;
  }
  string ToString() override {
    return this->path;
  }
};

#endif //ADVANCED1_EX4_SEARCH_SEARCHSOLUTION_H_
