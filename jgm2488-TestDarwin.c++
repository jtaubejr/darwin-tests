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
#include <iostream>
#include <sstream>
#include <string>
#include "Darwin.h"

using namespace std;

// ----
// test
// ----

// ----
// Instruction Tests
// ----

// Instruction(int c=-1, int l=0)

TEST(DarwinTest, instr1) {
  Instruction in;
  ASSERT_EQ(in.command, -1);
  ASSERT_EQ(in.line, 0);
}

TEST(DarwinTest, instr2) {
  Instruction in(0, 1);
  ASSERT_EQ(in.command, 0);
  ASSERT_EQ(in.line, 1);
}

TEST(DarwinTest, instr3) {
  Instruction in(-1, 0);
  ASSERT_EQ(in.command, -1);
  ASSERT_EQ(in.line, 0);
}

// ----
// Species Tests
// ----

// Species() / Species (const char s)

TEST(DarwinTest, spec1) {
  Species sp;
  ASSERT_EQ(sp.name, '.');
}

TEST(DarwinTest, spec2) {
  Species sp('h');
  ASSERT_EQ(sp.name, 'h');
}

TEST(DarwinTest, spec3) {
  Species sp;
  ASSERT_EQ(sp.instr.size(), 0);
}

// void addInstruction(int c, int l)

TEST(DarwinTest, spec7) {
  Species sp;
  sp.addInstruction(0, 0);
  ASSERT_EQ(sp.instr.size(), 1);
}

TEST(DarwinTest, spec8) {
  Species sp;
  sp.addInstruction(0, 0);
  sp.addInstruction(1, 1);
  ASSERT_EQ(sp.instr.size(), 2);
}

TEST(DarwinTest, spec9) {
  Species sp;
  sp.addInstruction(0, 0);
  sp.addInstruction(1, 1);
  sp.addInstruction(2, 2);
  ASSERT_EQ(sp.instr.size(), 3);
}

// void addInstruction(int i)

TEST(DarwinTest, spec10) {
  Species sp;
  sp.addInstruction(0);
  ASSERT_EQ(sp.instr.size(), 1);
}

TEST(DarwinTest, spec11) {
  Species sp;
  sp.addInstruction(0);
  sp.addInstruction(1);
  ASSERT_EQ(sp.instr.size(), 2);
}

TEST(DarwinTest, spec12) {
  Species sp;
  sp.addInstruction(0);
  sp.addInstruction(1);
  sp.addInstruction(2);
  ASSERT_EQ(sp.instr.size(), 3);
}

// ----
// Creature Tests
// ----

// Creature()

TEST(DarwinTest, creat1) {
  Creature cr;
  ASSERT_EQ(cr.species.name, '.');
}

TEST(DarwinTest, creat2) {
  Creature cr;
  ASSERT_EQ(cr.p_counter, 0);
}

TEST(DarwinTest, creat3) {
  Creature cr;
  ASSERT_EQ(cr.dir, 0);
}

// Creature(Species s, int d)

TEST(DarwinTest, creat4) {
  Species sp;
  Creature cr(sp, 0);
  ASSERT_EQ(cr.species.name, '.');
}

TEST(DarwinTest, creat5) {
  Species sp;
  Creature cr(sp, 0);
  ASSERT_EQ(cr.p_counter, 0);
}

TEST(DarwinTest, creat6) {
  Species sp;
  Creature cr(sp, 0);
  ASSERT_EQ(cr.dir, 0);
}

TEST(DarwinTest, creat_extra1) {
  Species sp('h');
  Creature cr(sp, 0);
  ASSERT_EQ(cr.species.name, 'h');
}

// bool different(Creature& prey);

TEST(DarwinTest, creat7) {
  Species sp('h');
  Creature cr(sp, 0);
  Creature cr2(sp, 0);
  ASSERT_FALSE(cr.different(cr2));
}

TEST(DarwinTest, creat8) {
  Species sp('h');
  Species sp2('f');
  Creature cr(sp, 0);
  Creature cr2(sp2, 0);
  ASSERT_TRUE(cr.different(cr2));
}

