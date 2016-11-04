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

#include "Darwin.h"

using namespace std;

// ----
// test
// ----

// Simple Tests
TEST(Specie, test00) {
  bool exceptioned = false;
  try {
    Darwin x(72, 72);
  } catch (...) {
    exceptioned = true;
  }
  ASSERT_FALSE(exceptioned);
}

TEST(Specie, test01) {
  bool exceptioned = false;
  try {
    Specie s('s');
  } catch (...) {
    exceptioned = true;
  }
  ASSERT_FALSE(exceptioned);
}

TEST(Specie, test02) {
  bool exceptioned = false;
  try {
    Specie s('s');
    Creature c(s);
  } catch (...) {
    exceptioned = true;
  }
  ASSERT_FALSE(exceptioned);
}

// Test Specie constructor AND operator<<
TEST(Specie, test1) {
  std::stringstream actual;
  Specie s('s');
  actual << s;
  ASSERT_EQ("s", actual.str());
}

TEST(Specie, test2) {
  std::stringstream actual;
  Specie s('h');
  actual << s;
  ASSERT_EQ("h", actual.str());
}

TEST(Specie, test3) {
  std::stringstream actual;
  Specie s('j');
  actual << s;
  ASSERT_EQ("j", actual.str());
}

TEST(Specie, test4) {
  std::stringstream out_s, out_t;
  Specie s('j');
  Specie t('j');
  out_s << s;
  out_t << t;
  ASSERT_EQ(out_s.str(), out_t.str());
}

TEST(Specie, test5) {
  std::stringstream actual;
  Specie h('h');
  Specie e('e');
  Specie l('l');
  Specie l2('l');
  Specie o('o');
  actual << h << e << l << l2 << o;
  ASSERT_EQ("hello", actual.str());
}

TEST(Specie, test6) {
  std::stringstream out_s;
  Specie s(' ');
  Specie t('s');
  out_s << s << t;
  ASSERT_EQ(" s", out_s.str());
}

// Test Specie's addInstruciton(enum Instruction action) AND currentInstruction
TEST(Specie, test7) {
  Specie s('s');
  s.addInstruction(do_hop);
  s.addInstruction(do_left);
  s.addInstruction(do_right);
  s.addInstruction(do_infect);
  ASSERT_EQ(get<0>(s.currentInstruction(0)), do_hop);
  ASSERT_EQ(get<0>(s.currentInstruction(1)), do_left);
  ASSERT_EQ(get<0>(s.currentInstruction(2)), do_right);
  ASSERT_EQ(get<0>(s.currentInstruction(3)), do_infect);
}

// add 10 instruction and check
TEST(Specie, test8) {
  Specie s('s');

  for (int i = 0; i < 10; ++i) {
    if (i % 4 == 0)
      s.addInstruction(do_hop);
    else if (i % 4 == 1)
      s.addInstruction(do_left);
    else if (i % 4 == 2)
      s.addInstruction(do_right);
    else if (i % 4 == 3)
      s.addInstruction(do_infect);
  }

  for (int i = 0; i < 10; i++) {
    if (i % 4 == 0)
      ASSERT_EQ(get<0>(s.currentInstruction(i)), do_hop);
    else if (i % 4 == 1)
      ASSERT_EQ(get<0>(s.currentInstruction(i)), do_left);
    else if (i % 4 == 2)
      ASSERT_EQ(get<0>(s.currentInstruction(i)), do_right);
    else if (i % 4 == 3)
      ASSERT_EQ(get<0>(s.currentInstruction(i)), do_infect);
  }
}

// add 100 instruction and check
TEST(Specie, test9) {
  Specie s('s');

  for (int i = 0; i < 100; ++i) {
    if (i % 4 == 0)
      s.addInstruction(do_hop);
    else if (i % 4 == 1)
      s.addInstruction(do_left);
    else if (i % 4 == 2)
      s.addInstruction(do_right);
    else if (i % 4 == 3)
      s.addInstruction(do_infect);
  }

  for (int i = 0; i < 100; ++i) {
    if (i % 4 == 0)
      ASSERT_EQ(get<0>(s.currentInstruction(i)), do_hop);
    else if (i % 4 == 1)
      ASSERT_EQ(get<0>(s.currentInstruction(i)), do_left);
    else if (i % 4 == 2)
      ASSERT_EQ(get<0>(s.currentInstruction(i)), do_right);
    else if (i % 4 == 3)
      ASSERT_EQ(get<0>(s.currentInstruction(i)), do_infect);
  }
}

