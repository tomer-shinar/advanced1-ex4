//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_BEST_FIRST_SEARCH_H_
#define ADVANCED1_EX4_SEARCH_BEST_FIRST_SEARCH_H_

#include "abstract_best_searcher.h"

template <class T>
class BestFirstSearch : AbstractBestSearcher<T> {
  /**
   * implement Best First Search algorithm
   */
 public:
  double GetKey(Node<T> n, Searchable<T> problem) {
    /**
     * returns the key for the node in the priority queue
     */
    return n.GetCost();
  }
};

#endif //ADVANCED1_EX4_SEARCH_BEST_FIRST_SEARCH_H_
