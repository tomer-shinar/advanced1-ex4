//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_ABSTRACT_BEST_SEARCHER_H_
#define ADVANCED1_EX4_SEARCH_ABSTRACT_BEST_SEARCHER_H_

#include "abstract_searcher.h"
#include <queue>

template <class T>
class Compare {
  bool operator()(pair<T, double> first, pair<T, double> second) {
    /**
     * comparator. returns true if second < first
     */
    return second.second <= first.second;
  }
};

template <class T>
class AbstractBestSearcher : AbstractSearcher<T> {
  /**
   * abstract class for the a* and best first search algorithm
   */
 private:
  priority_queue<pair<Node<T>, double>, vector<Node<T>, double>, Compare<T>> q;
 public:
  void Add(Node<T> n, Searchable<T>* problem) override {
    /**
     * add n to priority q
     */
    this->q.push(pair<Node<T>, double>(n, GetKey(n, problem)));
  }
  virtual double GetKey(Node<T> n, Searchable<T>* problem) = 0;
  bool Continue() override {return !this->q.empty();}
  Node<T> GetNext() override {
    /**
     * the next node to visit
     */
    Node<T> to_return = this->q.top().first;
    this->q.pop();
    return to_return;
  }
  bool StopWhenOpening() override {return false;}
};



#endif //ADVANCED1_EX4_SEARCH_ABSTRACT_BEST_SEARCHER_H_
