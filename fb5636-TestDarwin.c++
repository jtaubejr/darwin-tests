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

// -------------
// Species Tests
// -------------

TEST(SpeciesFixture, addInstruction) {
	Species test;
	test.addInstruction("hop");
	ASSERT_EQ(test.program_list.size(), 1);
}
TEST(SpeciesFixture, execute){
	Species test;
	test.addInstruction("if_empty 1");
	test.addInstruction("hop");

	Creature testCreature(test, "t");
	string res = test.execute(testCreature.counter, testCreature, nullptr, nullptr, nullptr, nullptr);

	ASSERT_EQ(res, "hop"); 
}
TEST(SpeciesFixture, execute2){
	Species test;
	test.addInstruction("hop");

	Creature testCreature(test, "t");
	string res = test.execute(testCreature.counter, testCreature, nullptr, nullptr, nullptr, nullptr);

	ASSERT_EQ(res, "hop");
}
TEST(SpeciesFixture, execute3){
	Species test;
	test.addInstruction("hop");

	int counter = 0;
	Creature testCreature(test, "t");
	string res = test.execute(counter, testCreature, nullptr, nullptr, nullptr, nullptr);

	ASSERT_EQ(counter, 1);
}
TEST(SpeciesFixture, execute4){
	Species enemy;

	Species test;
	test.addInstruction("if_enemy 2");
	test.addInstruction("hop");
	test.addInstruction("hop");

	int counter = 0;
	Creature testCreature(test, "t");
	Creature enemyCreature(enemy, "e");
	string res = test.execute(counter, testCreature, &enemyCreature, nullptr, nullptr, nullptr);

	ASSERT_EQ(counter, 3);
}
TEST(SpeciesFixture, execute5){
	Species test;
	test.addInstruction("if_wall 1");
	test.addInstruction("hop");
	test.addInstruction("hop");

	int counter = 0;
	Creature testCreature(test, "t");
	string res = test.execute(counter, testCreature, nullptr, nullptr, nullptr, nullptr);

	ASSERT_EQ(counter, 2);
}
TEST(SpeciesFixture, execute6){
	Species test;
	test.addInstruction("go 5");
	test.addInstruction("hop");
	test.addInstruction("hop");
	test.addInstruction("hop");
	test.addInstruction("hop");
	test.addInstruction("hop");

	int counter = 0;
	Creature testCreature(test, "t");
	string res = test.execute(counter, testCreature, nullptr, nullptr, nullptr, nullptr);

	ASSERT_EQ(counter, 6);
}
// --------------
// Creature Tests
// --------------
TEST(CreatureFixture, getfacing1){
	Species species;
	Creature temp(species, "t", 0);
	Creature facing(species, "f", 0);
	Creature* result = temp.getfacing(&facing, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, &facing);
}

TEST(CreatureFixture, getfacing2){
	Species species;
	Creature temp(species, "t", 3);
	Creature* result = temp.getfacing(nullptr, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, nullptr);
}

TEST(CreatureFixture, left1){
	Species species;
	Creature temp(species, "t", 3);
	temp.left();

	ASSERT_EQ(temp.direction, 2);
}

TEST(CreatureFixture, left2){
	Species species;
	Creature temp(species, "t", 0);
	temp.left();

	ASSERT_EQ(temp.direction, 3);
}

TEST(CreatureFixture, right1){
	Species species;
	Creature temp(species, "t", 0);
	temp.right();

	ASSERT_EQ(temp.direction, 1);
}

TEST(CreatureFixture, right2){
	Species species;
	Creature temp(species, "t", 3);
	temp.right();

	ASSERT_EQ(temp.direction, 0);
}

TEST(CreatureFixture, infect1){
	Species species;
	Species enemy;
	Creature temp(species, "t", 3);
	Creature enemyCreature(enemy, "e", 0);
	temp.infect(nullptr, nullptr, nullptr, &enemyCreature);

	ASSERT_EQ(enemyCreature._name, temp._name);
}

TEST(CreatureFixture, infect2){
	Species species;
	Creature temp(species, "t", 3);
	Creature enemyCreature(species, "t", 0);
	temp.infect(nullptr, nullptr, nullptr, &enemyCreature);

	ASSERT_EQ(enemyCreature._name, temp._name);
}

TEST(CreatureFixture, hop1){
	Species species;
	Creature temp(species, "t", 0);
	Creature nei(species, ".", 0);
	temp.hop(&nei, nullptr, nullptr, nullptr);

	ASSERT_EQ(temp._name, ".");
}

TEST(CreatureFixture, hop2){
	Species species;
	Creature temp(species, "t", 0);
	temp.hop(nullptr, nullptr, nullptr, nullptr);

	ASSERT_EQ(temp._name, "t");
}

TEST(CreatureFixture, hop3){
	Species species;
	Creature temp(species, "t", 2);
	Creature nei(species, ".", 0);
	temp.hop(nullptr, &nei, nullptr, nullptr);

	ASSERT_EQ(nei.executed, true);
}

TEST(CreatureFixture, if_enemy1){
	Species species;
	Species enemy;
	Creature temp(species, "t", 0);
	Creature enemyCreature(enemy, "e", 0);
	bool result = temp.if_enemy(&enemyCreature, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, true);
}

TEST(CreatureFixture, if_enemy2){
	Species species;
	Creature temp(species, "t", 0);
	bool result = temp.if_enemy(nullptr, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, false);
}


TEST(CreatureFixture, if_empty1){
	Species species;
	Creature temp(species, "t", 0);
	bool result = temp.if_empty(nullptr, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, false);
}

TEST(CreatureFixture, if_empty2){
	Species species;
	Species species1;
	Creature temp(species, "t", 0);
	Creature empty(species1, ".", 0);
	bool result = temp.if_empty(&empty, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, true);
}

TEST(CreatureFixture, if_empty3){
	Species species;
	Species species1;
	Creature temp(species, "t", 0);
	Creature not_empty(species1, "e", 0);
	bool result = temp.if_empty(&not_empty, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, false);
}

TEST(CreatureFixture, if_wall1){
	Species species;
	Species species1;
	Creature temp(species, "t", 0);
	Creature not_empty(species1, "e", 0);
	bool result = temp.if_wall(&not_empty, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, false);
}

TEST(CreatureFixture, if_wall2){
	Species species;
	Species species1;
	Creature temp(species, "t", 0);
	Creature empty(species1, ".", 0);
	bool result = temp.if_wall(&empty, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, false);
}

TEST(CreatureFixture, if_wall3){
	Species species;
	Creature temp(species, "t", 0);
	bool result = temp.if_wall(nullptr, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, true);
}

TEST(CreatureFixture, if_enemy3){
	Species species;
	Species species1;
	Creature temp(species, "t", 0);
	Creature enemy(species1, ".", 0);
	bool result = temp.if_enemy(&enemy, nullptr, nullptr, nullptr);

	ASSERT_EQ(result, false);
}

// ------------
// Darwin Tests
// ------------

TEST(DarwinFixture, addCreature){
	Species test;
	Creature c(test, "c");

	Darwin d(5, 5);
	d.addCreature(c, 2, 3);

	ASSERT_EQ(d.v[2*5+3]._name, c._name);
}
TEST(DarwinFixture, addCreature1){
	Darwin d(6, 6);
	ASSERT_EQ(d.max_row, 6);
}
TEST(DarwinFixture, addCreature2){
	Darwin d(6, 6);
	ASSERT_EQ(d.max_col, 6);
}