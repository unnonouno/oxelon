#ifndef TRANSPOSITION_TABLE_HPP_F19C4747_279F_418A_95BD_80858FDF41F1_
#define TRANSPOSITION_TABLE_HPP_F19C4747_279F_418A_95BD_80858FDF41F1_

#include <vector>

namespace oxelon {

template<class K, class T, class H>
class TranspositionTable {
public:
  typedef T entry_type;
  typedef K key_type;
  typedef std::pair<K, T> value_type;

  typedef typename std::vector<value_type>::iterator iterator;
  typedef typename std::vector<value_type>::const_iterator const_iterator;

  TranspositionTable(size_t size);

  ~TranspositionTable();

  size_t size() const;

  iterator end();

  iterator find(const K& key);

  iterator insert(const value_type& v);

  int get_hit_count() const { return hit_count_; }
  int get_entry_count() const { return entry_count_; }
  
private:
  std::vector<value_type> vec_data_;
  //std::vector<bool> vec_valid_;

  int hit_count_;
  int entry_count_;
};


template<class K, class T, class H>
inline
TranspositionTable<K, T, H>::TranspositionTable(size_t size)
    : vec_data_((1 << size) - 1),
      hit_count_(),
      entry_count_() {
}

template<class K, class T, class H> inline
TranspositionTable<K,T,H>::~TranspositionTable() {
}

template<class K, class T, class H> inline
size_t
TranspositionTable<K,T,H>::size() const {
  return vec_data_.size();
}

template<class K, class T, class H> inline
typename TranspositionTable<K, T, H>::iterator
TranspositionTable<K,T,H>::end() {
  return vec_data_.end();
}

template<class K, class T, class H> inline
typename TranspositionTable<K, T, H>::iterator
TranspositionTable<K, T, H>::find(const K& key) {
  size_t hash = H()(key);
  size_t index = hash % size();

  if (/*vec_valid_[index] && */vec_data_[index].first == key) {
    return vec_data_.begin() + index;
  } else {
    return end();
  }
}

template<class K, class T, class H> inline
typename TranspositionTable<K, T, H>::iterator
TranspositionTable<K, T, H>::insert(
    const typename TranspositionTable<K, T, H>::value_type& v) {
  size_t hash = H()(v.first);
  size_t index = hash % size();
  vec_data_[index] = v;
  //vec_valid_[index] = true;
  return vec_data_.begin() + index;
}

}  // namespace oxelon

#endif // TRANSPOSITION_TABLE_HPP_F19C4747_279F_418A_95BD_80858FDF41F1_
