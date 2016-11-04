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

// -----------
// parse tests
// -----------

TEST(ParseNameFixture, test0) {
  Instruction::Name name = Instruction::parseName("hop");
  ASSERT_EQ(name, Instruction::Name::HOP);
}

TEST(ParseNameFixture, test1) {
  Instruction::Name name = Instruction::parseName("left");
  ASSERT_EQ(name, Instruction::Name::LEFT);
}

TEST(ParseNameFixture, test2) {
  Instruction::Name name = Instruction::parseName("right");
  ASSERT_EQ(name, Instruction::Name::RIGHT);
}

TEST(ParseNameFixture, test3) {
  Instruction::Name name = Instruction::parseName("infect");
  ASSERT_EQ(name, Instruction::Name::INFECT);
}

TEST(ParseNameFixture, test4) {
  Instruction::Name name = Instruction::parseName("if_empty");
  ASSERT_EQ(name, Instruction::Name::IF_EMPTY);
}

TEST(ParseNameFixture, test5) {
  Instruction::Name name = Instruction::parseName("if_wall");
  ASSERT_EQ(name, Instruction::Name::IF_WALL);
}

TEST(ParseNameFixture, test6) {
  Instruction::Name name = Instruction::parseName("if_random");
  ASSERT_EQ(name, Instruction::Name::IF_RANDOM);
}

TEST(ParseNameFixture, test7) {
  Instruction::Name name = Instruction::parseName("if_enemy");
  ASSERT_EQ(name, Instruction::Name::IF_ENEMY);
}

TEST(ParseNameFixture, test8) {
  Instruction::Name name = Instruction::parseName("go");
  ASSERT_EQ(name, Instruction::Name::GO);
}

// -------------------------
// instruction factory tests
// -------------------------

TEST(FactoryFixture, test0) {
  Instruction instr = Instruction::parse("hop");
  ASSERT_EQ(instr.name, Instruction::Name::HOP);
  ASSERT_EQ(instr.arg, 0);
}

TEST(FactoryFixture, test1) {
  Instruction instr = Instruction::parse("left");
  ASSERT_EQ(instr.name, Instruction::Name::LEFT);
  ASSERT_EQ(instr.arg, 0);
}

TEST(FactoryFixture, test2) {
  Instruction instr = Instruction::parse("right");
  ASSERT_EQ(instr.name, Instruction::Name::RIGHT);
  ASSERT_EQ(instr.arg, 0);
}

TEST(FactoryFixture, test3) {
  Instruction instr = Instruction::parse("infect");
  ASSERT_EQ(instr.name, Instruction::Name::INFECT);
  ASSERT_EQ(instr.arg, 0);
}

TEST(FactoryFixture, test4) {
  Instruction instr = Instruction::parse("if_empty 1");
  ASSERT_EQ(instr.name, Instruction::Name::IF_EMPTY);
  ASSERT_EQ(instr.arg, 1);
}

TEST(FactoryFixture, test5) {
  Instruction instr = Instruction::parse("if_wall 1");
  ASSERT_EQ(instr.name, Instruction::Name::IF_WALL);
  ASSERT_EQ(instr.arg, 1);
}

TEST(FactoryFixture, test6) {
  Instruction instr = Instruction::parse("if_random 1");
  ASSERT_EQ(instr.name, Instruction::Name::IF_RANDOM);
  ASSERT_EQ(instr.arg, 1);
}

TEST(FactoryFixture, test7) {
  Instruction instr = Instruction::parse("if_enemy 1");
  ASSERT_EQ(instr.name, Instruction::Name::IF_ENEMY);
  ASSERT_EQ(instr.arg, 1);
}

TEST(FactoryFixture, test8) {
  Instruction instr = Instruction::parse("go 1");
  ASSERT_EQ(instr.name, Instruction::Name::GO);
  ASSERT_EQ(instr.arg, 1);
}

// Instruction type

TEST(InstructionFixture, type0) {
  Instruction instr = Instruction::parse("hop");
  ASSERT_EQ(Instruction::Type::ACTION, Instruction::type(instr.name));
}

TEST(InstructionFixture, type1) {
  Instruction instr = Instruction::parse("left");
  ASSERT_EQ(Instruction::Type::ACTION, Instruction::type(instr.name));
}

