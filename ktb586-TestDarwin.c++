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
#include <iostream>
#include <sstream>

using namespace std;

// ----
// Tests for Species
// ----

TEST(DarwinFixture, test1) {
    Species food('f');
    ASSERT_EQ(food.name, 'f');
}

TEST(DarwinFixture, test2) {
    Species hopper('h');
    ASSERT_EQ(hopper.name, 'h');
}

TEST(DarwinFixture, test3) {
    Species rover('r');
    ASSERT_EQ(rover.name, 'r');
}

TEST(DarwinFixture, test4) {
    Species trap('t');
    trap.add_instruction("left");
    ASSERT_EQ(trap.programs[0], "left");
}

TEST(DarwinFixture, test5) {
    Species trap('t');
    trap.add_instruction("left");
    trap.add_instruction("go 0");
    ASSERT_EQ(trap.programs[1], "go 0");
}

TEST(DarwinFixture, test6) {
    Species trap('t');
    trap.add_instruction("left");
    trap.add_instruction("left");
    trap.add_instruction("left");
    trap.add_instruction("left");
    ASSERT_EQ(trap.programs.size(), 4);
}

TEST(DarwinFixture, test7) {
    Species trap('t');
    Species hopper('h');
    ASSERT_FALSE(trap == hopper);
}

TEST(DarwinFixture, test8) {
    Species trap('t');
    Species trap2('t');
    ASSERT_EQ(trap, trap2);
}

TEST(DarwinFixture, test9) {
    Species trap('t');
    Species trap2('f');
    ASSERT_FALSE(trap == trap2);
}

TEST(DarwinFixture, test10) {
    Species trap('t');
    trap.add_instruction("right");
    ASSERT_FALSE(trap.get_instruction(0) == "left");
}

TEST(DarwinFixture, test11) {
    Species trap('t');
    trap.add_instruction("right");
    trap.add_instruction("hop");
    trap.add_instruction("go 0");
    ASSERT_EQ(trap.get_instruction(1), "hop");
}

TEST(DarwinFixture, test12) {
    Species trap('t');
    trap.add_instruction("right");
    trap.add_instruction("right");
    trap.add_instruction("right");
    trap.add_instruction("right");
    ASSERT_FALSE(trap.get_instruction(3) != "right");
}

// --------
// Creature
// --------

TEST(DarwinFixture1, creature1) {
    Species t('t');
    Creature c(&t, Direction::left);
    ASSERT_EQ(c.facing, Direction::left);
}

TEST(DarwinFixture1, creature2) {
    Species t('t');
    Species h('h');
    Creature c(&t, Direction::left);
    Creature h2(&h, Direction::left);
    h2.infect(c);
    ASSERT_EQ(h2.species, c.species);
}

TEST(DarwinFixture1, creature3) {
    Species t('t');
    Species h('h');
    Creature c(&t, Direction::left);
    Creature h2(&h, Direction::right);
    h2.infect(c);
    ASSERT_EQ(h2.species, c.species);
}

TEST(DarwinFixture1, creature4) {
    Species t('t');
    Species h('h');
    Creature c(&t, Direction::left);
    Creature c2(&t, Direction::left);
    Creature c3(&t, Direction::left);
    Creature h2(&h, Direction::right);
    h2.infect(c);
    h2.infect(c2);
    c3.infect(c2);
    ASSERT_EQ(c2.species, c3.species);
    ASSERT_EQ(c.species, h2.species);
}

TEST(DarwinFixture1, creature5) {
    Species t('t');
    t.add_instruction("go 0");
    string test = t.get_instruction(0);
    Creature c(&t, Direction::left);
    vector<string> s = c.split(test, ' ');
    ASSERT_EQ(s[0], "go");
}

TEST(DarwinFixture1, creature6) {
    Species t('t');
    t.add_instruction("go 0");
    string test = t.get_instruction(0);
    Creature c(&t, Direction::left);
    vector<string> s = c.split(test, ' ');
    ASSERT_EQ(s[1], "0");
}

TEST(DarwinFixture1, creature7) {
    Species t('t');
    t.add_instruction("right");
    string test = t.get_instruction(0);
    Creature c(&t, Direction::left);
    vector<string> s = c.split(test, ' ');
    ASSERT_EQ(s[0], "right");
}

