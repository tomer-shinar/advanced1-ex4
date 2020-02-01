//
// Created by tomer on 01/02/2020.
//

#include "StringVectorProblem.h"
#include <iostream>

string StringVectorProblem::hash() {
  string all;
  for (string line: this->vec) {
    all += line;
  }
  ::hash<string> hasher;
  return to_string(hasher(all));
}

vector<string> StringVectorProblem::GetVec() {
  return this->vec;
}