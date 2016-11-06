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

TEST(DarwinFixture, test3) {
  Instruction i(Condition::go, 0);
  int pc = 0;
  Action a = i.execute(pc, true, true, true);
  ASSERT_EQ(a, Action::nop);
  ASSERT_EQ(pc, 0);
}

TEST(DarwinFixture, right) {
  Instruction i(Action::right);
  int pc = 0;
  Action a = i.execute(pc, true, true, true);
  ASSERT_EQ(a, Action::right);
  ASSERT_EQ(pc, 1);
}

TEST(DarwinFixture, left) {
  Instruction i(Action::left);
  int pc = 0;
  Action a = i.execute(pc, true, true, true);
  ASSERT_EQ(a, Action::left);
  ASSERT_EQ(pc, 1);
}

TEST(DarwinFixture, infect) {
  Instruction i(Action::infect);
  int pc = 0;
  Action a = i.execute(pc, true, true, true);
  ASSERT_EQ(a, Action::infect);
  ASSERT_EQ(pc, 1);
}

TEST(DarwinFixture, test5) {
  Instruction i(Condition::if_wall, 2);
  int pc = 0;
  Action a = i.execute(pc, true, true, true);
  ASSERT_EQ(a, Action::nop);
  ASSERT_EQ(pc, 2);
}

TEST(DarwinFixture, test6) {
  Instruction i(Condition::if_empty, 2);
  int pc = 0;
  Action a = i.execute(pc, true, true, true);
  ASSERT_EQ(a, Action::nop);
  ASSERT_EQ(pc, 2);
}

TEST(DarwinFixture, test7) {
  Instruction i(Condition::if_enemy, 2);
  int pc = 0;
  Action a = i.execute(pc, true, true, true);
  ASSERT_EQ(a, Action::nop);
  ASSERT_EQ(pc, 2);
}

TEST(DarwinFixture, test8) {
  Instruction i(Condition::if_wall, 2);
  int pc = 0;
  Action a = i.execute(pc, false, false, false);
  ASSERT_EQ(a, Action::nop);
  ASSERT_EQ(pc, 1);
}

TEST(DarwinFixture, test9) {
  Instruction i(Condition::if_empty, 2);
  int pc = 0;
  Action a = i.execute(pc, false, false, false);
  ASSERT_EQ(a, Action::nop);
  ASSERT_EQ(pc, 1);
}

TEST(DarwinFixture, test10) {
  Instruction i(Condition::if_enemy, 2);
  int pc = 0;
  Action a = i.execute(pc, false, false, false);
  ASSERT_EQ(a, Action::nop);
  ASSERT_EQ(pc, 1);
}

TEST(DarwinFixture, test11) {
  Species s('s');
  int pc = 0;
  s.addInstruction(Action::hop);
  Action a = s.execute(pc, false, false, false);
  ASSERT_EQ(a, Action::hop);
  ASSERT_EQ(pc, 1);
}

TEST(DarwinFixture, test12) {
  Species s('s');
  int pc = 0;
  s.addInstruction(Condition::go, 1);
  s.addInstruction(Action::hop);
  Action a = s.execute(pc, false, false, false);
  ASSERT_EQ(a, Action::hop);
  ASSERT_EQ(pc, 2);
}

TEST(DarwinFixture, sprint) {
  ostringstream w;
  Species s('s');
  w << s;
  ASSERT_EQ("s", w.str());
}

TEST(DarwinFixture, senemy1) {
  Species s('s');
  int pc = 0;
  s.addInstruction(Condition::if_enemy, 3);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::infect);
  Action a = s.execute(pc, false, false, false);
  ASSERT_EQ(a, Action::hop);
  ASSERT_EQ(pc, 2);
}

TEST(DarwinFixture, senemy2) {
  Species s('s');
  int pc = 0;
  s.addInstruction(Condition::if_enemy, 3);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::infect);
  Action a = s.execute(pc, false, false, true);
  ASSERT_EQ(a, Action::infect);
  ASSERT_EQ(pc, 4);
}

TEST(DarwinFixture, sgo1) {
  Species s('s');
  int pc = 0;
  s.addInstruction(Condition::go, 3);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::infect);
  Action a = s.execute(pc, false, false, false);
  ASSERT_EQ(a, Action::infect);
  ASSERT_EQ(pc, 4);
}

TEST(DarwinFixture, sgo2) {
  Species s('s');
  int pc = 2;
  s.addInstruction(Action::hop);
  Action a = s.execute(pc, false, false, false);
  ASSERT_EQ(a, Action::hop);
  ASSERT_EQ(pc, 3);
}

