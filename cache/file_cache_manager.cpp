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
  ifstream f(to_string(hash<P>(key)) + ".txt");
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
  ifstream f(to_string(hash<P>(key)) + ".txt");
  S toReturn(f);
  f.close();
  return toReturn;
}
template <class P, class S>
void FileCacheManager<P, S>::Add(P key, S value) {
  /**
   * add the key:value to the cache
   */
  ofstream f(to_string(hash<P>(key)) + ".txt");
  value.WriteTo(f);
  f.close();
}