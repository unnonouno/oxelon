#include "fixed_pattern_evaluator.hpp"

#include <boost/preprocessor.hpp>

#include "board.hpp"
#include "horver.hpp"
#include "diagonal.hpp"
#include "edge2x.hpp"
#include "corner3x3.hpp"
#include "corner2x5.hpp"
#include "stream.hpp"

namespace oxelon {

FixedPatternEvaluator::FixedPatternEvaluator()
    : horver_2_weights_(HorVer<2>().pattern_size()),
      horver_3_weights_(HorVer<3>().pattern_size()),
      horver_4_weights_(HorVer<4>().pattern_size()),
      diagonal_4_weights_(Diagonal<4>().pattern_size()),
      diagonal_5_weights_(Diagonal<5>().pattern_size()),
      diagonal_6_weights_(Diagonal<6>().pattern_size()),
      diagonal_7_weights_(Diagonal<7>().pattern_size()),
      diagonal_8_weights_(Diagonal<8>().pattern_size()),
      corner3x3_weights_(Corner3x3<>().pattern_size()),
      corner2x5_weights_(Corner2x5<>().pattern_size()),
      edge2x_weights_(Edge2x<>().pattern_size()) {
}

eval_t
FixedPatternEvaluator::evaluate(const Board& board, Disc disc) const {
  eval_t ret = 0;
#define GEN_HOR_VER(z, i, data)                                         \
  ret += BOOST_PP_CAT(BOOST_PP_CAT(horver_, BOOST_PP_ADD(2, i)), _weights_)[ \
      HorVer<i+2, false, false>().encode(board, disc)];                 \
  ret += BOOST_PP_CAT(BOOST_PP_CAT(horver_, BOOST_PP_ADD(2, i)), _weights_)[ \
      HorVer<i+2, true,  false>().encode(board, disc)];                 \
  ret += BOOST_PP_CAT(BOOST_PP_CAT(horver_, BOOST_PP_ADD(2, i)), _weights_)[ \
      HorVer<i+2, false, true>().encode(board, disc)];                  \
  ret += BOOST_PP_CAT(BOOST_PP_CAT(horver_, BOOST_PP_ADD(2, i)), _weights_)[ \
      HorVer<i+2, true,  true>().encode(board, disc)];
  
  BOOST_PP_REPEAT(3, GEN_HOR_VER, _);
/*
#define GEN_DIAG(z, i, data) \
    ret += BOOST_PP_CAT(BOOST_PP_CAT(diagonal_, BOOST_PP_ADD(4, i)), _weights_)[ \
      HorVer<i+4, false, false>().encode(board, disc)]; \
    ret += BOOST_PP_CAT(BOOST_PP_CAT(diagonal_, BOOST_PP_ADD(4, i)), _weights_)[ \
      HorVer<i+4, true,  false>().encode(board, disc)]; \
    ret += BOOST_PP_CAT(BOOST_PP_CAT(diagonal_, BOOST_PP_ADD(4, i)), _weights_)[ \
      HorVer<i+4, false, true>().encode(board, disc)]; \
    ret += BOOST_PP_CAT(BOOST_PP_CAT(diagonal_, BOOST_PP_ADD(4, i)), _weights_)[ \
      HorVer<i+4, true,  true>().encode(board, disc)];
 
  
  BOOST_PP_REPEAT(4, GEN_DIAG, _)
 */

  ret += diagonal_4_weights_[Diagonal<4, false, false>().encode(board, disc)];
  ret += diagonal_4_weights_[Diagonal<4, true, false>().encode(board, disc)];
  ret += diagonal_4_weights_[Diagonal<4, false, true>().encode(board, disc)];
  ret += diagonal_4_weights_[Diagonal<4, true, true>().encode(board, disc)];

  ret += diagonal_5_weights_[Diagonal<5, false, false>().encode(board, disc)];
  ret += diagonal_5_weights_[Diagonal<5, true, false>().encode(board, disc)];
  ret += diagonal_5_weights_[Diagonal<5, false, true>().encode(board, disc)];
  ret += diagonal_5_weights_[Diagonal<5, true, true>().encode(board, disc)];

  ret += diagonal_6_weights_[Diagonal<6, false, false>().encode(board, disc)];
  ret += diagonal_6_weights_[Diagonal<6, true, false>().encode(board, disc)];
  ret += diagonal_6_weights_[Diagonal<6, false, true>().encode(board, disc)];
  ret += diagonal_6_weights_[Diagonal<6, true, true>().encode(board, disc)];

  ret += diagonal_7_weights_[Diagonal<7, false, false>().encode(board, disc)];
  ret += diagonal_7_weights_[Diagonal<7, true, false>().encode(board, disc)];
  ret += diagonal_7_weights_[Diagonal<7, false, true>().encode(board, disc)];
  ret += diagonal_7_weights_[Diagonal<7, true, true>().encode(board, disc)];

  ret += diagonal_8_weights_[Diagonal<8, false, false>().encode(board, disc)];
  ret += diagonal_8_weights_[Diagonal<8, true, false>().encode(board, disc)];

  ret += corner3x3_weights_[Corner3x3<false, false>().encode(board, disc)];
  ret += corner3x3_weights_[Corner3x3<true, false>().encode(board, disc)];
  ret += corner3x3_weights_[Corner3x3<false, true>().encode(board, disc)];
  ret += corner3x3_weights_[Corner3x3<true, true>().encode(board, disc)];

  ret += edge2x_weights_[Edge2x<false, false>().encode(board, disc)];
  ret += edge2x_weights_[Edge2x<true, false>().encode(board, disc)];
  ret += edge2x_weights_[Edge2x<false, true>().encode(board, disc)];
  ret += edge2x_weights_[Edge2x<true, true>().encode(board, disc)];
  
  ret += corner2x5_weights_[Corner2x5<false, false, false>().encode(board, disc)];
  ret += corner2x5_weights_[Corner2x5<true,  false, false>().encode(board, disc)];
  ret += corner2x5_weights_[Corner2x5<false,  true, false>().encode(board, disc)];
  ret += corner2x5_weights_[Corner2x5<true,   true, false>().encode(board, disc)];
  ret += corner2x5_weights_[Corner2x5<false, false, true>().encode(board, disc)];
  ret += corner2x5_weights_[Corner2x5<true,  false, true>().encode(board, disc)];
  ret += corner2x5_weights_[Corner2x5<false,  true, true>().encode(board, disc)];
  ret += corner2x5_weights_[Corner2x5<true,   true, true>().encode(board, disc)];
    
  return ret;
}

void
FixedPatternEvaluator::update(const Board& board, Disc disc,
                              eval_t error, int beta, int n_sample)
{
  //TODO: not implemented yet
}

void
FixedPatternEvaluator::swap()
{
  //TODO: not implemented yet
}

void
FixedPatternEvaluator::write(std::ostream &out) const
{
  //TODO: not implemented yet
}

void
FixedPatternEvaluator::read(std::istream &in)
{
  std::istream& (*read)(std::istream&, std::vector<eval_t>&)
    = read_binary_runlength<short, eval_t>;
    //= read_binary<short, eval_t>;

  read(in, diagonal_4_weights_);
  read(in, diagonal_5_weights_);
  read(in, diagonal_6_weights_);
  read(in, diagonal_7_weights_);
  read(in, diagonal_8_weights_);

  read(in, horver_2_weights_);
  read(in, horver_3_weights_);
  read(in, horver_4_weights_);

  read(in, edge2x_weights_);
  read(in, corner2x5_weights_);
  read(in, corner3x3_weights_);
  /*
  in >> diagonal_4_weights_;
  in >> diagonal_5_weights_;
  in >> diagonal_6_weights_;
  in >> diagonal_7_weights_;
  in >> diagonal_8_weights_;

  in >> horver_2_weights_;
  in >> horver_3_weights_;
  in >> horver_4_weights_;

  in >> edge2x_weights_;
  in >> corner2x5_weights_;
  in >> corner3x3_weights_;
  */
  // tune weights
  for (std::vector<eval_t>::iterator it = diagonal_4_weights_.begin();
       it != diagonal_4_weights_.end(); ++it) {
    *it *= 2;
  }
  for (std::vector<eval_t>::iterator it = diagonal_5_weights_.begin();
       it != diagonal_5_weights_.end(); ++it) {
    *it *= 2;
  }
  for (std::vector<eval_t>::iterator it = diagonal_6_weights_.begin();
       it != diagonal_6_weights_.end(); ++it) {
    *it *= 2;
  }
  for (std::vector<eval_t>::iterator it = diagonal_7_weights_.begin();
       it != diagonal_7_weights_.end(); ++it) {
    *it *= 2;
  }
  for (std::vector<eval_t>::iterator it = diagonal_8_weights_.begin();
       it != diagonal_8_weights_.end(); ++it) {
    *it *= 4;
  }

  for (std::vector<eval_t>::iterator it = horver_2_weights_.begin();
       it != horver_2_weights_.end(); ++it) {
    *it *= 2;
  }
  for (std::vector<eval_t>::iterator it = horver_3_weights_.begin();
       it != horver_3_weights_.end(); ++it) {
    *it *= 2;
  }
  for (std::vector<eval_t>::iterator it = horver_4_weights_.begin();
       it != horver_4_weights_.end(); ++it) {
    *it *= 2;
  }

  for (std::vector<eval_t>::iterator it = edge2x_weights_.begin();
       it != edge2x_weights_.end(); ++it) {
    *it *= 2;
  }
  for (std::vector<eval_t>::iterator it = corner3x3_weights_.begin();
       it != corner3x3_weights_.end(); ++it) {
    *it *= 2;
  }
}

}  // namespace oxelon
