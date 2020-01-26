//
// Created by tomer on 25/01/2020.
//

#ifndef EX4_CACHE_FILE_CACHE_MANAGER_H_
#define EX4_CACHE_FILE_CACHE_MANAGER_H_

#include "cache_manager.h"

template <class P, class S>
class FileCacheManager: public CacheManager<P, S> {
 public:
  FileCacheManager()= default;
  virtual bool InCache(P key);
  virtual S Get(P key);
  virtual void Add(P key, S value);
};

#endif //EX4_CACHE_FILE_CACHE_MANAGER_H_
