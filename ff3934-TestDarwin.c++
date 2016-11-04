// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <sstream>
#include "gtest/gtest.h"

#include "Darwin.h"

using namespace std;

// ------------------------
// testing Spcecies methods
// ------------------------

// testing addInstruction
TEST(SpeciesFixture, addInstruction_test1) {
   Species s;
   s.addInstruction ("go 4");
   ASSERT_TRUE(s.prog.at(0).compare("go 4") == 0);}

TEST(SpeciesFixture, addInstruction_test2) {
   Species s;
   s.addInstruction ("hop");
   ASSERT_TRUE(s.prog.at(0).compare("hop") == 0);}

TEST(SpeciesFixture, addInstruction_test3) {
   Species s;
   s.addInstruction ("if_enemy 2");
   s.addInstruction ("hop");
   s.addInstruction ("go 0");
   ASSERT_TRUE(s.prog.at(0).compare("if_enemy 2") == 0);
   ASSERT_TRUE(s.prog.at(1).compare("hop") == 0);
   ASSERT_TRUE(s.prog.at(2).compare("go 0") == 0);}

// testing read
TEST(SpeciesFixture, read_test1) {
   Species s;
   s.addInstruction ("go 4");
   ASSERT_TRUE(s.read(0).compare("go 4") == 0);}

TEST(SpeciesFixture, read_test2) {
   Species s;
   s.addInstruction ("hop");
   ASSERT_TRUE(s.read(0).compare("hop") == 0);}

TEST(SpeciesFixture, read_test3) {
   Species s;
   s.addInstruction ("if_enemy 2");
   s.addInstruction ("hop");
   s.addInstruction ("go 0");
   ASSERT_TRUE(s.read(0).compare("if_enemy 2") == 0);
   ASSERT_TRUE(s.read(1).compare("hop") == 0);
   ASSERT_TRUE(s.read(2).compare("go 0") == 0);}

// ------------------------
// testing Creature methods
// ------------------------

// testing isAction
TEST(CreatureFixture, isAction_test1) {
   Species s;
   Creature c(s, h, 'c');
   ASSERT_TRUE(c.isAction("hop"));}

TEST(CreatureFixture, isAction_test2) {
   Species s;
   Creature c(s, h, 'c');
   ASSERT_TRUE(c.isAction("left"));
   ASSERT_TRUE(c.isAction("right"));
   ASSERT_TRUE(c.isAction("infect"));
   ASSERT_TRUE(c.isAction("hop"));}

TEST(CreatureFixture, isAction_test3) {
   Species s;
   Creature c(s, h, 'c');
   ASSERT_FALSE(c.isAction("if_enemy 4"));
   ASSERT_FALSE(c.isAction("if_empty 5"));
   ASSERT_FALSE(c.isAction("if_random 7"));
   ASSERT_FALSE(c.isAction("go 0"));
   ASSERT_FALSE(c.isAction("if_wall 0"));}

// testing updatePC
TEST(CreatureFixture, updatePC_test1) {
   Species s;
   Creature c(s, h, 'c');
   c.updatePC(5);
   ASSERT_TRUE(c.pc == 5);}

TEST(CreatureFixture, updatePC_test2) {
   Species s;
   Creature c(s, h, 'c');
   c.updatePC(8);
   ASSERT_FALSE(c.pc == 5);}

TEST(CreatureFixture, updatePC_test3) {
   Species s;
   Creature c(s, h, 'c');
   c.updatePC(4);
   ASSERT_TRUE(c.pc == 4);
   c.updatePC(9);
   ASSERT_TRUE(c.pc == 9);}

// testing operator<<
TEST(CreatureFixture, operator_test1) {
   Species s;
   Creature c(s, h, 'c');
   stringstream ss;
   ss  << c;
   stringstream ss2;
   ss2 << 'c';
   ASSERT_TRUE(ss.str() == ss2.str());}

TEST(CreatureFixture, operator_test2) {
   Species s;
   Creature c(s, h, 'h');
   stringstream ss;
   ss  << c;
   stringstream ss2;
   ss2 << 'h';
   ASSERT_TRUE(ss.str() == ss2.str());}