TEST(DarwinFixture1, creature8) {
    Species t('t');
    t.add_instruction("right");
    Creature c(&t, Direction::left);
    ASSERT_EQ(c.facing, Direction::left);
    c.turn_left();
    ASSERT_EQ(c.facing, Direction::down);
}

TEST(DarwinFixture1, creature9) {
    Species t('t');
    Creature c(&t, Direction::left);
    c.turn_left();
    c.turn_left();
    ASSERT_EQ(c.facing, Direction::right);
}

TEST(DarwinFixture1, creature10) {
    Species t('t');
    Creature c(&t, Direction::left);
    ASSERT_EQ(c.facing, Direction::left);
    c.turn_left();
    c.turn_left();
    c.turn_left();
    ASSERT_EQ(c.facing, Direction::up);
}

TEST(DarwinFixture1, creature11) {
    Species t('t');
    t.add_instruction("right");
    t.add_instruction("go 0");
    Creature c(&t, Direction::left);
    c.exec_instr(NULL, NULL, NULL, NULL, NULL, 0);
    ASSERT_EQ(c.facing, 2);
}

TEST(DarwinFixture1, creature12) {
    Species t('t');
    t.add_instruction("left");
    t.add_instruction("go 0");
    Creature c(&t, Direction::right);
    c.exec_instr(NULL, NULL, NULL, NULL, NULL, 0);
    ASSERT_EQ(c.facing, 3);
}

TEST(DarwinFixture1, creature13) {
    Species t('t');
    t.add_instruction("right");
    t.add_instruction("right");
    t.add_instruction("right");
    Creature c(&t, Direction::down);
    c.exec_instr(NULL, NULL, NULL, NULL, NULL, 0);
    ASSERT_EQ(c.facing, 1);
}

TEST(DarwinFixture1, creature14) {
    Darwin x(8, 8);
    Species t('t');
    Creature c(&t, Direction::up);
    Creature c2(&t, Direction::up);
}

// ------
// Darwin
// ------

TEST(DarwinFixture2, darwin1) {
    Darwin x(4, 4);
    ASSERT_EQ(x.height, 4);
}

TEST(DarwinFixture2, darwin2) {
    Darwin x(100, 100);
    ASSERT_EQ(x.width, 100);
}

TEST(DarwinFixture2, darwin3) {
    Darwin x(9, 7);
    ASSERT_EQ(x.height, 9);
    ASSERT_EQ(x.width, 7);
}

TEST(DarwinFixture2, darwin4) {
    Darwin x(8, 8);
    Species t('t');
    Creature c(&t, Direction::left);
    Creature c2(&t, Direction::left);
    x.add_creature(c, 4, 4);
    ASSERT_EQ(x.board[4][4]->species, c2.species);
}

TEST(DarwinFixture2, darwin5) {
    Darwin x(8, 8);
    Species t('t');
    Creature c(&t, Direction::left);
    Creature c2(&t, Direction::left);
    x.add_creature(c, 3, 7);
    ASSERT_EQ(x.board[3][7]->species, c2.species);
}

TEST(DarwinFixture2, darwin6) {
    Darwin x(8, 8);
    Species t('t');
    Creature c(&t, Direction::left);
    Creature c2(&t, Direction::left);
    x.add_creature(c, 7, 7);
    ASSERT_EQ(x.board[7][7]->species, c2.species);
}

TEST(DarwinFixture2, darwin7) {
    Darwin x(8, 8);
    Species t('t');
    t.add_instruction("hop");
    t.add_instruction("go 0");
    Creature c(&t, Direction::left);
    Creature c2(&t, Direction::left);
    x.add_creature(c, 4, 7);
    ostringstream i;
    x.process_turn(1);
    ASSERT_EQ(x.board[4][6]->species, c.species);
}

TEST(DarwinFixture2, darwin9) {
    Darwin x(8, 8);
    Species t('t');
    t.add_instruction("hop");
    t.add_instruction("go 0");
    Creature c(&t, Direction::left);
    Creature c2(&t, Direction::left);
    x.add_creature(c, 4, 7);
    ostringstream i;
    x.process_turn(1);
    x.process_turn(2);
    x.process_turn(3);
    ASSERT_EQ(x.board[4][4]->species, c.species);
}
