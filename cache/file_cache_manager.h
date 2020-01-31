//
// Created by tomer on 25/01/2020.
//

#ifndef EX4_CACHE_FILE_CACHE_MANAGER_H_
#define EX4_CACHE_FILE_CACHE_MANAGER_H_

#include "cache_manager.h"
#include <iostream>
#include <fstream>
#include <string>


template <class P, class S>
class FileCacheManager: public CacheManager<P, S> {
 public:
  FileCacheManager()= default;
  virtual bool InCache(P key) {
    /**
  * check if the key is in cache by checking if the file exists
  */
    ifstream f(key.hash() + ".txt");
    return f.good();
  }
  virtual S Get(P key) {
    /***
 * get the saved value of the key
 */
    if (!this->InCache(key)) {
      throw "no such key in cache";
    }
    ifstream f(key.hash() + ".txt");
    S val;
    val.ReadFrom(f);
    f.close();
    return val;
  }
  virtual void Add(P key, S value) override {
    /**
 * add the key:value to the cache
 */
    ofstream f(key.hash() + ".txt");
    value.WriteTo(f);
    f.close();
  }
};

#endif //EX4_CACHE_FILE_CACHE_MANAGER_H_
