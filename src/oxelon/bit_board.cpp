#include "bit_board.hpp"

#include <iostream>
#include <stdexcept>

#include "position.hpp"

namespace oxelon {

#include "flip.hpp"

namespace {

/// Left-upper mask
const uint64_t QUAD_1 = 0x000000000F0F0F0FULL;
/// Right-upper mask
const uint64_t QUAD_2 = 0x00000000F0F0F0F0ULL;
/// Left-lower mask
const uint64_t QUAD_3 = 0x0F0F0F0F00000000ULL;
/// Right-lower mask
const uint64_t QUAD_4 = 0xF0F0F0F000000000ULL;

}

BitBoard::data_type
BitBoard::FLIP_TABLE_RIGHT_DOWN[SIZE-1][SIZE-1][SIZE-1][SIZE-1];

BitBoard::data_type
BitBoard::FLIP_TABLE_LEFT_UP[SIZE-1][SIZE-1][SIZE-1][SIZE-1];

std::vector<unsigned char> BitBoard::search_move_dirs_;

BitBoard::Static BitBoard::Static::inst_;

void
BitBoard::init_flip_table() {
  std::cerr << "init flip table" << std::endl;

  for (unsigned r = 0; r < SIZE-1; r++)
    for (unsigned dr = 0; dr < SIZE-1; dr++)
      for (unsigned d = 0; d < SIZE-1; d++)
        for (unsigned dl = 0; dl < SIZE-1; dl++) {
          FLIP_TABLE_RIGHT_DOWN[r][dr][d][dl] = 0;
          for (unsigned i = 0; i < r; i++)
            FLIP_TABLE_RIGHT_DOWN[r][dr][d][dl].set(Position(i+1, 0));
          for (unsigned i = 0; i < dr; i++)
            FLIP_TABLE_RIGHT_DOWN[r][dr][d][dl].set(Position(i+1, i+1));
          for (unsigned i = 0; i < d; i++)
            FLIP_TABLE_RIGHT_DOWN[r][dr][d][dl].set(Position(0, i+1));
          for (unsigned i = 0; i < dl; i++)
            FLIP_TABLE_RIGHT_DOWN[r][dr][d][dl].set(Position(SIZE-1-i, i));
        }
  
  for (unsigned l = 0; l < SIZE-1; l++)
    for (unsigned ul = 0; ul < SIZE-1; ul++)
      for (unsigned u = 0; u < SIZE-1; u++)
        for (unsigned ur = 0; ur < SIZE-1; ur++) {
          FLIP_TABLE_LEFT_UP[l][ul][u][ur] = 0;
          for (unsigned i = 0; i < l; i++)
            FLIP_TABLE_LEFT_UP[l][ul][u][ur].set(Position(SIZE-2-i, SIZE-1));
          for (unsigned i = 0; i < ul; i++)
            FLIP_TABLE_LEFT_UP[l][ul][u][ur].set(Position(SIZE-2-i, SIZE-2-i));
          for (unsigned i = 0; i < u; i++)
            FLIP_TABLE_LEFT_UP[l][ul][u][ur].set(Position(SIZE-1, SIZE-2-i));
          for (unsigned i = 0; i < ur; i++)
            FLIP_TABLE_LEFT_UP[l][ul][u][ur].set(Position(i, SIZE-1-i));
        }
}

void
BitBoard::init_search_move_dirs() {
  search_move_dirs_.resize(SIZE*SIZE);
  
  for (pos_t y = 0; y < SIZE; y++) {
    // left
    for (pos_t x = 2; x < SIZE; x++)
      search_move_dirs_[Position(x, y)] |= DIR_LEFT;
    // right
    for (pos_t x = 0; x < SIZE-2; x++)
      search_move_dirs_[Position(x, y)] |= DIR_RIGHT;
  }

  for (pos_t y = 0; y < SIZE-2; y++) {
    // down
    for (pos_t x = 0; x < SIZE; x++)
      search_move_dirs_[Position(x, y)] |= DIR_DOWN;
    // down left
    for (pos_t x = 2; x < SIZE; x++)
      search_move_dirs_[Position(x, y)] |= DIR_DOWN_LEFT;
    // down right
    for (pos_t x = 0; x < SIZE-2; x++)
      search_move_dirs_[Position(x, y)] |= DIR_DOWN_RIGHT;
  }

  for (pos_t y = 2; y < SIZE; y++) {
    // up
    for (pos_t x = 0; x < SIZE; x++)
      search_move_dirs_[Position(x, y)] |= DIR_UP;
    // up left
    for (pos_t x = 2; x < SIZE; x++)
      search_move_dirs_[Position(x, y)] |= DIR_UP_LEFT;
    // up right
    for (pos_t x = 0; x < SIZE-2; x++)
      search_move_dirs_[Position(x, y)] |= DIR_UP_RIGHT;
  }
}

BitBoard::BitBoard()
    : disc_map_(0),
      op_map_(0)
#ifdef BITBOARD_HASH_CASH
    , dirty_(true)
#endif
{
  //blank_map_.flip();
}

BitBoard::BitBoard(const Disc* b)
  : disc_map_(0),
    op_map_(0)
#ifdef BITBOARD_HASH_CASH
  , dirty_(true)
#endif
{
  //blank_map_.flip();
  for (unsigned y = 0; y < SIZE; y++)
    for (unsigned x = 0; x < SIZE; x++)
      set_disc(Position(x, y), b[x + y * SIZE]);
}

std::string
BitBoard::to_zebra_str() const
{
  std::string ret;
  for (Position pos; !pos.end(); ++pos) {
    if (pos % 8 == 0)
      ret += ' ';
    switch (at(pos)) {
      case BLANK:
        ret += '-';
        break;
      case BLACK:
        ret += 'X';
        break;
      case WHITE:
        ret += 'O';
        break;
    }
  }
  return ret;
}


BitBoard
BitBoard::make_initial_board()
{
  BitBoard ret;
  
  ret.set_disc(Position(HALF_SIZE - 1, HALF_SIZE - 1), WHITE);
  ret.set_disc(Position(HALF_SIZE, HALF_SIZE), WHITE);
  
  ret.set_disc(Position(HALF_SIZE - 1, HALF_SIZE), BLACK);
  ret.set_disc(Position(HALF_SIZE, HALF_SIZE - 1), BLACK);
  
  return ret;
}
/*
void BitBoard::move(BitMatrix<BitBoard::SIZE> start)
{
  if (!start.any())
    return;

  data_type my_disc, op_disc;
  my_disc = disc_map_;
  op_disc = ~disc_map_ & ~blank_map_;
  
  unsigned offset = start.get_next();
  
  unsigned search_move_dir = search_move_dirs_[offset];
  
  int n_left;
  if (search_move_dir & DIR_LEFT)
    n_left = get_move_count_to(start, my_disc, op_disc, data_type::left());
  else
    n_left = 0;

  int n_right;
  if (search_move_dir & DIR_RIGHT)
    n_right = get_move_count_to(start, my_disc, op_disc, data_type::right());
  else
    n_right = 0;

  int n_up;
  if (search_move_dir & DIR_UP)
    n_up = get_move_count_to(start, my_disc, op_disc, data_type::up());
  else
    n_up = 0;

  int n_down;
  if (search_move_dir & DIR_DOWN)
    n_down = get_move_count_to(start, my_disc, op_disc, data_type::down());
  else
    n_down = 0;

  int n_up_left;
  if (search_move_dir & DIR_UP_LEFT)
    n_up_left = get_move_count_to(start, my_disc, op_disc, data_type::up_left());
  else
    n_up_left = 0;

  int n_up_right;
  if (search_move_dir & DIR_UP_RIGHT)
    n_up_right
      = get_move_count_to(start, my_disc, op_disc, data_type::up_right());
  else
    n_up_right = 0;

  int n_down_left;
  if (search_move_dir & DIR_DOWN_LEFT)
    n_down_left
      = get_move_count_to(start, my_disc, op_disc, data_type::down_left());
  else
    n_down_left = 0;

  int n_down_right;
  if (search_move_dir & DIR_DOWN_RIGHT)
    n_down_right
      = get_move_count_to(start, my_disc, op_disc, data_type::down_right());
  else
    n_down_right = 0;

  data_type flip
    = (FLIP_TABLE_RIGHT_DOWN[n_right][n_down_right][n_down][n_down_left]
       << offset)
      | (FLIP_TABLE_LEFT_UP[n_left][n_up_left][n_up][n_up_right]
         >> (SIZE*SIZE-1-offset));
  disc_map_ ^= flip;
  set_disc(start);
}
*/
void
BitBoard::move(BitMatrix start)
{
  try_move(start.get_next());
  set_disc(start);
}

void
BitBoard::move(const Position& pos)
{
  if (pos.pass())
    return;

  move_to(pos, Position::left());
  move_to(pos, Position::right());
  move_to(pos, Position::up());
  move_to(pos, Position::down());
  move_to(pos, Position::up_left());
  move_to(pos, Position::up_right());
  move_to(pos, Position::down_left());
  move_to(pos, Position::down_right());
  
  set_disc(pos, BLACK);
}

template<class F>
void
BitBoard::move_to(const Position& pos, F move_f)
{
  // 探索場所
  for (Position p = move_f(pos); p.in() && at(p) != BLANK; p = move_f(p))
    if (at(p) == BLACK) {
      for (Position rp = move_f(pos); rp != p; rp = move_f(rp))
        set_disc(rp, BLACK);
      return;
    }
}

/*
int BitBoard::get_move_count(BitMatrix<BitBoard::SIZE> start,
                             unsigned offset) const
{
  data_type my_disc, op_disc;
  my_disc = disc_map_;
  op_disc = ~disc_map_ & ~blank_map_;
  
  unsigned search_move_dir = search_move_dirs_[offset];
  int ret = 0;
  if (search_move_dir & DIR_UP)
    ret += get_move_count_to(start, my_disc, op_disc, data_type::up());
  if (search_move_dir & DIR_DOWN)
    ret += get_move_count_to(start, my_disc, op_disc, data_type::down());
  if (search_move_dir & DIR_LEFT)
    ret += get_move_count_to(start, my_disc, op_disc, data_type::left());
  if (search_move_dir & DIR_RIGHT)
    ret += get_move_count_to(start, my_disc, op_disc, data_type::right());
  if (search_move_dir & DIR_UP_LEFT)
    ret += get_move_count_to(start, my_disc, op_disc, data_type::up_left());
  if (search_move_dir & DIR_UP_RIGHT)
    ret += get_move_count_to(start, my_disc, op_disc, data_type::up_right());
  if (search_move_dir & DIR_DOWN_LEFT)
    ret += get_move_count_to(start, my_disc, op_disc, data_type::down_left());
  if (search_move_dir & DIR_DOWN_RIGHT)
    ret += get_move_count_to(start, my_disc, op_disc, data_type::down_right());
  return ret;
}
*/

int
BitBoard::get_move_count(unsigned offset) const
{
  return count_f[offset](disc_map_, op_map_);
}

/*
int BitBoard::try_move(BitMatrix<BitBoard::SIZE> start, unsigned offset)
{
  data_type my_disc, op_disc;
  my_disc = disc_map_;
  op_disc = ~disc_map_ & ~blank_map_;
  
  unsigned search_move_dir = search_move_dirs_[offset];
  int n_up;
  if (search_move_dir & DIR_UP)
    n_up = get_move_count_to(start, my_disc, op_disc, data_type::up());
  else
    n_up = 0;
  
  int n_down;
  if (search_move_dir & DIR_DOWN)
    n_down = get_move_count_to(start, my_disc, op_disc, data_type::down());
  else
    n_down = 0;

  int n_left;
  if (search_move_dir & DIR_LEFT)
    n_left = get_move_count_to(start, my_disc, op_disc, data_type::left());
  else
    n_left = 0;
  
  int n_right;
  if (search_move_dir & DIR_RIGHT)
    n_right = get_move_count_to(start, my_disc, op_disc, data_type::right());
  else
    n_right = 0;

  int n_up_left;
  if (search_move_dir & DIR_UP_LEFT)
    n_up_left = get_move_count_to(start, my_disc, op_disc, data_type::up_left());
  else
    n_up_left = 0;
  
  int n_up_right;
  if (search_move_dir & DIR_UP_RIGHT)
    n_up_right
      = get_move_count_to(start, my_disc, op_disc, data_type::up_right());
  else
    n_up_right = 0;
  
  int n_down_left;
  if (search_move_dir & DIR_DOWN_LEFT)
    n_down_left
      = get_move_count_to(start, my_disc, op_disc, data_type::down_left());
  else
    n_down_left = 0;
  
  int n_down_right;
  if (search_move_dir & DIR_DOWN_RIGHT)
    n_down_right
      = get_move_count_to(start, my_disc, op_disc, data_type::down_right());
  else
    n_down_right = 0;

  data_type flip =
    (n_right || n_down_right || n_down || n_down_left) ?
      (FLIP_TABLE_RIGHT_DOWN[n_right][n_down_right][n_down][n_down_left]
       << offset) : 0;
  if (n_left || n_up_left || n_up || n_up_right)
    flip |=  (FLIP_TABLE_LEFT_UP[n_left][n_up_left][n_up][n_up_right]
         >> (SIZE*SIZE-1-offset));
  if (flip.any()) {
    disc_map_ ^= flip;
    set_disc(start);
    //return true;
  } //else
    //return false;
  return n_up + n_down + n_left + n_right +
    n_up_right + n_up_left + n_down_right + n_down_left;
}
*/

int
BitBoard::try_move(unsigned offset)
{
  int c = flip_f[offset](disc_map_, op_map_);
  if (c) {
    data_type m(1ULL << offset);
    disc_map_ |= m;
  }
  return c;
}

/*
bool BitBoard::try_move(unsigned offset)
{
  Position pos(offset);
  data_type my_disc, op_disc;
  my_disc = disc_map_;
  op_disc = ~disc_map_ & ~blank_map_;
  
  unsigned search_move_dir = search_move_dirs_[offset];
  int n_up;
  if (search_move_dir & DIR_UP)
    n_up = get_move_count_to(pos, my_disc, op_disc, Position::up());
  else
    n_up = 0;
  
  int n_down;
  if (search_move_dir & DIR_DOWN)
    n_down = get_move_count_to(pos, my_disc, op_disc, Position::down());
  else
    n_down = 0;

  int n_left;
  if (search_move_dir & DIR_LEFT)
    n_left = get_move_count_to(pos, my_disc, op_disc, Position::left());
  else
    n_left = 0;
  
  int n_right;
  if (search_move_dir & DIR_RIGHT)
    n_right = get_move_count_to(pos, my_disc, op_disc, Position::right());
  else
    n_right = 0;

  int n_up_left;
  if (search_move_dir & DIR_UP_LEFT)
    n_up_left = get_move_count_to(pos, my_disc, op_disc, Position::up_left());
  else
    n_up_left = 0;
  
  int n_up_right;
  if (search_move_dir & DIR_UP_RIGHT)
    n_up_right
      = get_move_count_to(pos, my_disc, op_disc, Position::up_right());
  else
    n_up_right = 0;
  
  int n_down_left;
  if (search_move_dir & DIR_DOWN_LEFT)
    n_down_left
      = get_move_count_to(pos, my_disc, op_disc, Position::down_left());
  else
    n_down_left = 0;
  
  int n_down_right;
  if (search_move_dir & DIR_DOWN_RIGHT)
    n_down_right
      = get_move_count_to(pos, my_disc, op_disc, Position::down_right());
  else
    n_down_right = 0;

  data_type flip =
    (n_right || n_down_right || n_down || n_down_left) ?
      (FLIP_TABLE_RIGHT_DOWN[n_right][n_down_right][n_down][n_down_left]
       << offset) : 0;
  if (n_left || n_up_left || n_up || n_up_right)
    flip |=  (FLIP_TABLE_LEFT_UP[n_left][n_up_left][n_up][n_up_right]
         >> (SIZE*SIZE-1-offset));
  if (flip.any()) {
    disc_map_ ^= flip;
    set_disc(pos, BLACK);
    return true;
  } else
    return false;
}
*/

template<class F>
int
BitBoard::get_move_count_to(const Position& p,
                            const BitMatrix& my_disc,
                            const BitMatrix& op_disc,
                            F move_f) const
{
  Position pos(p);
  // TODO: 8x8限定
  if ((pos = move_f(pos)) == Position::POS_PASS)
    return 0;
  if (op_disc.at(pos)) {
    if ((pos = move_f(pos)) == Position::POS_PASS)
      return 0;
    if (op_disc.at(pos)) {
      if ((pos = move_f(pos)) == Position::POS_PASS)
        return 0;
      if (op_disc.at(pos)) {
        if ((pos = move_f(pos)) == Position::POS_PASS)
          return 0;
        if (op_disc.at(pos)) {
          if ((pos = move_f(pos)) == Position::POS_PASS)
            return 0;
          if (op_disc.at(pos)) {
            if ((pos = move_f(pos)) == Position::POS_PASS)
              return 0;
            if (op_disc.at(pos)) {
              if ((pos = move_f(pos)) == Position::POS_PASS)
                return 0;
              if (my_disc.at(pos))
                return 6;
            } else if (my_disc.at(pos))
              return 5;
          } else if (my_disc.at(pos))
            return 4;
        } else if (my_disc.at(pos))
          return 3;
      } else if (my_disc.at(pos))
        return 2;
    } else if (my_disc.at(pos))
      return 1;
  }
  return 0;
}


template<class F>
int
BitBoard::get_move_count_to(BitMatrix start,
                            const BitMatrix& my_disc,
                            const BitMatrix& op_disc,
                            F move_f) const
{
  // TODO: 8x8限定
  move_f(start);
  if ((start & op_disc).any()) {
    move_f(start);
    if ((start & op_disc).any()) {
      move_f(start);
      if ((start & op_disc).any()) {
        move_f(start);
        if ((start & op_disc).any()) {
          move_f(start);
          if ((start & op_disc).any()) {
            move_f(start);
            if ((start & op_disc).any()) {
              move_f(start);
              if ((start & my_disc).any())
                return 6;
            } else if ((start & my_disc).any())
              return 5;
          } else if ((start & my_disc).any())
            return 4;
        } else if ((start & my_disc).any())
          return 3;
      } else if ((start & my_disc).any())
        return 2;
    } else if ((start & my_disc).any())
      return 1;
  }
  return 0;
}

static const unsigned long long
EXCEPT_RIGHT_LEFT_ONE = 0x7e7e7e7e7e7e7e7eULL;

BitBoard::data_type
BitBoard::get_move_bit() const
{
  data_type my_disc, op_disc;
  my_disc = disc_map_;
  op_disc = op_map_;
  data_type blank_map(~disc_map_ ^ op_map_);
  
#if defined GET_MOBILITY_INLINE
  unsigned long long blank = get_blank_bit().get_data();
  unsigned long long my = my_disc.get_data();
  unsigned long long op = op_disc.get_data();
  unsigned long long result = 0;

  {
    unsigned long long cur1 = my, cur2 = my;
    cur1 >>= 8; cur2 <<= 8;
    
    cur1 &= op; cur2 &= op;
    cur1 >>= 8; cur2 <<= 8;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 8; cur2 <<= 8;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 8; cur2 <<= 8;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 8; cur2 <<= 8;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 8; cur2 <<= 8;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 8; cur2 <<= 8;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
  }
  {
    unsigned long long cur1 = my, cur2 = my;
    op &= EXCEPT_RIGHT_LEFT_ONE;
    cur1 >>= 1; cur2 <<= 1;

    cur1 &= op; cur2 &= op;
    cur1 >>= 1; cur2 <<= 1;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 1; cur2 <<= 1;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 1; cur2 <<= 1;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 1; cur2 <<= 1;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 1; cur2 <<= 1;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 1; cur2 <<= 1;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
  }
  {
    unsigned long long cur1 = my, cur2 = my;
    cur1 >>= 9; cur2 <<= 9;

    cur1 &= op; cur2 &= op;
    cur1 >>= 9; cur2 <<= 9;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 9; cur2 <<= 9;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 9; cur2 <<= 9;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 9; cur2 <<= 9;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 9; cur2 <<= 9;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 9; cur2 <<= 9;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
  }
  {
    unsigned long long cur1 = my, cur2 = my;
    cur1 >>= 7; cur2 <<= 7;

    cur1 &= op; cur2 &= op;
    cur1 >>= 7; cur2 <<= 7;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 7; cur2 <<= 7;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 7; cur2 <<= 7;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 7; cur2 <<= 7;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 7; cur2 <<= 7;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
    cur1 &= op; cur2 &= op;
    cur1 >>= 7; cur2 <<= 7;
    result |= (cur1 & blank);
    result |= (cur2 & blank);
  }
  return result;
  
#else
  return 
      get_move_bit_to(my_disc, op_disc, blank_map, data_type::left())
      | get_move_bit_to(my_disc, op_disc, blank_map, data_type::right())
      | get_move_bit_to(my_disc, op_disc, blank_map, data_type::up())
      | get_move_bit_to(my_disc, op_disc, blank_map, data_type::down())
      | get_move_bit_to(my_disc, op_disc, blank_map, data_type::up_left())
      | get_move_bit_to(my_disc, op_disc, blank_map, data_type::up_right())
      | get_move_bit_to(my_disc, op_disc, blank_map, data_type::down_left())
      | get_move_bit_to(my_disc, op_disc, blank_map, data_type::down_right());
#endif
}

template<class F>
inline
BitBoard::data_type
BitBoard::get_move_bit_to(const BitBoard::data_type& my_disc,
                          const BitBoard::data_type& op_disc,
                          const BitBoard::data_type& blank,
                          F move_f) const
{
  data_type ret;
  data_type cur = my_disc;
  move_f(cur);
  
  cur &= op_disc;
  move_f(cur);
  ret |= (cur & blank);
  
  cur &= op_disc;
  move_f(cur);
  ret |= (cur & blank);
  
  cur &= op_disc;
  move_f(cur);
  ret |= (cur & blank);
  
  cur &= op_disc;
  move_f(cur);
  ret |= (cur & blank);
  
  cur &= op_disc;
  move_f(cur);
  ret |= (cur & blank);
  
  cur &= op_disc;
  move_f(cur);
  ret |= (cur & blank);

  return ret;
}

BitBoard BitBoard::parse_zebra_board(const std::string& zebra) {
  if (zebra.size() != 64) {
    throw std::runtime_error("Size of zebra string must be 64");
  }

  Disc discs[64];
  for (int i = 0; i < 64; i++) {
    char c = zebra[i];
    switch (c) {
      case '-':
        discs[i] = BLANK;
        break;
      case 'X':
        discs[i] = BLACK;
        break;
      case 'O':
        discs[i] = WHITE;
        break;
      default:
        throw std::runtime_error("");
        break;
    }
  }
  return BitBoard(discs);
}

}  // namespace oxelon
