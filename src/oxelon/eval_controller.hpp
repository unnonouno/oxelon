#ifndef EVAL_CONTROLLER_HPP_E4C7888D_72BE_4F13_9FB6_D5F5E91B7BA7_
#define EVAL_CONTROLLER_HPP_E4C7888D_72BE_4F13_9FB6_D5F5E91B7BA7_

#include <vector>
#include "board.hpp"
#include "evaluator.hpp"
#include "types.hpp"

namespace oxelon {

template <typename B>
class EvalController : public Evaluator<B> {
public:
  const static unsigned SEGMENT_MAX = 15;

  EvalController();

  void add_evaluator(typename Evaluator<B>::Ptr eval);

  void read(std::istream& in);

  void write(std::ostream& out) const;

  eval_t evaluate(const B& board, Disc disc) const;

  void update(const B& board, Disc disc, eval_t prediction, int beta, int n_sample);

  void swap();

  std::vector<eval_t> get_value_vec(const B& board, Disc disc) const;

  void smoothe(const B& board, Disc disc, int beta, int n_sample);

private:
  eval_t evaluate_segment(const B& board, Disc disc, int segment) const;

  void swap_segment(size_t);
  typedef std::vector<typename Evaluator<B>::Ptr> EvaluatorSet;
  std::vector<EvaluatorSet> evaluators_;
  std::vector<int> update_count_;

  static const std::vector<int> SWAP_COUNT;
};

////////////////////////////////////////////////////////////////////////////////
// inline method
////////////////////////////////////////////////////////////////////////////////

template<typename B>
EvalController<B>::EvalController()
    : evaluators_(SEGMENT_MAX),
      update_count_(SEGMENT_MAX) {}

