#ifndef BIT_BOARD_HPP_0BDFB0A1_5367_468E_85A1_E8FCF43CCCC2_
#define BIT_BOARD_HPP_0BDFB0A1_5367_468E_85A1_E8FCF43CCCC2_

#include <vector>

#include "bit_matrix.hpp"
#include "position.hpp"
#include "types.hpp"

namespace oxelon {

class Position;

class BitBoard {
 public:
  static const unsigned HALF_SIZE = 4;
  static const unsigned SIZE = HALF_SIZE * 2;
  static const unsigned COUNT_MAX = SIZE * SIZE - 4;

  typedef BitMatrix data_type;

  static BitBoard make_initial_board();

  BitBoard();
  BitBoard(const BitBoard& board);
  BitBoard(const Disc*);

  BitBoard(const data_type& d, const data_type& b)
    : disc_map_(d),
      op_map_(b) {
  }

  BitBoard& operator = (const BitBoard& rhs);

  bool operator == (const BitBoard& b) const {
    return disc_map_ == b.disc_map_ && op_map_ == b.op_map_;
  }

  std::string to_zebra_str() const;

  Disc at(const Position& p) const;
  Disc at(pos_t x, pos_t y)  const {
    return at(Position(x, y));
  }

  unsigned int code_at(unsigned position, Disc disc) const;
  unsigned int code_at(Position position) const;

  void set_disc(const Position& position, Disc disc);
  void set_disc(const data_type& p);

  unsigned count_disc(Disc disc) const;
  unsigned count_blank() const {
    return SIZE * SIZE - count_black() - count_white();
  }

  unsigned count_black() const {
    return disc_map_.size();
  }

  unsigned count_white() const {
    return op_map_.size();
  }

  int get_score() const;

  data_type get_blank_bit() const {
    return ~disc_map_ ^ op_map_;
  }

  data_type get_move_bit() const;

  data_type get_potential_move_bit() const;

  void move(const Position& pos);
  void move(data_type pos);
  int try_move(/*data_type start, */unsigned);
  int get_move_count(
      /*BitMatrix start,*/
      unsigned offset) const;

  template <class F>
  int get_move_count_to(
      const Position& p,
      const BitMatrix& my_disc,
      const BitMatrix& op_disc,
      F move_f) const;

  void inverse();
  BitBoard make_inverse() const;
  unsigned hash() const;
  int get_potential_mobility() const;
  int get_mobility() const {
    return get_move_bit().size();
  }

  int get_weighted_mobility() const {
    data_type m = get_move_bit();
    int mob = m.size();
    if (m.at(0, 0)) mob++;
    if (m.at(0, SIZE-1)) mob++;
    if (m.at(SIZE-1, 0)) mob++;
    if (m.at(SIZE-1, SIZE-1)) mob++;
    return mob;
  }
  int get_op_approximate_mobility() const;
  int get_my_approximate_mobility() const;
  int get_quad_parity() const;

 private:
  static const data_type::data_type QUAD_LEFT_TOP;
  static const data_type::data_type QUAD_RIGHT_TOP;
  static const data_type::data_type QUAD_LEFT_BOTTOM;
  static const data_type::data_type QUAD_RIGHT_BOTTOM;

  static const unsigned char DIR_LEFT = 0x1;
  static const unsigned char DIR_RIGHT = 0x2;
  static const unsigned char DIR_UP = 0x4;
  static const unsigned char DIR_DOWN = 0x8;
  static const unsigned char DIR_UP_LEFT = 0x10;
  static const unsigned char DIR_UP_RIGHT = 0x20;
  static const unsigned char DIR_DOWN_LEFT = 0x40;
  static const unsigned char DIR_DOWN_RIGHT = 0x80;

  /// Flip table for right, right-bottom, bottom, left-bottom from A1
  static data_type FLIP_TABLE_RIGHT_DOWN[7][7][7][7];
  /// Flip table for left-bottom, left, left-top, top from H8
  static data_type FLIP_TABLE_LEFT_UP[7][7][7][7];
  /// Movable direction for each position 
  static std::vector<unsigned char> search_move_dirs_;

  /// Initilaize flip tables
  static void init_flip_table();
  /// Initialize direction table
  static void init_search_move_dirs();
  
  struct Static {
    Static() {
      BitBoard::init_flip_table();
      BitBoard::init_search_move_dirs();
    }
    static Static inst_;
  };
  friend struct Static;
  
  template<class F>
  void move_to(const Position& pos, F move_f);

  template<class F>
  int get_move_count_to(
      BitMatrix start,
      const BitMatrix&,
      const BitMatrix&,
      F move_f) const;

  template<class F>
  data_type get_move_bit_to(
      const BitMatrix&,
      const BitMatrix&,
      const BitMatrix&,
      F move_f) const;

