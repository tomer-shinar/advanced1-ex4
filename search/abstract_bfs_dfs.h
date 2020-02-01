//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_ABSTRACT_BFS_DFS_H_
#define ADVANCED1_EX4_SEARCH_ABSTRACT_BFS_DFS_H_

#include "abstract_searcher.h"
#include <list>

template <class T>
class AbstractBfsDfs : AbstractSearcher<T> {
  /**
   * abstract class for the bfs and dfs algorithms
   */
 protected:
  list<Node<T>> to_visit;
 public:
  bool Continue() override {return !this->to_visit.empty();}
  Node<T> GetNext() override {
    /**
     * the next node to visit
     */
    Node<T> to_return = this->to_visit.front();
    this->to_visit.pop_front();
    return to_return;
  }
  bool StopWhenOpening() override {return false;}
};

#endif //ADVANCED1_EX4_SEARCH_ABSTRACT_BFS_DFS_H_
