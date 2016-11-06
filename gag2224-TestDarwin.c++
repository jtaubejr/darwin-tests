// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream>
#include <sstream>
#include <string>
#include "gtest/gtest.h"
#include "Darwin.h"

using namespace std;

// -----------------
// DarwinConstructor
// -----------------

TEST(DarwinConstructor, constructor1) {
    Darwin x;
    ASSERT_EQ(x._x, 10);
    ASSERT_EQ(x._y, 10);
}

TEST(DarwinConstructor, constructor2) {
    Darwin x = Darwin(7, 9);
    ASSERT_EQ(x._x, 7);
    ASSERT_EQ(x._y, 9);
}

TEST(DarwinConstructor, constructor3) {
    Darwin x = Darwin(72, 72);
    ASSERT_EQ(x._x, 72);
    ASSERT_EQ(x._y, 72);
}

// -----------------
// DarwinAddCreature
// -----------------

TEST(DarwinAddCreature, add1) {
    Darwin x;
    Species y = Species("y");
    Creature z = Creature(y, EAST);

    x.addCreature(z, 0, 0);
    ASSERT_TRUE(x._world[0][0] == &z);
}

TEST(DarwinAddCreature, add2) {
    Darwin x;
    Species y = Species("y");
    Creature z = Creature(y, EAST);

    x.addCreature(z, 9, 9);
    ASSERT_TRUE(x._world[9][9] == &z);

}

TEST(DarwinAddCreature, add3) {
    Darwin x;
    Species y1 = Species("a");
    Creature z1 = Creature(y1, EAST);
    Species y2 = Species("b");
    Creature z2 = Creature(y2, EAST);

    x.addCreature(z1, 0, 0);
    ASSERT_TRUE(x._world[0][0] == &z1);
    x.addCreature(z2, 9, 9);
    ASSERT_TRUE(x._world[9][9] == &z2);
}

// -------------------
// DarwinfindNeighbors
// -------------------

TEST(DarwinfindNeighbors, find1) {
    Darwin x;
    Creature *neighbors[4];
    x.findNeighbors(0, 0, neighbors);

    ASSERT_EQ(neighbors[0], WALL);
    ASSERT_EQ(neighbors[1], WALL);
    ASSERT_EQ(neighbors[2], nullptr);
    ASSERT_EQ(neighbors[3], nullptr);
}

TEST(DarwinfindNeighbors, find2) {
    Darwin x;
    Creature *neighbors[4];
    x.findNeighbors(9, 9, neighbors);

    ASSERT_EQ(neighbors[0], nullptr);
    ASSERT_EQ(neighbors[1], nullptr);
    ASSERT_EQ(neighbors[2], WALL);
    ASSERT_EQ(neighbors[3], WALL);
}

TEST(DarwinfindNeighbors, find3) {
    Darwin x;
    Creature *neighbors[4];
    x.findNeighbors(5, 5, neighbors);

    ASSERT_EQ(neighbors[0], nullptr);
    ASSERT_EQ(neighbors[1], nullptr);
    ASSERT_EQ(neighbors[2], nullptr);
    ASSERT_EQ(neighbors[3], nullptr);
}

// --------------------
// DarwinupdatePosition
// --------------------

TEST(DarwinupdatePosition, update1) {
    Darwin x;
    Species y = Species("y");
    Creature z = Creature(y, EAST);

    x.addCreature(z, 0, 0);
    x.updatePosition(0, 0, &z, EAST);

    ASSERT_EQ(x._world[0][0], nullptr);
    ASSERT_EQ(x._world[0][1], &z);
}

TEST(DarwinupdatePosition, update2) {
    Darwin x;
    Species y = Species("y");
    Creature z = Creature(y, EAST);

    x.addCreature(z, 0, 0);
    x.updatePosition(0, 0, &z, SOUTH);

    ASSERT_EQ(x._world[0][0], nullptr);
    ASSERT_EQ(x._world[1][0], &z);
}

TEST(DarwinupdatePosition, update3) {
    Darwin x;
    Species y = Species("y");
    Creature z = Creature(y, EAST);

    x.addCreature(z, 0, 0);
    x.updatePosition(0, 0, &z, NORTH);

    ASSERT_EQ(x._world[0][0], &z);
}

// -----------------
// DarwinexecuteTurn
// -----------------

TEST(DarwinexecuteTurn, execute1) {
    Darwin x;
    Species y = Species("y");
    y.addInstruction(HOP);
    y.addInstruction(GO, 0);
    Creature z = Creature(y, EAST);

    x.addCreature(z, 0, 0);

    x.executeTurn();
    ASSERT_EQ(x._world[0][0], nullptr);
    ASSERT_EQ(x._world[0][1], &z);
}

TEST(DarwinexecuteTurn, execute2) {
    Darwin x;
    Species y = Species("y");
    y.addInstruction(HOP);
    y.addInstruction(GO, 0);
    Creature z = Creature(y, EAST);

    x.addCreature(z, 0, 0);

    x.executeTurn();
    x.executeTurn();
    ASSERT_EQ(x._world[0][0], nullptr);
    ASSERT_EQ(x._world[0][2], &z);
}

