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

// TEST(DarwinFixture, test) {
//     Darwin x;
//     ASSERT_TRUE(x.dummy());}


// ----
// test
// ----

TEST(DarwinFixture, DarwinConstructPrint) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;
	Darwin x = Darwin(5,5, 5);
	w << x;
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, DarwinConstructPrint2) {
	istringstream r("Turn = 0.\n  01234567890123456\n0 .................\n1 .................\n2 .................\n3 ................."
		"\n4 .................\n5 .................\n6 .................\n7 .................\n8 .................\n9 ................."
		"\n0 .................\n1 .................\n2 .................\n3 .................\n4 .................\n5 .................\n"
		"6 .................\n\n");
	ostringstream w;
	Darwin x = Darwin(17,17, 15);
	w << x;
	ASSERT_EQ(r.str(), w.str());
}

// ----
// Initialize and display species
// ----

TEST(DarwinFixture, CreateDisplaySpecies) {
	Species s = Species("human");
	ostringstream w;
	w << s;
	ASSERT_EQ("h",w.str());
}

TEST(DarwinFixture, CreateDisplaySpecies2) {
	Species s = Species("rover");
	ostringstream w;
	w << s;
	ASSERT_EQ("r",w.str());
}

TEST(DarwinFixture, CreateDisplaySpecies3) {
	Species s = Species("compsci");
	ostringstream w;
	w << s;
	ASSERT_EQ("c",w.str());
}

// ----
// Initialize and display creature
// ----

TEST(DarwinFixture, CreateDisplayCreature) {
	Species s = Species("rover");
	Creature c = Creature(s, NORTH);
	ostringstream w;
	w << c;
	ASSERT_EQ("r",w.str());
}

TEST(DarwinFixture, CreateDisplayCreature2) {
	Species s = Species("hopper");
	Creature c = Creature(s, NORTH);
	ostringstream w;
	w << c;
	ASSERT_EQ("h",w.str());
}

TEST(DarwinFixture, CreateDisplayCreature3) {
	Species s = Species("grover");
	Creature c = Creature(s, NORTH);
	ostringstream w;
	w << c;
	ASSERT_EQ("g",w.str());
}

// ----
// Add creature to grid
// ----