  //template <typename B>
//const boost::array<int, EvalController<Board>::SEGMENT_MAX>
//EvalController<Board>::SWAP_COUNT
//= { 1000, 900, 800, 700, 500, 200, 100, 50, 30, 20, 10, 8, 6, 4, 2 };
//= { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
/*void EvalController::read_csv(std::istream& in,
                             const PatternMask& pat,
                             const std::vector<int>& weights)
{
  using namespace boost;
  
  unsigned int pat_max = pat.pattern_size();
  
  for (int seg = 0; seg < SEGMENT_MAX; seg++) {
//    std::string line;
    //getline(in, line);
    //char_separator <char> sep(",");
    //tokenizer<char_separator<char> > tokens(line, sep);
    
    std::vector<eval_t>
      nwin(pat_max), nlose(pat_max), ndraw(pat_max);
    
    long n_sample = 0;
    //tokenizer<char_separator<char> >::iterator
    //  it = tokens.begin(), end = tokens.end();
    for (unsigned int pat_code = 0; pat_code < pat_max; ++pat_code) {
      in >> nwin[pat_code] >> nlose[pat_code] >> ndraw[pat_code];
//      nwin[pat_code] = lexical_cast<eval_t>(*it);
//      ++it;
//      nlose[pat_code] = lexical_cast<eval_t>(*it);
//      ++it;
//      ndraw[pat_code] = lexical_cast<eval_t>(*it);
//      ++it;
      n_sample += nwin[pat_code] + nlose[pat_code] + ndraw[pat_code];
    }

    long total_cor = n_sample / pat_max + 1;
    std::vector<eval_t> value(pat_max);
    for (unsigned int pat_code = 0; pat_code < pat_max; ++pat_code) {
      value[pat_code]
        = (nwin[pat_code] - nlose[pat_code])
          * weights[seg] * 1000
          / (nwin[pat_code] + nlose[pat_code] + ndraw[pat_code] + total_cor);
    }
    
    evaluators_[seg].add_pattern(pat, value);
  }
}
*/
/*
void EvalController::read(std::istream& in,
                         const PatternMask& pat)
{
  for (int seg = 0; seg < SEGMENT_MAX; seg++) {
    PatternEvaluator eval(pat);
    eval.read(in);
    evaluators_[seg].push_back(eval);
  }
}
 */

template <typename B>
void
EvalController<B>::read(std::istream& in) {
  for (unsigned seg = 0; seg < SEGMENT_MAX; seg++) {
    for (typename EvaluatorSet::iterator it = evaluators_[seg].begin(),
             end = evaluators_[seg].end(); it != end; ++it) {
      (*it)->read(in);
    }
  }
}

template <typename B>
void
EvalController<B>::write(std::ostream& out) const
{
  for (unsigned seg = 0; seg < SEGMENT_MAX; seg++) {
    for (typename EvaluatorSet::const_iterator it = evaluators_[seg].begin(),
             end = evaluators_[seg].end(); it != end; ++it) {
      (*it)->write(out);
    }
    out << std::endl;
  }
}

template <typename B>
eval_t
EvalController<B>::evaluate(const B& board, Disc disc) const
{
  int count = B::COUNT_MAX - board.count_disc(BLANK);
  unsigned seg = count * SEGMENT_MAX / B::COUNT_MAX;

  if (seg == SEGMENT_MAX)
    return (board.count_disc(disc) - board.count_disc((Disc)-disc)) * 1024;
  else
    return evaluate_segment(board, disc, seg);
}

template <typename B>
void
EvalController<B>::update(const B& board,
                         Disc disc,
                         eval_t error,
                         int beta,
                         int n_sample)
{
  size_t count = B::COUNT_MAX - board.count_disc(BLANK);
  size_t seg = count * SEGMENT_MAX / B::COUNT_MAX;
  if (seg == SEGMENT_MAX)
    return;
  for (typename EvaluatorSet::iterator it = evaluators_[seg].begin(),
           end = evaluators_[seg].end(); it != end; ++it) {
    (*it)->update(board, disc, error, beta, n_sample/* * SWAP_COUNT[seg]*/);
  }

  
//  eval_t diff = evaluate(board, disc) + error;
  
/*  if (seg > 0) {
    eval_t prediction = evaluate_segment(board, disc, seg - 1);
    FOR_EACH (EvaluatorSet, it, evaluators_[seg])
      (*it)->update(board, disc, diff - prediction, beta, n_sample * SWAP_COUNT[seg]*4);
  }
  if (seg < SEGMENT_MAX - 1) {
    eval_t prediction = evaluate_segment(board, disc, seg + 1);
    FOR_EACH (EvaluatorSet, it, evaluators_[seg])
      (*it)->update(board, disc, diff - prediction, beta, n_sample * SWAP_COUNT[seg]*4);
  }*/
  /*
  if (seg > 1) {
    eval_t prediction = evaluate_segment(board, disc, seg - 2);
    FOR_EACH (EvaluatorSet, it, evaluators_[seg])
      (*it)->update(board, disc, diff - prediction, beta / 8, n_sample * SWAP_COUNT[seg]);
  }
  if (seg < SEGMENT_MAX - 2) {
    eval_t prediction = evaluate_segment(board, disc, seg + 2);
    FOR_EACH (EvaluatorSet, it, evaluators_[seg])
      (*it)->update(board, disc, diff - prediction, beta / 8, n_sample * SWAP_COUNT[seg]);
  }
   */
//#ifdef SEGMENT_LEARNING
    
  update_count_[seg] += 1;
/*  if (update_count_[seg] >= SWAP_COUNT[seg]) {
    swap_segment(seg);
    update_count_[seg] = 0;
  }
*/
//#endif
}

template <typename B>
void
EvalController<B>::swap_segment(size_t seg)
{
  for (typename EvaluatorSet::iterator it = evaluators_[seg].begin(),
           end = evaluators_[seg].end(); it != end; ++it) {
    (*it)->swap();
  }
}

template <typename B>
void
EvalController<B>::swap()
{
  for (size_t seg = 0; seg < SEGMENT_MAX; seg++) {
    for (typename EvaluatorSet::iterator it = evaluators_[seg].begin(),
             end = evaluators_[seg].end(); it != end; ++it) {
      (*it)->swap();
    }
  }
}

template <typename B>
void
EvalController<B>::smoothe(const B& board, Disc disc, int beta, int n_sample)
{
#ifdef BLACK_EVAL
  // smoothe BLACK value and WHITE value.
  if (board.blank() > 50)
    return;
  B rev_board = board.make_reverse_board();
  
  eval_t value = evaluate(board, disc);
  eval_t rev_value = evaluate(rev_board, -disc);
  eval_t average = (value + rev_value) / 2;

  // use average value
  update(board, disc, (value - average)/3, beta, n_sample);
  update(rev_board, disc, (rev_value - average)/3, beta, n_sample);

#else
  if (board.count_disc(BLANK) > 54)
    return;
  eval_t value = evaluate(board, disc);
  eval_t rev_value = -evaluate(board, -disc);
  eval_t average = (value + rev_value) / 2;

  // use average value
  update(board, disc, (value - average), beta, 1000);
  update(board, -disc, (-rev_value + average), beta, 1000);
#endif
}

template <typename B>
eval_t
EvalController<B>::evaluate_segment(const B& board, Disc disc, int segment) const {
  eval_t ret = eval_t();
  //FOR_EACH_CONST (EvaluatorSet, it, evaluators_[segment]) {
  for (size_t i = 0, size = evaluators_[segment].size(); i < size; i++) {
    //eval_t eval = (*it)->evaluate(board, disc);
    eval_t eval = evaluators_[segment][i]->evaluate(board, disc);
    // 存在しないとき
    if (eval == 0) {
      if (segment == 0) {
        eval = 2 * evaluators_[segment+1][i]->evaluate(board, disc)
            - evaluators_[segment+2][i]->evaluate(board, disc);
      } else if (segment == SEGMENT_MAX-1) {
        eval = 2 * evaluators_[segment-1][i]->evaluate(board, disc)
            - evaluators_[segment-2][i]->evaluate(board, disc);
      } else {
        eval = (evaluators_[segment-1][i]->evaluate(board, disc)
                + evaluators_[segment+1][i]->evaluate(board, disc))/2;
      }
    }
    ret += eval;
  }
  return ret;
}
  
/*
void EvalController::add_pattern(const PatternMask& pat)
{
  for (int seg = 0; seg < SEGMENT_MAX; seg++)
    evaluators_[seg].push_back(PatternEvaluator(pat));
}
*/
/*
template<typename T>
void EvalController::add_evaluator(const T& eval)
{
  for (int seg = 0; seg < SEGMENT_MAX; seg++)
    evaluators_[seg].push_back(new T(eval));
}
*/

template <typename B>
std::vector<eval_t>
EvalController<B>::get_value_vec(const B& board, Disc disc) const
{ 
  int count = Board::COUNT_MAX - board.count_disc(BLANK);
  int seg = count * SEGMENT_MAX / Board::COUNT_MAX;
  
  std::vector<eval_t> ret;
  for (typename EvaluatorSet::const_iterator it = evaluators_[seg].begin(),
           end = evaluators_[seg].end(); it != end; ++it) {
    ret.push_back( (*it)->evaluate(board, disc) );
  }
  return ret;
}

template<typename B>
void EvalController<B>::add_evaluator(typename Evaluator<B>::Ptr eval) {
  for (unsigned seg = 0; seg < SEGMENT_MAX; seg++) {
    evaluators_[seg].push_back(eval);
  }
}

}  // namespace oxelon

#endif // EVAL_CONTROLLER_HPP_E4C7888D_72BE_4F13_9FB6_D5F5E91B7BA7_