TEST(DarwinFixture, sgo3) {
  Species s('s');
  int pc = 0;
  Action a = s.execute(pc, false, false, false);
  ASSERT_EQ(a, Action::nop);
  ASSERT_EQ(pc, 0);
}

TEST(DarwinFixture, test13) {
  Species s('s');
  Species p('s');
  ASSERT_TRUE(s == p);
}

TEST(DarwinFixture, test14) {
  Species s('s');
  Species p('p');
  ASSERT_FALSE(s == p);
}

TEST(DarwinFixture, seq3) {
  Species s('s');
  ASSERT_TRUE(s == s);
}

TEST(DarwinFixture, ceq1) {
  Species s('s');
  Species p('s');
  Creature c1(s);
  Creature c2(p);
  ASSERT_TRUE(c1 == c2);
}

TEST(DarwinFixture, ceq2) {
  Species s('s');
  Creature c1(s);
  Creature c2(s);
  ASSERT_TRUE(c1 == c2);
}

TEST(DarwinFixture, ceq3) {
  Species s('s');
  Species p('p');
  Creature c1(s);
  Creature c2(p);
  ASSERT_FALSE(c1 == c2);
}

TEST(DarwinFixture, cprint) {
  ostringstream w;

  Species s('s');
  Creature c1(s);

  w << c1;

  ASSERT_EQ("s", w.str());
}

TEST(DarwinFixture, cenemy1) {
  Species s('s');
  s.addInstruction(Condition::if_enemy, 3);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::infect);

  Creature c(s);

  Action a = c.next(false, false, false);
  ASSERT_EQ(a, Action::hop);
}

TEST(DarwinFixture, cenemy2) {
  Species s('s');
  s.addInstruction(Condition::if_enemy, 3);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::infect);

  Creature c(s);

  Action a = c.next(false, false, true);
  ASSERT_EQ(a, Action::infect);
}

TEST(DarwinFixture, cgo1) {
  Species s('s');
  s.addInstruction(Condition::go, 3);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::hop);
  s.addInstruction(Action::infect);

  Creature c(s);

  Action a = c.next(false, false, false);
  ASSERT_EQ(a, Action::infect);
}

TEST(DarwinFixture, cgo2) {
  Species s('s');
  s.addInstruction(Action::hop);

  Creature c(s);

  Action a = c.next(false, false, false);
  ASSERT_EQ(a, Action::hop);
}

TEST(DarwinFixture, cgo3) {
  Species s('s');

  Creature c(s);

  Action a = c.next(false, false, false);
  ASSERT_EQ(a, Action::nop);
}

TEST(DarwinFixture, test1) {
  Tile t;
  ASSERT_TRUE(t.isEmpty());
}

TEST(DarwinFixture, test2) {
  Species s('s');
  Tile t(Creature(s), Direction::north);
  ASSERT_TRUE(!t.isEmpty());
}

TEST(DarwinFixture, tprint1) {
  ostringstream w;

  Tile t;

  w << t;

  ASSERT_EQ(".", w.str());
}

TEST(DarwinFixture, tprint2) {
  ostringstream w;

  Species s('s');
  Tile t(s, Direction::north);

  w << t;

  ASSERT_EQ("s", w.str());
}

TEST(DarwinFixture, tprint3) {
  ostringstream w;

  Species s('s');
  Tile t(s, Direction::south);

  w << t;

  ASSERT_EQ("s", w.str());
}

TEST(DarwinFixture, tinfect1) {
  ostringstream w;

  Species s('s');
  Species c('c');
  Tile t(s, Direction::north);

  t.infect(c);

  w << t;

  ASSERT_EQ("c", w.str());
}

TEST(DarwinFixture, tinfect2) {
  ostringstream w;

  Species c('c');
  Tile t;

  t.infect(c);

  w << t;

  ASSERT_EQ(".", w.str());
}

TEST(DarwinFixture, tinfect3) {
  ostringstream w;

  Species c('c');
  Tile t(c, Direction::north);

  t.infect(c);

  w << t;

  ASSERT_EQ("c", w.str());
}

TEST(DarwinFixture, tinfect5) {
  Species c('c');
  Tile t;

  t.infect(c);

  ASSERT_TRUE(t.isEmpty());
}

