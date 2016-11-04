// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Fernando Mendoza
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <sstream>
#include <string>

#include "gtest/gtest.h"

#include "Darwin.h"

using namespace std;

// ----
// test
// ----

TEST(Darwin_tests, darwin_output1) {
  Darwin t(4, 4);
  Species food('f');
  Creature c(food, NORTH);
  t.addCreature(c, make_tuple(2, 2));
  ostringstream output;
  output << t;

  string result = "Turn = 0.\n  0123\n0 ....\n1 ....\n2 ..f.\n3 ....\n\n";

  ASSERT_EQ(result, output.str());
}

TEST(Darwin_tests, darwin_output2) {
  Darwin t(10, 4);
  Species food('f');
  Creature c(food, NORTH);
  t.addCreature(c, make_tuple(8, 2));
  ostringstream output;
  output << t;

  string result = "Turn = 0.\n  0123\n0 ....\n1 ....\n2 ....\n3 ....\n4 "
                  "....\n5 ....\n6 ....\n7 ....\n8 ..f.\n9 ....\n\n";

  ASSERT_EQ(result, output.str());
}

TEST(Darwin_tests, darwin_output3) {
  Darwin t(10, 4);
  Species food('f');
  food.addInstruction(HOP);
  food.addInstruction(GO, 0);
  Creature c(food, NORTH);
  t.addCreature(c, make_tuple(8, 2));
  ostringstream output;
  t.run(10);
  output << t;

  string result = "Turn = 10.\n  0123\n0 ..f.\n1 ....\n2 ....\n3 ....\n4 "
                  "....\n5 ....\n6 ....\n7 ....\n8 ....\n9 ....\n\n";

  ASSERT_EQ(result, output.str());
}

TEST(Darwin_tests, darwin_run1) {
  Darwin t(8, 8);
  Species food('p');
  food.addInstruction(LEFT);
  food.addInstruction(GO, 0);
  Creature c(food, NORTH);
  t.addCreature(c, make_tuple(2, 2));
  ostringstream output;
  t.run(1);
  t.run(1);
  t.run(1);
  t.run(1);
  t.run(1);
  t.run(1);
  output << t;

  string result = "Turn = 6.\n  01234567\n0 ........\n1 ........\n2 "
                  "..p.....\n3 ........\n4 ........\n5 ........\n6 ........\n7 "
                  "........\n\n";

  ASSERT_EQ(result, output.str());
}

TEST(Darwin_tests, rover_vs_hopper) {
  Darwin t(10, 10);

  Species hopper('h');
  hopper.addInstruction(HOP);
  hopper.addInstruction(GO, 0);
  Creature c(hopper, NORTH);
  t.addCreature(c, make_tuple(8, 2));

  Species rover('r');
  rover.addInstruction(IF_ENEMY, 9);
  rover.addInstruction(IF_EMPTY, 7);
  rover.addInstruction(IF_RANDOM, 5);
  rover.addInstruction(LEFT);
  rover.addInstruction(GO, 0);
  rover.addInstruction(RIGHT);
  rover.addInstruction(GO, 0);
  rover.addInstruction(HOP);
  rover.addInstruction(GO, 0);
  rover.addInstruction(INFECT);
  rover.addInstruction(GO, 0);
  Creature d(rover, EAST);
  t.addCreature(d, make_tuple(5, 5));

  ostringstream output;
  t.run(50);
  output << t;

  string result = "Turn = 50.\n  0123456789\n0 ..........\n1 ..........\n2 "
                  "..........\n3 ..........\n4 ..........\n5 ..........\n6 "
                  "..........\n7 ..........\n8 ..........\n9 rr........\n\n";

  ASSERT_EQ(result, output.str());
}

TEST(Species, species_constructor1) {
  Species s('a');
  string p = s.representation();
  ASSERT_EQ("a", p);
}
TEST(Species, species_constructor2) {
  Species s('d');
  ASSERT_EQ("d", s.representation());
}
TEST(Species, species_constructor3) {
  Species s('8');
  ASSERT_EQ("8", s.representation());
}
TEST(Species, species_constructor4) {
  Species s('T');
  ASSERT_EQ("T", s.representation());
}
TEST(Species, species_constructor5) {
  Species s('~');
  ASSERT_EQ("~", s.representation());
}
TEST(Species, species_constructor6) {
  Species s(';');
  ASSERT_EQ(";", s.representation());
}
TEST(Species, species_constructor7) {
  Species s(';');
  ASSERT_EQ(";", s.representation());
}

TEST(Species, representation_test1) {
  Species s('1');
  ASSERT_EQ("1", s.representation());
}
TEST(Species, representation_test2) {
  Species s('2');
  string test = s.representation();
  ASSERT_EQ("2", test);
}
TEST(Species, representation_test3) {
  Species s('3');
  ASSERT_EQ("3", s.representation());
}

