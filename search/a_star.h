//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_A_STAR_H_
#define ADVANCED1_EX4_SEARCH_A_STAR_H_

#include "abstract_best_searcher.h"

template <class T>
class AStar : public AbstractBestSearcher<T> {
  /**
   * implement A* algorithm
   */
 public:
  double GetKey(Node<T> n, Searchable<T>* problem) override {
    /**
     * returns the key for the node in the priority queue
     */
    return n.GetCost() + problem->heuristics(n);
  }
};


#endif //ADVANCED1_EX4_SEARCH_A_STAR_H_
