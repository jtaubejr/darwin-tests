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

TEST(DarwinFixture, go) {
    Darwin x(2, 2);
    Species s("s");
    s.addInstruction("hop");
    Creature c(&s, 2);
    x.addCreature(&c, make_pair(0, 0));
    x.go();
    ASSERT_TRUE(x.board[0] == NULL);
}

TEST(DarwinFixture, go1) {
  Darwin x(2, 2);
  Species s("s");
  s.addInstruction("if_wall 2");
  s.addInstruction("hop");
  s.addInstruction("right");
  s.addInstruction("go 0");
  Creature c(&s, 1);
  x.addCreature(&c, make_pair(0, 0));
  x.go();
  x.go();
  ASSERT_TRUE(x.board[1] == &c);
}

TEST(DarwinFixture, addCreature) {
  Darwin x(2, 2);
  Species s("s");
  s.addInstruction("hop");
  Creature c(&s, 2);
  x.addCreature(&c, make_pair(0, 0));
  ASSERT_TRUE(x.board[0] == &c);
}

TEST(DarwinFixture, infect) {
  Darwin x(2, 2);
  Species s("s");
  s.addInstruction("infect");
  Creature c(&s, 2);
  Species s2("s2");
  Creature c2(&s, 2);
  s2.addInstruction("left");
  x.addCreature(&c, make_pair(0, 0));
  x.addCreature(&c2, make_pair(0, 1));
  x.go();
  ASSERT_EQ(c.species, c2.species);
}

TEST(DarwinFixture, getPair) {
  Darwin x(2, 2);
  ASSERT_TRUE(x.getPair(0) == make_pair(0, 0));
}

TEST(DarwinFixture, getPair1) {
  Darwin x(2, 2);
  ASSERT_TRUE(x.getPair(2) == make_pair(1, 0));
}

TEST(DarwinFixture, getPair2) {
  Darwin x(2, 2);
  ASSERT_TRUE(x.getPair(3) == make_pair(1, 1));
}

TEST(DarwinFixture, getIndex) {
  Darwin x(2, 2);
  ASSERT_EQ(x.getIndex(make_pair(0, 0)), 0);
}
  
TEST(DarwinFixture, getIndex1) {
  Darwin x(2, 2);
  ASSERT_EQ(x.getIndex(make_pair(1, 0)), 2);
}  

TEST(DarwinFixture, getIndex2) {
  Darwin x(2, 2);
  ASSERT_EQ(x.getIndex(make_pair(1, 1)), 3);
}  


TEST(SpeciesFixture, addInstruction) {
  Species s("s");
  s.addInstruction("hop");
  ASSERT_EQ(s.instructions[0], "hop");
}

TEST(SpeciesFixture, addInstruction1) {
  Species s("s");
  s.addInstruction("hop");
  s.addInstruction("go 0");
  ASSERT_EQ(s.instructions[1], "go 0");
}

TEST(SpeciesFixture, numInstruction) {
  Species s("s");
  s.addInstruction("hop");
  s.addInstruction("go 0");
  ASSERT_EQ(s.numInstructions, 2);
}

TEST(SpeciesFixture, go) {
  Species s("s");
  s.addInstruction("hop");
  s.addInstruction("go 0");
  SpeciesInstrInfo t = s.go(0, EMPTY);
  ASSERT_EQ(t.instruction, HOP);
}

TEST(SpeciesFixture, go1) {
  Species s("s");
  s.addInstruction("hop");
  s.addInstruction("go 0");
  SpeciesInstrInfo t = s.go(0, EMPTY);
  ASSERT_EQ(t.lineNumber, 1);
}

TEST(SpeciesFixture, go2) {
  Species s("s");
  s.addInstruction("if_enemy 2");
  s.addInstruction("go 0");
  s.addInstruction("hop");
  SpeciesInstrInfo t = s.go(0, ENEMY);
  ASSERT_EQ(t.lineNumber, 3);
}