TEST(DarwinFixture, tinfect6) {
  Species c('c');
  Tile t(c, Direction::north);

  t.infect(c);

  ASSERT_FALSE(t.isEmpty());
}

TEST(DarwinFixture, tenemy1) {
  Species s('s');
  s.addInstruction(Condition::if_enemy, 3);
  s.addInstruction(Action::left);
  s.addInstruction(Action::right);
  s.addInstruction(Action::hop);

  Tile t(s, Direction::north);

  Tile *envr[] = {nullptr, nullptr, nullptr, nullptr, nullptr};

  Direction d = t.run(envr);
  ASSERT_EQ(d, Direction::none);
}

TEST(DarwinFixture, tenemy2) {
  Species s('s');
  s.addInstruction(Condition::if_enemy, 3);
  s.addInstruction(Action::left);
  s.addInstruction(Action::right);
  s.addInstruction(Action::hop);

  Tile t(s, Direction::north);

  Tile *envr[] = {&t, &t, &t, &t, nullptr};

  Direction d = t.run(envr);
  ASSERT_EQ(d, Direction::none);
}

TEST(DarwinFixture, tenemy3) {
  Species s('s');
  s.addInstruction(Condition::if_enemy, 3);
  s.addInstruction(Action::left);
  s.addInstruction(Action::right);
  s.addInstruction(Action::hop);

  Species c('c');

  Tile t(s, Direction::north);
  Tile e(c, Direction::north);

  Tile *envr[] = {&e, &e, &e, &e, nullptr};

  Direction d = t.run(envr);
  ASSERT_EQ(d, Direction::north);
}

TEST(DarwinFixture, tgo1) {
  Species s('s');
  s.addInstruction(Condition::go, 3);
  s.addInstruction(Action::left);
  s.addInstruction(Action::right);
  s.addInstruction(Action::hop);

  Tile t(s, Direction::north);

  Tile *envr[] = {nullptr, nullptr, nullptr, nullptr, nullptr};

  Direction d = t.run(envr);
  ASSERT_EQ(d, Direction::north);
}

TEST(DarwinFixture, tgo2) {
  Species s('s');

  Tile t(s, Direction::north);

  Tile *envr[] = {nullptr, nullptr, nullptr, nullptr, nullptr};

  Direction d = t.run(envr);
  ASSERT_EQ(d, Direction::none);
}

TEST(DarwinFixture, d3) {
  ostringstream w;

  Species food('f');
  food.addInstruction(Action::left);
  food.addInstruction(Condition::go, 0);
  Darwin x(1, 1);

  w << x;
  ASSERT_EQ("Turn = 0.\n  0\n0 .\n\n", w.str());
}

TEST(DarwinFixture, d4) {
  ostringstream w;

  Species food('f');
  food.addInstruction(Action::left);
  food.addInstruction(Condition::go, 0);
  Darwin x(1, 1);
  x.addCreature(0, 0, food, Direction::north);

  w << x;
  ASSERT_EQ("Turn = 0.\n  0\n0 f\n\n", w.str());
}

TEST(DarwinFixture, test15) {
  ostringstream w;

  Species food('f');
  food.addInstruction(Action::left);
  food.addInstruction(Condition::go, 0);
  Darwin x(1, 1);
  x.addCreature(0, 0, food, Direction::north);
  x.runTurn();
  x.runTurn();
  x.runTurn();
  x.runTurn();

  w << x;
  ASSERT_EQ("Turn = 4.\n  0\n0 f\n\n", w.str());
}

TEST(DarwinFixture, test16) {
  ostringstream w;

  Species food('f');
  food.addInstruction(Action::right);
  food.addInstruction(Condition::go, 0);
  Darwin x(1, 1);
  x.addCreature(0, 0, food, Direction::north);
  x.runTurn();
  x.runTurn();
  x.runTurn();
  x.runTurn();

  w << x;

  ASSERT_EQ("Turn = 4.\n  0\n0 f\n\n", w.str());
}

TEST(DarwinFixture, test17) {
  ostringstream w;
  Species food('f');
  food.addInstruction(Action::right);
  food.addInstruction(Condition::go, 0);
  Species pred('s');
  pred.addInstruction(Action::infect);
  pred.addInstruction(Condition::go, 0);
  Darwin x(2, 1);
  x.addCreature(0, 0, food, Direction::north);
  x.addCreature(1, 0, pred, Direction::north);
  x.runTurn();

  w << x;

  ASSERT_EQ("Turn = 1.\n  0\n0 s\n1 s\n\n", w.str());
}
