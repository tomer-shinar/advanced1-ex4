//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_ABSTRACT_BEST_SEARCHER_H_
#define ADVANCED1_EX4_SEARCH_ABSTRACT_BEST_SEARCHER_H_

#include "abstract_searcher.h"
#include <queue>

template <class T>
class Compare {
 public:
  bool operator()(pair<Node<T>*, double> first, pair<Node<T>*, double> second) {
    /**
     * comparator. returns true if second < first
     */
    return second.second <= first.second;
  }
};

template <class T>
class AbstractBestSearcher : public AbstractSearcher<T> {
  /**
   * abstract class for the a* and best first search algorithm
   */
 private:
  priority_queue<pair<Node<T>*, double>, vector<pair<Node<T>*, double>>, Compare<T>> q;
 public:
  void Add(Node<T>* n, Searchable<T>* problem) override {
    /**
     * add n to priority q
     */
    priority_queue<pair<Node<T>*, double>, vector<pair<Node<T>*, double>>, Compare<T>> tmp;
    bool need_to_add = true;
    while (q.size()) {
      if (q.top().first->GetInfo() == n->GetInfo()) {
        need_to_add = false;
        if (GetKey(*(q.top().first), problem) > GetKey(*n, problem))
          tmp.push(pair<Node<T>*, double>(n, GetKey(*n, problem)));
        else
          tmp.push(q.top());
      } else {
        tmp.push(q.top());
      }
      q.pop();
    }
    this->q = tmp;
    if (need_to_add)
      this->q.push(pair<Node<T>*, double>(n, GetKey(*n, problem)));
  }
  virtual double GetKey(Node<T> n, Searchable<T>* problem) = 0;
  bool Continue() override {return !this->q.empty();}
  Node<T>* GetNext() override {
    /**
     * the next node to visit
     */
    Node<T>* to_return = this->q.top().first;
    this->q.pop();
    return to_return;
  }
  bool StopWhenOpening() override {return false;}
};



#endif //ADVANCED1_EX4_SEARCH_ABSTRACT_BEST_SEARCHER_H_
