#include "mtdf.hpp"

#include <cassert>
#include <sstream>
#include <stdexcept>

#include "types.hpp"
#include "bit_move_iterator.hpp"
#include "blank_table_iterator.hpp"
#include "trans_table_controller.hpp"
#include "move_ordering_iterator.hpp"
#include "sorted_list.hpp"

namespace oxelon {

unsigned char Mtdf::POS_SCORE[] = {
  1, 8, 2, 4, 4, 2, 8, 1,
  8, 9, 7, 6, 6, 7, 9, 8,
  2, 7, 3, 5, 5, 3, 7, 2,
  4, 6, 5, 0, 0, 5, 6, 4,
  4, 6, 5, 0, 0, 5, 6, 4,
  2, 7, 3, 5, 5, 3, 7, 2,
  8, 9, 7, 6, 6, 7, 9, 8,
  1, 8, 2, 4, 4, 2, 8, 1
};

Mtdf::Mtdf(std::auto_ptr<Evaluator<Board> > eval, unsigned max, unsigned size)
    : p_evaluator_(eval),
      max_depth_(max),
      table_size_(size),
      node_count_(),
      leaf_count_(),
      total_node_(0),
      total_leaf_(0),
      sort_keys_(max),
      sorted_nexts_(max),
      moves_(max)
#ifdef ITERATIVE_SEARCH
    , p_pre_trans_table_(new TransTable(2))
#endif
{}

/*
std::pair<Position, eval_t>
Mtdf::search_next(const Board& b, Disc d)
{
  std::pair<Position, eval_t> res;
  if (d == BLACK)
    res.second = evaluate(b, d);
  else
    res.second = evaluate(b.make_inverse(), d);
  res.first= next_move_;
  return res;
}
*/

std::vector<std::pair<unsigned, unsigned> >
Mtdf::make_blanks(const Board& board) const {
  Board::data_type blank = board.get_blank_bit();
  std::vector<std::pair<unsigned, unsigned> > v;
  v.reserve(NO_MOVE_ORDERING);
  v.push_back(std::make_pair(1, 0));
  std::vector<eval_t> sort_key;
  sort_key.push_back(0);
  while (blank.any()) {
    BitBoard::data_type next = blank.get_next_bit();
    unsigned pos = next.get_next();
    sort_insert(sort_key, v, POS_SCORE[pos], std::make_pair(1, pos));
    blank ^= next;
  }

  return v;
}

inline
eval_t Mtdf::get_difference(const Board& board, int n_blank) {
  //count_leaf();
  eval_t score = (static_cast<int>(board.count_black()) * 2 - 64 + n_blank) * 1024;
  assert(score == board.get_score());
  return score;
}

std::pair<Position, eval_t>
Mtdf::search_next(const Board& b, Disc d) {
  std::pair<Position, eval_t> res;
  if (d == BLACK)
    res.second = evaluate(b, d);
  else
    res.second = evaluate(b.make_inverse(), d);
  res.first= next_move_;
  return res;
}

eval_t Mtdf::alpha_beta_with_memory(
    const Board& board,
    unsigned n_blank,
    eval_t alpha,
    eval_t beta,
    unsigned d,
    bool passed) {
  //std::cerr << board.to_zebra_str() << std::endl;
  if (n_blank < NO_MOVE_ORDERING && d != max_depth_)
    return no_move_ordering_search(board, n_blank, alpha, beta, 0, passed
#ifdef BLANK_TABLE
                                   , make_blanks(board)
#endif
                                   );
  
  TransTableController<TransTable> ttc(*p_trans_table_);
  if (!ttc.init_alpha_beta(board, alpha, beta)) {
    cut_count_++;
    return ttc.get_return_value();
  }
  /*
  TransTable::iterator nit;
  Entry pre_entry;
  
  if (n_blank >= NO_TRANSPOSITION_TABLE) {
    nit = trans_table.find(board);
    if (nit != trans_table.end()) {
      hit_count_++;
      if (nit->second.lowerbound_ >= beta) {
        cut_count_++;
        return nit->second.lowerbound_;
      }
      if (nit->second.upperbound_ <= alpha) {
        cut_count_++;
        return nit->second.upperbound_;
      }
      alpha = std::max(alpha, nit->second.lowerbound_);
      beta = std::min(beta, nit->second.upperbound_);
      
      pre_entry = nit->second;
    }
  }
  */

  eval_t g;
  if (n_blank == 0) {
    g = get_difference(board, 0);
    
  } else if (d == 0) {
    count_leaf();
    g = p_evaluator_->evaluate(board, BLACK);
    
  } else {
    count_node();
    
    g = -INFINITY_VALUE;
    eval_t a = alpha;
    
    BitBoard::data_type moves = board.get_move_bit();
    unsigned moves_size = moves.size();
    if (moves_size == 0) {
      if (passed) {
        g = get_difference(board, n_blank);
        
      } else {
        Board next_board = board.make_inverse();
        g = -alpha_beta_with_memory(next_board,
                                    n_blank,
                                    -beta,
                                    -alpha,
                                    d - 1,
                                    true);
      }
      
      if (d == max_depth_)
        next_move_ = Position::POS_PASS;
      
#ifdef ONE_MOVE_INLINE
    } else if (moves_size == 1) {
      Board next_board(board);
      next_board.move(moves);
      g = std::max(g, -alpha_beta_with_memory(
          next_board.make_inverse(),
          n_blank-1,
          -beta,
          -a,
          d - 1,
          false));
      if (d == max_depth_ && g > a)
        next_move_bit_ = moves;
      a = std::max(a, g);
#endif
    } else {
      //std::cerr << moves_size << " " << n_blank << std::endl;
      
#if defined ITERATIVE_SEARCH
      // 前回の置換表により，もっとも探索経路として妥当なところから探索する
      if (n_blank >= NO_TRANSPOSITION_TABLE) {
        MoveOrderingIterator<TransTable> it(board, moves,
                                            *p_evaluator_, max_depth_ - d,
                                            *p_trans_table_, *p_pre_trans_table_);
        /*
        ValBoardMap& sorted_next = sorted_nexts_[max_depth_ - d];
        std::vector<eval_t>& sort_key = sort_keys_[max_depth_ - d];
        
        sorted_next.clear();
        sort_key.clear();
        
        while (moves.any()) {
          BitBoard::data_type next = moves.get_next_bit();
          moves ^= next;
          BitBoard next_board(board);
          next_board.try_move(next.get_next());
          std::pair<BitBoard, BitBoard::data_type>
            next_ent(next_board.make_inverse(), next);
          TransTable::iterator trans_it = p_trans_table_->find(next_ent.first);
          if (trans_it != p_trans_table_->end()) {
            // 見つからない
            if (trans_it->second.upperbound_ == trans_it->second.lowerbound_) {
              g = std::max(g, 
                           -alpha_beta_with_memory
                           (next_ent.first, n_blank-1, -beta, -a,
                            d - 1, false));
              if (d == max_depth_ && g > a)
                next_move_bit_ = next_ent.second;
              a = std::max(a, g);
              if (beta <= g)
                goto CUT;
            } else {
              sort_insert(sort_key, sorted_next,
                          trans_it->second.upperbound_, next_ent);
            }
            
          } else {
            TransTable::iterator pre_it;
            if (d > 2 &&
                (pre_it = p_pre_trans_table_->find(next_ent.first))
                != p_pre_trans_table_->end()) {
              //              if (false) {
              // 前回の探索結果を使う
              // TODO: lowerbound or upperbound?
              if (pre_it->second.upperbound_
                  == pre_it->second.lowerbound_) {
                g = std::max(g, -alpha_beta_with_memory(
                  next_ent.first, n_blank-1, -beta, -a,
                  d - 1, false));
                if (d == max_depth_ && g > a)
                  next_move_bit_ = next_ent.second;
                a = std::max(a, g);
                if (beta <= g)
                  goto CUT;
                
              } else
                sort_insert(sort_key, sorted_next,
                            pre_it->second.upperbound_, next_ent);
              
            } else {
              int v;
              if (n_blank > 20)
                v = p_evaluator_->evaluate(next_ent.first, BLACK);
              else
                //v = next_ent.first.get_mobility();
                v = next_ent.first.get_weighted_mobility();
                
              sort_insert(sort_key, sorted_next,
                          INFINITY_VALUE + v,
                          next_ent);
            }
          }
        }
        */

        while (it.has_next()) {
          if (beta <= g)
            break;
          Board next_board(it.get_next());
          g = std::max(g,
                       -alpha_beta_with_memory(next_board, n_blank-1, -beta, -a,
                                               d - 1, false));
          if (d == max_depth_ && g > a)
            next_move_bit_ = board.get_blank_bit() ^ next_board.get_blank_bit();
          a = std::max(a, g);
          it.go_next();
        }
        /*
        FOR_EACH_CONST (ValBoardMap, it, sorted_next) {
          if (beta <= g)
            break;
          
          g = std::max(g, -alpha_beta_with_memory(
            it->first, n_blank-1, -beta, -a,
            d - 1, false));
          if (d == max_depth_ && g > a)
            next_move_bit_ = it->second;
          a = std::max(a, g);
        }
      CUT:
        ;
        */
      } else if (n_blank >= NO_MOVE_ORDERING && moves_size >= 2) {
        // 上の方のifの分岐により、空所は NO_TRANSPOSITION_TABLE 以下
        //typedef FastVector<unsigned/*BitBoard::data_type*/, NO_TRANSPOSITION_TABLE> ValBitMap;
        typedef std::vector<unsigned> ValBitMap;
        ValBitMap sorted_next;
        std::vector<eval_t> sort_key;

        while (moves.any()) {
          BitBoard::data_type next = moves.get_next_bit();
          unsigned pos = next.get_next();
          BitBoard next_board(board);
          sort_insert(sort_key, sorted_next,
                      POS_SCORE[pos], pos);
          moves ^= next;
        }
        
        //while (moves.any()) {
        for (ValBitMap::const_iterator it = sorted_next.begin(),
                 end = sorted_next.end(); it != end; ++it) {
          BitBoard next_board(board);
          next_board.try_move(*it);
          next_board.inverse();
          g = std::max(g,
                       -alpha_beta_with_memory(next_board,
                                               n_blank-1, -beta, -a,
                                               d - 1, false));
          if (d == max_depth_ && g > a) {
            //next_move_bit_ = *it;
            next_move_bit_ = BitBoard::data_type();
            next_move_bit_.set(*it);
          }
          if (beta <= g)
            break;
          a = std::max(a, g);
        }
      } else {
        BitMoveIterator it(board);
        while (it.has_next()) {
          BitBoard next_board = it.get_next();
          g = std::max(g, -alpha_beta_with_memory(next_board,
                                                  n_blank-1, -beta, -a,
                                                  d - 1, false));
          if (d == max_depth_ && g > a)
            next_move_bit_ =
              (next_board.get_blank_bit() ^ board.get_blank_bit()).get_next();
          if (beta <= g)
            break;
          a = std::max(a, g);
        }
        /*
        // ソートしない
        while (moves.any()) {
          BitBoard::data_type next = moves.get_next_bit();
          BitBoard next_board(board);
          next_board.move(next);
          next_board.inverse();
          g = std::max(g, -alpha_beta_with_memory(next_board,
                                             n_blank-1, -beta, -a,
                                             d - 1, false));
          if (d == max_depth_ && g > a)
            next_move_bit_ = next;
          if (beta <= g)
            break;
          a = std::max(a, g);
          moves ^= next;
        }
        */
      }
#endif
    }
  }
  
  if (n_blank >= NO_TRANSPOSITION_TABLE) {
    ttc.update_alpha_beta(board, g, alpha, beta);
    /*
    if (nit == trans_table.end()) {
      nit = trans_table.insert(TransTable::value_type(board, Entry()));
      
    } else {
      // 下位の呼び出し中に上書きされた可能性，挿入し直し
      // TODO: Depthごとに置換表を用意
      if (!(nit->first == board))
        nit = trans_table.insert(TransTable::value_type(board, pre_entry));
    }
    update_trans_table(nit, g, alpha, beta);
    */
  }
  
  return g;
}

eval_t Mtdf::evaluate(const Board& board, Disc disc) {
  //std::cerr << board.to_zebra_str() << std::endl;
  node_count_ = leaf_count_ = hit_count_ = cut_count_ = failed_count_ = 0;

  eval_t g = p_evaluator_->evaluate(board, disc);
  eval_t upperbound = INFINITY_VALUE;
  eval_t lowerbound = -INFINITY_VALUE;
  
  /*#ifdef ITERATIVE_SEARCH
  // 前回の置換表を保存するために，２つ用意
  boost::shared_ptr<TransTable> p_trans_table(new TransTable(table_size_ - 1));
#else
  TransTable trans_table(table_size_);
  #endif*/
  p_trans_table_ = std::auto_ptr<TransTable>(new TransTable(table_size_));
  
  while (lowerbound < upperbound) {
    eval_t beta;
    if (g == lowerbound)
      beta = g + 1;
    else
      beta = g;
    g = alpha_beta_with_memory(board,
                               board.count_blank(),
                               beta - 1,
                               beta,
                               max_depth_,
                               false);
    if (g < beta) {
      upperbound = g;
    } else {
      lowerbound = g;
    }
  }
  
#ifdef BIT_MOVE_MAP
  next_move_ = Position(next_move_bit_.get_next());
#endif
  
  std::cerr << next_move_.to_str()
            << " V:" << g
            << ",n:" << node_count_
            << ",l:" << leaf_count_
            << ",h:" << hit_count_
            << ",c:" << cut_count_
#ifdef ITERATIVE_SEARCH
            << ",T:" << p_trans_table_->get_hit_count() 
            << "/" << p_trans_table_->get_entry_count ()
#else
            << ",T:" << p_trans_table_->get_hit_count()
            << "/" << p_trans_table_->get_entry_count ()
#endif
            << ",F:" << failed_count_
            << std::endl;
  
#ifdef ITERATIVE_SEARCH
  p_pre_trans_table_ = p_trans_table_;
#endif
  return g;
}

inline
void Mtdf::update_trans_table(TransTable::iterator& nit, eval_t g,
                              eval_t alpha, eval_t beta)
{
  Entry& new_n = nit->second;
    
  if (g <= alpha) {
    new_n.upperbound_ = g;
  } else if (g > alpha && g < beta) {
    new_n.lowerbound_ = g;
    new_n.upperbound_ = g;
  } else if (g >= beta)
    new_n.lowerbound_ = g;
}


eval_t Mtdf::no_move_ordering_search(const Board& board,
                                     unsigned n_blank,
                                     eval_t alpha,
                                     eval_t beta,
                                     const Board::data_type& last_move,
                                     bool passed
#ifdef BLANK_TABLE
                                     , std::vector<std::pair<unsigned, unsigned> >& blanks
#endif
                                     )
{
  if (n_blank < NO_TRANSPOSITION_TABLE) 
    return no_move_pos_check_search(board, n_blank, alpha, beta, passed
#ifdef BLANK_TABLE2
                                    , blanks
#endif
                                    );

#ifdef LAST_TWO_INLINE
  if (n_blank == 4) {
    std::cerr << "no_move_ordering" << std::endl;
    return last4_search(board, alpha, beta, passed);
  }
#endif

  TransTableController<TransTable> ttc(*p_trans_table_);
  if (!ttc.init_alpha_beta(board, alpha, beta)) {
    cut_count_++;
    return ttc.get_return_value();
  }
  /*
  TransTable::iterator nit;
  Entry pre_entry;

  nit = trans_table.find(board);
  if (nit != trans_table.end()) {
    hit_count_++;
    if (nit->second.lowerbound_ >= beta) {
      cut_count_++;
      return nit->second.lowerbound_;
    }
    if (nit->second.upperbound_ <= alpha) {
      cut_count_++;
      return nit->second.upperbound_;
    }
    alpha = std::max(alpha, nit->second.lowerbound_);
    beta = std::min(beta, nit->second.upperbound_);
    
    pre_entry = nit->second;
  }
  */
  count_node();
  eval_t g = -INFINITY_VALUE;
  eval_t a = alpha;

#ifdef BLANK_TABLE
  BlankTableIterator it(blanks, board);
#else
  BitMoveIterator it(board);
#endif

  for (; it.has_next(); it.go_next()) {
    BitBoard next_board(it.get_next());
    g = std::max(g, -no_move_ordering_search(next_board, n_blank-1, -beta, -a,
                                             0, false
#ifdef BLANK_TABLE
                                             , blanks
#endif
                                             ));
    if (beta <= g)
      goto cut;
    a = std::max(a, g);
  }

  if (g == -INFINITY_VALUE) {
    // passする
    if (passed) {
      g = get_difference(board, n_blank);
    } else {
      Board next_board = board.make_inverse();
      g = -no_move_ordering_search(next_board, n_blank,
                                   -beta, -alpha,
                                   0, true
#ifdef BLANK_TABLE
                                   , blanks
#endif
                                   );
    }
  }
 cut:

  ttc.update_alpha_beta(board, g, alpha, beta);
  /*
  if (nit == trans_table.end()) {
    nit = trans_table.insert(TransTable::value_type(board, Entry()));
    
  } else {
    // 下位の呼び出し中に上書きされた可能性，挿入し直し
    // TODO: Depthごとに置換表を用意
    if (!(nit->first == board))
      nit = trans_table.insert(TransTable::value_type(board, pre_entry));
  }

  update_trans_table(nit, g, alpha, beta);
  */

  return g;
}

inline
eval_t Mtdf::find_all(const Board& board,
                      unsigned n_blank,
                      eval_t g, eval_t a, eval_t beta,
                      BitBoard::data_type moves
#ifdef BLANK_TABLE
                      , std::vector<std::pair<unsigned, unsigned> >& blank_table
#endif
                      )
{
  while (moves.any()) {
    BitBoard::data_type next = moves.get_next_bit();
    BitBoard next_board(board);
    next_board.try_move(next.get_next());
    next_board.inverse();
    g = std::max(g, -no_move_ordering_search(next_board, n_blank-1, -beta, -a,
                                             next, false
#ifdef BLANK_TABLE
                                             , blank_table
#endif
                                             ));
    if (beta <= g)
      return g;
    a = std::max(a, g);
    moves ^= next;
  }
  return g;
}


eval_t Mtdf::no_move_pos_check_search(const Board& board, unsigned n_blank,
                                      eval_t alpha, eval_t beta,
                                      bool passed
#ifdef BLANK_TABLE2
                                      , std::vector<std::pair<unsigned, unsigned> >& blanks
#endif
                                      )
{
#ifdef LAST_TWO_INLINE
  if (n_blank == 4) {
    //std::cerr << "no_move_pos_check" << std::endl;
    return last4_search(board, alpha, beta, passed);
  }
#endif

  if (n_blank == 2) {
    return last2_search(board, alpha, beta, passed);
  }


  count_node();

  eval_t g = -INFINITY_VALUE;
  eval_t a = alpha;

#ifdef USE_PARITY
  // parity
  BitBoard::data_type checked_mask;
  for (int y = 0; y < 2; y++)
    for (int x = 0; x < 2; x++) {
      BitBoard::data_type quad = board.get_blank_bit().get_quad(x, y);
      checked_mask |= quad;
      if (quad.size() % 2 == 1)
        g = find_all(board, n_blank, g, a, beta, quad
#  ifdef BLANK_TABLE2
                     , blank_table
#  endif
                     );
    }
  if (beta <= g) {
    return g;
  }
  a = std::max(a, g);
#endif
    
  //BitBoard::data_type moves(board.get_potential_move_bit());
  //BitBoard::data_type moves(board.get_blank_bit());
#ifdef USE_PARITY
  //moves &= ~checked_mask;
#endif

  /*
#ifdef EVEN_THEORY
  // 偶数理論
  BitBoard::data_type mask = last_move.make_round();
  
  BitBoard::data_type tmp_move = moves & mask;
  moves ^= tmp_move;
  while (tmp_move.any()) {
    BitBoard::data_type next = tmp_move.get_next_bit();
    tmp_move ^= next;
    
    BitBoard next_board(board);
    next_board.move(next);
    next_board.inverse();
    g = std::max(g, -no_move_pos_check_search(next_board, n_blank-1, -beta, -a,
                                              false));
    if (beta <= g)
      return g;
    a = std::max(a, g);
  }
#endif
  */
#ifdef BLANK_TABLE2
  BlankTableIterator it(board, blanks);
#else
  BitMoveIterator it(board);
#endif
  for (; it.has_next(); it.go_next()) {
    const BitBoard& next_board = it.get_next();
    eval_t score = -no_move_pos_check_search(
        next_board, n_blank-1, -beta, -a, false);
    g = std::max(g, score);
    if (beta <= g) {
      return g;
    }
    a = std::max(a, g);
  }

  if (g != -INFINITY_VALUE) {
    return g;
  } else {
    if (passed) {
      return get_difference(board, n_blank);
    } else {
      Board next_board = board.make_inverse();
      return -no_move_pos_check_search(
          next_board, n_blank,
          -beta, -alpha, true
#ifdef BLANK_TABLE2
          , blanks
#endif
                                       );
    }
  }
}

inline
eval_t Mtdf::last1_search(const Board& board,
                          eval_t alpha,
                          eval_t beta,
                          bool passed)
{
  count_node();
  
  BitBoard::data_type moves = board.get_blank_bit();
  unsigned pos = moves.get_next();
  BitBoard new_board(board);
  if (new_board.try_move(/*moves, */pos)) {
    //    if (d == max_depth_)
    //      next_move_bit_ = moves;

    return get_difference(new_board, 0);
  } else {
    count_node();
    
    new_board.inverse();
    if (new_board.try_move(/*moves, */pos)) {
      //      if (d == max_depth_)
      //        next_move_bit_ = moves;
      
      return -get_difference(new_board, 0);
    } else {
      // どちらも打てない
      return -get_difference(new_board, 1);
    }
  }
}

inline
eval_t Mtdf::last1_search(const Board& board,
                          int diff,
                          /*const BitBoard::data_type move1, */unsigned pos1)
{
  count_node();
  count_leaf();
  //BitBoard new_board(board);
  int delta = board.get_move_count(/*move1, */pos1);
  if (delta != 0) {
    //return get_difference(new_board, 0);
    return diff + delta * 2048 + 1024;
  } else {
    count_node();
    
    BitBoard new_board(board);
    new_board.inverse();
    //if (delta = new_board.try_move(move1, pos1)) {
    delta = new_board.get_move_count(/*move1, */pos1);
    if (delta != 0) {
      //return -get_difference(new_board, 0);
      return diff - delta * 2048 - 1024;
    } else {
      //return -get_difference(new_board, 1);
      return diff;
    }
  }
}

eval_t Mtdf::last2_search(
    const Board& board,
    eval_t alpha,
    eval_t beta,
    bool passed) {
  BitBoard::data_type rest = board.get_blank_bit();
  if (rest.size() != 2) {
    throw std::exception();
  }
  BitBoard::data_type move1 = rest.get_next_bit();
  BitBoard::data_type move2 = rest;
  move2 ^= move1;
  if (move2.size() != 1) {
    throw std::exception();
  }
  unsigned pos1 = move1.get_next();
  unsigned pos2 = move2.get_next();
  return last2_search(board, alpha, beta, passed,
                      get_difference(board, 2),
                      /*move1, */pos1,
                      /*move2, */pos2);
}
  
eval_t Mtdf::last2_search(
    const Board& board,
    eval_t alpha,
    eval_t beta,
    bool passed,
    int diff,
    /*const BitBoard::data_type& move1, */unsigned pos1,
    /*const BitBoard::data_type& move2, */unsigned pos2) {
  if (diff != board.get_score()) {
    std::stringstream ss;
    ss << diff << " " << board.get_score();
    throw std::runtime_error(ss.str());
  }
  eval_t g = -INFINITY_VALUE;
  int delta;

  count_node();

  BitBoard new_board(board);
  delta = new_board.try_move(/*move1, */pos1);
  if (delta != 0) {
    new_board.inverse();
    g = -last1_search(new_board, -(diff + delta * 2048 + 1024), /*move2, */pos2);

    if (beta <= g)
      return g;
    new_board = board;
  }
  delta = new_board.try_move(/*move2, */pos2);
  if (delta != 0) {
    new_board.inverse();
    g = std::max(g, -last1_search(new_board, -(diff + delta * 2048 + 1024), /*move1, */pos1));
    return g;
  }

  if (g == -INFINITY_VALUE) {
    if (passed) {
      //return get_difference(board, 2);
      count_leaf();
      return diff;
    } else {
      new_board.inverse();
      return -last2_search(new_board,
                           -beta, -alpha, true,
                           -diff,
                           /*move1, */pos1,
                           /*move2, */pos2);
    }
  }
  return g;
}

eval_t Mtdf::last3_search(const Board& board,
                          eval_t alpha, eval_t beta,
                          bool passed)
{
  BitBoard::data_type rest = board.get_blank_bit();
  BitBoard::data_type move1 = rest.get_next_bit();
  rest ^= move1;
  BitBoard::data_type move2 = rest.get_next_bit();
  rest ^= move2;
  BitBoard::data_type move3 = rest;
  unsigned pos1 = move1.get_next();
  unsigned pos2 = move2.get_next();
  unsigned pos3 = move3.get_next();

  int diff = get_difference(board, 3);
  return last3_search(board, alpha, beta, passed, diff, pos1, pos2, pos3);
}

eval_t Mtdf::last3_search(const Board& board,
                          eval_t alpha, eval_t beta, bool passed,
                          int diff,
                          unsigned pos1,
                          unsigned pos2,
                          unsigned pos3)
{
  if (diff != board.get_score()) {
    std::stringstream ss;
    ss << "last3: " << diff << " " << board.get_score();
    throw std::runtime_error(ss.str());
  }

  int delta;
  
  eval_t g = -INFINITY_VALUE;

  count_node();

  BitBoard new_board(board);
  delta = new_board.try_move(/*move1, */pos1);
  if (delta != 0) {
    new_board.inverse();
    g = -last2_search(new_board, -beta, -alpha, false,
                      -(diff + delta * 2048 + 1024),
                      /*move2, */pos2,
                      /*move3, */pos3);

    if (beta <= g)
      return g;
    alpha = std::max(alpha, g);
    new_board = board;
  }
  delta = new_board.try_move(/*move2, */pos2);
  if (delta != 0) {
    new_board.inverse();
    g = std::max(g, -last2_search(new_board, -beta, -alpha, false,
                                  -(diff + delta * 2048 + 1024),
                                  /*move1, */pos1,
                                  /*move3, */pos3));
    if (beta <= g)
      return g;
    alpha = std::max(alpha, g);
    new_board = board;
  }
  delta = new_board.try_move(/*move3, */pos3);
  if (delta != 0) {
    new_board.inverse();
    g = std::max(g, -last2_search(new_board, -beta, -alpha, false,
                                  -(diff + delta * 2048 + 1024),
                                  /*move1, */pos1,
                                  /*move2, */pos2));
    return g;
  }

  if (g == -INFINITY_VALUE) {
    if (passed) {
      //return get_difference(board, 2);
      count_leaf();
      return diff;
    } else {
      new_board.inverse();
      return -last3_search(new_board,
                           -beta, -alpha, true);
    }
  }
  return g;
}

eval_t Mtdf::last4_search(const Board& board,
                          eval_t alpha, eval_t beta,
                          bool passed)
{
  BitBoard::data_type rest = board.get_blank_bit();
  BitBoard::data_type move1 = rest.get_next_bit();
  rest ^= move1;
  BitBoard::data_type move2 = rest.get_next_bit();
  rest ^= move2;
  BitBoard::data_type move3 = rest.get_next_bit();
  rest ^= move3;
  BitBoard::data_type move4 = rest;
  unsigned pos1 = move1.get_next();
  unsigned pos2 = move2.get_next();
  unsigned pos3 = move3.get_next();
  unsigned pos4 = move4.get_next();

  int diff = get_difference(board, 4);
  int delta;
  
  eval_t g = -INFINITY_VALUE;

  count_node();

  BitBoard new_board(board);
  delta = new_board.try_move(pos1);
  if (delta != 0) {
    new_board.inverse();
    g = -last3_search(new_board, -beta, -alpha, false,
                      -(diff + delta * 2048 + 1024),
                      pos2, pos3, pos4);

    if (beta <= g)
      return g;
    alpha = std::max(alpha, g);
    new_board = board;
  }
  delta = new_board.try_move(pos2);
  if (delta != 0) {
    new_board.inverse();
    g = std::max(g, -last3_search(new_board, -beta, -alpha, false,
                                  -(diff + delta * 2048 + 1024),
                                  pos1, pos3, pos4));
    if (beta <= g)
      return g;
    alpha = std::max(alpha, g);
    new_board = board;
  }
  delta = new_board.try_move(pos3);
  if (delta != 0) {
    new_board.inverse();
    g = std::max(g, -last3_search(new_board, -beta, -alpha, false,
                                  -(diff + delta * 2048 + 1024),
                                  pos1, pos2, pos4));
    if (beta <= g)
      return g;
    alpha = std::max(alpha, g);
    new_board = board;
  }
  delta = new_board.try_move(pos4);
  if (delta != 0) {
    new_board.inverse();
    g = std::max(g, -last3_search(new_board, -beta, -alpha, false,
                                  -(diff + delta * 2048 + 1024),
                                  pos1, pos2, pos3));
    return g;
  }

  if (g == -INFINITY_VALUE) {
    if (passed) {
      //return get_difference(board, 2);
      count_leaf();
      return diff;
    } else {
      new_board.inverse();
      return -last4_search(new_board,
                           -beta, -alpha, true);
    }
  }
  return g;
}

}  // namespace oxelon