TEST(InstructionFixture, type2) {
  Instruction instr = Instruction::parse("right");
  ASSERT_EQ(Instruction::Type::ACTION, Instruction::type(instr.name));
}

TEST(InstructionFixture, type3) {
  Instruction instr = Instruction::parse("infect");
  ASSERT_EQ(Instruction::Type::ACTION, Instruction::type(instr.name));
}

TEST(InstructionFixture, type4) {
  Instruction instr = Instruction::parse("if_empty 1");
  ASSERT_EQ(Instruction::Type::CONTROL, Instruction::type(instr.name));
}

TEST(InstructionFixture, type5) {
  Instruction instr = Instruction::parse("if_wall 1");
  ASSERT_EQ(Instruction::Type::CONTROL, Instruction::type(instr.name));
}

TEST(InstructionFixture, type6) {
  Instruction instr = Instruction::parse("if_random 1");
  ASSERT_EQ(Instruction::Type::CONTROL, Instruction::type(instr.name));
}

TEST(InstructionFixture, type7) {
  Instruction instr = Instruction::parse("if_enemy 1");
  ASSERT_EQ(Instruction::Type::CONTROL, Instruction::type(instr.name));
}

TEST(InstructionFixture, type8) {
  Instruction instr = Instruction::parse("go 1");
  ASSERT_EQ(Instruction::Type::CONTROL, Instruction::type(instr.name));
}

// Instruction execution

