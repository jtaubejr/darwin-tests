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
#include <sstream> // istringtstream, ostringstream
#include <utility> // pair
#include "Darwin.h"

using namespace std;

// ----
// Darwin Tests
// ----

TEST(DarwinFixture, darwin_constructor) {
  Darwin<8, 8> d;
  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  d.run_darwin(0);

  const string board = "Turn = 0.\n  01234567\n0 ........\n1 ........\n2 "
                       "........\n3 ........\n4 ........\n5 ........\n6 "
                       "........\n7 ........\n\n";
  cout.rdbuf(old_buf);
  ASSERT_EQ(board, ss.str());
}

TEST(DarwinFixture, darwin_add1) {
  Darwin<8, 8> d;
  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  Species s = Species();
  Creature c = Creature(&s, Creature::East, 'f');
  d.addCreature(*c, 0, 0);
  d.run_darwin(0);

  const string board = "Turn = 0.\n  01234567\n0 f.......\n1 ........\n2 "
                       "........\n3 ........\n4 ........\n5 ........\n6 "
                       "........\n7 ........\n\n";
  cout.rdbuf(old_buf);
  ASSERT_EQ(board, ss.str());
}

TEST(DarwinFixture, darwin_add2) {
  Darwin<8, 8> d;
  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  Species s = Species();
  Creature c1 = Creature(&s, Creature::East, 'f');
  Creature c2 = Creature(&s, Creature::East, 'f');
  d.addCreature(*c1, 0, 0);
  d.addCreature(*c2, 3, 4);
  d.run_darwin(0);

  const string board = "Turn = 0.\n  01234567\n0 f.......\n1 ........\n2 "
                       "........\n3 ....f...\n4 ........\n5 ........\n6 "
                       "........\n7 ........\n\n";
  cout.rdbuf(old_buf);
  ASSERT_EQ(board, ss.str());
}

TEST(DarwinFixture, add3) {
  Darwin<8, 8> d;

  Species s = Species();
  Creature c1 = Creature(&s, Creature::East, 'f');
  Creature c2 = Creature(&s, Creature::East, 'h');
  d.addCreature(*c1, 0, 0);
  d.addCreature(*c2, 3, 4);

  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  d.run_darwin(0);

  const string board = "Turn = 0.\n  01234567\n0 f.......\n1 ........\n2 "
                       "........\n3 ....h...\n4 ........\n5 ........\n6 "
                       "........\n7 ........\n\n";
  cout.rdbuf(old_buf);
  ASSERT_EQ(board, ss.str());
}

TEST(DarwinFixture, darwin_point_is_valid_1) {
  Darwin<8, 8> d;

  ASSERT_TRUE(d.point_is_valid(0, 0));
}

TEST(DarwinFixture, darwin_point_is_valid_2) {
  Darwin<8, 8> d;

  ASSERT_FALSE(d.point_is_valid(-1, 0));
}

TEST(DarwinFixture, darwin_point_is_valid_3) {
  Darwin<8, 8> d;

  ASSERT_FALSE(d.point_is_valid(0, -1));
}

TEST(DarwinFixture, darwin_point_is_valid_4) {
  Darwin<8, 8> d;

  ASSERT_FALSE(d.point_is_valid(9, 0));
}

TEST(DarwinFixture, darwin_point_is_valid_5) {
  Darwin<8, 8> d;

  ASSERT_FALSE(d.point_is_valid(0, 9));
}

TEST(DarwinFixture, darwin_run_darwin_1) {
  Darwin<8, 8> d;

  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::East, 'h');
  Creature c2 = Creature(&h, Creature::East, 'h');
  d.addCreature(*c1, 0, 0);
  d.addCreature(*c2, 3, 4);

  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  d.run_darwin(1);

  const string board = "Turn = 0.\n  01234567\n0 h.......\n1 ........\n2 "
                       "........\n3 ....h...\n4 ........\n5 ........\n6 "
                       "........\n7 ........\n\nTurn = 1.\n  01234567\n0 "
                       ".h......\n1 ........\n2 ........\n3 .....h..\n4 "
                       "........\n5 ........\n6 ........\n7 ........\n\n";
  cout.rdbuf(old_buf);
  ASSERT_EQ(board, ss.str());
}