// Test Specie's addInstruciton(enum Instruction control) and currentinstruction
TEST(Specie, test10) {
  Specie s('s');
  s.addInstruction(if_empty, 1);
  s.addInstruction(if_wall, 1);
  s.addInstruction(if_random, 1);
  s.addInstruction(go, 1);
  ASSERT_EQ(get<0>(s.currentInstruction(0)), if_empty);
  ASSERT_EQ(get<0>(s.currentInstruction(1)), if_wall);
  ASSERT_EQ(get<0>(s.currentInstruction(2)), if_random);
  ASSERT_EQ(get<0>(s.currentInstruction(3)), go);
  ASSERT_EQ(get<1>(s.currentInstruction(0)), 1);
  ASSERT_EQ(get<1>(s.currentInstruction(1)), 1);
  ASSERT_EQ(get<1>(s.currentInstruction(2)), 1);
  ASSERT_EQ(get<1>(s.currentInstruction(3)), 1);
}

// add 12 condition instructions and line number,then check
TEST(Specie, test11) {
  Specie s('s');

  for (int i = 0; i < 12; ++i) {
    if (i % 4 == 0)
      s.addInstruction(if_empty, 1);
    else if (i % 4 == 1)
      s.addInstruction(if_wall, 1);
    else if (i % 4 == 2)
      s.addInstruction(if_random, 1);
    else
      s.addInstruction(go, 1);
  }
  for (int i = 0; i < 12; ++i) {
    if (i % 4 == 0) {
      ASSERT_EQ(get<0>(s.currentInstruction(i)), if_empty);
      ASSERT_EQ(get<1>(s.currentInstruction(i)), 1);
    } else if (i % 4 == 1) {
      ASSERT_EQ(get<0>(s.currentInstruction(i)), if_wall);
      ASSERT_EQ(get<1>(s.currentInstruction(i)), 1);
    } else if (i % 4 == 2) {
      ASSERT_EQ(get<0>(s.currentInstruction(i)), if_random);
      ASSERT_EQ(get<1>(s.currentInstruction(i)), 1);
    } else {
      ASSERT_EQ(get<0>(s.currentInstruction(i)), go);
      ASSERT_EQ(get<1>(s.currentInstruction(i)), 1);
    }
  }
}

// add 120 condition instructions and line number, then check
TEST(Specie, test12) {
  Specie s('s');

  for (int i = 0; i < 120; ++i) {
    if (i % 4 == 0)
      s.addInstruction(if_empty, 1);
    else if (i % 4 == 1)
      s.addInstruction(if_wall, 1);
    else if (i % 4 == 2)
      s.addInstruction(if_random, 1);
    else
      s.addInstruction(go, 1);
  }
  for (int i = 0; i < 120; ++i) {
    if (i % 4 == 0) {
      ASSERT_EQ(get<0>(s.currentInstruction(i)), if_empty);
      ASSERT_EQ(get<1>(s.currentInstruction(i)), 1);
    } else if (i % 4 == 1) {
      ASSERT_EQ(get<0>(s.currentInstruction(i)), if_wall);
      ASSERT_EQ(get<1>(s.currentInstruction(i)), 1);
    } else if (i % 4 == 2) {
      ASSERT_EQ(get<0>(s.currentInstruction(i)), if_random);
      ASSERT_EQ(get<1>(s.currentInstruction(i)), 1);
    } else {
      ASSERT_EQ(get<0>(s.currentInstruction(i)), go);
      ASSERT_EQ(get<1>(s.currentInstruction(i)), 1);
    }
  }
}

