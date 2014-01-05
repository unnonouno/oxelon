#ifndef BIT_MATRIX_HPP_5DD9761F_E812_4388_99D4_31AE85C9CDE7_
#define BIT_MATRIX_HPP_5DD9761F_E812_4388_99D4_31AE85C9CDE7_

#include <stdint.h>
#include <string>
#include <iostream>

namespace oxelon {

class BitMatrix {
 public:
  static const uint32_t N = 8;

  typedef uint64_t data_type;
  typedef uint32_t position_t;

  BitMatrix();
  BitMatrix(const BitMatrix& b);
  BitMatrix(const data_type& d);

  static BitMatrix parse(const std::string& s);

  BitMatrix& operator = (const BitMatrix& rhs);

  bool operator == (const BitMatrix& rhs) const {
    return data_ == rhs.data_;
  }

  void shift_left();
  void shift_right();
  void shift_up();
  void shift_down();
  void shift_up_left();
  void shift_down_left();
  void shift_up_right();
  void shift_down_right();

  BitMatrix make_left() const;
  BitMatrix make_right() const;
  BitMatrix make_up() const;
  BitMatrix make_down() const;

  const data_type& get_data() const {
    return data_;
  }

  // Make a matrix which has 8 bits around the original
  BitMatrix make_round() const;

  int at(position_t pos) const;
  int at(int x, int y) const;
  bool operator [] (position_t pos) const;

  BitMatrix& operator ^= (const BitMatrix& rhs);
  BitMatrix operator ^ (const BitMatrix& rhs) const;

  inline BitMatrix operator ~() const {
    return BitMatrix(~data_);
  }

  BitMatrix& operator <<= (uint32_t pos) {
    data_ <<= pos;
    return *this;
  }
  BitMatrix& operator >>= (uint32_t pos) {
    data_ >>= pos;
    return *this;
  }
  BitMatrix operator << (uint32_t pos) const {
    return BitMatrix(data_ << pos);
  }
  BitMatrix operator >> (uint32_t pos) const {
    return BitMatrix(data_ >> pos);
  }

  BitMatrix& operator |= (const BitMatrix& rhs) {
    data_ |= rhs.data_;
    return *this;
  }
  BitMatrix& operator &= (const BitMatrix& rhs) {
    data_ &= rhs.data_;
    return *this;
  }
  BitMatrix operator | (const BitMatrix& rhs) const {
    return BitMatrix(data_ | rhs.data_);
  }
  BitMatrix operator & (const BitMatrix& rhs) const {
    return BitMatrix(data_ & rhs.data_);
  }
  
  void set(position_t pos, bool val = true) {
    if (val) {
      data_ |= (data_type(1) << pos);
    } else {
      data_  &= ~(data_type(1) << pos);
    }
  }

  void flip() {
    data_ = ~data_;
  }
  bool any() const {
    return data_ != 0;
  }

  unsigned size() const;

  struct right {
    void operator()(BitMatrix& m) const { m.shift_right(); }
  };
  struct left {
    void operator()(BitMatrix& m) const { m.shift_left(); }
  };
  struct up {
    void operator()(BitMatrix& m) const { m.shift_up(); }
  };
  struct down {
    void operator()(BitMatrix& m) const { m.shift_down(); }
  };
  
  struct up_right {
    void operator()(BitMatrix& m) const { m.shift_up_right(); }
  };
  struct up_left {
    void operator()(BitMatrix& m) const { m.shift_up_left(); }
  };
  struct down_right {
    void operator()(BitMatrix& m) const { m.shift_down_right(); }
  };
  struct down_left {
    void operator()(BitMatrix& m) const { m.shift_down_left(); }
  };

  struct bit_right {
    void operator()(BitMatrix& m) const { m <<= 1; }
  };
  struct bit_left {
    void operator()(BitMatrix& m) const { m >>= 1; }
  };
  struct bit_up {
    void operator()(BitMatrix& m) const { m >>= N; }
  };
  struct bit_down {
    void operator()(BitMatrix& m) const { m <<= N; }
  };
  struct bit_up_right {
    void operator()(BitMatrix& m) const { m >>= N - 1; }
  };
  struct bit_up_left {
    void operator()(BitMatrix& m) const { m >>= N + 1; }
  };
  struct bit_down_right {
    void operator()(BitMatrix& m) const { m <<= N + 1; }
  };
  struct bit_down_left {
    void operator()(BitMatrix& m) const { m <<= N - 1; }
  };
  
  uint64_t& raw() { return data_; }
  const uint64_t& raw() const { return data_; }

  uint32_t get_next() const;

  BitMatrix get_next_bit() const {
    return data_ & ~(data_ - 1);
  }

  BitMatrix get_quad(int x, int y) const {
    return data_ && (0xF0F0F0Full << x << (y * 0x100000000ull));
  }

