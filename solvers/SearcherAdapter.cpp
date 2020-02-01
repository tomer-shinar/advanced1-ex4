//
// Created by tomer on 01/02/2020.
//

#include "SearcherAdapter.h"
#include "SearchableMatrix.h"
#include <sstream>
#include "a_star.h"

vector<int> to_vector(string s) {
  /**
   * takes string and split it to vector of ints
   */
  stringstream ss(s);
  string token;
  vector<int> values;
  while (getline(ss, token, ','))
    values.push_back(stoi(token));
  return values;
}

StringSolution SearcherAdapter::solve(StringVectorProblem problem) {
  vector<vector<int>> mat;
  int i;
  for (i = 0; i < problem.GetVec().size() - 2; i++) {
    //going other all lines accept the last 2
    mat.push_back(to_vector(problem.GetVec()[i]));
  }
  pair<int, int> src, dst;
  src.first = to_vector(problem.GetVec()[i])[0];
  src.second = to_vector(problem.GetVec()[i])[1];
  dst.first = to_vector(problem.GetVec()[i + 1])[0];
  dst.second = to_vector(problem.GetVec()[i + 1])[1];
  AStar<pair<int, int>> searcher;
  return StringSolution(searcher.Search(new SearchableMatrix(mat, src, dst)));
}