// Test NONEINSTRUCT
TEST(Specie, test13) {
  Specie s('s');
  s.addInstruction(NONEINSTRUCT);
  s.addInstruction(do_hop);
  ASSERT_EQ(get<0>(s.currentInstruction(0)), do_hop);
}

TEST(Specie, test14) {
  Specie s('s');
  s.addInstruction(NONEINSTRUCT, 1);
  s.addInstruction(if_empty, 1);
  ASSERT_EQ(get<0>(s.currentInstruction(0)), if_empty);
}

// try to create 200 of NONEINSTRUCT and check first one is do_hop
TEST(Specie, test15) {
  Specie s('s');
  for (int i = 0; i < 100; ++i) {
    s.addInstruction(NONEINSTRUCT);
    s.addInstruction(NONEINSTRUCT, 1);
  }
  s.addInstruction(do_hop);
  ASSERT_EQ(get<0>(s.currentInstruction(0)), do_hop);
}

// Test Creature's default Constructor
// and operator<< will be tested along with others
TEST(Creature, test16) {
  Creature d;
  std::stringstream actual;
  actual << d;
  ASSERT_EQ("", actual.str());
}

/// Test Creature's default Constructor, add consecutively
TEST(Creature, test17) {
  Creature d;
  std::stringstream actual;
  actual << d;
  Creature c;
  actual << c;
  Creature b;
  actual << b;
  ASSERT_EQ("", actual.str());
}

/// Test Creature's default Constructor 100 times and check
TEST(Creature, test18) {
  for (int i = 0; i < 100; ++i) {
    Creature d;
    std::stringstream actual;
    actual << d;
    ASSERT_EQ("", actual.str());
  }
}

// Test Creature's Specie Constructor
TEST(Creature, test19) {
  Specie s('h');
  Creature c(s);
  std::stringstream actual;
  actual << c;
  ASSERT_EQ("h", actual.str());
}

// Test Creature's Specie Constructor consecutively
TEST(Creature, test20) {
  Specie s('i');
  Creature c(s);
  std::stringstream actual;
  actual << c;
  Specie t('j');
  Creature d(t);
  actual << d;
  ASSERT_EQ("ij", actual.str());
}

// Test Creature's Specie Constructor 100 times
TEST(Creature, test21) {
  for (int i = 0; i < 100; ++i) {
    Specie s('j');
    Creature c(s);
    std::stringstream actual;
    actual << c;
    ASSERT_EQ("j", actual.str());
  }
}

// Test Creature's isNull function
TEST(Creature, test22) {
  Creature c;
  ASSERT_EQ(c.isNull(), true);
}

// Test Creature's isNull function using copy constructor
TEST(Creature, test23) {
  Creature d;
  Creature c(d);
  ASSERT_EQ(c.isNull(), true);
}

// Test Creature's isNull function 100 times
TEST(Creature, test24) {
  for (int i = 0; i < 100; ++i) {
    Creature c;
    ASSERT_EQ(c.isNull(), true);
  }
}

// Test Creature's copy constructor
TEST(Creature, test25) {
  Specie s('h');
  Creature c(s);
  std::stringstream actual, expect;
  actual << c;
  Creature d(c);
  expect << d;
  ASSERT_EQ(expect.str(), actual.str());
}

// Test Creature's copy constructor twice
TEST(Creature, test26) {
  Specie s('h');
  Creature c(s);
  std::stringstream actual, expect;
  actual << c;
  Creature d(c);
  Creature e(d);
  expect << e;
  ASSERT_EQ(expect.str(), actual.str());
}

// Test Creature's copy constructor 100 times
TEST(Creature, test27) {
  Specie s('h');
  Creature c(s);
  std::stringstream actual;
  actual << c;
  for (int i = 0; i < 100; ++i) {
    std::stringstream expect;
    Creature d(c);
    expect << d;
    ASSERT_EQ(expect.str(), actual.str());
  }
}

// Test Creature's default copy assignment
TEST(Creature, test28) {
  Specie s('h');
  Creature c(s);

  Specie t('j');
  std::stringstream expect;
  Creature d(t);
  d = c;
  expect << d;
  ASSERT_EQ(expect.str(), "h");
}

