//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_DFS_H_
#define ADVANCED1_EX4_SEARCH_DFS_H_

#include "abstract_bfs_dfs.h"

template<class T>
class DFS : public AbstractBfsDfs<T> {
  /**
   * implement dfs algorithm
   */
  void Add(Node<T>* n, Searchable<T>* problem) override {
    this->to_visit.push_front(n);
  }
};

#endif //ADVANCED1_EX4_SEARCH_DFS_H_