TEST(DarwinexecuteTurn, execute3) {
    Darwin x;
    Species y = Species("y");
    y.addInstruction(LEFT);
    y.addInstruction(GO, 0);
    Creature z = Creature(y, EAST);

    x.addCreature(z, 0, 0);

    x.executeTurn();
    ASSERT_EQ(x._world[0][0], &z);
}

// -----------
// Darwinprint
// -----------

TEST(Darwinprint, print1) {
    Darwin x;
    stringstream ss;

    ss << x;
    ASSERT_EQ(ss.str(), "Turn = 0.\n  0123456789\n0 ..........\n1 ..........\n2 ..........\n3 ..........\n4 ..........\n5 ..........\n6 ..........\n7 ..........\n8 ..........\n9 ..........\n");
}

TEST(Darwinprint, print2) {
    Darwin x;
    stringstream ss;

    Species y = Species("y");
    Creature z = Creature(y, EAST);
    x.addCreature(z, 0, 0);

    ss << x;
    ASSERT_EQ(ss.str(), "Turn = 0.\n  0123456789\n0 y.........\n1 ..........\n2 ..........\n3 ..........\n4 ..........\n5 ..........\n6 ..........\n7 ..........\n8 ..........\n9 ..........\n");
}

TEST(Darwinprint, print3) {
    Darwin x;
    stringstream ss;

    Species y = Species("y");
    Creature z = Creature(y, EAST);
    x.addCreature(z, 9, 9);

    ss << x;
    ASSERT_EQ(ss.str(), "Turn = 0.\n  0123456789\n0 ..........\n1 ..........\n2 ..........\n3 ..........\n4 ..........\n5 ..........\n6 ..........\n7 ..........\n8 ..........\n9 .........y\n");
}

// -------------------
// CreatureConstructor
// -------------------

TEST(CreatureConstructor, constructor1) {
    Species y = Species("y");
    Creature z = Creature(y, EAST);

    ASSERT_EQ(z._species._name, y._name);
    ASSERT_EQ(z._dir, EAST);
    ASSERT_EQ(z._pc, 0);
}

TEST(CreatureConstructor, constructor2) {
    Species y = Species("x");
    Creature z = Creature(y, WEST);

    ASSERT_EQ(z._species._name, y._name);
    ASSERT_EQ(z._dir, WEST);
    ASSERT_EQ(z._pc, 0);
}

TEST(CreatureConstructor, constructor3) {
    Species y = Species("x");
    Creature z = Creature(y, SOUTH);

    ASSERT_EQ(z._species._name, y._name);
    ASSERT_EQ(z._dir, SOUTH);
    ASSERT_EQ(z._pc, 0);
}

// ---------------
// Creatureexecute
// ---------------

TEST(Creatureexecute, execute1) {
    Creature *neighbors[4] = {};
    Species y = Species("y");
    y.addInstruction(HOP);
    y.addInstruction(GO, 0);
    Creature z = Creature(y, SOUTH);

    Direction dir = z.execute(neighbors);

    ASSERT_EQ(z._pc, 1);
    ASSERT_EQ(z._dir, SOUTH);
    ASSERT_EQ(dir, SOUTH);
}

TEST(Creatureexecute, execute2) {
    Creature *neighbors[4] = {nullptr, WALL, nullptr, nullptr};
    Species y = Species("y");
    y.addInstruction(HOP);
    y.addInstruction(GO, 0);
    Creature z = Creature(y, NORTH);

    Direction dir = z.execute(neighbors);

    ASSERT_EQ(z._pc, 1);
    ASSERT_EQ(z._dir, NORTH);
    ASSERT_EQ(dir, NONE);
}

TEST(Creatureexecute, execute3) {
    Creature *neighbors[4] = {};
    Species y = Species("y");
    y.addInstruction(LEFT);
    y.addInstruction(GO, 0);
    Creature z = Creature(y, SOUTH);

    Direction dir = z.execute(neighbors);

    ASSERT_EQ(z._pc, 1);
    ASSERT_EQ(z._dir, EAST);
    ASSERT_EQ(dir, NONE);
}

// --------------
// Creatureinfect
// --------------

TEST(Creatureinfect, infect1) {
    Species y = Species("y");
    Creature z = Creature(y, SOUTH);

    z.infect(y);

    ASSERT_EQ(z._species._name, y._name);
}

TEST(Creatureinfect, infect2) {
    Species x = Species("x");
    Species y = Species("y");
    Creature z = Creature(y, SOUTH);

    z.infect(x);

    ASSERT_EQ(z._species._name, x._name);
}

TEST(Creatureinfect, infect3) {
    Species x = Species("x");
    Species y = Species("y");
    Creature z = Creature(y, SOUTH);

    z.infect(x);
    z.infect(y);

    ASSERT_EQ(z._species._name, y._name);
}

// ----------------
// Creaturenotequal
// ----------------