// Test Swapping of Creatures using copy assingment
TEST(Creature, test29) {
  Specie s('h');
  Creature c(s);

  Specie u('k');
  Creature e(u);

  Specie t('j');
  std::stringstream expect;
  Creature d(t);
  e = c;
  d = e;
  expect << d;
  ASSERT_EQ(expect.str(), "h");
}

// Test executeTurn
// This is better tested via simulation, but here are some direct tests.
TEST(Creature, test30) {
  Specie A('A');
  A.addInstruction(do_hop);
  A.addInstruction(go, 0);

  Creature a(A);

  Specie B('B');
  Creature b0(B);
  Creature b1(B);
  Creature b2(B);
  Creature b3(B);

  Direction result;

  Creature *creatures[4];

  creatures[0] = &b0;
  creatures[1] = &b1;
  creatures[2] = &b2;
  creatures[3] = &b3;

  result = a.executeTurn(creatures);

  ASSERT_EQ(NONEDIRECT, result);
}

TEST(Creature, test31) {
  Specie A('A');
  A.addInstruction(do_hop);
  A.addInstruction(go, 0);

  Creature a(A);

  Specie B('B');
  Creature b0(B);
  Creature b1(B);
  Creature b2(B);
  Creature b3(B);

  b0 = Creature();

  Direction result;

  Creature *creatures[4];

  creatures[0] = &b0;
  creatures[1] = &b1;
  creatures[2] = &b2;
  creatures[3] = &b3;

  result = a.executeTurn(creatures);

  ASSERT_EQ(NORTH, result);
}

// Darwin Constructor tests
TEST(Darwin, test40) {
  Darwin x(5, 5);
  std::stringstream actual;
  actual << x;
  ASSERT_EQ("  01234\n0 .....\n1 .....\n2 .....\n3 .....\n4 .....\n",
            actual.str());
}

TEST(Darwin, test41) {
  bool errorOccured = false;
  try {
    Darwin x(0, 0);
  } catch (invalid_argument &e) {
    errorOccured = true;
  }
  ASSERT_TRUE(errorOccured);
}

TEST(Darwin, test42) {
  bool errorOccured = false;
  try {
    Darwin x(std::numeric_limits<std::size_t>::max(),
             std::numeric_limits<std::size_t>::max());
  } catch (invalid_argument &e) {
    errorOccured = true;
  }
  ASSERT_TRUE(errorOccured);
}

TEST(Darwin, test43) {
  bool errorOccured = false;
  try {
    Darwin x(-1, -1);
  } catch (invalid_argument &e) {
    errorOccured = true;
  }
  ASSERT_TRUE(errorOccured);
}

// Darwin addCreature tests
TEST(Darwin, test50) {

  Specie chuck_norris('c');
  chuck_norris.addInstruction(if_enemy, 3);
  chuck_norris.addInstruction(do_left);
  chuck_norris.addInstruction(go, 0);
  chuck_norris.addInstruction(do_infect);
  chuck_norris.addInstruction(go, 0);

  Darwin x(3, 3);

  x.addCreature(chuck_norris, NORTH, 0, 0);
  x.addCreature(chuck_norris, NORTH, 0, 1);
  x.addCreature(chuck_norris, NORTH, 0, 2);
  x.addCreature(chuck_norris, NORTH, 1, 0);
  x.addCreature(chuck_norris, NORTH, 1, 1);
  x.addCreature(chuck_norris, NORTH, 1, 2);
  x.addCreature(chuck_norris, NORTH, 2, 0);
  x.addCreature(chuck_norris, NORTH, 2, 1);
  x.addCreature(chuck_norris, NORTH, 2, 2);

  std::stringstream actual;
  actual << x;

  ASSERT_EQ("  012\n0 ccc\n1 ccc\n2 ccc\n", actual.str());
}

