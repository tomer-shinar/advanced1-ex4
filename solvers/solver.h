//
// Created by tomer on 26/01/2020.
//

#ifndef EX4__SOLVER_H_
#define EX4__SOLVER_H_

template <class P, class S>
class Solver {
 public:
  virtual S solve(P problem) = 0;
};

#endif //EX4__SOLVER_H_
