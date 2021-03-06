//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_SEARCHER_H_
#define ADVANCED1_EX4_SEARCH_SEARCHER_H_

#include <string>
#include "searchable.h"
#include "SearchSolution.h"

template <class T>
class Searcher {
 public:
  virtual SearchSolution Search(Searchable<T>* problem) = 0;
};

#endif //ADVANCED1_EX4_SEARCH_SEARCHER_H_
