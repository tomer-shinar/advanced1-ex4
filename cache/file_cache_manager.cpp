//
// Created by tomer on 25/01/2020.
//

#include "file_cache_manager.h"
#include <iostream>
#include <fstream>

using namespace std;

template <class P, class S>
bool FileCacheManager<P, S>::InCache(P key) {
  /**
  * check if the key is in cache by checking if the file exists
  */
  ifstream f(key.HashFileName().c_str());
  return f.good();
}
template <class P, class S>
S FileCacheManager<P, S>::Get(P key) {
  /***
   * get the saved value of the key
   */
  if (!this->InCache(key)) {
    throw "no such key in cache";
  }
  ifstream f(key.HashFileName());
  S toReturn(f);
  f.close();
  return toReturn;
}
template <class P, class S>
void FileCacheManager<P, S>::Add(P key, S value) {
  /**
   * add the key:value to the cache
   */
  ofstream f(key.HashFileName);
  value.WriteTo(f);
  f.close();
}