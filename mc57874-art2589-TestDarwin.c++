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

// ----
// test
// ----

/* --------- Darwin Tests -------- */

// ------------
// add_creature
// ------------
TEST(DarwinFixture, darwin_add_creature1) {
    Darwin d1(1,1);
    Darwin::Species food('f');
    food.add_inst("left\ngo 0");
    Darwin::Creature c = Darwin::Creature(&food, 0, EAST);
    d1.add_creature(&c, 0, 0);
    ostringstream os;
    d1.print_map(os);
    ASSERT_EQ("  0\n0 f\n\n", os.str());
}

TEST(DarwinFixture, darwin_add_creature2) {
    Darwin d2(2,2);
    Darwin::Species hopper('h');
    hopper.add_inst("hop\ngo 0");

    Darwin::Creature bot_left = Darwin::Creature(&hopper, 0, NORTH);
    Darwin::Creature top_right = Darwin::Creature(&hopper, 0, EAST);
    Darwin::Creature bot_right = Darwin::Creature(&hopper, 0, WEST);

    d2.add_creature(&bot_left, 1, 0);
    d2.add_creature(&top_right, 0, 1);
    d2.add_creature(&bot_right, 1, 1);
    ostringstream os;
    d2.print_map(os);
    ASSERT_EQ("  01\n0 .h\n1 hh\n\n", os.str());
}

TEST(DarwinFixture, darwin_add_creature3) {
    Darwin d3(2,2);
    Darwin::Species food('f');
    food.add_inst("left\ngo 0");
    Darwin::Creature c = Darwin::Creature(&food, 0, EAST);
    d3.add_creature(&c, 1, 1);
    ostringstream os;
    d3.print_map(os);
    ASSERT_EQ("  01\n0 ..\n1 .f\n\n", os.str());
}

// ---------
// run_board
// ---------
TEST(DarwinFixture, darwin_run_board1) {
    Darwin d1(2,2);
    Darwin::Species hopper('h');
    hopper.add_inst("hop\ngo 0");

    Darwin::Creature bot_left = Darwin::Creature(&hopper, 0, NORTH);
    Darwin::Creature top_right = Darwin::Creature(&hopper, 0, EAST);
    Darwin::Creature bot_right = Darwin::Creature(&hopper, 0, WEST);

    d1.add_creature(&bot_left, 1, 0);
    d1.add_creature(&top_right, 0, 1);
    d1.add_creature(&bot_right, 1, 1);
    ostringstream os;
    d1.run_board();
    d1.print_map(os);
    ASSERT_EQ("  01\n0 hh\n1 h.\n\n", os.str());
}


TEST(DarwinFixture, darwin_run_board2) {
    Darwin d1(5,5);
    Darwin::Species rover('r');
    rover.add_inst("if_enemy 9\nif_empty 7\nif_random 5\nleft\ngo 0\nright\ngo "
            "0\nhop\ngo 0\ninfect\ngo 0");
    Darwin::Species hopper('h');
    hopper.add_inst("hop\ngo 0");

    Darwin::Creature c1 = Darwin::Creature(&hopper, 0, EAST);
    Darwin::Creature c2 = Darwin::Creature(&rover, 0, WEST);
    Darwin::Creature c3 = Darwin::Creature(&hopper, 0, EAST);
    Darwin::Creature c4 = Darwin::Creature(&hopper, 0, EAST);

    d1.add_creature(&c1, 2, 2);
    d1.add_creature(&c2, 2, 3);
    d1.add_creature(&c3, 1, 4);
    d1.add_creature(&c4, 1, 3);

    ostringstream os;
    d1.run_board();
    d1.print_map(os);
    ASSERT_EQ("  01234\n0 .....\n1 ...hh\n2 ..rr.\n3 .....\n4 .....\n\n", os.str());
}

TEST(DarwinFixture, darwin_run_board3) {
    // makes sure each creature only gets one turn
    Darwin d3(2,2);
    Darwin::Species hopper('r');
    hopper.add_inst("right\nhop");
    Darwin::Creature c1 = Darwin::Creature(&hopper, 0, EAST);
    d3.add_creature(&c1,0,0);

    d3.run_board();

    ostringstream os;
    d3.print_map(os);
    ASSERT_EQ("  01\n0 r.\n1 ..\n\n", os.str());
}

