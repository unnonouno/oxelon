#ifndef STREAM_HPP_979401B2_A050_408A_9C31_4AC1011E3DAA_
#define STREAM_HPP_979401B2_A050_408A_9C31_4AC1011E3DAA_

// TODO: Use serializer

#include <iostream>
#include <vector>

namespace oxelon {

template<typename T>
static std::istream&
operator >> (std::istream& in, std::vector<T>& v) {
  for (size_t i = 0; i < v.size(); ++i) {
    in >> v[i];
  }
  return in;
}

template<typename T>
static std::ostream&
operator << (std::ostream& out, const std::vector<T>& v)
{
  for (size_t i = 0; i < v.size(); ++i) {
    out << v[i] << " ";
  }
  return out;
}

template<typename U, typename T>
static std::istream&
read_binary(std::istream& in, std::vector<T>& v)
{
  //in.read(reinterpret_cast<char*>(&v[0]), sizeof(T) * v.size());
  for (unsigned i = 0; i < v.size(); i++) {
    U x;
    in.read(reinterpret_cast<char*>(&x), sizeof(U));
    v[i] = x;
  }
  return in;
}

template<typename U, typename T>
static std::ostream&
write_binary_runlength(std::ostream& out, std::vector<T>& v)
{
  unsigned char c = 0;
  U cur;
  for (typename std::vector<T>::const_iterator it = v.begin();
       it != v.end(); ++it) {
    if (it == v.begin()) {
      c = 1;
      cur = static_cast<U>(*it);
    } else if (*it != cur || c == 0xff) {
      out.write(reinterpret_cast<char*>(&c), sizeof(unsigned char));
      out.write(reinterpret_cast<char*>(&cur), sizeof(U));
      c = 1;
      cur = static_cast<U>(*it);
    } else
      c++;
  }

  if (c > 0) {
    out.write(reinterpret_cast<char*>(&c), sizeof(unsigned char));
    out.write(reinterpret_cast<char*>(&cur), sizeof(U));
  }

  return out;
}

template<typename U, typename T>
static std::istream&
read_binary_runlength(std::istream& in, std::vector<T>& v)
{
  unsigned cur = 0;
  while (cur < v.size()) {
    unsigned char c;
    U x;
    in.read(reinterpret_cast<char*>(&c), sizeof(unsigned char));
    in.read(reinterpret_cast<char*>(&x), sizeof(U));
    for (unsigned i = 0; i < c && cur < v.size(); i++) {
      v[cur++] = x;
    }
  }

  return in;
}

}  // namespace oxelon

#endif // STREAM_HPP_979401B2_A050_408A_9C31_4AC1011E3DAA_