TEST(DarwinTest, creat9) {
  Species sp;
  Species sp2('.');
  Creature cr(sp, 0);
  Creature cr2(sp2, 0);
  ASSERT_FALSE(cr.different(cr2));
}

// void infect(Creature& prey);

TEST(DarwinTest, creat10) {
  Species sp('h');
  Species sp2('f');
  Creature cr(sp, 0);
  Creature cr2(sp2, 0);
  cr.infect(cr2);
  ASSERT_EQ(cr.species.name, cr2.species.name);
}

TEST(DarwinTest, creat11) {
  Species sp('h');
  Species sp2('f');
  Creature cr(sp, 0);
  Creature cr2(sp2, 0);
  cr.infect(cr2);
  ASSERT_EQ(cr2.p_counter, 0);
}

TEST(DarwinTest, creat12) {
  Species sp('h');
  Species sp2('f');
  Creature cr(sp, 0);
  Creature cr2(sp2, 0);
  cr.infect(cr2);
  ASSERT_EQ(cr.p_counter, 1);
}

// void moveRight();

TEST(DarwinTest, creat13) {
  Species sp('h');
  Creature cr(sp, 3);
  cr.moveRight();
  ASSERT_EQ(cr.dir, 0);
}

TEST(DarwinTest, creat14) {
  Species sp('h');
  Creature cr(sp, 0);
  cr.moveRight();
  ASSERT_EQ(cr.dir, 1);
}

TEST(DarwinTest, creat15) {
  Species sp('h');
  Creature cr(sp, 2);
  cr.moveRight();
  ASSERT_EQ(cr.dir, 3);
}

// void moveLeft();

TEST(DarwinTest, creat16) {
  Species sp('h');
  Creature cr(sp, 0);
  cr.moveLeft();
  ASSERT_EQ(cr.dir, 3);
}

TEST(DarwinTest, creat17) {
  Species sp('h');
  Creature cr(sp, 3);
  cr.moveLeft();
  ASSERT_EQ(cr.dir, 2);
}

TEST(DarwinTest, creat18) {
  Species sp('h');
  Creature cr(sp, 1);
  cr.moveLeft();
  ASSERT_EQ(cr.dir, 0);
}

// void updatePC(int newPC=-1);

TEST(DarwinTest, creat19) {
  Species sp('h');
  Creature cr(sp, 0);
  cr.updatePC(-1);
  ASSERT_EQ(cr.p_counter, 1);
}

TEST(DarwinTest, creat20) {
  Species sp('h');
  Creature cr(sp, 0);
  cr.updatePC(1);
  ASSERT_EQ(cr.p_counter, 1);
}

TEST(DarwinTest, creat21) {
  Species sp('h');
  Creature cr(sp, 0);
  cr.updatePC(-2);
  ASSERT_EQ(cr.p_counter, -2);
}

// void Instruction Creature::currentInstruction()
TEST(DarwinTest, creatExtra) {
  Species sp('h');
  sp.addInstruction(HOP);
  Creature cr(sp, 0);
  ASSERT_EQ(cr.currentInstruction().command, 0);
}

// bool validWest(int row=-1, int col=-1, int rows=-1, int columns=-1);

TEST(DarwinTest, creat22) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 0);
  board.addCreature(cr, 4, 4);
  ASSERT_TRUE(cr.validWest(4, 4, 8, 8));
}

TEST(DarwinTest, creat23) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 1);
  board.addCreature(cr, 4, 4);
  ASSERT_FALSE(cr.validWest(4, 4, 8, 8));
}

TEST(DarwinTest, creat24) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 0);
  board.addCreature(cr, 4, 0);
  ASSERT_FALSE(cr.validWest(4, 0, 8, 8));
}

// bool validNorth(int row=-1, int col=-1, int rows=-1, int columns=-1);

