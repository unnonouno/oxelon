#ifndef NEGAMAX_HPP_39DE9B8D_0F71_4C7A_B40F_375BC4841EE0_
#define NEGAMAX_HPP_39DE9B8D_0F71_4C7A_B40F_375BC4841EE0_

#include <utility>

namespace oxelon {

typedef std::pair<Board, Disc> Key;
  
template<class E>
class NegaMax : public Solver {
public:
  NegaMax(const E& eval, int max)
       : evaluator_(eval), max_depth_(max), total_node_(0), total_leaf_(0),
         trans_table_(1000000)
  {}
  
  void set_max_depth(int max) const { max_depth_ = max; }
  int get_total_node() const { return total_node_; }
  int get_total_leaf() const { return total_leaf_; }

  eval_t evaluate(const Board& board, Disc disc) const
    {
      leaf_count_ = 0;
      cut_count_ = 0;
      node_count_ = 0;
      hit_count_ = 0;
      trans_table_.clear();
      eval_t ret = iter_evaluate(board, max_depth_, -10000000, 10000001, disc);
      std::cerr << next_move_.to_str()
        << "V:" << ret
        << " n" << node_count_
        << ",l" << leaf_count_
        << ",h" << hit_count_
        <<",c" << cut_count_
        << std::endl;
//      std::cerr << search_count_ << "(" << hit_count_ << ", "
//        << trans_table_.size() << ")" << std::endl;
      return ret;
    }

  void read(std::istream& in) { evaluator_.read(in); }
  void write(std::ostream& out) const { evaluator_.write(out); }
  void update(const Board& board, Disc disc, eval_t error, int beta, int n_sample) {
    Board next = board;
    next.move(search_next(board, disc), disc);
    evaluator_.update(next, (Disc)-disc, error, beta, n_sample);
  }
  void swap() {}

  std::pair<Position, eval_t> search_next(const Board& board, Disc disc) const {
    std::pair<Position, eval_t> res;
    res.second = evaluate(board, disc);
    res.first = next_move_;
    return res;
  }

private:
  eval_t iter_evaluate(const Board& board,
                       int depth,
                       eval_t alpha,
                       eval_t beta,
                       Disc disc) const
    {
      
#ifdef WITH_HASH
      Key key(board, disc);
      TranspositionTable::iterator nit
        = trans_table_.find(key);
      
      bool found = false;
      if (nit != trans_table_.end()) {
        hit_count_++;
        found = true;
        return nit->second;
      }
#endif

      eval_t ret;
      if (board.count_disc(BLANK) == 0) {
        leaf_count_++;
        total_leaf_++;
        g = (static_cast<eval_t>(key.first.count_disc(key.second))
             - static_cast<eval_t>(key.first.count_disc(-key.second))) * 1024;
      } else if (depth == 0) {
        leaf_count_++;
        total_leaf_++;
        ret = evaluator_.evaluate(board, disc);
        
      } else {
        node_count_++;
        total_node_++;
        
        eval_t a = alpha;
        std::vector<Position> mov_pos = board.get_move_position(disc);
        if (mov_pos.size() == 0) {
          ret = -iter_evaluate(board, depth - 1, -beta, -alpha, (Disc)-disc);

          if (depth == max_depth_)
            next_move_ = Position::POS_PASS;
        } else {
          
          if (depth > 1) {
            typedef std::multimap<eval_t, std::pair<Board, Position> >
              ValBoardMap;
            ValBoardMap sorted_next;
            FOR_EACH_CONST (std::vector<Position>, it, mov_pos) {
              Board next_board = board;
              next_board.move(*it, disc);
              sorted_next.insert(ValBoardMap::value_type(
                //evaluator_.evaluate(next_board, (Disc)-disc),
                next_board.get_about_movility(-disc),
                std::pair<Board, Position>(next_board, *it)));
            }
            
            for (ValBoardMap::const_iterator it = sorted_next.begin(),
                 end = sorted_next.end(); it != end; ++it) {
              eval_t t = -iter_evaluate(it->second.first, depth - 1, -beta, -a,
                                        (Disc)-disc);
              if (a < t) {
                a = t;
                if (depth == max_depth_)
                  next_move_ = it->second.second;
              }
              if (a >= beta) {
                cut_count_++;
                break;
              }
            }
            
          } else {
            for (std::vector<Position>::const_iterator it = mov_pos.begin();
                 it != mov_pos.end(); ++it) {
              Board next_board(board);
              next_board.move(*it, disc);
              eval_t t = -iter_evaluate(next_board, depth - 1, -beta, -a,
                                        (Disc)-disc);
              if (a < t) {
                a = t;
                if (depth == max_depth_)
                  next_move_ = *it;
              }
              if (a >= beta) {
                cut_count_++;
                break;
              }
            }
          }
          
          ret = a;
        }
      }
      
#ifdef WITH_HASH
      if (trans_table_.size() < 2000000) {
        eval_t& new_n = found ? nit->second : trans_table_[key];
        new_n = ret;
      }
#endif

      return ret;
    }

  E evaluator_;
  mutable int max_depth_;
  mutable Position next_move_;
  mutable int cut_count_;
  mutable int node_count_;
  mutable int leaf_count_;
  mutable int hit_count_;

  mutable int total_node_;
  mutable int total_leaf_;

  struct Hash {
    operator()(const Key& key) const {
      return key.first.hash();
    }
  };
  typedef std::hash_map<Key, eval_t, Hash> TranspositionTable;
  mutable TranspositionTable trans_table_;


}  // namespace oxelon

#endif // NEGAMAX_HPP_39DE9B8D_0F71_4C7A_B40F_375BC4841EE0_