TEST(Creaturenotequal, equal1) {
    Species y = Species("y");
    Creature z = Creature(y, SOUTH);

    ASSERT_FALSE(y != z);
}

TEST(Creaturenotequal, equal2) {
    Species x = Species("x");
    Species y = Species("y");
    Creature z = Creature(y, SOUTH);

    ASSERT_FALSE(y != z);
    ASSERT_TRUE(x != z);
}

TEST(Creaturenotequal, equal3) {
    Species x = Species("x");
    Species y = Species("y");
    Creature z = Creature(x, SOUTH);

    ASSERT_FALSE(x != z);
    ASSERT_TRUE(y != z);
}

// ------------
// Creatureprint
// ------------

TEST(Creatureprint, print1) {
    Species y = Species("y");
    Creature z = Creature(y, SOUTH);

    stringstream ss;
    ss << z;

    ASSERT_EQ(ss.str(), "y");
}

TEST(Creatureprint, print2) {
    Species y = Species("a");
    Creature z = Creature(y, SOUTH);

    stringstream ss;
    ss << z;

    ASSERT_EQ(ss.str(), "a");
}

TEST(Creatureprint, print3) {
    Species y = Species("x");
    Creature z = Creature(y, SOUTH);

    stringstream ss;
    ss << z;

    ASSERT_EQ(ss.str(), "x");
}

// ------------------
// SpeciesConstructor
// ------------------

TEST(SpeciesConstructor, constructor1) {
    Species y = Species();

    ASSERT_EQ(y._name, "a");
}

TEST(SpeciesConstructor, constructor2) {
    Species y = Species("y");

    ASSERT_EQ(y._name, "y");
}

TEST(SpeciesConstructor, constructor3) {
    Species y = Species("hopper");

    ASSERT_EQ(y._name, "hopper");
}

// ---------------------
// SpeciesaddInstruction
// ---------------------

TEST(SpeciesaddInstruction, add1) {
    Species y = Species("y");
    y.addInstruction(GO, 0);

    ASSERT_EQ(y._program.size(), 1);
    ASSERT_EQ(y._program[0], make_pair(GO, 0));
}

TEST(SpeciesaddInstruction, add2) {
    Species y = Species("y");
    y.addInstruction(HOP);
    y.addInstruction(GO, 0);

    ASSERT_EQ(y._program.size(), 2);
    ASSERT_EQ(y._program[0], make_pair(HOP, -1));
    ASSERT_EQ(y._program[1], make_pair(GO, 0));
}

TEST(SpeciesaddInstruction, add3) {
    Species y = Species("y");
    y.addInstruction(LEFT);
    y.addInstruction(HOP);
    y.addInstruction(GO, 0);

    ASSERT_EQ(y._program.size(), 3);
    ASSERT_EQ(y._program[0], make_pair(LEFT, -1));
    ASSERT_EQ(y._program[1], make_pair(HOP, -1));
    ASSERT_EQ(y._program[2], make_pair(GO, 0));
}

// --------------
// Speciesexecute
// --------------

TEST(Speciesexecute, execute1) {
    Creature *neighbors[4] = {};
    Direction dir = NORTH;
    int pc = 0;
    Species y = Species("y");
    y.addInstruction(HOP);
    y.addInstruction(GO, 0);

    Direction move = y.execute(neighbors, &dir, &pc);

    ASSERT_EQ(dir, NORTH);
    ASSERT_EQ(pc, 1);
    ASSERT_EQ(move, NORTH);
}

TEST(Speciesexecute, execute2) {
    Creature *neighbors[4] = {nullptr, WALL, nullptr, nullptr};
    Direction dir = NORTH;
    int pc = 0;
    Species y = Species("y");
    y.addInstruction(HOP);
    y.addInstruction(GO, 0);

    Direction move = y.execute(neighbors, &dir, &pc);

    ASSERT_EQ(dir, NORTH);
    ASSERT_EQ(pc, 1);
    ASSERT_EQ(move, NONE);
}

TEST(Speciesexecute, execute3) {
    Creature *neighbors[4] = {};
    Direction dir = NORTH;
    int pc = 0;
    Species y = Species("y");
    y.addInstruction(LEFT);
    y.addInstruction(GO, 0);

    Direction move = y.execute(neighbors, &dir, &pc);

    ASSERT_EQ(dir, WEST);
    ASSERT_EQ(pc, 1);
    ASSERT_EQ(move, NONE);
}

// ---------------
// Speciesprint
// ---------------

TEST(Speciesprint, print1) {
    Species y = Species("y");

    stringstream ss;
    ss << y;

    ASSERT_EQ(ss.str(), "y");
}

TEST(Speciesprint, print2) {
    Species y = Species("x");

    stringstream ss;
    ss << y;

    ASSERT_EQ(ss.str(), "x");
}

TEST(Speciesprint, print3) {
    Species y = Species("hopper");

    stringstream ss;
    ss << y;

    ASSERT_EQ(ss.str(), "h");
}
