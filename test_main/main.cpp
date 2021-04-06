// -*- C++ -*-
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy Basak on 06/04/21.
//

#include "FrameWork.h"

#include <cassert>

using std::cout;
using std::endl;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
// main()
int main(const int argc, const char **argv) {
  cout << "Program main start" << endl;
  cout << "==================" << endl;

#ifdef DEBUG
  cout << "\n...... Debug build ......\n\n";
#endif

  // ProcessArguments(argc, argv);

  assert(FrameWork::CheckFrameWorkBuild());

  cout << endl << "Program main end" << endl;

  return 0;
}
#pragma GCC diagnostic pop