TEST(DarwinFixture, darwin_run_darwin_2) {
  Darwin<8, 8> d;
  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::East, 'h');
  Creature c2 = Creature(&h, Creature::East, 'h');
  d.addCreature(*c1, 0, 0);
  d.addCreature(*c2, 3, 4);

  d.run_darwin(3);

  const string board =
      "Turn = 0.\n  01234567\n0 h.......\n1 ........\n2 ........\n3 "
      "....h...\n4 ........\n5 ........\n6 ........\n7 ........\n\nTurn = 1.\n "
      " 01234567\n0 .h......\n1 ........\n2 ........\n3 .....h..\n4 "
      "........\n5 ........\n6 ........\n7 ........\n\nTurn = 2.\n  "
      "01234567\n0 ..h.....\n1 ........\n2 ........\n3 ......h.\n4 ........\n5 "
      "........\n6 ........\n7 ........\n\nTurn = 3.\n  01234567\n0 "
      "...h....\n1 ........\n2 ........\n3 .......h\n4 ........\n5 ........\n6 "
      "........\n7 ........\n\n";
  cout.rdbuf(old_buf);
  ASSERT_EQ(board, ss.str());
}

TEST(DarwinFixture, darwin_run_darwin_3) {
  Darwin<8, 8> d;
  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Species r = Species();
  r.addInstruction("if_enemy 9");
  r.addInstruction("if_empty 7");
  r.addInstruction("if_random 5");
  r.addInstruction("left");
  r.addInstruction("go 0");
  r.addInstruction("right");
  r.addInstruction("go 0");
  r.addInstruction("hop");
  r.addInstruction("go 0");
  r.addInstruction("infect");
  r.addInstruction("go 0");

  Creature c1 = Creature(&r, Creature::East, 'r');
  Creature c2 = Creature(&h, Creature::East, 'h');
  d.addCreature(*c1, 0, 0);
  d.addCreature(*c2, 0, 1);

  d.run_darwin(1);

  const string board = "Turn = 0.\n  01234567\n0 rh......\n1 ........\n2 "
                       "........\n3 ........\n4 ........\n5 ........\n6 "
                       "........\n7 ........\n\nTurn = 1.\n  01234567\n0 "
                       "r.r.....\n1 ........\n2 ........\n3 ........\n4 "
                       "........\n5 ........\n6 ........\n7 ........\n\n";
  cout.rdbuf(old_buf);
  ASSERT_EQ(board, ss.str());
}

TEST(DarwinFixture, darwin_run_darwin_4) {
  Darwin<8, 8> d;
  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Species t = Species();
  t.addInstruction("if_enemy 3");
  t.addInstruction("left");
  t.addInstruction("go 0");
  t.addInstruction("infect");
  t.addInstruction("go 0");

  Species r = Species();
  r.addInstruction("if_enemy 9");
  r.addInstruction("if_empty 7");
  r.addInstruction("if_random 5");
  r.addInstruction("left");
  r.addInstruction("go 0");
  r.addInstruction("right");
  r.addInstruction("go 0");
  r.addInstruction("hop");
  r.addInstruction("go 0");
  r.addInstruction("infect");
  r.addInstruction("go 0");

  Creature c1 = Creature(&t, Creature::South, 't');
  Creature c2 = Creature(&h, Creature::East, 'h');
  Creature c3 = Creature(&r, Creature::North, 'r');
  Creature c4 = Creature(&t, Creature::West, 't');

  d.addCreature(*c1, 0, 0);
  d.addCreature(*c2, 3, 2);
  d.addCreature(*c3, 5, 4);
  d.addCreature(*c4, 6, 8);

  d.run_darwin(5);

  const string board =
      "Turn = 0.\n  01234567\n0 t.......\n1 ........\n2 ........\n3 "
      "..h.....\n4 ........\n5 ....r...\n6 ........\n7 t.......\n\nTurn = 1.\n "
      " 01234567\n0 t.......\n1 ........\n2 ........\n3 ...h....\n4 "
      "....r...\n5 ........\n6 ........\n7 t.......\n\nTurn = 2.\n  "
      "01234567\n0 t.......\n1 ........\n2 ........\n3 ....r...\n4 ....r...\n5 "
      "........\n6 ........\n7 t.......\n\nTurn = 3.\n  01234567\n0 "
      "t.......\n1 ........\n2 ........\n3 ....rr..\n4 ........\n5 ........\n6 "
      "........\n7 t.......\n\nTurn = 4.\n  01234567\n0 t.......\n1 "
      "........\n2 ....r...\n3 ......r.\n4 ........\n5 ........\n6 ........\n7 "
      "t.......\n\nTurn = 5.\n  01234567\n0 t.......\n1 ....r...\n2 "
      "........\n3 .......r\n4 ........\n5 ........\n6 ........\n7 "
      "t.......\n\n";
  cout.rdbuf(old_buf);
  ASSERT_EQ(board, ss.str());
}

