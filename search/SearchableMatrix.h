//
// Created by tomer on 01/02/2020.
//

#ifndef ADVANCED1_EX4_SEARCH_SEARCHABLEMATRIX_H_
#define ADVANCED1_EX4_SEARCH_SEARCHABLEMATRIX_H_

#include "searchable.h"
#include <vector>

class SearchableMatrix : public Searchable<pair<int, int>> {
 private:
  vector<vector<int>> mat;
  int min_value; // the lowest value (exclude -1) in the matrix
  int row_len;
  pair<int, int> dst, src;

  Node<pair<int, int> >* next(Node<pair<int, int> >* prev, int row, int col);
 public:
  SearchableMatrix(vector<vector<int>> mt, pair<int, int> src, pair<int, int> dst) : mat(mt), dst(dst), src(src),
  row_len(mat[0].size()) {
    this->min_value = 0;
    for (auto & i : this->mat) {
      for (int j = 0; j < this->row_len; j++) {
        if (i[j] < this->min_value && i[j] != -1)
          this->min_value = i[j];
      }
    }
  };
  SearchableMatrix(vector<vector<int>> mt) : SearchableMatrix(mt, pair<int, int>(0, 0), pair<int, int>(mt.size(),
      mt[0].size())) {};

  Node<pair<int, int>>* GetInitialState() override ;
  bool IsGoalState(Node<pair<int, int>> n) override;
  vector<Node<pair<int, int>>*> GetAllPossibleStates(Node<pair<int, int>>* n) override ;
  double heuristics(Node<pair<int, int>> n) override ;
  string GetSolution(Node<pair<int, int>>* n) override ;
};

#endif //ADVANCED1_EX4_SEARCH_SEARCHABLEMATRIX_H_