TEST(DarwinTest, creat25) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 1);
  board.addCreature(cr, 4, 4);
  ASSERT_TRUE(cr.validNorth(4, 4, 8, 8));
}

TEST(DarwinTest, creat26) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 0);
  board.addCreature(cr, 4, 4);
  ASSERT_FALSE(cr.validNorth(4, 4, 8, 8));
}

TEST(DarwinTest, creat27) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 1);
  board.addCreature(cr, 0, 4);
  ASSERT_FALSE(cr.validNorth(0, 4, 8, 8));
}

// bool validEast(int row=-1, int col=-1, int rows=-1, int columns=-1);

TEST(DarwinTest, creat28) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 2);
  board.addCreature(cr, 4, 4);
  ASSERT_TRUE(cr.validEast(4, 4, 8, 8));
}

TEST(DarwinTest, creat29) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 1);
  board.addCreature(cr, 4, 4);
  ASSERT_FALSE(cr.validEast(4, 4, 8, 8));
}

TEST(DarwinTest, creat30) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 2);
  board.addCreature(cr, 4, 7);
  ASSERT_FALSE(cr.validEast(4, 7, 8, 8));
}

// bool validSouth(int row=-1, int col=-1, int rows=-1, int columns=-1);

TEST(DarwinTest, creat31) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 3);
  board.addCreature(cr, 4, 4);
  ASSERT_TRUE(cr.validSouth(4, 4, 8, 8));
}

TEST(DarwinTest, creat32) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 1);
  board.addCreature(cr, 4, 4);
  ASSERT_FALSE(cr.validSouth(4, 4, 8, 8));
}

TEST(DarwinTest, creat33) {
  Darwin board(8, 8);
  Species sp('h');
  Creature cr(sp, 3);
  board.addCreature(cr, 7, 4);
  ASSERT_FALSE(cr.validSouth(7, 4, 8, 8));
}

// Instruction currentInstruction()

TEST(DarwinTest, creat37) {
  Species sp('t');
  sp.addInstruction(0);
  Creature cr(sp, 0);
  ASSERT_EQ(cr.currentInstruction().command, 0);
}

TEST(DarwinTest, creat38) {
  Species sp('t');
  sp.addInstruction(0);
  sp.addInstruction(1);
  Creature cr(sp, 0);
  ASSERT_EQ(cr.currentInstruction().command, 0);
}

TEST(DarwinTest, creat39) {
  Species sp('t');
  sp.addInstruction(0);
  sp.addInstruction(1);
  Creature cr(sp, 0);
  cr.updatePC(1);
  ASSERT_EQ(cr.currentInstruction().command, 1);;
}

// ----
// Darwin Tests
// ----

// Darwin()

TEST(DarwinTest, dar1) {
  Darwin dar;
  ASSERT_EQ(dar.rows, 0);
}

TEST(DarwinTest, dar2) {
  Darwin dar;
  ASSERT_EQ(dar.columns, 0);
}


TEST(DarwinTest, dar3) {
  Darwin dar;
  ASSERT_EQ(dar.turns, 0);
}


// Darwin(int r, int c)

TEST(DarwinTest, dar4) {
  Darwin dar(1, 1);
  ASSERT_EQ(dar.rows, 1);
}

TEST(DarwinTest, dar5) {
  Darwin dar(1, 1);
  ASSERT_EQ(dar.columns, 1);
}

// void addCreature(Creature& creat, int r, int c)

TEST(DarwinTest, dar7) {
  Darwin dar(8, 8);
  Species sp('h');
  Creature cr(sp, 0);
  dar.addCreature(cr, 4, 4);
  ASSERT_EQ(dar.board[4][4], &cr);
}

TEST(DarwinTest, dar8) {
  Darwin dar(8, 8);
  Species sp('h');
  Creature cr(sp, 0);
  Creature cr2(sp, 0);
  dar.addCreature(cr, 4, 4);
  dar.addCreature(cr2, 4, 4);
  ASSERT_EQ(dar.board[4][4], &cr2);
}

