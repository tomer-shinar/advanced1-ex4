//
// Created by tomer on 01/02/2020.
//

#include "SearchableMatrix.h"
#include <cstdlib>

string get_direction(pair<int, int> prev, pair<int, int> next);

Node<pair<int, int>>* SearchableMatrix::GetInitialState() {
  /**
   * return the initial state of the problem
   */
  return new Node<pair<int, int>>(this->src, this->mat[this->src.first][this->src.second]);
}

vector<Node<pair<int, int> >* > SearchableMatrix::GetAllPossibleStates(Node<pair<int, int> >* n) {
  /**
   * given a state, returns all the next possible states
   */
   vector<Node<pair<int, int> >* > v;
   if (n->GetInfo().first - 1 >= 0) {
    v.push_back(next(n, n->GetInfo().first - 1, n->GetInfo().second));
  }
  if (n->GetInfo().second - 1 >= 0) {
    v.push_back(next(n, n->GetInfo().first, n->GetInfo().second - 1));
  }
   if (n->GetInfo().second + 1 < this->row_len) {
    v.push_back(next(n, n->GetInfo().first, n->GetInfo().second + 1));
  }
   if (n->GetInfo().first + 1 < this->mat.size()) {
    v.push_back(next(n, n->GetInfo().first + 1, n->GetInfo().second));
  }
  return v;
}

Node<pair<int, int> >* SearchableMatrix::next(Node<pair<int, int> >* prev, int row, int col) {
  /**
   * return the node at (row, col) that his prev is prev
   */
   return new Node<pair<int, int> >(pair<int, int>(row, col), prev->GetCost() + this->mat[row][col], prev);
}

bool SearchableMatrix::IsGoalState(Node<pair<int, int> > n) {
  /**
   * check if the node is the goal
   */
   return n.GetInfo() == this->dst;
}

double SearchableMatrix::heuristics(Node<pair<int, int> > n) {
  /**
   * heuristics for the remaining path cost
   */
   if (IsGoalState(n)) {
     return 0;
   }
   return (abs(n.GetInfo().first - this->dst.first) + abs(n.GetInfo().second - this->dst.second)) * this->min_value;
}

string SearchableMatrix::GetSolution(Node<pair<int, int> >* n) {
  /**
   * return the solution to the problem from the solution node
   */
   string solution;
   Node<pair<int, int>> *current = n, *prev = n->GetPrev();
   while (prev != nullptr) {
     if (current != n) {
       //not the last so we put " ," before
       solution = "," + solution;
     }
     solution = get_direction(prev->GetInfo(), current->GetInfo()) + " (" + to_string((int) current->GetCost()) + ")" + solution;
     current = prev;
     prev = prev->GetPrev();
   }
   return solution;
}

string get_direction(pair<int, int> prev, pair<int, int> next) {
  /**
   * check in what direction the movement form prev to next is
   */
   if (prev.first == next.first + 1)
     return string("Up");
  if (prev.first == next.first - 1)
    return string("Down");
  if (prev.second == next.second + 1)
    return string("Left");
  return string("Right");
}