TEST(Darwin, test51) {
  bool errorOccured = false;

  Specie chuck_norris('c');
  chuck_norris.addInstruction(if_enemy, 3);
  chuck_norris.addInstruction(do_left);
  chuck_norris.addInstruction(go, 0);
  chuck_norris.addInstruction(do_infect);
  chuck_norris.addInstruction(go, 0);

  Darwin x(3, 3);

  x.addCreature(chuck_norris, NORTH, 0, 0);

  try {
    x.addCreature(chuck_norris, NORTH, 0, 0);
  } catch (invalid_argument &e) {
    errorOccured = true;
  }

  ASSERT_TRUE(errorOccured);
}

TEST(Darwin, test52) {
  Specie donald_trump('d');
  donald_trump.addInstruction(do_hop);
  donald_trump.addInstruction(go, 0);

  Specie hillary_clinton('h');
  donald_trump.addInstruction(do_hop);
  donald_trump.addInstruction(go, 0);

  Specie bernie_sanders('b');
  bernie_sanders.addInstruction(if_enemy, 9);
  bernie_sanders.addInstruction(if_empty, 7);
  bernie_sanders.addInstruction(if_random, 5);
  bernie_sanders.addInstruction(do_left);
  bernie_sanders.addInstruction(go, 0);
  bernie_sanders.addInstruction(do_right);
  bernie_sanders.addInstruction(go, 0);
  bernie_sanders.addInstruction(do_hop);
  bernie_sanders.addInstruction(go, 0);
  bernie_sanders.addInstruction(do_infect);
  bernie_sanders.addInstruction(go, 0);

  Darwin x(3, 3);

  x.addCreature(donald_trump, SOUTH, 0, 0);
  x.addCreature(hillary_clinton, SOUTH, 0, 2);
  x.addCreature(bernie_sanders, NORTH, 2, 1);

  std::stringstream actual;
  actual << x;

  ASSERT_EQ("  012\n0 d.h\n1 ...\n2 .b.\n", actual.str());
}

// Darwin simulate() tests
TEST(Darwin, test60) {
  srand(0);
  Specie donald_trump('d');
  donald_trump.addInstruction(do_hop);
  donald_trump.addInstruction(go, 0);

  Specie hillary_clinton('h');
  hillary_clinton.addInstruction(do_hop);
  hillary_clinton.addInstruction(go, 0);

  Specie bernie_sanders('b');
  bernie_sanders.addInstruction(if_enemy, 9);
  bernie_sanders.addInstruction(if_empty, 7);
  bernie_sanders.addInstruction(if_random, 5);
  bernie_sanders.addInstruction(do_left);
  bernie_sanders.addInstruction(go, 0);
  bernie_sanders.addInstruction(do_right);
  bernie_sanders.addInstruction(go, 0);
  bernie_sanders.addInstruction(do_hop);
  bernie_sanders.addInstruction(go, 0);
  bernie_sanders.addInstruction(do_infect);
  bernie_sanders.addInstruction(go, 0);

  Darwin test(3, 3);

  test.addCreature(donald_trump, SOUTH, 0, 0);
  test.addCreature(hillary_clinton, SOUTH, 0, 2);
  test.addCreature(bernie_sanders, NORTH, 2, 1);

  std::stringstream actual;
  actual << test;

  ASSERT_EQ("  012\n0 d.h\n1 ...\n2 .b.\n", actual.str());

  // Clear string stream
  actual.str("");

  for (int i = 0; i < 11; ++i) {
    test.simulate();
  }

  actual << test;

  ASSERT_EQ("  012\n0 ...\n1 .b.\n2 bb.\n", actual.str());
}

