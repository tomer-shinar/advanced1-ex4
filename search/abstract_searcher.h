//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_ABSTRACT_SEARCHER_H_
#define ADVANCED1_EX4_SEARCH_ABSTRACT_SEARCHER_H_

#include "searcher.h"
#include <set>

template<class T>
class AbstractSearcher : public Searcher<T> {
  /**
   * template class with the skeleton of the search algorithm
   */
 public:
  string Search(Searchable<T>* problem) override {
    /**
     * abstract searching
     */
    Add(problem->GetInitialState(), problem);
    set<pair<int, int>> closed;

    while (Continue()) {
      Node<T> n = GetNext();
      if (problem->IsGoalState(n))
        return problem->GetSolution(n);
      closed.insert(n.GetInfo());
      for (Node<T> s: problem->GetAllPossibleStates(n)) {
        if (StopWhenOpening() && problem->IsGoalState(s))
          return problem->GetSolution(s);
        if (!closed.count(s))
          //not in closed
          Add(s, problem);
      }
    }

    return string("no solution");
  }
  virtual void Add(Node<T> n, Searchable<T>* problem) = 0;
  virtual bool Continue() = 0;
  virtual Node<T> GetNext() = 0;
  virtual bool StopWhenOpening() = 0;

};

#endif //ADVANCED1_EX4_SEARCH_ABSTRACT_SEARCHER_H_