TEST(CreatureFixture, operator_test3) {
   Species s;
   Creature c(s, h, 't');
   stringstream ss;
   ss  << c;
   stringstream ss2;
   ss2 << 'c';
   ASSERT_FALSE(ss.str() == ss2.str());}

// testing turnLeft
TEST(CreatureFixture, turnLeft_test1) {
   Species s;
   Creature c(s, h, 't');
   c.turnLeft();
   ASSERT_TRUE(c.dir == j);}

TEST(CreatureFixture, turnLeft_test2) {
   Species s;
   Creature c(s, l, 't');
   c.turnLeft();
   c.turnLeft();
   ASSERT_TRUE(c.dir == h);}

TEST(CreatureFixture, turnLeft_test3) {
   Species s;
   Creature c(s, l, 't');
   c.turnLeft();
   ASSERT_FALSE(c.dir == j);}

// testing turnRight
TEST(CreatureFixture, turnRight_test1) {
   Species s;
   Creature c(s, h, 't');
   c.turnRight();
   ASSERT_TRUE(c.dir == k);}

TEST(CreatureFixture, turnRight_test2) {
   Species s;
   Creature c(s, l, 't');
   c.turnRight();
   c.turnRight();
   ASSERT_TRUE(c.dir == h);}

TEST(CreatureFixture, turnRight_test3) {
   Species s;
   Creature c(s, l, 't');
   c.turnRight();
   ASSERT_FALSE(c.dir == k);}

// testing infected
TEST(CreatureFixture, infected_test1) {
   Species s;
   Species s2;
   Creature c(s, l, 'h');
   Creature c2(s2, l, 't');
   ASSERT_FALSE(c.creatureRepresentaion == c2.creatureRepresentaion);
   c.infected(c2);
   ASSERT_TRUE(c.creatureRepresentaion == c2.creatureRepresentaion);}

TEST(CreatureFixture, infected_test2) {
   Species s;
   Species s2;
   Creature c(s, l, 'h');
   Creature c2(s2, l, 't');
   ASSERT_FALSE(c.creatureRepresentaion == c2.creatureRepresentaion);
   c.updatePC(4);
   ASSERT_FALSE(c.pc == 0);
   c.infected(c2);
   ASSERT_TRUE(c.pc == 0);
   ASSERT_TRUE(c.creatureRepresentaion == c2.creatureRepresentaion);}

TEST(CreatureFixture, infected_test3) {
   Species s;
   Species s2;
   Creature c(s, l, 'h');
   Creature c2(s2, l, 't');
   ASSERT_FALSE(c.creatureRepresentaion == c2.creatureRepresentaion);
   c.updatePC(4);
   ASSERT_FALSE(c.pc == 0);
   ASSERT_FALSE(c.s == c2.s);
   c.infected(c2);
   ASSERT_TRUE(c.pc == 0);
   ASSERT_TRUE(c.s == c2.s);
   ASSERT_TRUE(c.creatureRepresentaion == c2.creatureRepresentaion);}

// testing readAction
TEST(CreatureFixture, readAction_test1) {
   Species hopper;
   hopper.addInstruction("hop");
   hopper.addInstruction("go 0");
   Creature h1(hopper, l, 'h');
   h1.updatePC(1);
   string s = h1.readAction(empty);
   ASSERT_TRUE(s.compare("hop") == 0);}

TEST(CreatureFixture, readAction_test2) {
   Species hopper;
   hopper.addInstruction("hop");
   hopper.addInstruction("go 0");
   Creature h1(hopper, l, 'h');
   string s = h1.readAction(empty);
   ASSERT_TRUE(s.compare("hop") == 0);
   s = h1.readAction(empty);
   ASSERT_TRUE(s.compare("hop") == 0);
   s = h1.readAction(empty);
   ASSERT_TRUE(s.compare("hop") == 0);}

TEST(CreatureFixture, readAction_test3) {
   Species hopper;
   hopper.addInstruction("hop");
   hopper.addInstruction("if_enemy 3");
   hopper.addInstruction("go 0");
   hopper.addInstruction("infect");
   Creature h1(hopper, l, 'h');
   string s = h1.readAction(empty);
   ASSERT_TRUE(s.compare("hop") == 0);
   s = h1.readAction(empty);
   ASSERT_TRUE(s.compare("hop") == 0);
   s = h1.readAction(enemy);
   ASSERT_TRUE(s.compare("infect") == 0);}