// Wall in each direction.
TEST(Darwin, test61) {
  srand(0);
  Specie donald_trump('d');
  donald_trump.addInstruction(do_hop);
  donald_trump.addInstruction(go, 0);

  Specie hillary_clinton('h');
  hillary_clinton.addInstruction(do_hop);
  hillary_clinton.addInstruction(go, 0);

  Specie bernie_sanders('b');
  bernie_sanders.addInstruction(if_enemy, 9);
  bernie_sanders.addInstruction(if_empty, 7);
  bernie_sanders.addInstruction(if_random, 5);
  bernie_sanders.addInstruction(do_left);
  bernie_sanders.addInstruction(go, 0);
  bernie_sanders.addInstruction(do_right);
  bernie_sanders.addInstruction(go, 0);
  bernie_sanders.addInstruction(do_hop);
  bernie_sanders.addInstruction(go, 0);
  bernie_sanders.addInstruction(do_infect);
  bernie_sanders.addInstruction(go, 0);

  Darwin test(3, 3);

  test.addCreature(donald_trump, NORTH, 0, 0);
  test.addCreature(donald_trump, WEST, 2, 2);
  test.addCreature(hillary_clinton, EAST, 0, 2);
  test.addCreature(hillary_clinton, SOUTH, 2, 0);
  test.addCreature(bernie_sanders, NORTH, 1, 1);

  std::stringstream actual;
  actual << test;

  ASSERT_EQ("  012\n0 d.h\n1 .b.\n2 h.d\n", actual.str());

  // Clear string stream
  actual.str("");

  for (int i = 0; i < 11; ++i) {
    test.simulate();
  }

  actual << test;

  ASSERT_EQ("  012\n0 bb.\n1 b..\n2 b.b\n", actual.str());
}

// Test roundOver()
TEST(turnFinishedTest, turnFinishedReturn) {
  Specie s('s');
  Creature c(s);
  c._turnFinished = true;
  c.roundOver();
  ASSERT_EQ(false, c._turnFinished);
}

// Test turnRight()
TEST(turnRightTest, turnRightLoop) {
  Specie s('s');
  Creature c(s);
  // Creatures are born facing north.
  c.turnRight();
  c.turnRight();
  ASSERT_EQ(SOUTH, c._direction);
}

// create 10x10 and move hopper down from the top
TEST(DarwinSimulationTest, test1) {
  Darwin x(10, 10);
  Specie hopper('h');
  hopper.addInstruction(do_hop);
  hopper.addInstruction(go, 0);
  // create hopper in every row
  for (int i = 0; i < 10; ++i) {
    Creature c(hopper);
    x.addCreature(c, SOUTH, 0, i);
  }

  // create an expecting answer/output
  std::stringstream expect;
  expect << "  0123456789\n";
  for (int i = 0; i < 10; ++i) {
    expect << i << " ";
    for (int j = 0; j < 10; ++j) {
      if (i == 9)
        expect << "h";
      else
        expect << ".";
    }
    expect << "\n";
  }

  // bring hoppers down to the bottom
  for (int i = 0; i < 10; ++i) {
    x.simulate();
  }

  std::stringstream actual;
  actual << x;
  ASSERT_EQ(expect.str(), actual.str());
}

// Bring Hopper down to bottom and get infected by traps
TEST(DarwinSimulationTest, test2) {
  Darwin x(100, 100);
  Specie hopper('h');
  hopper.addInstruction(do_hop);
  hopper.addInstruction(go, 0);
  Specie trap('t');
  trap.addInstruction(if_enemy, 3);
  trap.addInstruction(do_left);
  trap.addInstruction(go, 0);
  trap.addInstruction(do_infect);
  trap.addInstruction(go, 0);

  // create hopper in every row
  for (int i = 0; i < 100; ++i) {
    Creature c(hopper);
    x.addCreature(c, SOUTH, 0, i);
    Creature d(trap);
    x.addCreature(d, NORTH, 99, i);
  }

  // create an expecting answer/output
  std::stringstream expect;
  expect << "  ";
  for (int i = 0; i < 100; ++i)
    expect << (i % 10);
  expect << "\n";
  for (int i = 0; i < 100; ++i) {
    expect << (i % 10) << " ";
    for (int j = 0; j < 100; ++j) {
      if (i == 98 || i == 99)
        expect << "t";
      else
        expect << ".";
    }
    expect << "\n";
  }

  // bring hoppers down to the bottom then infect them all by trap
  for (int i = 0; i < 120; ++i) {
    x.simulate();
  }

  std::stringstream actual;
  actual << x;
  ASSERT_EQ(expect.str(), actual.str());
}