// --------------
// front_creature
// --------------
TEST(DarwinFixture, darwin_front_creature1) {
    Darwin d(2,2);
    Darwin::Species s1('a');
    Darwin::Species s2('b');
    Darwin::Creature c1 = Darwin::Creature(&s1, 0, EAST);
    Darwin::Creature c2 = Darwin::Creature(&s2, 0, EAST);

    d.add_creature(&c1, 0, 0);
    d.add_creature(&c2, 0, 1);

    ASSERT_EQ(&c2,d.front_creature(0,0));
}

TEST(DarwinFixture, darwin_front_creature2) {
    Darwin d(2,2);
    Darwin::Species s1('a');
    Darwin::Species s2('b');
    Darwin::Creature c1 = Darwin::Creature(&s1, 0, SOUTH);
    Darwin::Creature c2 = Darwin::Creature(&s2, 0, EAST);

    d.add_creature(&c1, 0, 0);
    d.add_creature(&c2, 0, 1);

    ASSERT_NE(d.front_creature(0,0), &c2);
}

TEST(DarwinFixture, darwin_front_creature3) {
    Darwin d(2,2);
    Darwin::Species s1('a');
    Darwin::Species s2('b');
    Darwin::Creature c1 = Darwin::Creature(&s1, 0, NORTH);
    Darwin::Creature c2 = Darwin::Creature(&s2, 0, EAST);

    d.add_creature(&c1, 0, 0);
    d.add_creature(&c2, 0, 1);

    ASSERT_EQ(d.front_creature(0,0), &c1);
}

// ---------
// print_map
// ---------

TEST(DarwinFixture, print_map1) {
    Darwin d(1,1);
    Darwin::Species s1('a');
    Darwin::Creature c1 = Darwin::Creature(&s1, 0, NORTH);
    d.add_creature(&c1, 0, 0);
    ostringstream os;
    d.print_map(os);

    ASSERT_EQ("  0\n0 a\n\n", os.str());
}

TEST(DarwinFixture, print_map2) {
    Darwin d(2,2);
    Darwin::Species s1('a');
    Darwin::Creature c1 = Darwin::Creature(&s1, 0, NORTH);
    Darwin::Species s2('b');
    Darwin::Creature c2 = Darwin::Creature(&s2, 0, NORTH);
    d.add_creature(&c1, 0, 0);
    d.add_creature(&c2, 1, 1);
    ostringstream os;
    d.print_map(os);

    ASSERT_EQ("  01\n0 a.\n1 .b\n\n", os.str());
}

TEST(DarwinFixture, print_map3) {
    Darwin d(3,1);
    Darwin::Species s1('a');
    Darwin::Creature c1 = Darwin::Creature(&s1, 0, NORTH);
    Darwin::Species s2('b');
    Darwin::Creature c2 = Darwin::Creature(&s1, 0, NORTH);
    d.add_creature(&c1, 0, 0);
    d.add_creature(&c2, 2, 0);
    ostringstream os;
    d.print_map(os);

    ASSERT_EQ("  0\n0 a\n1 .\n2 a\n\n", os.str());
}
/* --------- Species Tests -------- */
// ----------------
// Species constructor
// ----------------
TEST(SpeciesFixture, species_constructor_1) {
    Darwin::Species food('f');
    food.add_inst("left\ngo 0");
    ASSERT_EQ(food.program.size(), 2);
    ASSERT_EQ(food.display, 'f');
}

TEST(SpeciesFixture, species_constructor_2) {
    Darwin::Species hopper('h');
    hopper.add_inst("hop\ngo 0");
    ASSERT_EQ(hopper.program.size(), 2);
    ASSERT_EQ(hopper.display, 'h');
}

TEST(SpeciesFixture, species_constructor_3) {
    Darwin::Species trap('t');
    trap.add_inst("if_enemy 3\nleft\ngo 0\ninfect\ngo 0");
    ASSERT_EQ(trap.program.size(), 5);
    ASSERT_EQ(trap.display, 't');
}

