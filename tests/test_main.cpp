// -*- C++ -*-
//
// WARRANTY:
// Use all material in this file at your own risk.
//
// Created by Hiranmoy Basak on 06/04/21.
//

#define CATCH_CONFIG_MAIN

#include "FrameWork.h"
#include <catch2/catch.hpp>

using std::cout;
using std::endl;

TEST_CASE("CheckBuild", "[basic]") {

  cout << "init test start" << endl;
  cout << "===============" << endl;

#ifdef DEBUG
  cout << "\n...... Debug build ......\n\n";
#endif

  // ProcessArguments(argc, argv);

  REQUIRE(FrameWork::CheckFrameWorkBuild());

  cout << "init test end" << endl;
}