TEST(DarwinSimulationTest, test3) {
  Darwin x(50, 50);
  Specie hopper('h');
  hopper.addInstruction(do_hop);
  hopper.addInstruction(go, 0);
  Specie trap('t');
  trap.addInstruction(if_enemy, 3);
  trap.addInstruction(do_left);
  trap.addInstruction(go, 0);
  trap.addInstruction(do_infect);
  trap.addInstruction(go, 0);
  // create hopper and trap
  for (int i = 0; i < 50; ++i) {
    Creature c(hopper);
    x.addCreature(c, SOUTH, i, 5);
    Creature d(trap);
    x.addCreature(d, NORTH, i, 49);
  }

  // create an expecting answer/output
  std::stringstream expect;
  expect << "  ";
  for (int i = 0; i < 50; ++i)
    expect << (i % 10);
  expect << "\n";
  for (int i = 0; i < 50; ++i) {
    expect << (i % 10) << " ";
    for (int j = 0; j < 50; ++j) {
      if (j == 5)
        expect << "h";
      else if (j == 49)
        expect << "t";
      else
        expect << ".";
    }
    expect << "\n";
  }

  // bring hoppers down to the bottom then infect them all by trap
  for (int i = 0; i < 50; ++i) {
    x.simulate();
  }

  std::stringstream actual;
  actual << x;
  ASSERT_EQ(expect.str(), actual.str());
}

// create foods and hopper eats it and rover infects hopper
TEST(DarwinStressTest, test1) {
  // test same set up 10times
  Specie hopper('h');
  hopper.addInstruction(do_hop);
  hopper.addInstruction(go, 0);
  Specie food('f');
  food.addInstruction(do_left);
  food.addInstruction(go, 0);
  Specie rover('r');
  rover.addInstruction(if_enemy, 9);
  rover.addInstruction(if_empty, 7);
  rover.addInstruction(if_random, 5);
  rover.addInstruction(do_left);
  rover.addInstruction(go, 0);
  rover.addInstruction(do_right);
  rover.addInstruction(go, 0);
  rover.addInstruction(do_hop);
  rover.addInstruction(go, 0);
  rover.addInstruction(do_infect);
  rover.addInstruction(go, 0);
  int turn = 5;
  while (turn--) {
    Darwin x(100, 100);
    // create hopper in every row
    for (int i = 0; i < 100; ++i) {
      Creature c(rover);
      x.addCreature(c, SOUTH, 0, i);
      Creature d(hopper);
      x.addCreature(d, SOUTH, 51, i);
      Creature f(food);
      x.addCreature(f, NORTH, 99, i);
    }

    // create an expecting answer/output
    std::stringstream expect;
    expect << "  ";
    for (int i = 0; i < 100; ++i)
      expect << (i % 10);
    expect << "\n";
    for (int i = 0; i < 100; ++i) {
      expect << (i % 10) << " ";
      for (int j = 0; j < 100; ++j) {
        if (i == 97 || i == 98 || i == 99)
          expect << "r";
        else
          expect << ".";
      }
      expect << "\n";
    }

    // bring hoppers down to the bottom then infect them all by trap
    for (int i = 0; i < 100; ++i) {
      x.simulate();
    }

    std::stringstream actual;
    actual << x;
    // cout << actual.str();
    // cout << "\n\n" << expect.str() << "\n";
    ASSERT_EQ(expect.str(), actual.str());
  }
}