TEST(SpeciesFixture, species_constructor_4) {
    Darwin::Species r('r');
    r.add_inst("if_enemy 9\nif_empty 7\nif_random 5\nleft\ngo 0\nright\ngo 0\nhop\ngo 0\ninfect\ngo 0");
    ASSERT_EQ(r.program.size(), 11);
    ASSERT_EQ(r.display, 'r');
}
// ----------------
// Species add_inst
// ----------------
TEST(SpeciesFixture, species_add_inst1) {
    Darwin::Species food('f');
    food.add_inst("hop\nleft\nright");
    ASSERT_EQ(food.current_inst(1), "left");
}

TEST(SpeciesFixture, species_add_inst2) {
    Darwin::Species hopper('h');
    hopper.add_inst("hop\nif_wall 1\ngo 0");
    ASSERT_EQ(hopper.current_inst(1), "if_wall 1");
}

TEST(SpeciesFixture, species_add_inst3) {
    Darwin::Species food('c');
    food.add_inst("hop\nleft\nright");
    ASSERT_EQ(food.current_inst(0), "hop");
}

// -------------
// Species print
// -------------
TEST(SpeciesFixture, species_print1) {
    Darwin::Species rover('r');
    ostringstream o;
    rover.print(o);
    ASSERT_EQ("r", o.str());
}

TEST(SpeciesFixture, species_print2) {
    Darwin::Species rover('b');
    ostringstream o;
    rover.print(o);
    ASSERT_EQ("b", o.str());
}

TEST(SpeciesFixture, species_print3) {
    Darwin::Species food('f');
    ostringstream o;
    food.print(o);
    ASSERT_EQ("f", o.str());
}

// --------------------
// Species current_inst
// --------------------
TEST(SpeciesFixture, species_current_inst1) {
    Darwin::Species trap('t');
    ostringstream o;
    trap.add_inst("hop\nleft");
    ASSERT_EQ(trap.current_inst(0), "hop");
}

TEST(SpeciesFixture, species_current_inst2) {
    Darwin::Species best('b');
    ostringstream o;
    best.add_inst("inst0\ninst1\ninst2\ninst3\ninst4\ninst5\ninst6\ninst7\ninst8\n");
    ASSERT_EQ(best.current_inst(6), "inst6");
}

TEST(SpeciesFixture, species_current_inst3) {
    Darwin::Species alad('a');
    ostringstream o;
    alad.add_inst("inst0\ninst1\ninst2\ninst3\ninst4\ninst5\ninst6\ninst7\ninst8\n");
    ASSERT_EQ(alad.current_inst(3), "inst3");

}

// -------------------
// Species check_enemy
// -------------------
TEST(SpeciesFixture, species_check_enemy1) {
    Darwin::Species s1('r');
    Darwin::Species s2('f');
    ASSERT_EQ(true, s1.check_enemy(s2));
}

TEST(SpeciesFixture, species_check_enemy2) {
    Darwin::Species s1('r');
    Darwin::Species s2('r');
    ASSERT_EQ(false, s1.check_enemy(s2));
}

// ---------
// Creature 
// ---------

// constructor tests
TEST(CreatureFixture, creature_constructor_1) {
    Darwin::Species s = Darwin::Species('h');
    Darwin::Creature c = Darwin::Creature(&s, 0, 0);
    ASSERT_EQ(0, c.pc);
    ASSERT_EQ(WEST, c.direction);
}

TEST(CreatureFixture, creature_constructor_2) {
    Darwin::Species s = Darwin::Species('r');
    Darwin::Creature c = Darwin::Creature(&s, 1, 3);
    ASSERT_EQ(1, c.pc);
    ASSERT_EQ(SOUTH, c.direction);
}

TEST(CreatureFixture, creature_constructor_3) {
    Darwin::Species s = Darwin::Species('t');
    Darwin::Creature c = Darwin::Creature(&s, 0, 2);
    ASSERT_EQ(0, c.pc);
    ASSERT_EQ(EAST, c.direction);
}

//next_x
TEST(CreatureFixture, next_x_1) {
    Darwin::Species s = Darwin::Species('h');
    Darwin::Creature c = Darwin::Creature(&s, 0, 0);
    int next_x = c.next_x(3);
    ASSERT_EQ(3, next_x);
}