TEST(DarwinFixture, AddCreature) {
	istringstream r("Turn = 0.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 5);
    Species s = Species("hopper");
	Creature c = Creature(s, NORTH);
	x.addCreature(&c, 0, 0);
	w << x;
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, AddCreature2) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 ...h.\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 5);
    Species s = Species("hopper");
	Creature c = Creature(s, NORTH);
	x.addCreature(&c, 1, 3);
	w << x;
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, AddMultipleCreature) {
	istringstream r("Turn = 0.\n  01234\n0 h....\n1 h....\n2 .....\n3 ..h..\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 5);
    Species s = Species("hopper");
	Creature c = Creature(s, NORTH);

	x.addCreature(&c, 0, 0);
	x.addCreature(&c, 1, 0);
	x.addCreature(&c, 3, 2);

	w << x;
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, AddMultipleCreature2) {
	istringstream i("Turn = 0.\n  01234\n0 h....\n1 h....\n2 .....\n3 ..hr.\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 5);
    Species s = Species("hopper");
    Species r = Species("rover");
	Creature c = Creature(s, NORTH);
	Creature d = Creature(r, SOUTH);

	x.addCreature(&c, 0, 0);
	x.addCreature(&c, 1, 0);
	x.addCreature(&c, 3, 2);
	x.addCreature(&d, 3, 3);

	w << x;
	ASSERT_EQ(i.str(), w.str());
}

TEST(DarwinFixture, AddMultipleCreature3) {
	istringstream i("Turn = 0.\n  01234\n0 h....\n1 hr...\n2 .....\n3 ..hr.\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 5);
    Species s = Species("hopper");
    Species r = Species("rover");
	Creature c = Creature(s, NORTH);
	Creature d = Creature(r, SOUTH);

	x.addCreature(&c, 0, 0);
	x.addCreature(&c, 1, 0);
	x.addCreature(&c, 3, 2);
	x.addCreature(&d, 3, 3);
	x.addCreature(&d, 1, 1);

	w << x;
	ASSERT_EQ(i.str(), w.str());
}

// ----
// Creature Hops
// ----

TEST(DarwinFixture, HopNorth) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, NORTH);
	x.addCreature(&c, 1, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, HopEast) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, EAST);
	x.addCreature(&c, 1, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, HopSouth) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .....\n2 h....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, SOUTH);
	x.addCreature(&c, 1, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, HopWest) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, WEST);
	x.addCreature(&c, 1, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, HopMult) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .....\n2 .h...\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 .....\n2 .....\n3 .h...\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, SOUTH);
	x.addCreature(&c, 1, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, HopWall) {
	istringstream r("Turn = 0.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, NORTH);
	x.addCreature(&c, 0, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, HopWall2) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, WEST);
	x.addCreature(&c, 1, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, HopWall3) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .....\n2 .....\n3 .....\n4 .h...\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .....\n2 .....\n3 .....\n4 .h...\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, SOUTH);
	x.addCreature(&c, 4, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, HopWall4) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 ....h\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 ....h\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, EAST);
	x.addCreature(&c, 1, 4);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, HopObject) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 fh...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 fh...\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    Species food = Species("food");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
    food.addInstruction(LEFT);
    food.addInstruction(GO,0);
	Creature c = Creature(s, WEST);
	Creature f = Creature(food, WEST);
	x.addCreature(&c, 1, 1);
	x.addCreature(&f, 1, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

// ----
// Creature Turns
// ----

//20th tests below
TEST(DarwinFixture, TurnLeft) {
	istringstream r("Turn = 0.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, WEST);
	x.addCreature(&c, 0, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}
//20th above

TEST(DarwinFixture, TurnRight) {
	istringstream r("Turn = 0.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(RIGHT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, NORTH);
	x.addCreature(&c, 0, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

// ----
// Creature Infect
// ----

TEST(DarwinFixture, CreatureInfect) {
	istringstream r("Turn = 0.\n  01234\n0 hf...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 hh...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    Species food = Species("food");
    s.addInstruction(INFECT);
    s.addInstruction(GO, 0);
    food.addInstruction(LEFT);
    food.addInstruction(GO, 0);
	Creature c = Creature(s, EAST);
	Creature f = Creature(food, WEST);
	x.addCreature(&c, 0, 0);
	x.addCreature(&f,0,1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureNoInfect) {
	istringstream r("Turn = 0.\n  01234\n0 h.f..\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 h.f..\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 1);
    Species s = Species("hopper");
    Species food = Species("food");
    s.addInstruction(INFECT);
    s.addInstruction(GO, 0);
    food.addInstruction(LEFT);
    food.addInstruction(GO, 0);
	Creature c = Creature(s, EAST);
	Creature f = Creature(food, WEST);
	x.addCreature(&c, 0, 0);
	x.addCreature(&f,0,2);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureInfectWest) {
	istringstream r("Turn = 0.\n  01234\n0 h.f..\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 h.f..\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .hf..\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 .hh..\n1 .....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    Species food = Species("food");
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(INFECT);
    s.addInstruction(GO, 0);
    food.addInstruction(LEFT);
    food.addInstruction(GO, 0);
	Creature c = Creature(s, SOUTH);
	Creature f = Creature(food, WEST);
	x.addCreature(&c, 0, 0);
	x.addCreature(&f,0,2);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureInfectEast) {
	istringstream r("Turn = 0.\n  01234\n0 f.h..\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 f.h..\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 fh...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 hh...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    Species food = Species("food");
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(INFECT);
    s.addInstruction(GO, 0);
    food.addInstruction(LEFT);
    food.addInstruction(GO, 0);
	Creature c = Creature(s, NORTH);
	Creature f = Creature(food, WEST);
	x.addCreature(&c, 0, 2);
	x.addCreature(&f,0,0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}


TEST(DarwinFixture, CreatureInfectNorth) {
	istringstream r("Turn = 0.\n  01234\n0 f....\n1 .....\n2 h....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 f....\n1 .....\n2 h....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 f....\n1 h....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 h....\n1 h....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    Species food = Species("food");
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(INFECT);
    s.addInstruction(GO, 0);
    food.addInstruction(LEFT);
    food.addInstruction(GO, 0);
	Creature c = Creature(s, EAST);
	Creature f = Creature(food, WEST);
	x.addCreature(&c, 2, 0);
	x.addCreature(&f,0,0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureInfectSouth) {
	istringstream r("Turn = 0.\n  01234\n0 h....\n1 .....\n2 f....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 h....\n1 .....\n2 f....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 h....\n2 f....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 .....\n1 h....\n2 h....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    Species food = Species("food");
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(INFECT);
    s.addInstruction(GO, 0);
    food.addInstruction(LEFT);
    food.addInstruction(GO, 0);
	Creature c = Creature(s, WEST);
	Creature f = Creature(food, WEST);
	x.addCreature(&c, 0, 0);
	x.addCreature(&f,2,0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureInfectWall) {
	istringstream r("Turn = 0.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    s.addInstruction(INFECT);
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, WEST);
	x.addCreature(&c, 0, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureInfectFriend) {
	istringstream r("Turn = 0.\n  01234\n0 hh...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 hh...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 hh...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 .....\n1 hh...\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    s.addInstruction(INFECT);
    s.addInstruction(RIGHT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, EAST);
	Creature d = Creature(s, EAST);
	x.addCreature(&c, 0, 0);
	x.addCreature(&d, 0, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureInfectMult1) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .....\n2 .....\n3 ..h..\n4 .....\n5 ....r\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .....\n2 .....\n3 ...h.\n4 ....r\n5 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 .....\n2 .....\n3 ....r\n4 ....r\n5 .....\n\n");
		//"Turn = 3.\n  01234\n0 .....\n1 .....\n2 .....\n3 .....\n4 .....\n5 .....\n\n");

    ostringstream w;

    Species hopper("hopper");
    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Species rover("rover");
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

    srand(0);

    Darwin d2(6, 5, 2);
    Creature h21(hopper, EAST);
    Creature r21(rover, NORTH);
    d2.addCreature(&h21, 3,2);
    d2.addCreature(&r21, 5,4);
    d2.playGame(w);

	ASSERT_EQ(r.str(), w.str());
}

//
// IF EMPTY TEST
//

TEST(DarwinFixture, CreatureIfEmpty1) {
	istringstream r("Turn = 0.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    s.addInstruction(IF_EMPTY, 3);
    s.addInstruction(LEFT);
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(LEFT);
    s.addInstruction(LEFT);
    s.addInstruction(GO, 0);

	Creature c = Creature(s, EAST);
	x.addCreature(&c, 0, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureIfEmptyWest) {
	istringstream r("Turn = 0.\n  01234\n0 ...h.\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 ..h..\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(IF_EMPTY, 3);
    s.addInstruction(LEFT);
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(HOP);
    s.addInstruction(LEFT);
    s.addInstruction(GO, 0);

	Creature c = Creature(s, WEST);
	x.addCreature(&c, 0, 3);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureIfEmptyWall) {
	istringstream r("Turn = 0.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    s.addInstruction(IF_EMPTY, 3);
    s.addInstruction(LEFT);
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);

	Creature c = Creature(s, WEST);
	x.addCreature(&c, 0, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureIfEmptyFrenemy) {
	istringstream r("Turn = 0.\n  01234\n0 hf...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 hf...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 hf...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 hf...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    s.addInstruction(IF_EMPTY, 3);
    s.addInstruction(LEFT);
    s.addInstruction(LEFT);
    s.addInstruction(RIGHT);
    s.addInstruction(HOP);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);


    Species food = Species("food");
    food.addInstruction(LEFT);
    food.addInstruction(GO, 0);
	Creature f = Creature(food, WEST);
	Creature c = Creature(s, EAST);

	x.addCreature(&f, 0, 1);
	x.addCreature(&c, 0, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureIfEmptyFrenemy2) {
	istringstream r("Turn = 0.\n  01234\n0 h.f..\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 h.f..\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 ..f..\n1 h....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 ..f..\n1 .....\n2 h....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    s.addInstruction(IF_EMPTY, 3);
    s.addInstruction(LEFT);
    s.addInstruction(LEFT);
    s.addInstruction(RIGHT);
    s.addInstruction(HOP);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);


    Species food = Species("food");
    food.addInstruction(LEFT);
    food.addInstruction(GO, 0);
	Creature f = Creature(food, WEST);
	Creature c = Creature(s, EAST);

	x.addCreature(&f, 0, 2);
	x.addCreature(&c, 0, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

//
// Creature Turn
//

TEST(DarwinFixture, CreatureTurnRight) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(RIGHT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, WEST);
	x.addCreature(&c, 1, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureTurnRight2) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 ..h..\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(RIGHT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, NORTH);
	x.addCreature(&c, 1, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureTurnRight3) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 .....\n2 .h...\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(RIGHT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, EAST);
	x.addCreature(&c, 1, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureTurnRight4) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(RIGHT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, SOUTH);
	x.addCreature(&c, 1, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureTurnLeft) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 .....\n2 .h...\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, WEST);
	x.addCreature(&c, 1, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureTurnLeft2) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, NORTH);
	x.addCreature(&c, 1, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureTurnLeft3) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, EAST);
	x.addCreature(&c, 1, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureTurnLeft4) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .....\n1 .h...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 ..h..\n2 .....\n3 .....\n4 .....\n\n");
    ostringstream w;

    Darwin x = Darwin(5,5, 2);
    Species s = Species("hopper");
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);
	Creature c = Creature(s, SOUTH);
	x.addCreature(&c, 1, 1);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureIfWall1) {
	istringstream r("Turn = 0.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 .....\n1 h....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    s.addInstruction(IF_WALL, 3);
    s.addInstruction(HOP);
    s.addInstruction(LEFT);
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(LEFT);
    s.addInstruction(GO, 0);

	Creature c = Creature(s, WEST);
	x.addCreature(&c, 0, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureIfWallNone) {
	istringstream r("Turn = 0.\n  01234\n0 h....\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 .h...\n1 .....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 3);
    Species s = Species("hopper");
    s.addInstruction(IF_WALL, 3);
    s.addInstruction(HOP);
    s.addInstruction(LEFT);
    s.addInstruction(LEFT);
    s.addInstruction(HOP);
    s.addInstruction(LEFT);
    s.addInstruction(GO, 0);

	Creature c = Creature(s, EAST);
	x.addCreature(&c, 0, 0);
	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

//
// Test Flow of Control
//

TEST(DarwinFixture, CreatureControlFlow1) {
	istringstream r("Turn = 0.\n  01234\n0 ...f.\n1 .r...\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 .r.f.\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 .r.f.\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 ..rf.\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 4.\n  01234\n0 ..r.r\n1 .....\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;

    Darwin x = Darwin(5,5, 4);

    Species food("food");
    food.addInstruction(RIGHT);
    food.addInstruction(GO, 0);

    Species rover("rover");
    rover.addInstruction(IF_EMPTY, 7);
    rover.addInstruction(IF_ENEMY, 9);
    rover.addInstruction(IF_RANDOM, 5);
    rover.addInstruction(LEFT);
    rover.addInstruction(GO, 0);
    rover.addInstruction(RIGHT);
    rover.addInstruction(GO, 0);
    rover.addInstruction(HOP);
    rover.addInstruction(GO, 0);
    rover.addInstruction(INFECT);
    rover.addInstruction(GO, 0);

   	Creature rov = Creature(rover, NORTH);
	Creature f = Creature(food, SOUTH);
	x.addCreature(&rov, 1, 1);
	x.addCreature(&f, 0, 3);

	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}

TEST(DarwinFixture, CreatureControlFlow2) {
	istringstream r("Turn = 0.\n  01234\n0 .....\n1 ....r\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 1.\n  01234\n0 ....r\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 2.\n  01234\n0 ....r\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 3.\n  01234\n0 ....r\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 4.\n  01234\n0 ....r\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 5.\n  01234\n0 ....r\n1 .....\n2 .....\n3 .....\n4 .....\n\n"
		"Turn = 6.\n  01234\n0 .....\n1 ....r\n2 .....\n3 .....\n4 .....\n\n");

    ostringstream w;
    srand(0);
    Darwin x = Darwin(5,5, 6);

    Species rover("rover");
    rover.addInstruction(IF_EMPTY, 7);
    rover.addInstruction(IF_ENEMY, 9);
    rover.addInstruction(IF_RANDOM, 5);
    rover.addInstruction(LEFT);
    rover.addInstruction(GO, 0);
    rover.addInstruction(RIGHT);
    rover.addInstruction(GO, 0);
    rover.addInstruction(HOP);
    rover.addInstruction(GO, 0);
    rover.addInstruction(INFECT);
    rover.addInstruction(GO, 0);

   	Creature rov = Creature(rover, NORTH);
	x.addCreature(&rov, 1, 4);

	x.playGame(w);
	ASSERT_EQ(r.str(), w.str());
}