TEST(DarwinTest, dar9) {
  Darwin dar(8, 8);
  Species sp('h');
  Creature cr(sp, 0);
  Creature cr2(sp, 0);
  dar.addCreature(cr, 0, 0);
  dar.addCreature(cr2, 4, 4);
  ASSERT_EQ(dar.board[0][0], &cr);
  ASSERT_EQ(dar.board[4][4], &cr2);
}

// void playTurn(Creature& creat, int r, int c)

//hopWest

TEST(DarwinTest, dar10_1) {
  Darwin dar(8, 8);
  Species sp('h');
  sp.addInstruction(HOP);
  Creature cr(sp, 0);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(dar.board[4][3], &cr);
  ASSERT_EQ(dar.board[4][4], nullptr);
}

//hopNorth

TEST(DarwinTest, dar10_2) {
  Darwin dar(8, 8);
  Species sp('h');
  sp.addInstruction(HOP);
  Creature cr(sp, 1);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(dar.board[3][4], &cr);
  ASSERT_EQ(dar.board[4][4], nullptr);
}

//hopEast

TEST(DarwinTest, dar10_3) {
  Darwin dar(8, 8);
  Species sp('h');
  sp.addInstruction(HOP);
  Creature cr(sp, 2);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(dar.board[4][5], &cr);
  ASSERT_EQ(dar.board[4][4], nullptr);
}

//hopSouth

TEST(DarwinTest, dar10_4) {
  Darwin dar(8, 8);
  Species sp('h');
  sp.addInstruction(HOP);
  Creature cr(sp, 3);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(dar.board[5][4], &cr);
  ASSERT_EQ(dar.board[4][4], nullptr);
}



//infectWest

TEST(DarwinTest, dar11_1) {
  Darwin dar(8, 8);
  Species sp('h');
  Species sp2('f');
  sp.addInstruction(INFECT);
  Creature cr(sp, 0);
  Creature cr2(sp2, 0);
  dar.addCreature(cr2, 4, 3);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(cr.species.name, cr2.species.name);
}

//infectNorth

TEST(DarwinTest, dar11_2) {
  Darwin dar(8, 8);
  Species sp('h');
  Species sp2('f');
  sp.addInstruction(INFECT);
  Creature cr(sp, 1);
  Creature cr2(sp2, 1);
  dar.addCreature(cr2, 3, 4);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(cr.species.name, cr2.species.name);
}

//infectEast

TEST(DarwinTest, dar11_3) {
  Darwin dar(8, 8);
  Species sp('h');
  Species sp2('f');
  sp.addInstruction(INFECT);
  Creature cr(sp, 2);
  Creature cr2(sp2, 2);
  dar.addCreature(cr2, 4, 5);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(cr.species.name, cr2.species.name);
}

//infectSouth

TEST(DarwinTest, dar11_4) {
  Darwin dar(8, 8);
  Species sp('h');
  Species sp2('f');
  sp.addInstruction(INFECT);
  Creature cr(sp, 3);
  Creature cr2(sp2, 3);
  dar.addCreature(cr2, 5, 4);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(cr.species.name, cr2.species.name);
}

//ifempty1

TEST(DarwinTest, dar12_1) {
  Darwin dar(8, 8);
  Species sp('h');
  sp.addInstruction(IF_EMPTY, 1);
  sp.addInstruction(LEFT);
  Creature cr(sp, 0);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(cr.p_counter, 2);
}

 //ifwall1

TEST(DarwinTest, dar13_1) {
   Darwin dar(8, 8);
   Species sp('h');
   sp.addInstruction(IF_WALL, 1);
   sp.addInstruction(LEFT);
   Creature cr(sp, 0);
   dar.playTurn(cr, 0, 0);
   ASSERT_EQ(cr.p_counter, 2);
 }
 
 //ifwall2

