//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_BFS_H_
#define ADVANCED1_EX4_SEARCH_BFS_H_

#include "abstract_bfs_dfs.h"

template<class T>
class BFS : AbstractBfsDfs<T> {
  /**
   * implement bfs algorithm
   */
   void Add(Node<T>* n) override {
     this->to_visit.push_back(n);
   }
};

#endif //ADVANCED1_EX4_SEARCH_BFS_H_