// testing changeTurrn
TEST(CreatureFixture, changeTurn_test1) {
   Species s;
   Creature c(s, l, 'h');
   ASSERT_TRUE(c.canRun);}

TEST(CreatureFixture, changeTurn_test2) {
   Species s;
   Creature c(s, l, 'h');
   c.changeTurn();
   c.changeTurn();
   ASSERT_TRUE(c.canRun);}

TEST(CreatureFixture, changeTurn_test3) {
   Species s;
   Creature c(s, l, 'h');
   c.changeTurn();
   ASSERT_FALSE(c.canRun);}

// testing isEnemy
TEST(CreatureFixture, isEnemy_test1) {
   Species s;
   Species s2;
   Creature c(s, l, 'h');
   Creature c2(s2, l, 't');
   ASSERT_TRUE(c.isEnemy(c2));}

TEST(CreatureFixture, isEnemy_test2) {
   Species s;
   Creature c(s, l, 'h');
   Creature c2(s, k, 'h');
   ASSERT_FALSE(c.isEnemy(c2));}

TEST(CreatureFixture, isEnemy_test3) {
   Species s;
   Species s2;
   Creature c(s, l, 'h');
   Creature c2(s2, l, 't');
   c.infected(c2);
   ASSERT_FALSE(c.isEnemy(c2));}

// testing inFront
TEST(CreatureFixture, inFront_test1) {
   Species s;
   Creature c(s, l, 'h');
   int row = 0;
   int col = 0;
   c.inFront(row, col);
   ASSERT_TRUE(row == 0);
   ASSERT_TRUE(col == 1);}

TEST(CreatureFixture, inFront_test2) {
   Species s;
   Creature c(s, h, 'h');
   int row = 1;
   int col = 1;
   c.inFront(row, col);
   ASSERT_TRUE(row == 1);
   ASSERT_TRUE(col == 0);}

TEST(CreatureFixture, inFront_test3) {
   Species s;
   Creature c(s, k, 'h');
   int row = 1;
   int col = 1;
   c.inFront(row, col);
   ASSERT_TRUE(row == 0);
   ASSERT_TRUE(col == 1);
   Creature c2(s, j, 'h');
   c2.inFront(row, col);
   ASSERT_TRUE(row == 1);
   ASSERT_TRUE(col == 1);}

// ----------------------
// testing Darwin methods
// ----------------------

// testing parseAction
TEST(DarwinFixture, parseAction_test1) {
   Darwin d(4, 4);
   action a = d.parseAction("hop");
   ASSERT_TRUE(a == hop);}

TEST(DarwinFixture, parseAction_test2) {
   Darwin d(4, 4);
   action a = d.parseAction("nop");
   ASSERT_TRUE(a == nop);}

TEST(DarwinFixture, parseAction_test3) {
   Darwin d(4, 4);
   action a = d.parseAction("left");
   ASSERT_TRUE(a == turn_left);
   a = d.parseAction("right");
   ASSERT_TRUE(a == turn_right);
   a = d.parseAction("infect");
   ASSERT_TRUE(a == infect);}

// testing operator<<
TEST(DarwinFixture, operator_test1) {
   Darwin d(4, 4);
   stringstream o;
   o << "Turn = 0." << endl;
   o << "  0123" << endl;
   o << "0 ...." << endl;
   o << "1 ...." << endl;
   o << "2 ...." << endl;
   o << "3 ...." << endl;
   stringstream ss;
   ss << d;
   ASSERT_TRUE(o.str() == ss.str());}

TEST(DarwinFixture, operator_test2) {
   Species s;
   Creature c(s, l, 'h');
   Darwin d(4, 4);
   d.addCreature(c, 0, 0);
   stringstream o;
   o << "Turn = 0." << endl;
   o << "  0123" << endl;
   o << "0 h..." << endl;
   o << "1 ...." << endl;
   o << "2 ...." << endl;
   o << "3 ...." << endl;
   stringstream ss;
   ss << d;
   ASSERT_TRUE(o.str() == ss.str());}

