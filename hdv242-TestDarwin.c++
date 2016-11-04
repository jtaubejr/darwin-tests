// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <assert.h>
#include "Darwin.h"

// -------------------------------------
// projects/allocator/TestAllocator1.c++
// Copyright (C) 2015
// Glenn P. Downing
// -------------------------------------

using namespace std;


// ------------------
// Constructor tests
// ------------------

TEST(SpeciesFixture, SpeciesConstructor) {
  Species food('f');
  ASSERT_EQ(food.name, 'f');
  ASSERT_EQ(food.instructions.size(), 0);
}

TEST(SpeciesFixture, SpeciesConstructor2) {
  Species rover('r');
  ASSERT_EQ(rover.name, 'r');
  ASSERT_EQ(rover.instructions.size(), 0);
}

TEST(SpeciesFixture, SpeciesConstructor3) {
  Species hopper('h');
  ASSERT_EQ(hopper.name, 'h');
  ASSERT_EQ(hopper.instructions.size(), 0);
}

TEST(CreatureFixture, CreatureConstructor) {
	Creature c;
  ASSERT_EQ(c.dir, n);

	Species food('f');
	Creature f(n, food);
	ASSERT_EQ(f.dir, n); 
	ASSERT_EQ(f.pc, 0);
	ASSERT_EQ(f.moveCounter, 0);

  Species hopper('h');
	Creature h(s, hopper);
  ASSERT_EQ(h.dir, s); 
  ASSERT_EQ(h.pc, 0);
  ASSERT_EQ(h.moveCounter, 0);

	Species rover('r');
	Creature r(e, rover);
  ASSERT_EQ(r.dir, e); 
  ASSERT_EQ(r.pc, 0);
  ASSERT_EQ(r.moveCounter, 0);
}

TEST(DarwinFixture, DarwinConstructor1) {
  Darwin d(10, 5);
  ASSERT_EQ(d.rows, 10);
  ASSERT_EQ(d.cols, 5);
  ASSERT_EQ(d.turn, 0);
}

TEST(DarwinFixture, DarwinConstructor2) {
  Darwin d(15, 15);
  ASSERT_EQ(d.rows, 15);
  ASSERT_EQ(d.cols, 15);
  ASSERT_EQ(d.turn, 0);
}

TEST(DarwinFixture, DarwinConstructor3) {
  Darwin d(100, 100);
  ASSERT_EQ(d.rows, 100);
  ASSERT_EQ(d.cols, 100);
  ASSERT_EQ(d.turn, 0);
}

TEST(DarwinFixture, DarwinConstructor4) {
  Darwin d(15, 10);
  ASSERT_EQ(d.rows, 15);
  ASSERT_EQ(d.cols, 10);
  ASSERT_EQ(d.turn, 0);
}

TEST(DarwinFixture, DarwinConstructor5) {
  Darwin d(100, 200);
  ASSERT_EQ(d.rows, 100);
  ASSERT_EQ(d.cols, 200);
  ASSERT_EQ(d.turn, 0);
}

// --------------
// Species tests
// --------------

TEST(SpeciesFixture, AddInstruction) {
  Species food('f');
  food.addInstruction ("right");
  food.addInstruction ("go 0");
  ASSERT_EQ(food.instructions[0], "right");
  ASSERT_EQ(food.instructions[1], "go 0");
}

TEST(SpeciesFixture, Print) {
  Species food('f');
  ostringstream os;
  food.print (os);
  ASSERT_EQ(os.str (), "f");
}

TEST(SpeciesFixture, Print2) {
  Species food('f');
  ostringstream os;
  food.print (os);
  food.print (os);
  ASSERT_EQ(os.str (), "ff");
}

TEST(SpeciesFixture, Print3) {
  Species hopper('h');
  Species rover('r');
  ostringstream os;
  hopper.print (os);
  rover.print (os);
  ASSERT_EQ(os.str (), "hr");
}

// --------------
// Creature tests
// --------------

TEST(CreatureFixture, Print) {
  Species food('f');
  Creature f (n, food);
  ostringstream os;
  f.print (os);
  ASSERT_EQ(os.str (), "f");
}

TEST(CreatureFixture, Print2) {
  Species food('f');
  Creature f (n, food);
  ostringstream os;
  f.print (os);
  f.print (os);
  ASSERT_EQ(os.str (), "ff");
}

TEST(CreatureFixture, Print3) {
  Species hopper('h');
  Species rover('r');
  Creature h (n, hopper);
  Creature r (n, rover);
  ostringstream os;
  h.print (os);
  r.print (os);
  ASSERT_EQ(os.str (), "hr");
}

TEST(CreatureFixture, DirectionChange) {
  Species food('f');
  Creature f1(n, food);
  ASSERT_EQ(f1.dir, n);
  f1.left();
  f1.left();
  ASSERT_EQ(f1.dir, s);
}

TEST(CreatureFixture, DirectionChange2) {
  Species food('f');
  Creature f1(n, food);
  ASSERT_EQ(f1.dir, n);
  f1.right();
  ASSERT_EQ(f1.dir, e);
}

