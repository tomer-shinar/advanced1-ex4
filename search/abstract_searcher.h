//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_ABSTRACT_SEARCHER_H_
#define ADVANCED1_EX4_SEARCH_ABSTRACT_SEARCHER_H_

#include "searcher.h"
#include <set>
#include <iostream>

template <class T>
void free_all(vector<Node<T>*> vec) {
  for (auto p: vec)
    delete p;
}

template<class T>
class AbstractSearcher : public Searcher<T> {
  /**
   * template class with the skeleton of the search algorithm
   */
 public:
  SearchSolution Search(Searchable<T>* problem) override {
    /**
     * abstract searching
     */
    Add(problem->GetInitialState(), problem);
    set<pair<int, int>> closed;
    vector<Node<T>*> to_free;
    int evaluated = 0;

    while (Continue()) {
      Node<T>* n = GetNext();
      if (closed.count(n->GetInfo()))
        continue;
      evaluated++;
      if (problem->IsGoalState(*n)) {
        string str = problem->GetSolution(n);
        free_all(to_free);
        return SearchSolution(str, evaluated);
      }
      closed.insert(n->GetInfo());
      for (Node<T>* s: problem->GetAllPossibleStates(n)) {
        to_free.push_back(s);
        if (StopWhenOpening() && problem->IsGoalState(*s)) {
          string str = problem->GetSolution(s);
          free_all(to_free);
          return SearchSolution(str, evaluated);
        }
        if (!closed.count(s->GetInfo()))
          //not in closed
          Add(s, problem);
      }
    }

    free_all(to_free);
    return SearchSolution(string("no solution"), -1);
  }
  virtual void Add(Node<T>* n, Searchable<T>* problem) = 0;
  virtual bool Continue() = 0;
  virtual Node<T>* GetNext() = 0;
  virtual bool StopWhenOpening() = 0;

};

#endif //ADVANCED1_EX4_SEARCH_ABSTRACT_SEARCHER_H_