TEST(Species, instruction_test0) {
  Species s('r');
  s.addInstruction(HOP);
  tuple<int, int> ins = s.getNextInstruction(0);
  ASSERT_EQ(HOP, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));
}
TEST(Species, instruction_test1) {
  Species s('r');
  s.addInstruction(LEFT);
  tuple<int, int> ins = s.getNextInstruction(0);
  ASSERT_EQ(LEFT, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));
}
TEST(Species, instruction_test2) {
  Species s('r');
  s.addInstruction(RIGHT);
  tuple<int, int> ins = s.getNextInstruction(0);
  ASSERT_EQ(RIGHT, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));
}
TEST(Species, instruction_test3) {
  Species s('r');
  s.addInstruction(HOP);
  tuple<int, int> ins = s.getNextInstruction(0);
  ASSERT_EQ(HOP, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));
  s.addInstruction(HOP);
  ins = s.getNextInstruction(1);
  ASSERT_EQ(HOP, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));
  s.addInstruction(HOP);
  ins = s.getNextInstruction(2);
  ASSERT_EQ(HOP, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));
  s.addInstruction(HOP);
  ins = s.getNextInstruction(3);
  ASSERT_EQ(HOP, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));
}
TEST(Species, instruction_test4) {
  Species s('r');
  s.addInstruction(-10);
  tuple<int, int> ins = s.getNextInstruction(0);
  ASSERT_EQ(-10, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));
}

TEST(Species, instruction_test5) {
  Species s('r');
  s.addInstruction(IF_WALL, 1000);
  tuple<int, int> ins = s.getNextInstruction(0);
  ASSERT_EQ(IF_WALL, get<0>(ins));
  ASSERT_EQ(1000, get<1>(ins));
}
TEST(Species, instruction_test6) {
  Species s('r');
  s.addInstruction(HOP);
  tuple<int, int> ins = s.getNextInstruction(0);
  ASSERT_EQ(HOP, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));

  s.addInstruction(LEFT);
  ins = s.getNextInstruction(1);
  ASSERT_EQ(LEFT, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));

  s.addInstruction(RIGHT);
  ins = s.getNextInstruction(2);
  ASSERT_EQ(RIGHT, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));

  s.addInstruction(INFECT);
  ins = s.getNextInstruction(3);
  ASSERT_EQ(INFECT, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));

  s.addInstruction(IF_EMPTY, 0);
  ins = s.getNextInstruction(4);
  ASSERT_EQ(IF_EMPTY, get<0>(ins));
  ASSERT_EQ(0, get<1>(ins));

  s.addInstruction(IF_WALL, 0);
  ins = s.getNextInstruction(5);
  ASSERT_EQ(IF_WALL, get<0>(ins));
  ASSERT_EQ(0, get<1>(ins));

  s.addInstruction(IF_RANDOM, 0);
  ins = s.getNextInstruction(6);
  ASSERT_EQ(IF_RANDOM, get<0>(ins));
  ASSERT_EQ(0, get<1>(ins));

  s.addInstruction(IF_ENEMY, 0);
  ins = s.getNextInstruction(7);
  ASSERT_EQ(IF_ENEMY, get<0>(ins));
  ASSERT_EQ(0, get<1>(ins));

  s.addInstruction(GO, 0);
  ins = s.getNextInstruction(8);
  ASSERT_EQ(GO, get<0>(ins));
  ASSERT_EQ(0, get<1>(ins));
}
TEST(Species, get_instruction0) {
  Species s('r');
  s.addInstruction(HOP);
  tuple<int, int> ins = s.getNextInstruction(0);
  ASSERT_EQ(HOP, get<0>(ins));
  ASSERT_EQ(-1, get<1>(ins));
}
TEST(Species, get_instruction1) {
  Species s('r');
  s.addInstruction(GO, 0);
  tuple<int, int> ins = s.getNextInstruction(0);
  ASSERT_EQ(GO, get<0>(ins));
  ASSERT_EQ(0, get<1>(ins));
}

/* Creature */

TEST(Creature, Constructor) {
  Species s = Species('A');
  Creature c1 = Creature(s, WEST);
  Creature c2 = Creature(c1, EAST);
  ASSERT_EQ(c2.getSpecies(), "A");
}

TEST(Creature, OutputCreature1) {
  Species e('.');
  Creature c(e, NORTH);
  ASSERT_EQ(".", c.getSpecies());
}

TEST(Creature, OutputCreature2) {
  Species t('T');
  Creature c(t, NORTH);
  ASSERT_EQ("T", c.getSpecies());
}

TEST(Creature, OutputCreature3) {
  Species a('a');
  Creature c(a, NORTH);
  ASSERT_EQ("a", c.getSpecies());
}

TEST(Creature, OutputCreature4) {
  Species f('f');
  Creature c(f, NORTH);
  ASSERT_EQ("f", c.getSpecies());
}

TEST(Creature, OutputCreature5) {
  Species q('Q');
  Creature c(q, NORTH);
  ASSERT_EQ("Q", c.getSpecies());
}

TEST(Creature, OutputCreature6) {
  Species w('W');
  Creature c(w, NORTH);
  ASSERT_EQ("W", c.getSpecies());
}