TEST(DarwinFixture, operator_test3) {
   Species s;
   Creature c(s, l, 'h');
   Creature c2(s, k, 't');
   Darwin d(4, 4);
   d.addCreature(c, 0, 0);
   d.addCreature(c2, 3, 3);
   stringstream o;
   o << "Turn = 0." << endl;
   o << "  0123" << endl;
   o << "0 h..." << endl;
   o << "1 ...." << endl;
   o << "2 ...." << endl;
   o << "3 ...t" << endl;
   stringstream ss;
   ss << d;
   ASSERT_TRUE(o.str() == ss.str());}

// testing updateGrid
TEST(DarwinFixture, updateGrid_test1) {
   Darwin d(4, 4);
   stringstream o;
   o << "Turn = 3." << endl;
   o << "  0123" << endl;
   o << "0 ...." << endl;
   o << "1 ...." << endl;
   o << "2 ...." << endl;
   o << "3 ...." << endl;
   d.updateGrid();
   d.updateGrid();
   d.updateGrid();
   stringstream ss;
   ss << d;
   ASSERT_TRUE(o.str() == ss.str());}

TEST(DarwinFixture, updateGrid_test2) {
   Species hopper;
   hopper.addInstruction("hop");
   hopper.addInstruction("go 0");
   Creature h1(hopper, l, 'h');
   Darwin d(4, 4);
   d.addCreature(h1, 0, 0);
   stringstream o;
   o << "Turn = 3." << endl;
   o << "  0123" << endl;
   o << "0 ...h" << endl;
   o << "1 ...." << endl;
   o << "2 ...." << endl;
   o << "3 ...." << endl;
   d.updateGrid();
   d.updateGrid();
   d.updateGrid();
   stringstream ss;
   ss << d;
   ASSERT_TRUE(o.str() == ss.str());}

TEST(DarwinFixture, updateGrid_test3) {
   Species hopper;
   hopper.addInstruction("hop");
   hopper.addInstruction("go 0");
   Creature h1(hopper, l, 'h');
   Creature h2(hopper, k, 'h');
   Darwin d(4, 4);
   d.addCreature(h1, 0, 0);
   d.addCreature(h2, 3, 1);
   stringstream o;
   o << "Turn = 3." << endl;
   o << "  0123" << endl;
   o << "0 .h.h" << endl;
   o << "1 ...." << endl;
   o << "2 ...." << endl;
   o << "3 ...." << endl;
   d.updateGrid();
   d.updateGrid();
   d.updateGrid();
   stringstream ss;
   ss << d;
   ASSERT_TRUE(o.str() == ss.str());}

// testing addCreature
TEST(DarwinFixture, addCreature_test1) {
   Species s;
   Creature c(s, k, 'c');
   Darwin d(4, 4);
   ASSERT_TRUE(d.grid.at(0) == NULL);
   d.addCreature(c, 0, 0);
   ASSERT_TRUE(d.grid.at(0) == &c);}

TEST(DarwinFixture, addCreature_test2) {
   Species s;
   Creature c(s, k, 'c');
   Creature c2(s, j, 'c');
   Darwin d(4, 4);
   ASSERT_TRUE(d.grid.at(0) == NULL);
   ASSERT_TRUE(d.grid.at(3) == NULL);
   d.addCreature(c, 0, 0);
   d.addCreature(c2, 0, 3);
   ASSERT_TRUE(d.grid.at(3) == &c2);
   ASSERT_TRUE(d.grid.at(0) == &c);}

TEST(DarwinFixture, addCreature_test3) {
   Species s;
   Creature c(s, k, 'c');
   Creature c2(s, j, 'c');
   Creature c3(s, j, 'c');
   Creature c4(s, j, 'c');
   Darwin d(2, 2);
   ASSERT_TRUE(d.grid.at(0) == NULL);
   ASSERT_TRUE(d.grid.at(1) == NULL);
   ASSERT_TRUE(d.grid.at(2) == NULL);
   ASSERT_TRUE(d.grid.at(3) == NULL);
   d.addCreature(c, 0, 0);
   d.addCreature(c2, 0, 1);
   d.addCreature(c3, 1, 0);
   d.addCreature(c4, 1, 1);
   ASSERT_TRUE(d.grid.at(0) == &c);
   ASSERT_TRUE(d.grid.at(1) == &c2);
   ASSERT_TRUE(d.grid.at(2) == &c3);
   ASSERT_TRUE(d.grid.at(3) == &c4);}