TEST(CreatureFixture, next_x_2) {
	Darwin::Species s = Darwin::Species('h');
    Darwin::Creature c = Darwin::Creature(&s, 0, 1);
    int next_x = c.next_x(3); 
    ASSERT_EQ(2, next_x);
}

// next_y tests
TEST(CreatureFixture, next_y_1) {
    Darwin::Species s = Darwin::Species('h');
    Darwin::Creature c = Darwin::Creature(&s, 0, 0);
    int next_y = c.next_y(3); 
    ASSERT_EQ(2, next_y);
}

TEST(CreatureFixture, next_y_2) {
    Darwin::Species s = Darwin::Species('h');
    Darwin::Creature c = Darwin::Creature(&s, 0, 1);
    int next_y = c.next_y(3); 
    ASSERT_EQ(3, next_y);
}

//is_action tests
TEST(CreatureFixture, is_action_1) {
    Darwin::Species s = Darwin::Species('h');
    Darwin::Creature c = Darwin::Creature(&s, 0, 1);
    bool action = c.is_action("hop");

    ASSERT_EQ(true, action);
}

TEST(CreatureFixture, is_action_2) {
    Darwin::Species s = Darwin::Species('r');
    Darwin::Creature c = Darwin::Creature(&s, 0, 1);
    bool action = c.is_action("if_random");

    ASSERT_EQ(false, action);
}

//parse_exec tests

TEST(CreatureFixture, parse_exec_1) {

    Darwin d(4,4);

    Darwin::Species rover = Darwin::Species('r');
    Darwin::Species hopper = Darwin::Species('h');
    rover.add_inst("hop\nleft");
    hopper.add_inst("hop\nleft");
    Darwin::Creature c1 = Darwin::Creature(&rover, 0, 1);
    Darwin::Creature c2 = Darwin::Creature(&hopper, 0, 1);
    Darwin::Creature* ptr1 = &c1;
    Darwin::Creature* ptr2 = &c2;

    bool a = c1.parse_exec(ptr1, ptr2, 0, 0, 10, 10);
    ASSERT_EQ(a, true);
}

TEST(CreatureFixture, parse_exec_2) {

    Darwin d(4,4);

    Darwin::Species rover = Darwin::Species('r');
    Darwin::Species hopper = Darwin::Species('h');
    rover.add_inst("hop\nleft");
    hopper.add_inst("hop\nleft");
    Darwin::Creature c1 = Darwin::Creature(&rover, 0, 1);
    Darwin::Creature c2 = Darwin::Creature(&hopper, 0, 1);
    Darwin::Creature* ptr1 = &c1;
    Darwin::Creature* ptr2 = &c2;
    c1.parse_exec(ptr1, ptr2, 0, 0, 10, 10);

    ASSERT_EQ(c1.pc, 1);
}

TEST(CreatureFixture, parse_exec_3) {

    Darwin d(4,4);

    Darwin::Species rover = Darwin::Species('r');
    Darwin::Species hopper = Darwin::Species('h');
    rover.add_inst("right\nleft");
    hopper.add_inst("hop\nleft");
    Darwin::Creature c1 = Darwin::Creature(&rover, 0, 1);
    Darwin::Creature c2 = Darwin::Creature(&hopper, 0, 1);
    Darwin::Creature* ptr1 = &c1;
    Darwin::Creature* ptr2 = &c2;
    c1.parse_exec(ptr1, ptr2, 0, 0, 10, 10);

    ASSERT_EQ(c1.direction, 2);
}

TEST(CreatureFixture, parse_exec_4) {

    Darwin d(4,4);

    Darwin::Species rover = Darwin::Species('r');
    Darwin::Species hopper = Darwin::Species('h');
    rover.add_inst("if_empty 3\nleft\nhop\ngo 1");
    hopper.add_inst("hop\nleft");
    Darwin::Creature c1 = Darwin::Creature(&rover, 0, 1);
    Darwin::Creature c2 = Darwin::Creature(&hopper, 0, 1);
    Darwin::Creature* ptr1 = &c1;
    Darwin::Creature* ptr2 = &c2;
    c1.parse_exec(ptr1, ptr2, 0, 0, 10, 10);

    ASSERT_EQ(c1.pc, 1);
}
