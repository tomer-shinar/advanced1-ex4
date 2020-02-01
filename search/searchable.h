//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_SEARCHABLE_H_
#define ADVANCED1_EX4_SEARCH_SEARCHABLE_H_

#include "node.h"
#include <vector>
#include <string>

using namespace std;

template<class T>
class Searchable {
 public:
  virtual Node<T> GetInitialState() = 0;
  virtual bool IsGoalState(Node<T> n) = 0;
  virtual vector<Node<T>> GetAllPossibleStates(Node<T> n) = 0;
  virtual double heuristics(Node<T> n) = 0;
  virtual string GetSolution(Node<T> n) = 0;
};

#endif //ADVANCED1_EX4_SEARCH_SEARCHABLE_H_
