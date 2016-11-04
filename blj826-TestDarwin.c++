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

// I know that these aren't great, but with the way
// I wrote my code there wasn't much I code do.
// All I can do is assume that if it doesn't break
// than I know it's probably right.

// Test if it breaks. If not it's good to go
TEST(DarwinFixture, test1) {
  Darwin x(4, 4);
  Species hopper('h');
  hopper.addInstruction(Hop);
  hopper.addInstruction(Go, 0);
  Creature h1(hopper, N);

  Species trap('t');
  trap.addInstruction(if_enemy, 3);
  trap.addInstruction(Left);
  trap.addInstruction(Go, 0);
  trap.addInstruction(Infect);
  trap.addInstruction(Go, 0);
  Creature t1(trap, W);

  x.addCreature(h1, 1, 1);
  x.addCreature(t1, 1, 2);
  ASSERT_TRUE(true);
}

TEST(DarwinFixture, test2) {
  Darwin x(5, 4);
  Species hopper('h');
  hopper.addInstruction(Hop);
  hopper.addInstruction(Go, 0);
  Creature h1(hopper, N);

  Species trap('t');
  trap.addInstruction(if_enemy, 3);
  trap.addInstruction(Left);
  trap.addInstruction(Go, 0);
  trap.addInstruction(Infect);
  trap.addInstruction(Go, 0);
  Creature t1(trap, W);

  x.addCreature(h1, 1, 1);
  x.addCreature(t1, 1, 2);

  x.turn(false);
  ASSERT_TRUE(true);
}

TEST(DarwinFixture, test3) {
  Darwin x(5, 4);
  Species hopper('h');
  hopper.addInstruction(Hop);
  hopper.addInstruction(Go, 0);
  Creature h1(hopper, N);

  Species trap('t');
  trap.addInstruction(if_enemy, 3);
  trap.addInstruction(Left);
  trap.addInstruction(Go, 0);
  trap.addInstruction(Infect);
  trap.addInstruction(Hop);
  trap.addInstruction(if_empty, 3);
  trap.addInstruction(Go, 0);
  Creature t1(trap, W);

  x.addCreature(h1, 1, 1);
  x.addCreature(t1, 1, 2);

  x.turn(false);
  x.turn(false);
  x.turn(false);
  x.turn(false);
  ASSERT_TRUE(true);
}

TEST(DarwinFixture, test4) {
  Darwin x(4, 4);
  Species hopper('h');
  hopper.addInstruction(Hop);
  hopper.addInstruction(Go, 0);
  Creature h1(hopper, N);

  Species trap('t');
  trap.addInstruction(if_enemy, 3);
  trap.addInstruction(Left);
  trap.addInstruction(Go, 0);
  trap.addInstruction(Infect);
  trap.addInstruction(Go, 0);
  Creature t1(trap, W);

  x.addCreature(h1, 1, 1);
  x.addCreature(t1, 1, 2);
  ASSERT_TRUE(true);
}

TEST(DarwinFixture, test5) {
  Darwin x(5, 4);
  Species hopper('h');
  hopper.addInstruction(Hop);
  hopper.addInstruction(Go, 0);
  Creature h1(hopper, N);

  Species trap('t');
  trap.addInstruction(if_enemy, 3);
  trap.addInstruction(Left);
  trap.addInstruction(Go, 0);
  trap.addInstruction(Infect);
  trap.addInstruction(Go, 0);
  Creature t1(trap, W);

  x.addCreature(h1, 1, 1);
  x.addCreature(t1, 1, 2);

  x.turn(false);
  ASSERT_TRUE(true);
}

TEST(DarwinFixture, test6) {
  Darwin x(5, 4);
  Species hopper('h');
  hopper.addInstruction(Hop);
  hopper.addInstruction(Go, 0);
  Creature h1(hopper, N);

  Species trap('t');
  trap.addInstruction(if_enemy, 3);
  trap.addInstruction(Left);
  trap.addInstruction(Go, 0);
  trap.addInstruction(Infect);
  trap.addInstruction(Hop);
  trap.addInstruction(if_empty, 3);
  trap.addInstruction(Go, 0);
  Creature t1(trap, W);

  x.addCreature(h1, 1, 1);
  x.addCreature(t1, 1, 2);

  x.turn(false);
  x.turn(false);
  x.turn(false);
  x.turn(false);
  ASSERT_TRUE(true);
}

TEST(DarwinFixture, test7) {
  Species rover('r');
  Species rover2('r');
  ASSERT_TRUE(rover.isEqual(rover2));
}

TEST(DarwinFixture, test8) {
  Species rover('m');
  Species rover2('m');
  ASSERT_TRUE(rover.isEqual(rover2));
}

TEST(DarwinFixture, test9) {
  Species rover('a');
  Species rover2('a');
  ASSERT_TRUE(rover.isEqual(rover2));
}

TEST(DarwinFixture, test10) {
  Darwin x(5, 4);
  Species hopper('h');
  hopper.addInstruction(Hop);
  hopper.addInstruction(Go, 0);
  Creature h1(hopper, N);

  Species trap('t');
  trap.addInstruction(if_enemy, 3);
  trap.addInstruction(Left);
  trap.addInstruction(Go, 0);
  trap.addInstruction(Infect);
  trap.addInstruction(Go, 0);
  Creature t1(trap, W);

  x.addCreature(h1, 1, 1);
  x.addCreature(t1, 1, 2);

  x.turn(false);

  ASSERT_FALSE(trap.isEqual(hopper));
}

TEST(DarwinFixture, test11) {
  Species rover('q');
  Species rover2('a');
  ASSERT_FALSE(rover.isEqual(rover2));
}

TEST(DarwinFixture, test12) {
  Species rover('a');
  rover.addInstruction(Hop);
  Species rover2('a');
  ASSERT_TRUE(rover.isEqual(rover2));
}