// ----
// Creature Tests
// ----

TEST(DarwinFixture, creature_in_front_1) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::South, 'h');
  Creature c2 = Creature(&h, Creature::North, 'h');
  d.addCreature(*c1, 0, 0);

  int r = 1;
  int c = 0;
  d.addCreature(*c2, 1, 0);

  c2.inFront(r, c);

  ASSERT_EQ(r, c);
}

TEST(DarwinFixture, creature_in_front_2) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::North, 'h');
  Creature c2 = Creature(&h, Creature::South, 'h');

  int r1 = 1;
  int co1 = 0;
  d.addCreature(*c1, r1, co1);

  int r2 = 0;
  int co2 = 0;
  d.addCreature(*c2, r2, co2);

  c1.inFront(r1, co1);

  ASSERT_EQ(r1, r2);
  ASSERT_EQ(co1, co2);
}

TEST(DarwinFixture, creature_in_front_3) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::East, 'h');
  Creature c2 = Creature(&h, Creature::West, 'h');
  d.addCreature(*c1, 0, 0);

  int r = 0;
  int c = 1;
  d.addCreature(*c2, r, c);

  c2.inFront(r, c);

  ASSERT_EQ(r, c);
}

TEST(DarwinFixture, creature_in_front_4) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::West, 'h');
  Creature c2 = Creature(&h, Creature::East, 'h');

  int r1 = 0;
  int co1 = 1;
  d.addCreature(*c1, r1, co1);

  int r2 = 0;
  int co2 = 0;
  d.addCreature(*c2, r2, co2);

  c1.inFront(r1, co1);

  ASSERT_EQ(r1, r2);
  ASSERT_EQ(co1, co2);
}

TEST(DarwinFixture, creature_turn_left_1) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::East, 'h');
  int r = 1;
  int c = 1;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_EQ(r + 1, c);
}

TEST(DarwinFixture, creature_turn_left_2) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::West, 'h');
  int r = 1;
  int c = 1;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_EQ(r - 1, c);
}

TEST(DarwinFixture, creature_turn_left_3) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::North, 'h');
  int r = 1;
  int c = 1;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_EQ(r, c - 1);
}

TEST(DarwinFixture, creature_turn_left_4) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::South, 'h');
  int r = 1;
  int c = 1;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_EQ(r, c + 1);
}

TEST(DarwinFixture, creature_turn_left_5) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::North, 'h');
  int r = 5;
  int c = 4;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_TRUE(r == 4);
}

TEST(DarwinFixture, creature_turn_left_6) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::East, 'h');
  int r = 5;
  int c = 4;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_TRUE(c == 5);
}

TEST(DarwinFixture, creature_turn_left_7) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::West, 'h');
  int r = 5;
  int c = 4;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_TRUE(c == 3);
}

TEST(DarwinFixture, creature_turn_left_8) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::South, 'h');
  int r = 5;
  int c = 4;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_TRUE(r == 6);
}

TEST(DarwinFixture, creature_turn_right_1) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::North, 'h');
  int r = 1;
  int c = 1;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_EQ(r, c - 1);
}