TEST(InstructionFixture, hop0) {
  Darwin darwin(5, 5);
  Species sp({"hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {1, 2}));
}

TEST(InstructionFixture, hop1) {
  Darwin darwin(5, 5);
  Species sp({"hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 0, 0);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {0, 0}));
}

TEST(InstructionFixture, hop2) {
  Darwin darwin(5, 5);
  Species sp({"hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::EAST);
  darwin.addCreature(cr, 0, 4);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {0, 4}));
}

TEST(InstructionFixture, hop3) {
  Darwin darwin(5, 5);
  Species sp({"hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::WEST);
  darwin.addCreature(cr, 0, 0);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {0, 0}));
}

TEST(InstructionFixture, go0) {
  Darwin darwin(5, 5);
  Species sp({"go 2", "hop", "left"}, 'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {2, 2}));
}

TEST(InstructionFixture, go1) {
  Darwin darwin(5, 5);
  Species sp({"go 2", "hop", "go 1", "left"}, 'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {1, 2}));
}

TEST(InstructionFixture, left0) {
  Darwin darwin(5, 5);
  Species sp({"left", "hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {2, 1}));
}

TEST(InstructionFixture, left1) {
  Darwin darwin(5, 5);
  Species sp({"left", "hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::WEST);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {3, 2}));
}

TEST(InstructionFixture, left2) {
  Darwin darwin(5, 5);
  Species sp({"left", "hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::SOUTH);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {2, 3}));
}

TEST(InstructionFixture, left3) {
  Darwin darwin(5, 5);
  Species sp({"left", "hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::EAST);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {1, 2}));
}

TEST(InstructionFixture, right0) {
  Darwin darwin(5, 5);
  Species sp({"right", "hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {2, 3}));
}

TEST(InstructionFixture, right1) {
  Darwin darwin(5, 5);
  Species sp({"right", "hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::EAST);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {3, 2}));
}

TEST(InstructionFixture, right2) {
  Darwin darwin(5, 5);
  Species sp({"right", "hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::SOUTH);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {2, 1}));
}

TEST(InstructionFixture, right3) {
  Darwin darwin(5, 5);
  Species sp({"right", "hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::WEST);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {1, 2}));
}

TEST(InstructionFixture, infect) {
  Darwin darwin(5, 5);
  Species sp({"infect", "go 0"}, 'x');
  Species f({"left", "go 0"}, 'f');
  Creature cr(&sp, Direction::SOUTH);
  Creature en(&f, Direction::NORTH);
  darwin.addCreature(cr, 2, 2);
  darwin.addCreature(en, 3, 2);
  ASSERT_EQ(CellContent::ENEMY, darwin.getContent(cr, {3, 2}));
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {3, 2}));
}

TEST(InstructionFixture, if_empty0) {
  Darwin darwin(5, 5);
  Species sp({"if_empty 2", "right", "hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {1, 2}));
}

TEST(InstructionFixture, if_empty1) {
  Darwin darwin(5, 5);
  Species sp({"if_empty 2", "right", "hop", "go 0"}, 'x');
  Creature cr(&sp, Direction::SOUTH);
  Creature other(&sp, Direction::SOUTH);
  darwin.addCreature(cr, 2, 2);
  darwin.addCreature(other, 3, 2);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {2, 2}));
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {4, 2}));
}

TEST(InstructionFixture, if_empty2) {
  Darwin darwin(5, 5);
  Species sp({"if_empty 2", "left", "hop", "go 0", "right", "hop", "go 0"},
             'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 0, 2);
  darwin.executeTurn();
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {0, 1}));
}

TEST(InstructionFixture, if_empty3) {
  Darwin darwin(5, 5);
  Species sp({"if_empty 2", "left", "hop", "go 0", "right", "hop", "go 0"},
             'x');
  Species f({"left", "go 0"}, 'f');
  Creature cf(&f, Direction::NORTH);
  Creature cr(&sp, Direction::SOUTH);
  darwin.addCreature(cr, 0, 2);
  darwin.addCreature(cr, 1, 2);
  darwin.executeTurn();
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {0, 3}));
}

TEST(InstructionFixture, if_wall0) {
  Darwin darwin(5, 5);
  Species sp({"if_wall 3", "hop", "go 0", "right", "go 0"}, 'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 0, 2);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {0, 2}));
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {0, 3}));
}

TEST(InstructionFixture, if_wall1) {
  Darwin darwin(5, 5);
  Species sp({"if_wall 3", "hop", "go 0", "right", "go 0"}, 'x');
  Creature cr(&sp, Direction::WEST);
  darwin.addCreature(cr, 2, 0);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {2, 0}));
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {1, 0}));
}

TEST(InstructionFixture, if_wall2) {
  Darwin darwin(5, 5);
  Species sp({"if_wall 3", "hop", "go 0", "right", "go 0"}, 'x');
  Creature cr(&sp, Direction::SOUTH);
  darwin.addCreature(cr, 4, 2);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {4, 2}));
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {4, 1}));
}

TEST(InstructionFixture, if_wall3) {
  Darwin darwin(5, 5);
  Species sp({"if_wall 3", "hop", "go 0", "right", "go 0"}, 'x');
  Creature cr(&sp, Direction::EAST);
  darwin.addCreature(cr, 2, 4);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {2, 4}));
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {3, 4}));
}

TEST(InstructionFixture, if_random0) {
  srand(0);
  Darwin darwin(5, 5);
  Species sp({"if_random 3", // it's odd
              "hop", "go 0", "right", "go 0"},
             'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {2, 2}));
}

TEST(InstructionFixture, if_random1) {
  srand(2);
  Darwin darwin(5, 5);
  Species sp({"if_random 3", // it's odd
              "hop", "go 0", "right", "go 0"},
             'x');
  Creature cr(&sp, Direction::NORTH);
  darwin.addCreature(cr, 2, 2);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {1, 2}));
}

TEST(InstructionFixture, if_enemy) {
  Darwin darwin(5, 5);
  Species sp({"if_enemy 3", "left", "go 0", "infect", "go 0"}, 'x');
  Species f({"left", "go 0"}, 'f');
  Creature cr(&sp, Direction::WEST);
  Creature other(&f, Direction::SOUTH);
  darwin.addCreature(cr, 2, 2);
  darwin.addCreature(other, 3, 2);
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {2, 2}));
  ASSERT_EQ(CellContent::ENEMY, darwin.getContent(cr, {3, 2}));
  darwin.executeTurn();
  ASSERT_EQ(CellContent::FRIEND, darwin.getContent(cr, {3, 2}));
}

TEST(InstructionFixture, equals) {
  Instruction a = Instruction::parse("hop");
  Instruction b = Instruction::parse("hop");
  ASSERT_TRUE(a == b);
}

TEST(InstructionFixture, not_equals) {
  Instruction a = Instruction::parse("hop");
  Instruction b = Instruction::parse("left");
  ASSERT_FALSE(a == b);
}

// Species

TEST(SpeciesFixture, index) {
  Species s({"hop", "go 0"}, 'w');
  ASSERT_EQ(Instruction::Name::HOP, s[0].name);
  ASSERT_EQ(Instruction::Name::GO, s[1].name);
}

TEST(SpeciesFixture, equality) {
  Species s({"hop", "go 0"}, 'w');
  Species t({"hop", "go 0"}, 'w');
  ASSERT_TRUE(s == t);
}