  uint32_t upper() const {
    return data_ >> 32;
  }

  uint32_t lower() const {
    return data_;
  }

  std::string to_str() const;

 private:
  static const data_type EXCEPT_LEFT_ONE = 0xFEFEFEFEFEFEFEFEULL;
  static const data_type EXCEPT_RIGHT_ONE = 0x7F7F7F7F7F7F7F7FULL;
  static const data_type LOWER_TWO_BYTE = 0xFFFF;

 public:
   union {
    data_type data_;
    struct {
      uint32_t lower_;
      uint32_t upper_;
    };
    struct {
      unsigned short lower1_;
      unsigned short lower2_;
      unsigned short upper1_;
      unsigned short upper2_;
    };
  };

  //data_type data_;
};

inline
BitMatrix::BitMatrix()
    : data_(0) {
}

inline
BitMatrix::BitMatrix(const BitMatrix& b)
    : data_(b.data_) {
}

inline
BitMatrix::BitMatrix(const BitMatrix::data_type& d)
    : data_(d) {
}

inline
BitMatrix& BitMatrix::operator = (const BitMatrix& rhs) {
  data_ = rhs.data_;
  return *this;
}

inline
int BitMatrix::at(unsigned pos) const {
  return (data_ >> pos) & 1;
}

inline
int BitMatrix::at(int x, int y) const {
  return at(x + y * N);
}

inline
bool BitMatrix::operator [] (position_t pos) const {
  return at(pos);
}

inline
unsigned BitMatrix::get_next() const {
  return __builtin_ctzll(data_);
  /*
  uint64_t mask = data_;
  unsigned pos = 0;
  
  if ((mask & ((1ull<<32)-1)) == 0) {
    pos += 32;
    mask >>= 32;
  }

  if ((mask & ((1u<<16)-1)) == 0) {
    pos += 16;
    mask >>= 16;
  }
  
  if ((mask & ((1u<<8)-1)) == 0) {
    pos += 8;
    mask >>= 8;
  }
  if ((mask & ((1u<<4)-1)) == 0) {
    pos += 4;
    mask >>= 4;
  }
  if ((mask & ((1u<<2)-1)) == 0) {
    pos += 2;
    mask >>= 2;
  }
  if ((mask & ((1u<<1)-1)) == 0) {
    pos += 1;
    mask >>= 1;
  }
  return pos;
  */
}

inline
void BitMatrix::shift_left() {
  data_ &= EXCEPT_LEFT_ONE;
  data_ >>= 1;
}

inline
void BitMatrix::shift_right() {
  data_ &= EXCEPT_RIGHT_ONE;
  data_ <<= 1;
}

inline
void BitMatrix::shift_up() {
  data_ >>= N;
}

inline
void BitMatrix::shift_down() {
  data_ <<= N;
}

inline
void BitMatrix::shift_up_left() {
  data_ &= EXCEPT_LEFT_ONE;
  data_ >>= N + 1;
}

inline
void BitMatrix::shift_up_right() {
  data_ &= EXCEPT_RIGHT_ONE;
  data_ >>= N - 1;
}

inline
void BitMatrix::shift_down_left() {
  data_ &= EXCEPT_LEFT_ONE;
  data_ <<= N - 1;
}

inline
void BitMatrix::shift_down_right() {
  data_ &= EXCEPT_RIGHT_ONE;
  data_ <<= N + 1;
}

inline
BitMatrix BitMatrix::make_left() const {
  BitMatrix ret = *this;
  ret.shift_left();
  return ret;
}

inline
BitMatrix BitMatrix::make_right() const {
  BitMatrix ret = *this;
  ret.shift_right();
  return ret;
}

inline
BitMatrix BitMatrix::make_up() const {
  BitMatrix ret = *this;
  ret.shift_up();
  return ret;
}

inline
BitMatrix BitMatrix::make_down() const {
  BitMatrix ret = *this;
  ret.shift_down();
  return ret;
}

inline
BitMatrix BitMatrix::make_round() const {
  BitMatrix m = *this;
  m |= m.make_left();
  m |= m.make_right();
  m |= m.make_up();
  m |= m.make_down();
  return m;
}

inline
BitMatrix& BitMatrix::operator ^= (const BitMatrix& rhs) {
  data_ ^= rhs.data_;
  return *this;
}

inline
BitMatrix BitMatrix::operator ^ (const BitMatrix& rhs) const {
  BitMatrix m(*this);
  m ^= rhs;
  return m;
}

inline
unsigned BitMatrix::size() const {
  return __builtin_popcountll(data_);
}

}  // namespace oxelon

#endif // BIT_MATRIX_HPP_5DD9761F_E812_4388_99D4_31AE85C9CDE7_
