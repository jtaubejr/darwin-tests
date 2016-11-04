// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"
#include <string>

#include "Darwin.h"

using namespace std;

// ----
// test
// ----

TEST(SpeciesFixture, test) {
  Species x('x');
  ASSERT_TRUE(x.dummy());
}

TEST(AddCreatureFixture, test1) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test2) {
  std::string s = "Turn = 0.\n  0123\n0 ff..\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(0, 1, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test3) {
  std::string s = "Turn = 0.\n  0123\n0 f.f.\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(0, 2, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test4) {
  std::string s = "Turn = 0.\n  0123\n0 f..f\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(0, 3, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test5) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 f...\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(1, 0, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test6) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 .f..\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(1, 1, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test7) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ..f.\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(1, 2, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test8) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ...f\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(1, 3, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test9) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 f...\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(2, 0, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test10) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 .f..\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(2, 1, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test11) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 f...\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(1, 0, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test12) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 f...\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(2, 0, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test13) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 ....\n3 f...\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(3, 0, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test14) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 ..f.\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(2, 2, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddCreatureFixture, test15) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ..f.\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature f2(1, 2, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(f2);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test1) {
  std::string s = "Turn = 1.\n  0123\n0 f.h.\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(0, 1, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test2) {
  std::string s = "Turn = 1.\n  0123\n0 f..h\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(0, 2, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test3) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 .h..\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(1, 0, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test4) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ..h.\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(1, 1, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test5) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ...h\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(1, 2, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test6) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 .h..\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(2, 0, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test7) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 ..h.\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(2, 1, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test8) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 ...h\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(2, 2, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test9) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 ....\n3 .h..\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(3, 0, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test10) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 ....\n3 ..h.\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(3, 1, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopFixture, test11) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 ....\n3 ...h\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(3, 2, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopperConflictFixture, test1) {
  std::string s = "Turn = 1.\n  0123\n0 fhh.\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(0, 1, east, hopper);
  Creature h2(0, 2, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);
  x1.addCreature(h2);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopperConflictFixture, test2) {
  std::string s = "Turn = 2.\n  0123\n0 f.hh\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(0, 1, east, hopper);
  Creature h2(0, 3, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);
  x1.addCreature(h2);

  x1.oneTurn();
  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopperConflictFixture, test3) {
  std::string s = "Turn = 2.\n  0123\n0 f...\n1 .hh.\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(1, 3, west, hopper);
  Creature h2(1, 0, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);
  x1.addCreature(h2);

  x1.oneTurn();
  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopperConflictFixture, test4) {
  std::string s = "Turn = 2.\n  0123\n0 f...\n1 ....\n2 .hh.\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(2, 3, west, hopper);
  Creature h2(2, 0, east, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);
  x1.addCreature(h2);

  x1.oneTurn();
  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test1) {
  std::string s = "Turn = 0.\n  0123\n0 ft..\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(0, 1, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test2) {
  std::string s = "Turn = 0.\n  0123\n0 f.t.\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(0, 2, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test3) {
  std::string s = "Turn = 0.\n  0123\n0 f..t\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(0, 3, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test4) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 t...\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(1, 0, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test5) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 .t..\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(1, 1, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test6) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ..t.\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(1, 2, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test7) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ...t\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(1, 3, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test8) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 t...\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(2, 0, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test9) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 .t..\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(2, 1, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test10) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 ..t.\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(2, 2, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test11) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 ...t\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(2, 3, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test12) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 ....\n3 t...\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(3, 0, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test13) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 ....\n3 .t..\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(3, 1, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test14) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 ....\n3 ..t.\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(3, 2, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(AddDiffCreatureFixture, test15) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 ....\n3 ...t\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species trap('t');
  trap.addControlInstruction("if_enemy", 3);
  trap.addActionInstruction("left");
  trap.addControlInstruction("go", 0);
  trap.addActionInstruction("infect");
  trap.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature t1(3, 3, east, trap);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(t1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test1) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 ....\n3 ..h.\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(3, 3, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test2) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 ....\n3 .h..\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(3, 2, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test3) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 ....\n3 h...\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(3, 1, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test4) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 ..h.\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(2, 3, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test5) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 .h..\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(2, 2, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test6) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ....\n2 h...\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(2, 1, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test7) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 ..h.\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(1, 3, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test8) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 .h..\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(1, 2, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test9) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 h...\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(1, 1, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test10) {
  std::string s = "Turn = 1.\n  0123\n0 f.h.\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(0, 3, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(HopBotFixture, test11) {
  std::string s = "Turn = 1.\n  0123\n0 fh..\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(0, 2, west, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test1) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 ....\n2 ....\n3 ...f\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(3, 3, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test2) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 ....\n2 ....\n3 ..f.\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(3, 2, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test3) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 ....\n2 ....\n3 .f..\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(3, 1, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test4) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 ....\n2 ....\n3 f...\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(3, 0, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test5) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 ....\n2 ...f\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(2, 3, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test6) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 ....\n2 ..f.\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(2, 2, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test7) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 ....\n2 .f..\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(2, 1, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test8) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 ....\n2 f...\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(2, 0, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test9) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 ...f\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(1, 3, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test10) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 ..f.\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(1, 2, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test11) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 .f..\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(1, 1, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test12) {
  std::string s = "Turn = 0.\n  0123\n0 ....\n1 f...\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(1, 0, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test13) {
  std::string s = "Turn = 0.\n  0123\n0 ...f\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 3, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test14) {
  std::string s = "Turn = 0.\n  0123\n0 ..f.\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 2, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test15) {
  std::string s = "Turn = 0.\n  0123\n0 .f..\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 1, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(DiffCreatureFixture, test16) {
  std::string s = "Turn = 0.\n  0123\n0 f...\n1 ....\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);

  Darwin<4, 4> x1;
  x1.addCreature(f1);

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(MultiHopBotFixture, test1) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 .h..\n2 ...h\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(1, 2, west, hopper);
  Creature h2(3, 3, north, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);
  x1.addCreature(h2);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}

TEST(MultiHopBotFixture, test2) {
  std::string s = "Turn = 1.\n  0123\n0 f...\n1 .h.h\n2 ....\n3 ....\n\n";

  Species food('f');
  food.addActionInstruction("left");
  food.addControlInstruction("go", 0);

  Species hopper('h');
  hopper.addActionInstruction("hop");
  hopper.addControlInstruction("go", 0);

  Creature f1(0, 0, east, food);
  Creature h1(1, 2, west, hopper);
  Creature h2(2, 3, north, hopper);

  Darwin<4, 4> x1;
  x1.addCreature(f1);
  x1.addCreature(h1);
  x1.addCreature(h2);

  x1.oneTurn();

  if (x1.printGrid() == s) {
    ASSERT_TRUE(1);
  } else {
    ASSERT_TRUE(0);
  }
}