  data_type disc_map_;
  data_type op_map_;
  
#ifdef BITBOARD_HASH_CASH
  mutable unsigned cached_hash_;
  mutable bool dirty_;
#endif
  
};

inline
BitBoard::BitBoard(const BitBoard& b)
    : disc_map_(b.disc_map_),
      op_map_(b.op_map_)
#ifdef BITBOARD_HASH_CASH
    , cached_hash_(b.cached_hash_),
    dirty_(b.dirty_)
#endif
{}

inline
BitBoard&
BitBoard::operator = (const BitBoard& rhs) {
  //blank_map_ = rhs.blank_map_;
  disc_map_ = rhs.disc_map_;
  op_map_ = rhs.op_map_;
#ifdef BITBOARD_HASH_CASH
  cached_hash_ = rhs.cached_hash_;
  dirty_ = rhs.dirty_;
#endif
  return *this;
}

inline
Disc BitBoard::at(const Position& p) const {
  if (disc_map_[p]) {
    return BLACK;
  }
  if (op_map_[p]) {
    return WHITE;
  }
  return BLANK;
}

inline
unsigned int BitBoard::code_at(unsigned pos, Disc) const
{
#if defined __i386__ && defined _MSC_VER
    _asm {
      mov eax, -2;
      mov ebx, pos;
      cmp ebx, 32;
      jae UPPER;
      
      mov edx, DWORD PTR [ecx];
      bt edx, ebx;
      adc eax, 0;
      mov edx, DWORD PTR [ecx+8];
      bt edx, ebx;
      setc ebx;
      add eax, ebx;
      add eax, ebx;
      neg eax;
    }
    return;
    _asm {
    UPPER:
      sub ebx, 32;
      mov edx, DWORD PTR [ecx+4];
      bt edx, ebx;
      adc eax, 0;
      mov edx, DWORD PTR [ecx+12];
      bt edx, ebx;
      setc ebx;
      add eax, ebx;
      add eax, ebx;
      neg eax;
    }
    return;
#else
  // color   d  blank  disc  op ret
  // black  -1      0     1   0  0
  // black   1      0     1   0  2
  // white  -1      0     0   1  2
  // white   1      0     0   1  0
  // blank  -1      1     0   0  1
  // blank   1      1     0   0  1
  //return 2 - blank_map_.at(pos) - 2 * disc_map_.at(pos);
  return -disc_map_.at(pos) + op_map_.at(pos) + 1;

#endif
}

inline
unsigned int BitBoard::code_at(Position p) const {
  //return 2 - blank_map_.at(p) - 2 * disc_map_.at(p);
  return -disc_map_.at(p) + op_map_.at(p) + 1;
}

inline
void BitBoard::set_disc(const Position& p, Disc d) {
  switch (d) {
    case BLANK:
      disc_map_.set(p, false);
      op_map_.set(p, false);
      break;
    case BLACK:
      disc_map_.set(p, true);
      op_map_.set(p, false);
      break;
    case WHITE:
      disc_map_.set(p, false);
      op_map_.set(p, true);
      break;
  }
#ifdef BITBOARD_HASH_CASH
  dirty_ = true;
#endif
}

inline
void BitBoard::set_disc(const data_type& p) {
  disc_map_ |= p;
  op_map_ &= ~p;
#ifdef BITBOARD_HASH_CASH
  dirty_ = true;
#endif
}

inline
unsigned BitBoard::count_disc(Disc disc) const {
  switch (disc) {
    case BLANK:
      return count_blank();
    case BLACK:
      return count_black();
    case WHITE:
      return count_white();
  }
  return 0;
}

inline
int BitBoard::get_score() const {
  return (count_black() - count_white()) * 1024;
}

inline
void BitBoard::inverse() {
  data_type tmp = disc_map_;
  disc_map_ = op_map_;
  op_map_ = tmp;
#ifdef BITBOARD_HASH_CASH
  dirty_ = true;
#endif
}

inline
BitBoard BitBoard::make_inverse() const {
  BitBoard ret(*this);
  ret.inverse();
  return ret;
  /*
  data_type::data_type b = blank_map_.get_data();
  data_type::data_type d = disc_map_.get_data();
  return BitBoard(d ^ ~b, b);
  */
  //return BitBoard(disc_map_ ^ ~blank_map_, blank_map_);
}

inline
unsigned BitBoard::hash() const {
  /*
#ifdef BITBOARD_HASH_CASH
  if (dirty_) {
#endif
    unsigned long d1 = disc_map_.lower();
    unsigned long d2 = disc_map_.upper();
    unsigned long b1 = blank_map_.lower();
    unsigned long b2 = blank_map_.upper();
    
    d1 += b2; b2 += d1; d1 ^= (d1>>7);
    d2 += d1; d1 += d2; d2 ^= (d2<<13);
    b1 += d2; d2 += b1; b1 ^= (b1>>17);
    b2 += b1; b1 += b2; b2 ^= (b2<<9);
    d1 += b2; b2 += d1; d1 ^= (d1>>3);
    d2 += d1; d1 += d2; d2 ^= (d2<<7);
    b1 += d2; d2 += b1; b1 ^= (b1>>15);
    b2 += b1; b1 += b2; b2 ^= (b2<<11);
#ifdef BITBOARD_HASH_CASH
    cached_hash_ = b2;
    dirty_ = false;
  }
  return cached_hash_;
#else
  return b2;
#endif
  */
  return (disc_map_.lower()
          + disc_map_.upper()
          + op_map_.lower() * 2
          + op_map_.upper() * 2);
}

inline
int BitBoard::get_potential_mobility() const {
  data_type blank = ~disc_map_ ^ op_map_;
  int ret = 0;
  
  data_type tmp = op_map_;
  tmp.shift_left();
  ret += (tmp & blank).size();
  tmp.shift_up();
  ret += (tmp & blank).size();
  
  tmp = op_map_;
  tmp.shift_up();
  ret += (tmp & blank).size();
  tmp.shift_right();
  ret += (tmp & blank).size();
  
  tmp = op_map_;
  tmp.shift_right();
  ret += (tmp & blank).size();
  tmp.shift_down();
  ret += (tmp & blank).size();
  
  tmp = op_map_;
  tmp.shift_down();
  ret += (tmp & blank).size();
  tmp.shift_left();
  ret += (tmp & blank).size();
  
  return ret;
}

inline
int BitBoard::get_op_approximate_mobility() const {
  data_type blank = ~disc_map_ ^ op_map_;
  data_type my_disc = disc_map_;
  data_type tmp = my_disc;
  
  tmp.shift_left();
  my_disc |= tmp;
  tmp = my_disc;
  tmp.shift_right();
  my_disc |= tmp;
  
  tmp = my_disc;
  tmp.shift_up();
  my_disc |= tmp;
  
  tmp = my_disc;
  tmp.shift_down();
  my_disc |= tmp;
  
  return (blank & my_disc).size();
}

inline
int BitBoard::get_my_approximate_mobility() const {
  data_type op_disc(op_map_);
  data_type blank_map(~disc_map_ ^ op_map_);
  
#if defined _MMX && defined _MSVC
  _asm {
    movq mm0, op_disc;
    
    movq mm1, mm0;
    movq mm2, mm0;
    
    pand mm1, BitMatrix::EXCEPT_LEFT_ONE;
    pand mm2, BitMatrix::EXCEPT_RIGHT_ONE;
    
    psrlq mm1, 1;
    psllq mm2, 1;
    
    por mm0, mm1;
    por mm0, mm2;
    
    movq mm1, mm0;
    movq mm2, mm0;
    
    psllq mm1, 8;
    psrlq mm2, 8;
    
    por mm0, mm1;
    por mm0, mm2;
    
    pand mm0, blank_map;
    
    movq mm1, mm0;
    psrlq mm1, 1;
    pand mm1, _c55;
    psubd mm0, mm1;
    
    movq mm1, mm0;
    psrlq mm1, 2;
    pand mm1, _c33;
    pand mm0, _c33;
    paddd mm0, mm1;
    
    movq mm1, mm0;
    psrlq mm1, 4;
    paddd mm0, mm1;
    pand mm0, _c0f;
    
    movq mm1, mm0;
    psrlq mm1, 8;
    paddd mm0, mm1;
    
    movq mm1, mm0;
    psrlq mm1, 16;
    paddd mm0, mm1;
    
    movq mm1, mm0;
    psrlq mm1, 32;
    paddd mm0, mm1;
    
    movd eax, mm0;
    and eax, 255;
    emms;
  }
#else
  data_type tmp = op_disc;
  tmp.shift_left();
  op_disc |= tmp;
  tmp = op_disc;
  tmp.shift_right();
  op_disc |= tmp;
  
  tmp = op_disc;
  tmp.shift_up();
  op_disc |= tmp;
  
  tmp = op_disc;
  tmp.shift_down();
  op_disc |= tmp;
  
  return (blank_map & op_disc).size();
#endif
}

inline
int BitBoard::get_quad_parity() const {
  data_type any_map(disc_map_ | op_map_);
  const data_type mask(0xFFFF);
  return
    (any_map & QUAD_LEFT_TOP).size() % 2 +
    (any_map & QUAD_RIGHT_TOP).size() % 2 +
    (any_map & QUAD_LEFT_BOTTOM).size() % 2 +
    (any_map & QUAD_RIGHT_BOTTOM).size() % 2;
}

inline
BitBoard::data_type BitBoard::get_potential_move_bit() const {
  return op_map_.make_round() & get_blank_bit();
}


/*
template <int X, int Y>
BitBoard::move_at<X, Y>()
{
  const unsigned long long p = 0x1ul << (X + Y * 8);
  if (op_map & p) {
    flip_to_at<X, Y>
  } else if (blank_map_ & p) {

  }
}

template <int X, int Y, int DX, int DY>
BitBoard::flip_to_at<X,Y,DX,DY>()
{
  const unsigned long long p = 0x1ul << (X + Y * 8);
  if (op_map & p)
    flip_to_at<X+DX, Y+DY, DX, DY>();
  else
    
}
*/

}  // namespace oxelon

#endif // BIT_BOARD_HPP_0BDFB0A1_5367_468E_85A1_E8FCF43CCCC2_