// Stress test 2 the opposite way
TEST(DarwinStressTest, test2) {
  // test same set up 10times
  Specie hopper('h');
  hopper.addInstruction(do_hop);
  hopper.addInstruction(go, 0);
  Specie food('f');
  food.addInstruction(do_left);
  food.addInstruction(go, 0);
  Specie rover('r');
  rover.addInstruction(if_enemy, 9);
  rover.addInstruction(if_empty, 7);
  rover.addInstruction(if_random, 5);
  rover.addInstruction(do_left);
  rover.addInstruction(go, 0);
  rover.addInstruction(do_right);
  rover.addInstruction(go, 0);
  rover.addInstruction(do_hop);
  rover.addInstruction(go, 0);
  rover.addInstruction(do_infect);
  rover.addInstruction(go, 0);
  int turn = 5;
  while (turn--) {
    Darwin x(100, 100);
    // create hopper in every row
    for (int i = 0; i < 100; ++i) {
      Creature c(rover);
      x.addCreature(c, NORTH, 99, i);
      Creature d(hopper);
      x.addCreature(d, NORTH, 51, i);
      Creature f(food);
      x.addCreature(f, NORTH, 0, i);
    }

    // create an expecting answer/output
    std::stringstream expect;
    expect << "  ";
    for (int i = 0; i < 100; ++i)
      expect << (i % 10);
    expect << "\n";
    for (int i = 0; i < 100; ++i) {
      expect << (i % 10) << " ";
      for (int j = 0; j < 100; ++j) {
        if (i == 0 || i == 1 || i == 2)
          expect << "r";
        else
          expect << ".";
      }
      expect << "\n";
    }

    // bring hoppers down to the bottom then infect them all by trap
    for (int i = 0; i < 100; ++i) {
      x.simulate();
    }

    std::stringstream actual;
    actual << x;
    // cout << actual.str();
    // cout << "\n\n" << expect.str() << "\n";
    ASSERT_EQ(expect.str(), actual.str());
  }
}

// Stress test 3 the side way
TEST(DarwinStressTest, test3) {
  // test same set up 10times
  Specie hopper('h');
  hopper.addInstruction(do_hop);
  hopper.addInstruction(go, 0);
  Specie food('f');
  food.addInstruction(do_left);
  food.addInstruction(go, 0);
  Specie rover('r');
  rover.addInstruction(if_enemy, 9);
  rover.addInstruction(if_empty, 7);
  rover.addInstruction(if_random, 5);
  rover.addInstruction(do_left);
  rover.addInstruction(go, 0);
  rover.addInstruction(do_right);
  rover.addInstruction(go, 0);
  rover.addInstruction(do_hop);
  rover.addInstruction(go, 0);
  rover.addInstruction(do_infect);
  rover.addInstruction(go, 0);
  int turn = 5;
  while (turn--) {
    Darwin x(100, 100);
    // create hopper in every row
    for (int i = 0; i < 100; ++i) {
      Creature c(rover);
      x.addCreature(c, EAST, i, 0);
      Creature d(hopper);
      x.addCreature(d, EAST, i, 5);
      Creature f(food);
      x.addCreature(f, NORTH, i, 99);
    }

    // create an expecting answer/output
    std::stringstream expect;
    expect << "  ";
    for (int i = 0; i < 100; ++i)
      expect << (i % 10);
    expect << "\n";
    for (int i = 0; i < 100; ++i) {
      expect << (i % 10) << " ";
      for (int j = 0; j < 100; ++j) {
        if (j == 97 || j == 98 || j == 99)
          expect << "r";
        else
          expect << ".";
      }
      expect << "\n";
    }

    // bring hoppers down to the bottom then infect them all by trap
    for (int i = 0; i < 100; ++i) {
      x.simulate();
    }

    std::stringstream actual;
    actual << x;
    // cout << actual.str();
    // cout << "\n\n" << expect.str() << "\n";
    ASSERT_EQ(expect.str(), actual.str());
  }
}

TEST(Darwin, test62) {
  Specie donald_trump('d');
  donald_trump.addInstruction(do_hop);
  donald_trump.addInstruction(do_infect);
  donald_trump.addInstruction(if_empty, 0);
  donald_trump.addInstruction(do_right);
  donald_trump.addInstruction(go, 0);

  Darwin test(3, 3);

  test.addCreature(donald_trump, EAST, 0, 0);

  std::stringstream actual;

  for (int i = 0; i < 10000; ++i) {
    test.simulate();
  }

  actual << test;

  ASSERT_EQ("  012\n0 d..\n1 ...\n2 ...\n", actual.str());
}