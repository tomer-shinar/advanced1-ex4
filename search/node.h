//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_NODE_H_
#define ADVANCED1_EX4_SEARCH_NODE_H_

template <class T>
class Node {
  /**
   * representing a node/state in a search problem.
   * T is the type of information saved for each possible state
   */
 private:
  T info;
  double cost;
  Node<T>* prev;
 public:
  Node(T info, double cost, Node<T>* prev) : info(info), cost(cost), prev(prev) {};
  Node(T info, double initial_cost) : Node(info, initial_cost, nullptr) {};
  T GetInfo() {
    return this->info;
  }
  double GetCost() {
    return this->cost;
  }
  Node<T>* GetPrev() {
    return this->prev;
  }
};

#endif //ADVANCED1_EX4_SEARCH_NODE_H_