TEST(SpeciesFixture, inequality0) {
  Species s({"hop", "go 0"}, 'w');
  Species t({"hop", "go 0"}, 'h');
  ASSERT_FALSE(s == t);
}

TEST(SpeciesFixture, inequality1) {
  Species s({"hop", "go 0"}, 'w');
  Species t({"hop", "go 1"}, 'w');
  ASSERT_FALSE(s == t);
}

// Creature

TEST(CreatureFixture, get_infected) {
  Species s({"hop", "go 0"}, 'w');
  Species t({"hop", "go 1"}, 'w');

  Creature a(&s, Direction::NORTH);
  Creature b(&t, Direction::SOUTH);

  ASSERT_FALSE(a.sameSpecies(b));
  a.getInfected(b);
  ASSERT_TRUE(a.sameSpecies(b));
}

TEST(CreatureFixture, front0) {
  Species s({"hop", "go 0"}, 'w');
  Creature a(&s, Direction::NORTH);
  Point p = {2, 2};
  Point e = {1, 2};
  ASSERT_EQ(e.row, a.front(p).row);
  ASSERT_EQ(e.col, a.front(p).col);
}

TEST(CreatureFixture, front1) {
  Species s({"hop", "go 0"}, 'w');
  Creature a(&s, Direction::SOUTH);
  Point p = {2, 2};
  Point e = {3, 2};
  ASSERT_EQ(e.row, a.front(p).row);
  ASSERT_EQ(e.col, a.front(p).col);
}

TEST(CreatureFixture, front2) {
  Species s({"hop", "go 0"}, 'w');
  Creature a(&s, Direction::EAST);
  Point p = {2, 2};
  Point e = {2, 3};
  ASSERT_EQ(e.row, a.front(p).row);
  ASSERT_EQ(e.col, a.front(p).col);
}

TEST(CreatureFixture, front3) {
  Species s({"hop", "go 0"}, 'w');
  Creature a(&s, Direction::WEST);
  Point p = {2, 2};
  Point e = {2, 1};
  ASSERT_EQ(e.row, a.front(p).row);
  ASSERT_EQ(e.col, a.front(p).col);
}

// ---
// prints
// ---

TEST(PrintFixture, species0) {
  Species s({"left", "go 0"}, 'x');
  ostringstream o;
  s.print(o);
  ASSERT_EQ("x", o.str());
}

TEST(PrintFixture, species1) {
  Species s({"left", "go 0"}, 'a');
  ostringstream o;
  s.print(o);
  ASSERT_EQ("a", o.str());
}

TEST(PrintFixture, creature0) {
  Species s({"left", "go 0"}, 'a');
  Creature c(&s, Direction::NORTH);
  ostringstream o;
  c.print(o);
  ASSERT_EQ("a", o.str());
}

TEST(PrintFixture, creature1) {
  Species s({"left", "go 0"}, 'x');
  Creature c(&s, Direction::NORTH);
  ostringstream o;
  c.print(o);
  ASSERT_EQ("x", o.str());
}

TEST(PrintFixture, darwin0) {
  Darwin d(2, 2);
  Species s({"left", "go 0"}, 'a');
  Creature c(&s, Direction::NORTH);
  d.addCreature(c, 0, 0);
  ostringstream o;
  d.print(o);
  ASSERT_EQ("  01\n0 a.\n1 ..\n", o.str());
}

TEST(PrintFixture, darwin1) {
  Darwin d(1, 11);
  Species s({"left", "go 0"}, 'a');
  Creature c(&s, Direction::NORTH);
  d.addCreature(c, 0, 0);
  ostringstream o;
  d.print(o);
  ASSERT_EQ("  01234567890\n0 a..........\n", o.str());
}

TEST(PrintFixture, darwin2) {
  Darwin d(11, 1);
  Species s({"left", "go 0"}, 'a');
  Creature c(&s, Direction::NORTH);
  d.addCreature(c, 0, 0);
  ostringstream o;
  d.print(o);
  ASSERT_EQ("  0\n0 a\n1 .\n2 .\n3 .\n4 .\n5 .\n6 .\n7 .\n8 .\n9 .\n0 .\n",
            o.str());
}
// ----
// test
// ----

TEST(DarwinFixture, test) { ASSERT_TRUE(true); }
