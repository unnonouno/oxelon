#ifndef MTDF_HPP_FABDB592_2CEC_4B57_9174_1C68BD9515B3_
#define MTDF_HPP_FABDB592_2CEC_4B57_9174_1C68BD9515B3_

#ifndef ORG_TRN_TBL
#  define ORG_TRN_TBL
#endif

//#ifndef ONE_DEPTH_SORT
//#  define ONE_DEPTH_SORT
//#endif
#ifndef ITERATIVE_SEARCH
#  define ITERATIVE_SEARCH
#endif
#ifndef LAST_TWO_INLINE
#  define LAST_TWO_INLINE
#endif
#ifndef ONE_MOVE_INLINE
//#  define ONE_MOVE_INLINE
#endif
#ifndef EVEN_THEORY
//#  define EVEN_THEORY
#endif
#ifndef BLANK_TABLE
//#  define BLANK_TABLE
#endif

#include <utility>
#include <vector>

#include "bit_move.hpp"
#include "board.hpp"
#include "evaluator.hpp"
#include "solver.hpp"
#include "transposition_table.hpp"

namespace oxelon {

class Mtdf : public Solver {
 public:
  Mtdf(std::auto_ptr<Evaluator<Board> > eval, unsigned max, unsigned table_size);
  virtual ~Mtdf() {}

  std::pair<Position, eval_t> search_next(const Board& b, Disc d);
  void update(const Board& board, Disc disc, eval_t error, int beta, int) {}
  void swap() {}
  
  void set_max_depth(unsigned max) {
    max_depth_ = max;
    sort_keys_.resize(max);
    sorted_nexts_.resize(max);
    moves_.resize(max);
  }

  unsigned get_total_node() const { return total_node_; }
  void clear_total_node() { total_node_ = 0; }
  unsigned get_total_leaf() const { return total_leaf_; }
  void clear_total_leaf() { total_leaf_ = 0; }
  
 private:

  static const unsigned NO_MOVE_ORDERING = 9;
  static const unsigned NO_TRANSPOSITION_TABLE = 8;
  
  eval_t evaluate(const Board& board, Disc disc);

  struct Entry {
    Entry() : lowerbound_(-INFINITY_VALUE), upperbound_(INFINITY_VALUE) {}
    eval_t lowerbound_;
    eval_t upperbound_;
  };

  struct Hash {
    unsigned operator()(const Board& key) const {
      return key.hash();
    }
  };

  
  typedef TranspositionTable<Board, Entry, Hash> TransTable;
  //typedef SetAssociative<Board, Entry, Hash, 2> TransTable;
  
  void update_trans_table(TransTable::iterator& nit, eval_t g,
                          eval_t alpha, eval_t beta);

  eval_t alpha_beta_with_memory(const Board& board,
                                unsigned n_blank,
                                eval_t alpha, eval_t beta, unsigned d,
                                bool passed);

  eval_t no_move_ordering_search(const Board& board, unsigned n_blank,
                                 eval_t alpha, eval_t beta,
                                 const Board::data_type& last_move,
                                 bool passed
#ifdef BLANK_TABLE
                                  , std::vector<std::pair<unsigned, unsigned> >&
#endif
                                 );

  std::vector<std::pair<unsigned, unsigned> >
    make_blanks(const Board& board) const;
  eval_t no_move_pos_check_search(const Board& board, unsigned n_blank,
                                  eval_t alpha, eval_t beta,
                                  bool passed
#ifdef BLANK_TABLE2
                                  , std::vector<std::pair<unsigned, unsigned> >&
#endif
                                  );

  eval_t find_all(const Board& board,
                  unsigned n_blank,
                  eval_t g, eval_t a, eval_t beta,
                  BitBoard::data_type moves
#ifdef BLANK_TABLE
                  , std::vector<std::pair<unsigned, unsigned> >& blank_table
#endif
                  );

  eval_t last1_search(const Board& board);

  eval_t last1_search(const Board& board,
                      unsigned pos1);

  eval_t last2_search(const Board& board,
                      eval_t alpha, eval_t beta,
                      bool passed);

  eval_t last2_search(const Board& board,
                      eval_t alpha, eval_t beta, bool passed,
                      unsigned pos1,
                      unsigned pos2);

  eval_t last3_search(const Board& board,
                      eval_t alpha, eval_t beta,
                      bool passed);
  eval_t last3_search(const Board& board,
                      eval_t alpha, eval_t beta, bool passed,
                      unsigned pos1,
                      unsigned pos2,
                      unsigned pos3);
  eval_t last4_search(const Board& board,
                      eval_t alpha, eval_t beta,
                      bool passed);


  inline void count_leaf() {
    leaf_count_++;
    total_leaf_++;
  }

  inline void count_node() {
    node_count_++;
    total_node_++;
  }

  static const eval_t INFINITY_VALUE = 10000000;
  
  std::auto_ptr<Evaluator<Board> > p_evaluator_;
  unsigned max_depth_;
  unsigned table_size_;
  //  mutable TransTable trans_table_;
  std::auto_ptr<TransTable> p_trans_table_;
  
  BitBoard::data_type next_move_bit_;
  Position next_move_;
  unsigned node_count_;
  unsigned leaf_count_;
  unsigned total_node_;
  unsigned total_leaf_;
  unsigned cut_count_;
  unsigned hit_count_;
  unsigned failed_count_;

  typedef std::vector<std::pair<BitBoard, BitBoard::data_type> > ValBoardMap;
  mutable std::vector<std::vector<eval_t> > sort_keys_;
  mutable std::vector<ValBoardMap> sorted_nexts_;
  mutable std::vector<std::vector<BitMove> > moves_;

#ifdef ITERATIVE_SEARCH
  std::auto_ptr<TransTable> p_pre_trans_table_;
#endif
  
  static unsigned char POS_SCORE[64];
  
};

}  // namespace oxelon

#endif // MTDF_HPP_FABDB592_2CEC_4B57_9174_1C68BD9515B3_
