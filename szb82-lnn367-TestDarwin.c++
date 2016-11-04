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

TEST(DarwinFixture, step_1) {
  Darwin d1(8, 8);
  int lastTurn = d1._turn;
  d1.step();
  ASSERT_TRUE(lastTurn+1 == d1._turn);
}

TEST(DarwinFixture, step_2) {
  Darwin d1(20, 20);
  int lastTurn = d1._turn;
  for(int i = 1; i <= 4; i++){
  	d1.step();
  	ASSERT_TRUE(lastTurn+i == d1._turn);
  }
  ASSERT_TRUE(lastTurn+4 == d1._turn);
}

TEST(DarwinFixture, step_3) {
  Darwin d1(3, 5);
  int lastTurn = d1._turn;
  for(int i = 1; i <= 2; i++){
  	d1.step();
  	ASSERT_TRUE(lastTurn+i == d1._turn);
  }
  ASSERT_TRUE(lastTurn+2 == d1._turn);
}

TEST(DarwinFixture, addCreature_1) {
  Species food('f');
  food.addInstruction({LEFT});
  food.addInstruction({GO, 0});
  
  Darwin d1(8, 8);

  Creature foodCreature1(&food, &d1, WEST);
  d1.addCreature(&foodCreature1, 3, 4);

  int numCreatures = 0;

  for(int r = 0; r < d1._rows; r++){
  	for(int c = 0; c < d1._cols; c++){
  		if(d1._map[(r * d1._rows) + c])
  			numCreatures++;
  	}
  }
  ASSERT_TRUE(numCreatures == 1);
}

TEST(DarwinFixture, addCreature_2) {
  Species food('f');
  food.addInstruction({LEFT});
  food.addInstruction({GO, 0});
  
  Darwin d1(8, 8);

  Creature foodCreature1(&food, &d1, WEST);
  d1.addCreature(&foodCreature1, 3, 4);

  Creature foodCreature2(&food, &d1, WEST);
  d1.addCreature(&foodCreature2, 2, 3);

  Creature foodCreature3(&food, &d1, WEST);
  d1.addCreature(&foodCreature3, 1, 1);

  int numCreatures = 0;

  for(int r = 0; r < d1._rows; r++){
  	for(int c = 0; c < d1._cols; c++){
  		if(d1._map[(r * d1._rows) + c])
  			numCreatures++;
  	}
  }
  ASSERT_TRUE(numCreatures == 3);
}

TEST(DarwinFixture, addCreature_3) {
  Species food('f');
  food.addInstruction({LEFT});
  food.addInstruction({GO, 0});
  
  Darwin d1(8, 8);

  int numCreatures = 0;
  for(int r = 0; r < d1._rows; r++){
  	for(int c = 0; c < d1._cols; c++){
  		if(d1._map[(r * d1._rows) + c])
  			numCreatures++;
  	}
  }
  ASSERT_TRUE(numCreatures == 0);
}

TEST(DarwinFixture, move_1) {
  Species hopper('h');
  hopper.addInstruction({HOP});
  hopper.addInstruction({GO, 0});
  
  Darwin d1(8, 8);

  int x = 1;
  int y = 1;
  Creature hopperCreature(&hopper, &d1, EAST);
  d1.addCreature(&hopperCreature, x, y);

  ASSERT_TRUE(d1._map[(y * d1._cols) + x]);

  d1.step();
  
  ASSERT_FALSE(d1._map[(y * d1._cols) + x]);
  ASSERT_TRUE(d1._map[(y * d1._cols) + x + 1]);
}

TEST(DarwinFixture, move_2) {
  Species hopper('h');
  hopper.addInstruction({HOP});
  hopper.addInstruction({GO, 0});
  
  Darwin d1(8, 8);

  int x = 1;
  int y = 1;
  Creature hopperCreature(&hopper, &d1, EAST);
  d1.addCreature(&hopperCreature, x, y);

  ASSERT_TRUE(d1._map[(y * d1._cols) + x]);

  d1.step();
  d1.step();
  
  ASSERT_FALSE(d1._map[(y * d1._cols) + x]);
  ASSERT_TRUE(d1._map[(y * d1._cols) + x + 2]);
}

TEST(DarwinFixture, move_3) {
  Species hopper('h');
  hopper.addInstruction({HOP});
  hopper.addInstruction({GO, 0});
  
  Darwin d1(8, 8);

  int x = 1;
  int y = 1;
  Creature hopperCreature(&hopper, &d1, EAST);
  d1.addCreature(&hopperCreature, x, y);

  ASSERT_TRUE(d1._map[(y * d1._cols) + x]);

  d1.step();
  d1.step();
  d1.step();
  d1.step();
  
  ASSERT_FALSE(d1._map[(y * d1._cols) + x]);
  ASSERT_TRUE(d1._map[(y * d1._cols) + x + 4]);
}

