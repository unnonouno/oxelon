#include <iostream>
#include <fstream>

#include "../third_party/cmdline.h"

#include "../oxelon/timer.hpp"
#include "../oxelon/types.hpp"
#include "../oxelon/evaluator.hpp"
#include "../oxelon/mtdf.hpp"
#include "../oxelon/nega_scout.hpp"
#include "../oxelon/eval_controller.hpp"
//#include "../oxelon/pattern_evaluator.hpp"
#include "../oxelon/fixed_pattern_evaluator.hpp"
//#include "../oxelon/pattern.h"
#include "../oxelon/position.hpp"
#include "../oxelon/board.hpp"
//#include "../game/negamax.h"

using std::string;

namespace oxelon {

Board read_board(std::istream& in) {
  Disc discs[64];
  for (int i = 0; i < 64; i++) {
    char c;
    in >> c;
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
        // TODO: throw exception
        break;
    }
  }
  return Board(discs);
}

Disc read_move(std::istream& in) {
  Disc move = WHITE;
  char c;
  in >> c;
  switch (c) {
    case 'X':
      move = BLACK;
      break;
    case 'O':
      move = WHITE;
      break;
    default:
      // TODO: throw exception
      break;
  }
  return move;
}

std::auto_ptr<Evaluator<Board> >
select_evaluator(const std::string& datadir) {
/*
  const char* pat_file[] = {
    "diag4", "diag5", "diag6", "diag7", "diag8", "hor2", "hor3", "hor4",
    "edge2x", "corner2x5", "corner3x3"
  };

  const bool sym[][3] = {
    {true, true, false},
    {true, true, false},
    {true, true, false},
    {true, true, false},
    {true, false, false},
    {false, true, true},
    {false, true, true},
    {false, true, true},
    {false, true, true},
    {true, true, true},
    {true, true, false}
  };
 */
  std::auto_ptr<EvalController<Board> > eval(new EvalController<Board>());
    /*
       for (int i = 0; i < 11; i++) {
       std::ifstream pat_in((datadir + pat_file[i] + ".pat").c_str());
       PatternMask pat;
       pat_in >> pat;

       eval.add_evaluator(PatternEvaluator(pat, sym[i][0], sym[i][1], sym[i][2]));
       }
     */
  eval->add_evaluator(Evaluator<Board>::Ptr(new FixedPatternEvaluator()));
//  eval.add_evaluator(ParityEvaluator());
//  eval.add_evaluator(PotentialMovilityEvaluator());
  std::ifstream win((datadir + "/weight.patonly.rl").c_str(),
                    std::ios::binary);
  if (!win) {
    std::cerr << "error" << std::endl;
    //return -1;
    throw std::string("error");
  }

  eval->read(win);
  win.close();
  return std::auto_ptr<Evaluator<Board> >(eval);
}

std::auto_ptr<Solver> select_solver(
    const std::string& method,
    std::auto_ptr<Evaluator<Board> > e,
    int depth) {
  std::cout << "Search algorithm: ";
  if (method == "mtdf") {
    std::cout << "MTD(f)" << std::endl;
    return std::auto_ptr<Solver>(new Mtdf(e, depth, 22));
  } else if (method == "negascout") {
    std::cout << "NegaScout" << std::endl;
    return std::auto_ptr<Solver>(new NegaScout(e, depth));
  } else {
    std::cout << "MTD(f): defalut" << std::endl;
    return std::auto_ptr<Solver>(new Mtdf(e, depth, 22));
  }
}

void solve(std::auto_ptr<Solver> solver, Board board, Disc next_move) {
  std::cout << "Start to solve" << std::endl;
  std::cout << " disc: " << next_move << std::endl;
  oxelon::Timer t;
  solver->search_next(board, next_move);
  std::cout << t.elapsed() << "sec" << std::endl;
    /*
       solver->set_max_depth(10);
       t.restart();
       solver->search_next(board, next_move);
       std::cout << t.elapsed() << "sec" << std::endl;
     */
    //  solver->set_max_depth(14);
    //solver->search_next(board, next_move);
//  solver->set_max_depth(16);
//  solver->search_next(board, next_move);
    //  solver->search_next(board, next_move);
//  solver->set_max_depth(20);
//  solver->search_next(board, next_move);
//  for (int i = 20; i <= 20; i++) {
    //Mtdf<EndEvaluator> solver(EndEvaluator(), 20);
    //NegaMax<EvalControler> solver(eval, i);
    //solver->search_next(board, next_move);
    solver->set_max_depth(64);

    t.restart();
    std::pair<Position, eval_t> result =
        solver->search_next(board, next_move);
    double sec = t.elapsed();
    int nodes = solver->get_total_node();
    double nps = nodes / sec / 1000;
    int leaves = solver->get_total_leaf();
    double lps = leaves / sec / 1000;
    std::cout << sec << "sec ";
    std::cout << result.first.to_str()
              << " Score:" << result.second / 1024
              << " Node:" << nodes << "(" << nps << " Knps)"
              << " Leaf:" << leaves << "(" << lps << "Klps)" << std::endl;
//  }

}

}

int main(int argc, char *argv[]) try{
  cmdline::parser p;
  p.add<string>("method", 'm', "search method", false, "mtdf",
                cmdline::oneof<string>("mtdf", "negascout"));
  p.add<int>("depth", 'd', "set max search depth", false, 10);
  p.add<string>("input", 'i', "set initial board file");
  p.add<string>("data", '\0', "set data directory", false, "data");
  p.add("version", 'v', "show version");

  p.parse_check(argc, argv);

  oxelon::Board board;
  oxelon::Disc next_move;
  if (p.exist("input")) {
    std::string filename = p.get<string>("input");
    std::ifstream in(filename.c_str());
    if (!in) {
      std::cerr << "cannot open initial board: " << filename << std::endl;
      return 1;
    }
    board = oxelon::read_board(in);
    next_move = oxelon::read_move(in);
    in.close();
  } else {
    board = oxelon::read_board(std::cin);
    next_move = oxelon::read_move(std::cin);
  }
    
  std::auto_ptr<oxelon::Evaluator<oxelon::Board> > e
      = oxelon::select_evaluator(p.get<string>("data"));
  int depth = p.get<int>("depth");
  std::auto_ptr<oxelon::Solver> solver
      = oxelon::select_solver(p.get<string>("method"), e, depth);

  solve(solver, board, next_move);
  
} catch(std::exception &e) {
  std::cerr << "error: " << e.what() << std::endl;
  return -1;
} catch(...) {
  std::cerr << "unknown exception" << std::endl;
  return -1;
}
