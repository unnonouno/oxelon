#ifndef SORTED_LIST_HPP_AF833EDA_0FE3_48CC_91CC_6F23C28915E5_
#define SORTED_LIST_HPP_AF833EDA_0FE3_48CC_91CC_6F23C28915E5_

// TODO: Use heap

#include <vector>

namespace oxelon {

template<class E1, class E2> inline
void sort_insert(
    std::vector<E1> &keys,
    std::vector<E2> &cont,
    const E1 &key,
    const E2 &val) {
  int i = keys.size() - 1;

  if (i >= 0) {
    if (keys[i] <= key) {
      keys.insert(keys.end(), key);
      cont.insert(cont.end(), val);
      return;
    } else {
      --i;
    }
  }

  while (i >= 0) {
    if (keys[i] <= key) {
      keys.insert(keys.begin() + i+1, key);
      cont.insert(cont.begin() + i+1, val);
      return;
    } else {
      --i;
    }
  }
  keys.insert(keys.begin(), key);
  cont.insert(cont.begin(), val);
}

template<class T1, class T2, class E1, class E2> inline
void sort_insert(T1 &keys, T2 &cont, const E1 &key, const E2 &val) {
  typename T1::iterator it1 = keys.begin();
  typename T2::iterator it2 = cont.begin();

  typename T1::iterator end = keys.end();
  while (it1 != end) {
    if (key < *it1) {
      keys.insert(it1, key);
      cont.insert(it2, val);
      return;
    } else {
      ++it1;
      ++it2;
    }
  }
  keys.insert(it1, key);
  cont.insert(it2, val);
}

}  // namespace oxelon

#endif // SORTED_LIST_HPP_AF833EDA_0FE3_48CC_91CC_6F23C28915E5_
