//
// Created by tomer on 25/01/2020.
//

#ifndef EX4_CACHE_CACHE_MANAGER_H_
#define EX4_CACHE_CACHE_MANAGER_H_

template <class P, class S>
class CacheManager {
 public:
  virtual bool InCache(P key) = 0;
  virtual S Get(P key) = 0;
  virtual void Add(P key, S value);
  virtual ~CacheManager() {};
};

#endif //EX4_CACHE_CACHE_MANAGER_H_