TEST(Creature, FrontPosition1) {
  Species s = Species('A');
  Creature c = Creature(s, NORTH);
  tuple<int, int> result = c.getFrontPosition(make_tuple(0, 0));
  ASSERT_EQ(get<0>(result), 0);
  ASSERT_EQ(get<1>(result), -1);
}

TEST(Creature, FrontPosition2) {
  Species s = Species('A');
  Creature c = Creature(s, WEST);
  tuple<int, int> result = c.getFrontPosition(make_tuple(0, 0));
  ASSERT_EQ(get<0>(result), -1);
  ASSERT_EQ(get<1>(result), 0);
}

TEST(Creature, FrontPosition3) {
  Species s = Species('A');
  Creature c = Creature(s, SOUTH);
  tuple<int, int> result = c.getFrontPosition(make_tuple(0, 0));
  ASSERT_EQ(get<0>(result), 0);
  ASSERT_EQ(get<1>(result), 1);
}

TEST(Creature, FrontPosition4) {
  Species s = Species('A');
  Creature c = Creature(s, EAST);
  tuple<int, int> result = c.getFrontPosition(make_tuple(0, 0));
  ASSERT_EQ(get<0>(result), 1);
  ASSERT_EQ(get<1>(result), 0);
}

TEST(Creature, FrontPosition5) {
  Species s = Species('A');
  Creature c = Creature(s, NORTH);
  tuple<int, int> result = c.getFrontPosition(make_tuple(5, 5));
  ASSERT_EQ(get<0>(result), 5);
  ASSERT_EQ(get<1>(result), 4);
}

TEST(Creature, FrontPosition6) {
  Species s = Species('A');
  Creature c = Creature(s, EAST);
  tuple<int, int> result = c.getFrontPosition(make_tuple(5, 5));
  ASSERT_EQ(get<0>(result), 6);
  ASSERT_EQ(get<1>(result), 5);
}

TEST(Creature, FrontPosition7) {
  Species s = Species('A');
  Creature c = Creature(s, WEST);
  tuple<int, int> result = c.getFrontPosition(make_tuple(10, 10));
  ASSERT_EQ(get<0>(result), 9);
  ASSERT_EQ(get<1>(result), 10);
}

TEST(Creature, FrontPosition8) {
  Species s = Species('A');
  Creature c = Creature(s, SOUTH);
  tuple<int, int> result = c.getFrontPosition(make_tuple(10, 10));
  ASSERT_EQ(get<0>(result), 10);
  ASSERT_EQ(get<1>(result), 11);
}

TEST(Creature, Execute1) {
  Species foodSpecies('f');
  foodSpecies.addInstruction(LEFT);
  foodSpecies.addInstruction(GO, 0);

  Creature food(foodSpecies, EAST);
  tuple<int, int, int, int> result = food.execute(make_tuple(0, 0));

  ASSERT_EQ(get<0>(result), 0);
  ASSERT_EQ(get<1>(result), 0);
  ASSERT_EQ(get<2>(result), LEFT);
  ASSERT_EQ(get<3>(result), -1);
}

TEST(Creature, Execute2) {
  Species hopperSpecies('h');
  hopperSpecies.addInstruction(HOP);

  Creature hopper(hopperSpecies, EAST);
  tuple<int, int, int, int> result = hopper.execute(make_tuple(0, 0));

  ASSERT_EQ(get<0>(result), 1);
  ASSERT_EQ(get<1>(result), 0);
  ASSERT_EQ(get<2>(result), HOP);
  ASSERT_EQ(get<3>(result), -1);
}

TEST(Creature, Execute3) {
  Species hopperSpecies('h');
  hopperSpecies.addInstruction(HOP);

  Creature hopper(hopperSpecies, NORTH);
  tuple<int, int, int, int> result = hopper.execute(make_tuple(0, 0));

  ASSERT_EQ(get<0>(result), 0);
  ASSERT_EQ(get<1>(result), -1);
  ASSERT_EQ(get<2>(result), HOP);
  ASSERT_EQ(get<3>(result), -1);
}

TEST(Creature, Execute4) {
  Species hopperSpecies('h');
  hopperSpecies.addInstruction(RIGHT);

  Creature hopper(hopperSpecies, EAST);
  tuple<int, int, int, int> result = hopper.execute(make_tuple(10, 10));

  ASSERT_EQ(get<0>(result), 10);
  ASSERT_EQ(get<1>(result), 10);
  ASSERT_EQ(get<2>(result), EAST);
  ASSERT_EQ(get<3>(result), -1);
}

TEST(Creature, Execute5) {
  Species hopperSpecies('h');
  hopperSpecies.addInstruction(INFECT);

  Creature hopper(hopperSpecies, NORTH);
  tuple<int, int, int, int> result = hopper.execute(make_tuple(5, 5));

  ASSERT_EQ(get<0>(result), 5);
  ASSERT_EQ(get<1>(result), 5);
  ASSERT_EQ(get<2>(result), INFECT);
  ASSERT_EQ(get<3>(result), -1);
}
