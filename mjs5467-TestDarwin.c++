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
#include <cstdlib> // srand
#include <sstream> // ostringstream
#include <string>  // string

#include "Darwin.h"

using namespace std;

// ----
// test
// ----

TEST(DarwinFixture, test1) {
  Darwin x(1, 1);
  ostringstream s;
  s << x;
  string s2 = "Turn = 0.\n  0\n0 .\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(DarwinFixture, test2) {
  Darwin x(1, 12);
  ostringstream s;
  s << x;
  string s2 = "Turn = 0.\n  012345678901\n0 ............\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(DarwinFixture, test3) {
  Darwin x(12, 1);
  ostringstream s;
  s << x;
  string s2 = "Turn = 0.\n  0\n0 .\n1 .\n2 .\n3 .\n4 .\n5 .\n6 .\n7 .\n8 .\n9 "
              ".\n0 .\n1 .\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(DarwinFixture, test4) {
  Darwin x(2, 2);
  ostringstream s;
  s << x;
  string s2 = "Turn = 0.\n  01\n0 ..\n1 ..\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(DarwinFixture, test5) {
  Darwin x(1, 1);
  x.add_creature(Creature(0, 0, 'c'), 0, 0);
  ostringstream s;
  s << x;
  string s2 = "Turn = 0.\n  0\n0 c\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(DarwinFixture, test6) {
  Darwin x(2, 2);
  x.add_creature(Creature(0, 0, 'c'), 0, 0);
  x.add_creature(Creature(0, 2, 'x'), 1, 1);
  ostringstream s;
  s << x;
  string s2 = "Turn = 0.\n  01\n0 c.\n1 .x\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(DarwinFixture, test7) {
  Darwin x(2, 2);
  x.add_creature(Creature(0, 0, 'c'), 0, 0);
  x.add_creature(Creature(0, 2, 'x'), 1, 1);
  x.add_creature(Creature(0, 3, 'a'), 1, 0);
  x.add_creature(Creature(0, 1, 'b'), 0, 1);
  ostringstream s;
  s << x;
  string s2 = "Turn = 0.\n  01\n0 cb\n1 ax\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(DarwinFixture, test8) {
  Darwin x(1, 1);
  Species my_species;
  my_species.add_instruction("left");
  my_species.add_instruction("go 0");
  x.add_creature(Creature(&my_species, 0, 'c'), 0, 0);
  x.advance(5);
  ostringstream s;
  s << x;
  string s2 = "Turn = 5.\n  0\n0 c\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(DarwinFixture, test9) {
  Darwin x(2, 2);
  Species my_species;
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  x.add_creature(Creature(&my_species, 2, 'c'), 0, 0);
  x.add_creature(Creature(&my_species, 1, 'd'), 1, 0);
  x.advance(1);
  ostringstream s;
  s << x;
  string s2 = "Turn = 1.\n  01\n0 c.\n1 .d\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(DarwinFixture, test10) {
  Darwin x(2, 2);
  Species my_species;
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  x.add_creature(Creature(&my_species, 2, 'c'), 0, 0);
  x.add_creature(Creature(&my_species, 1, 'd'), 1, 0);
  x.advance(2);
  ostringstream s;
  s << x;
  string s2 = "Turn = 2.\n  01\n0 ..\n1 cd\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(DarwinFixture, test11) {
  Darwin x(2, 2);
  Species my_species;
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  x.add_creature(Creature(&my_species, 2, 'c'), 0, 0);
  x.add_creature(Creature(&my_species, 1, 'd'), 1, 0);
  x.advance(10);
  ostringstream s;
  s << x;
  string s2 = "Turn = 10.\n  01\n0 ..\n1 cd\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

/* This tests whether a creature will only be moved
   once even though it will be getting passed twice
   in the loop in the advance method */
TEST(DarwinFixture, test12) {
  Darwin x(3, 1);
  Species my_species;
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  x.add_creature(Creature(&my_species, 2, 'c'), 0, 0);
  x.advance(1);
  ostringstream s;
  s << x;
  string s2 = "Turn = 1.\n  0\n0 .\n1 c\n2 .\n";
  ASSERT_STREQ(s2.c_str(), s.str().c_str());
}

TEST(CreatureFixture, test1) {
  Species my_species;
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  int move_num = Creature(&my_species, 0, 'm').move(0, 0, 0, 0);
  ASSERT_EQ(-1, move_num);
}

TEST(CreatureFixture, test2) {
  Species my_species;
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  Creature my_creature(&my_species, 1, 'm');
  Creature m;
  int move_num = my_creature.move(0, &m, 0, 0);
  ASSERT_EQ(1, move_num);
}

TEST(CreatureFixture, test3) {
  Species my_species;
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  Creature my_creature(&my_species, 1, 'm');
  Creature m(&my_species, 2, 'm');
  int move_num = my_creature.move(0, &m, 0, 0);
  ASSERT_EQ(-1, move_num);
}

TEST(CreatureFixture, test4) {
  Species my_species;
  my_species.add_instruction("left");
  my_species.add_instruction("go 0");
  Creature my_creature(&my_species, 1, 'm');
  Creature m;
  int move_num = my_creature.move(0, &m, 0, 0);
  ASSERT_EQ(-1, move_num);
}

TEST(CreatureFixture, test5) {
  Species my_species;
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  Creature my_creature(&my_species, 3, 'm');
  Creature m;
  int move_num = my_creature.move(0, &m, 0, &m);
  ASSERT_EQ(3, move_num);
}

TEST(CreatureFixture, test6) {
  Species my_species;
  my_species.add_instruction("infect");
  my_species.add_instruction("go 0");
  Creature my_creature(&my_species, 1, 'm');
  Creature m;
  int move_num = my_creature.move(0, &m, 0, 0);
  ASSERT_EQ(-1, move_num);
}

TEST(CreatureFixture, test7) {
  Species my_species;
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  Creature my_creature(&my_species, 1, 'm');
  Species s2;
  s2.add_instruction("left");
  s2.add_instruction("go 0");
  Creature m(&s2, 2, 's');
  my_creature.infect(&m);
  ostringstream a, b;
  a << my_creature;
  b << m;
  ASSERT_STREQ(a.str().c_str(), b.str().c_str());
}

TEST(CreatureFixture, test8) {
  Species my_species;
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  Creature my_creature(&my_species, 1, 'm');
  Species s2;
  s2.add_instruction("left");
  s2.add_instruction("go 0");
  Creature m(&s2, 1, 's');
  my_creature.infect(&m);
  Creature m2;
  int move_num = m.move(0, &m2, 0, 0);
  ASSERT_EQ(1, move_num);
}

TEST(CreatureFixture, test9) {
  Species my_species;
  my_species.add_instruction("if_enemy 3");
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  my_species.add_instruction("infect");
  my_species.add_instruction("go 0");
  Creature my_creature(&my_species, 1, 'm');
  Species s2;
  s2.add_instruction("left");
  s2.add_instruction("go 0");
  Creature m(&s2, 1, 's');
  my_creature.infect(&m);
  Creature m2(&s2, 2, 't');
  m.move(0, &m2, 0, 0);
  Creature m3;
  int move_num = m2.move(0, 0, &m3, 0);
  ASSERT_EQ(2, move_num);
}

TEST(CreatureFixture, test10) {
  Species my_species;
  my_species.add_instruction("if_enemy 3");
  my_species.add_instruction("hop");
  my_species.add_instruction("go 0");
  my_species.add_instruction("infect");
  my_species.add_instruction("go 0");
  Creature my_creature(&my_species, 1, 'm');
  Species s2;
  s2.add_instruction("left");
  s2.add_instruction("go 0");
  Creature m(&s2, 1, 's');
  my_creature.infect(&m);
  Creature m2(&s2, 3, 't');
  m.move(0, &m2, 0, 0);
  Creature m3;
  int move_num = m2.move(0, 0, 0, &m3);
  ASSERT_EQ(3, move_num);
}

TEST(CreatureFixture, test11) {
  Species my_species;
  my_species.add_instruction("infect");
  my_species.add_instruction("go 0");
  Creature my_creature(&my_species, 1, 'm');
  Creature my_creature2(&my_species, 2, 'm');
  int move_num = my_creature.move(0, &my_creature2, 0, 0);
  ASSERT_EQ(-1, move_num);
}

TEST(SpeciesFixture, test1) {
  srand(0);
  Species s;
  s.add_instruction("if_random 3");
  s.add_instruction("right");
  s.add_instruction("go 0");
  s.add_instruction("hop");
  s.add_instruction("go 0");
  Species::Instruction flag;
  int pc = s.execute(0, Species::EMPTY, flag);
  ASSERT_EQ(4, pc);
}

TEST(SpeciesFixture, test2) {
  srand(0);
  Species s;
  s.add_instruction("if_random 3");
  s.add_instruction("right");
  s.add_instruction("go 0");
  s.add_instruction("hop");
  s.add_instruction("go 0");
  Species::Instruction flag;
  s.execute(0, Species::EMPTY, flag);
  ASSERT_EQ(0, flag);
}

TEST(SpeciesFixture, test3) {
  Species s;
  s.add_instruction("if_wall 3");
  s.add_instruction("hop");
  s.add_instruction("go 0");
  s.add_instruction("right");
  s.add_instruction("go 0");
  Species::Instruction flag;
  int pc = s.execute(0, Species::WALL, flag);
  ASSERT_EQ(4, pc);
}

TEST(SpeciesFixture, test4) {
  Species s;
  s.add_instruction("if_wall 3");
  s.add_instruction("hop");
  s.add_instruction("go 0");
  s.add_instruction("right");
  s.add_instruction("go 0");
  Species::Instruction flag;
  s.execute(0, Species::WALL, flag);
  ASSERT_EQ(2, flag);
}

TEST(SpeciesFixture, test5) {
  Species s;
  s.add_instruction("if_empty 3");
  s.add_instruction("hop");
  s.add_instruction("go 0");
  s.add_instruction("infect");
  s.add_instruction("go 0");
  Species::Instruction flag;
  int pc = s.execute(0, Species::EMPTY, flag);
  ASSERT_EQ(4, pc);
}

TEST(SpeciesFixture, test6) {
  Species s;
  s.add_instruction("if_empty 3");
  s.add_instruction("hop");
  s.add_instruction("go 0");
  s.add_instruction("infect");
  s.add_instruction("go 0");
  Species::Instruction flag;
  s.execute(0, Species::EMPTY, flag);
  ASSERT_EQ(-1, flag);
}

TEST(SpeciesFixture, test7) {
  Species s;
  s.add_instruction("if_enemy 3");
  s.add_instruction("hop");
  s.add_instruction("go 0");
  s.add_instruction("infect");
  s.add_instruction("go 0");
  Species::Instruction flag;
  s.execute(0, Species::DIFF_SPECIES, flag);
  ASSERT_EQ(3, flag);
}

TEST(SpeciesFixture, test8) {
  Species s;
  s.add_instruction("if_wall 3");
  s.add_instruction("hop");
  s.add_instruction("go 0");
  s.add_instruction("infect");
  s.add_instruction("go 0");
  Species::Instruction flag;
  int pc = s.execute(0, Species::WALL, flag);
  ASSERT_EQ(4, pc);
}

TEST(SpeciesFixture, test9) {
  Species s;
  s.add_instruction("if_wall 3");
  s.add_instruction("hop");
  s.add_instruction("go 0");
  s.add_instruction("infect");
  s.add_instruction("go 0");
  Species::Instruction flag;
  s.execute(0, Species::WALL, flag);
  ASSERT_EQ(-1, flag);
}

TEST(SpeciesFixture, test10) {
  Species s;
  s.add_instruction("if_wall 3");
  s.add_instruction("hop");
  s.add_instruction("go 0");
  s.add_instruction("infect");
  s.add_instruction("go 0");
  Species::Instruction flag;
  s.execute(0, Species::EMPTY, flag);
  ASSERT_EQ(0, flag);
}

TEST(SpeciesFixture, test11) {
  Species s;
  s.add_instruction("if_wall 3");
  s.add_instruction("infect");
  s.add_instruction("go 0");
  s.add_instruction("left");
  s.add_instruction("go 0");
  Species::Instruction flag;
  s.execute(0, Species::SAME_SPECIES, flag);
  ASSERT_EQ(-1, flag);
}

TEST(SpeciesFixture, test12) {
  Species s;
  s.add_instruction("infect");
  s.add_instruction("go 0");
  Species::Instruction flag;
  s.execute(0, Species::EMPTY, flag);
  ASSERT_EQ(-1, flag);
}

TEST(SpeciesFixture, test13) {
  Species s;
  s.add_instruction("infect");
  s.add_instruction("go 0");
  Species::Instruction flag;
  s.execute(0, Species::SAME_SPECIES, flag);
  ASSERT_EQ(-1, flag);
}