TEST(DarwinFixture, creature_turn_right_2) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::East, 'h');
  int r = 1;
  int c = 1;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_EQ(r + 1, c);
}

TEST(DarwinFixture, creature_turn_right_3) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::South, 'h');
  int r = 1;
  int c = 1;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_EQ(r, c + 1);
}

TEST(DarwinFixture, creature_turn_right_4) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::West, 'h');
  int r = 1;
  int c = 1;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_EQ(r - 1, c);
}

TEST(DarwinFixture, creature_turn_right_5) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::West, 'h');
  int r = 5;
  int c = 6;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_EQ(r, c);
}

TEST(DarwinFixture, creature_turn_right_6) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::East, 'h');
  int r = 3;
  int c = 6;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_TRUE(c == 7);
}

TEST(DarwinFixture, creature_turn_right_7) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::North, 'h');
  int r = 3;
  int c = 6;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_TRUE(r == 2);
}

TEST(DarwinFixture, creature_turn_right_8) {

  Darwin<8, 8> d;
  Species h = Species();
  h.addInstruction("hop");
  h.addInstruction("go 0");

  Creature c1 = Creature(&h, Creature::South, 'h');
  int r = 3;
  int c = 2;
  d.addCreature(*c1, r, c);
  c1.inFront(r, c);

  ASSERT_TRUE(r == 4);
}

TEST(DarwinFixture, creature_infect_1) {
  Darwin<8, 8> d;
  Species h = Species();
  Species t = Species();

  Creature c1 = Creature(&h, Creature::East, 'h');
  Creature c2 = Creature(&t, Creature::West, 't');

  Creature *co2 = &c2;
  Creature *&coo2 = co2;
  c1.infect(coo2);
  ASSERT_TRUE(c1.same_species(&c2));
}

TEST(DarwinFixture, creature_print_self_1) {
  Species t = Species();
  Creature c1 = Creature(&t, Creature::East, 't');

  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  ss << c1;

  const string species = "t";
  cout.rdbuf(old_buf);
  ASSERT_EQ(species, ss.str());
}

TEST(DarwinFixture, creature_print_self_2) {
  Species t = Species();
  Creature c1 = Creature(&t, Creature::East, 'h');

  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  ss << c1;

  const string species = "h";
  cout.rdbuf(old_buf);
  ASSERT_EQ(species, ss.str());
}

TEST(DarwinFixture, creature_print_self_3) {
  Species t = Species();
  Creature c1 = Creature(&t, Creature::East, 'f');

  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());

  ss << c1;

  const string species = "f";
  cout.rdbuf(old_buf);
  ASSERT_EQ(species, ss.str());
}

TEST(DarwinFixture, creature_hop) {

  Species t = Species();
  Creature c1 = Creature(&t, Creature::East, 't');

  Creature *cre[2];
  cre[0] = *c1;

  c1.hop(cre[1]);

  ASSERT_EQ(cre[0], cre[1]);
}

TEST(DarwinFixture, creature_hop_2) {

  Species t = Species();
  Creature c1 = Creature(&t, Creature::East, 't');

  Creature *cre[3];
  cre[0] = *c1;

  c1.hop(cre[1]);
  (cre[1])->hop(cre[2]);

  ASSERT_EQ(cre[1], cre[2]);
}

TEST(DarwinFixture, creature_hop_3) {

  Species t = Species();
  Creature c1 = Creature(&t, Creature::East, 't');

  Creature *cre[4];
  cre[0] = *c1;

  c1.hop(cre[1]);
  (cre[1])->hop(cre[2]);
  (cre[2])->hop(cre[3]);

  ASSERT_EQ(cre[2], cre[3]);
}

TEST(DarwinFixture, creature_copy_constructor) {

  stringstream ss;
  auto old_buf = cout.rdbuf(ss.rdbuf());
  Species t = Species();
  Creature c1 = Creature(&t, Creature::East, 't');

  Creature c2 = c1;
  c1 = Creature(&t, Creature::East, 'z');

  ss << c1 << c2;
  const string species = "zt";
  cout.rdbuf(old_buf);
  ASSERT_EQ(species, ss.str());
}

// ----
// Species Tests
// ----
