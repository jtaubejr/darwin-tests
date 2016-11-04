// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_tions

// --------
// includes
// --------

#include "gtest/gtest.h"
#include <sstream> // ostringstream
#include "Darwin.h"

using namespace std;


//-----------------
// DarwinPrintGrid
//-----------------

TEST(DarwinPrintGrid, print1) {

}

TEST(DarwinPrintGrid, print2) {
// ostringstream answer;

}

TEST(DarwinPrintGrid, print3) {
// ostringstream answer;

}

//-------------------
// DarwinAddCreature
//-------------------

TEST(DarwinAddCreature, creature1) {
	Darwin sim(1,1);
	ASSERT_EQ((sim.rows[0])[0], nullptr);
	Species test("f", "north");
	sim.placeInGrid((Species*)&test, 0, 0);
	ASSERT_EQ(&(*((sim.rows[0])[0])), &test);
}

TEST(DarwinAddCreature, creature2) {
	Darwin sim(2,2);
	ASSERT_EQ((sim.rows[1])[0], nullptr);
	Species test("f", "north");
	sim.placeInGrid((Species*)&test, 1, 0);
	ASSERT_EQ(&(*((sim.rows[1])[0])), &test);
}

//----------------
// SpeciesIsEnemy
//----------------

TEST(SpeciesIsEnemy, isEnemy1){

}

TEST(SpeciesIsEnemy, isEnemy2) {

}

TEST(SpeciesIsEnemy, isNotEnemy) {

}

TEST(SpeciesIsEnemy, isEmpty) {

}