TEST(CreatureFixture, DirectionChange3) {
  Species food('f');
  Creature f1(n, food);
  ASSERT_EQ(f1.dir, n);
  f1.left();
  f1.left();
  ASSERT_EQ(f1.dir, s);
  f1.right();
  f1.right();
  f1.right();
  ASSERT_EQ(f1.dir, e);
}

TEST(CreatureFixture, AdvancePC) {
  Species food('f');
  Creature f1(n, food);
  ASSERT_EQ(f1.pc, 0);
  f1.advance_pc();
  ASSERT_EQ(f1.pc, 1);

}

TEST(CreatureFixture, AdvancePC2) {
  Species food('f');
  Creature f1(n, food);
  ASSERT_EQ(f1.pc, 0);
  f1.advance_pc();
  f1.advance_pc();
  ASSERT_EQ(f1.pc, 2);

}

TEST(CreatureFixture, AdvancePC3) {
  Species food('f');
  Creature f1(n, food);
  ASSERT_EQ(f1.pc, 0);
  f1.advance_pc();
  f1.advance_pc();
  f1.advance_pc();
  ASSERT_EQ(f1.pc, 3);

}

TEST(DarwinFixture, AddCreature) {
  Darwin d(10, 10);
  Species food('f');
  Creature f1(n, food);

  d.addCreature (f1, 0, 0);
  ASSERT_EQ(d.board[0][0], &f1);
}

TEST(DarwinFixture, Run1) {
  Darwin d(10, 10);
  Species food ('f');
  food.addInstruction ("left");
  food.addInstruction ("go 0");

  Species hopper ('h');
  hopper.addInstruction ("hop");
  hopper.addInstruction ("go 0");

  Species trap ('t');
  trap.addInstruction ("if_enemy 3");
  trap.addInstruction ("left");
  trap.addInstruction ("go 0");
  trap.addInstruction ("infect");
  trap.addInstruction ("go 0");

  Species rover ('r');
  rover.addInstruction ("if_enemy 9");
  rover.addInstruction ("if_empty 7");
  rover.addInstruction ("if_random 5");
  rover.addInstruction ("left");
  rover.addInstruction ("go 0");
  rover.addInstruction ("right");
  rover.addInstruction ("go 0");
  rover.addInstruction ("hop");
  rover.addInstruction ("go 0");
  rover.addInstruction ("infect");
  rover.addInstruction ("go 0");

  Creature f1 (e, food);
  Creature h1 (n, hopper);
  Creature h2 (n, hopper);
  Creature h3 (n, hopper);
  Creature h4 (n, hopper);
  Creature t1 (e, trap);
  Creature r1 (n, rover);

  d.addCreature (f1, 0, 0);
  d.addCreature (h1, 9, 0);
  d.addCreature (h2, 9, 1);
  d.addCreature (h3, 9, 2);
  d.addCreature (h4, 9, 3);
  d.addCreature (t1, 9, 9);
  d.addCreature (r1, 4, 4);

  srand(0);
  for (int i = 0; i <= 5; i++) {
    d.run ();
  }
  ASSERT_EQ(d.board[3][0], &h1);
  ASSERT_EQ(d.board[3][1], &h2);
  ASSERT_EQ(d.board[3][2], &h3);
  ASSERT_EQ(d.board[3][3], &h4);
}

TEST(DarwinFixture, Run2) {
  Darwin d(10, 10);
  Species food ('f');
  food.addInstruction ("left");
  food.addInstruction ("go 0");

  Species hopper ('h');
  hopper.addInstruction ("hop");
  hopper.addInstruction ("go 0");

  Species trap ('t');
  trap.addInstruction ("if_enemy 3");
  trap.addInstruction ("left");
  trap.addInstruction ("go 0");
  trap.addInstruction ("infect");
  trap.addInstruction ("go 0");

  Species rover ('r');
  rover.addInstruction ("if_enemy 9");
  rover.addInstruction ("if_empty 7");
  rover.addInstruction ("if_random 5");
  rover.addInstruction ("left");
  rover.addInstruction ("go 0");
  rover.addInstruction ("right");
  rover.addInstruction ("go 0");
  rover.addInstruction ("hop");
  rover.addInstruction ("go 0");
  rover.addInstruction ("infect");
  rover.addInstruction ("go 0");
  

  Creature f1 (e, food);
  Creature h1 (n, hopper);
  Creature h2 (n, hopper);
  Creature h3 (n, hopper);
  Creature h4 (n, hopper);
  Creature t1 (e, trap);
  Creature r1 (n, rover);

  d.addCreature (f1, 0, 0);
  d.addCreature (h1, 1, 0);
  d.addCreature (h2, 2, 1);
  d.addCreature (h3, 3, 2);
  d.addCreature (h4, 4, 3);
  d.addCreature (t1, 0, 2);
  d.addCreature (r1, 4, 4);

  srand(0);
  ostringstream os;
  for (int i = 0; i <= 5; i++) {
    d.printBoard (os);
    d.run ();
  }
  ASSERT_EQ(d.board[0][0], &f1);
  ASSERT_EQ(d.board[1][0], &h1);
  ASSERT_EQ(d.board[0][1], &h2);
  ASSERT_EQ(d.board[1][2], &h3);
  ASSERT_EQ(d.board[0][3], &h4);
}