TEST(SpeciesFixture, empty) {
  Species s("s");
  s.addInstruction("if_empty 3");
  s.addInstruction("hop");
  s.addInstruction("go 0");
  s.addInstruction("hop");
  SpeciesInstrInfo t = s.go(0, EMPTY);
  ASSERT_EQ(t.instruction, HOP);
}

TEST(SpeciesFixture, enemy) {
  Species s("s");
  s.addInstruction("if_enemy 3");
  s.addInstruction("hop");
  s.addInstruction("go 0");
  s.addInstruction("infect");
  SpeciesInstrInfo t = s.go(0, ENEMY);
  ASSERT_EQ(t.instruction, INFECT);
}

TEST(SpeciesFixture, enemy1) {
  Species s("s");
  s.addInstruction("if_enemy 3");
  s.addInstruction("hop");
  s.addInstruction("go 0");
  s.addInstruction("infect");
  SpeciesInstrInfo t = s.go(0, EMPTY);
  ASSERT_EQ(t.instruction, HOP);
}

TEST(SpeciesFixture, enemy2) {
  Species s("s");
  s.addInstruction("if_enemy 3");
  s.addInstruction("hop");
  s.addInstruction("go 0");
  s.addInstruction("infect");
  SpeciesInstrInfo t = s.go(0, CREATURE);
  ASSERT_EQ(t.instruction, NOOP);
}

TEST(SpeciesFixture, print) {
  Species s("tester");
  ASSERT_EQ(s.print(), "t");
}

TEST(SpeciesFixture, print1) {
  Species s("food");
  ASSERT_EQ(s.print(), "f");
}

TEST(CreatureFixture, go) {
  Species s("s");
  s.addInstruction("hop");
  s.addInstruction("go 0");
  Creature c(&s, 2);
  CreatureInstrInfo t = c.go(EMPTY);
  ASSERT_EQ(t.instr, 0);
}

TEST(CreatureFixture, go1) {
  Species s("s");
  s.addInstruction("hop");
  s.addInstruction("go 0");
  Creature c(&s, 2);
  CreatureInstrInfo t = c.go(EMPTY);
  ASSERT_EQ(t.a, c.species);
}

TEST(CreatureFixture, go2) {
  Species s("s");
  s.addInstruction("infect");
  s.addInstruction("go 0");
  Creature c(&s, 2);
  CreatureInstrInfo t = c.go(EMPTY);
  ASSERT_EQ(t.instr, -1);
}

TEST(CreatureFixture, go3) {
  Species s("s");
  s.addInstruction("left");
  s.addInstruction("go 0");
  Creature c(&s, 2);
  CreatureInstrInfo t = c.go(EMPTY);
  ASSERT_EQ(t.instr, -1);
}

TEST(CreatureFixture, left) {
  Species s("s");
  s.addInstruction("left");
  s.addInstruction("go 0");
  Creature c(&s, 2);
  CreatureInstrInfo t = c.go(EMPTY);
  ASSERT_EQ(c.direction, 1);
}

TEST(CreatureFixture, right) {
  Species s("s");
  s.addInstruction("right");
  s.addInstruction("go 0");
  Creature c(&s, 2);
  CreatureInstrInfo t = c.go(EMPTY);
  ASSERT_EQ(c.direction, 3);
}

TEST(CreatureFixture, inFront) {
  Species s("s");
  Creature c(&s, 2);
  pair<int, int> p = c.inFront(make_pair(0, 0));
  ASSERT_TRUE(p == make_pair(0, 1));
}  

TEST(CreatureFixture, inFront1) {
  Species s("s");
  Creature c(&s, 1);
  pair<int, int> p = c.inFront(make_pair(0, 0));
  ASSERT_TRUE(p == make_pair(-1, 0));
}
 
TEST(CreatureFixture, inFront2) {
  Species s("s");
  Creature c(&s, 3);
  pair<int, int> p = c.inFront(make_pair(0, 0));
  ASSERT_TRUE(p == make_pair(1, 0));
}

TEST(CreatureFixture, beInfected) {
  Species s("s");
  Creature c(&s, 2);
  Species s2("s2");
  c.beInfected(&s2);
  ASSERT_EQ(c.species, &s2);
}