TEST(DarwinTest, dar13_2) {
   Darwin dar(8, 8);
   Species sp('h');
   sp.addInstruction(LEFT);
   sp.addInstruction(IF_WALL, 1);
   sp.addInstruction(LEFT);
   Creature cr(sp, 1);
   dar.playTurn(cr, 4, 4);
   dar.playTurn(cr, 4, 4);
   ASSERT_EQ(cr.p_counter, 3);
 } 

//ifrandom1

 TEST(DarwinTest, dar13_3) {
   Darwin dar(8, 8);
   Species sp('h');
   sp.addInstruction(IF_RANDOM, 1);
   sp.addInstruction(LEFT);
   Creature cr(sp, 0);
   dar.playTurn(cr, 0, 0);
   ASSERT_EQ(cr.p_counter, 2);
 }

//ifrandom2


//ifenemy1

TEST(DarwinTest, dar14_1) {
  Darwin dar(8, 8);
  Species sp('h');
  Species sp2('g');
  sp.addInstruction(IF_ENEMY, 1);
  sp.addInstruction(LEFT);
  Creature cr(sp, 3);
  Creature cr2(sp2, 0);
  dar.addCreature(cr2, 0, 1);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(cr.p_counter, 2);
}

//ifenemy2

TEST(DarwinTest, dar14_2) {
  Darwin dar(8, 8);
  Species sp('h');
  sp.addInstruction(LEFT);
  sp.addInstruction(IF_ENEMY, 1);
  Creature cr(sp, 3);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(cr.p_counter, 1);
}

//go

TEST(DarwinTest, dar15) {
  Darwin dar(8, 8);
  Species sp('h');
  sp.addInstruction(GO, 1);
  sp.addInstruction(LEFT);
  Creature cr(sp, 3);
  dar.playTurn(cr, 4, 4);
  ASSERT_EQ(cr.p_counter, 2);
}


// void play(int numTurns=0)

TEST(DarwinTest, dar16) {
  Darwin dar(8, 8);
  Species sp('h');
  sp.addInstruction(HOP);
  Creature cr(sp, 0);
  dar.addCreature(cr, 4, 4);
  dar.play(0);
  ASSERT_EQ(dar.board[4][3]->species.name, sp.name);
}

TEST(DarwinTest, dar17) {
  Darwin dar(8, 8);
  Species sp('h');
  sp.addInstruction(HOP);
  sp.addInstruction(HOP);
  Creature cr(sp, 0);
  dar.addCreature(cr, 4, 4);
  dar.play(1);
  ASSERT_EQ(dar.board[4][2]->species.name, sp.name);
}

TEST(DarwinTest, dar18) {
  Darwin dar(8, 8);
  Species sp('h');
  sp.addInstruction(HOP);
  sp.addInstruction(HOP);
  sp.addInstruction(HOP);
  Creature cr(sp, 0);
  dar.addCreature(cr, 4, 4);
  dar.play(2);
  ASSERT_EQ(dar.board[4][1]->species.name, sp.name);
}

// void play(int numTurns, int first, int print)

TEST(DarwinTest, dar19) {
  Darwin dar(5, 5);
  Species sp('h');
  sp.addInstruction(HOP);
  Creature cr(sp, 0);
  dar.addCreature(cr, 4, 4);
  dar.play(0, 1, 2);
  ASSERT_EQ(dar.board[4][3]->species.name, sp.name);
}

TEST(DarwinTest, dar20) {
  Darwin dar(5, 5);
  Species sp('h');
  sp.addInstruction(HOP);
  sp.addInstruction(HOP);
  Creature cr(sp, 0);
  dar.addCreature(cr, 4, 4);
  dar.play(0, 2, 2);
  ASSERT_EQ(dar.board[4][2]->species.name, sp.name);
}

TEST(DarwinTest, dar21) {
  Darwin dar(5, 5);
  Species sp('h');
  sp.addInstruction(HOP);
  sp.addInstruction(HOP);
  sp.addInstruction(HOP);
  Creature cr(sp, 0);
  dar.addCreature(cr, 4, 4);
  dar.play(0, 3, 2);
  ASSERT_EQ(dar.board[4][1]->species.name, sp.name);
}
