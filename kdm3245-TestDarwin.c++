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

TEST(DarwinFixture, test) {
    Darwin x(10, 10);
    ASSERT_TRUE(x.dummy());}

// control()
TEST(DarwinFixture, control1) {
    Instruction i(LEFT);
    ASSERT_TRUE(!i.control());
}

TEST(DarwinFixture, control2) {
    Instruction i(GO, 0);
    ASSERT_TRUE(i.control());
}

TEST(DarwinFixture, control3) {
    Instruction i(50);
    ASSERT_TRUE(!i.control());
}

// == and != operators
TEST(DarwinFixture, op1) {
    Species a('h');
    Species b('h');
    ASSERT_TRUE(a == b);
}

TEST(DarwinFixture, op2) {
    Species a('g');
    Species b('f');
    ASSERT_TRUE(a != b);
}

TEST(DarwinFixture, op3) {
    Species a('h');
    a.add_instr(Instruction(GO, 0));
    Species b('h');
    ASSERT_TRUE(a != b);
}

// Species::add_instr

TEST(DarwinFixture, add_instr1) {
    Species s('h');
    s.add_instr(LEFT);
    Instruction in(LEFT);
    ASSERT_TRUE(s.size() == 1);
}

TEST(DarwinFixture, add_instr2) {
    Species s('h');
    s.add_instr(LEFT);
    s.add_instr(HOP);
    Instruction in1(LEFT);
    Instruction in2(HOP);
    ASSERT_TRUE(s.size() == 2);
    ASSERT_TRUE(s.instr[0].command == in1.command);
    ASSERT_TRUE(s.instr[0].target == in1.target);
    ASSERT_TRUE(s.instr[1].command == in2.command);
    ASSERT_TRUE(s.instr[1].target == in2.target);
}

TEST(DarwinFixture, add_instr3) {
    Species s('h');
    Instruction in(GO, 0);
    s.add_instr(in);
    ASSERT_TRUE(&s.instr[0] != &in);
}

// Species::retrieve_instr

TEST(DarwinFixture, retrieve1) {
    Species s('h');
    s.add_instr(Instruction(GO, 0));
    ASSERT_TRUE(s.retrieve_instr(0).command == s.instr[0].command);
    ASSERT_TRUE(s.retrieve_instr(0).target == s.instr[0].target);
}

TEST(DarwinFixture, retrieve2) {
    Species s('h');
    try {
        Instruction in = s.retrieve_instr(50);
        ASSERT_TRUE(false);
    } catch(...) {
        ASSERT_TRUE(s.instr.size() == 0);
    }
}

TEST(DarwinFixture, retrieve3) {
    Species s('h');
    s.add_instr(Instruction(GO, 0));
    s.add_instr(Instruction(LEFT));
    ASSERT_TRUE(s.retrieve_instr(1).command == Instruction(LEFT).command);
    ASSERT_TRUE(s.retrieve_instr(1).target == Instruction(LEFT).target);
}

// Creature::print_sym

TEST(DarwinFixture, print1) {
    Creature c(Species('h'));
    ostringstream os;
    c.print_sym(os);
    ASSERT_TRUE(strcmp(os.str().c_str(), "h") == 0);
}

TEST(DarwinFixture, print2) {
    Creature c(Species('g'));
    ostringstream os;
    c.print_sym(os);
    ASSERT_TRUE(strcmp(os.str().c_str(), "g") == 0);
}

TEST(DarwinFixture, print3) {
    Creature c(Species('h'));
    c.species.sym = 'f';
    ostringstream os;
    c.print_sym(os);
    ASSERT_TRUE(strcmp(os.str().c_str(), "f") == 0);
}

// Creature::infect_c

TEST(DarwinFixture, infect1) {
    Creature c1(Species('h'));
    Creature c2(Species('f'));
    c1.infect_c(c2);
    ASSERT_TRUE(c2.species.sym == 'f');
    ASSERT_TRUE(c1.species.sym == 'f');
    ASSERT_TRUE(c1.prog_count == 0);
}

TEST(DarwinFixture, infect2) {
    Creature c1(Species('h'));
    Creature c2(Species('h'));
    c1.infect_c(c2);
    ASSERT_TRUE(c1.prog_count == 0);
}

TEST(DarwinFixture, infect3) {
    Creature c1(Species('g'));
    Creature c2(Species('t'));
    c1.infect_c(c2);
    ASSERT_TRUE(c2.species.sym == 't');
    ASSERT_TRUE(c1.species.sym == 't');
    ASSERT_TRUE(c1.prog_count == 0);
}

// Creature::request_instr

TEST(DarwinFixture, request1) {
    Creature c(Species('h'));
    c.species.add_instr(HOP);
    Instruction in = c.request_instr();
    ASSERT_TRUE(in.command == HOP);
}

TEST(DarwinFixture, request2) {
    Creature c(Species('h'));
    c.species.add_instr(Instruction(LEFT));
    c.species.add_instr(Instruction(RIGHT));
    c.update_pc(Instruction(LEFT), false);
    ASSERT_TRUE(c.prog_count == 1);
}

TEST(DarwinFixture, request3) {
    Creature c(Species('h'));
    try {
        Instruction in = c.request_instr();
        ASSERT_TRUE(false);
    } catch(...) {}
}

// Creature::update_pc

TEST(DarwinFixture, pc1) {
    Creature c(Species('h'));
    c.update_pc(Instruction(HOP), true);
    ASSERT_TRUE(c.prog_count == 0);
}

TEST(DarwinFixture, pc2) {
    Creature c(Species('h'));
    c.species.add_instr(Instruction(HOP));
    c.species.add_instr(Instruction(GO, 0));
    c.update_pc(Instruction(HOP), false);
    ASSERT_TRUE(c.prog_count == 1);
}

TEST(DarwinFixture, pc3) {
    Creature c(Species('h'));
    c.prog_count = 50;
    c.update_pc(Instruction(HOP), true);
    ASSERT_TRUE(c.prog_count == 0);
}

// Darwin::add_creature

TEST(DarwinFixture, add1) {
    Darwin x(1, 1);
    Creature c(Species('h'));
    x.add_creature(c, NORTH, 0, 0);
    ASSERT_TRUE(x.board[0][0].creature.species.sym == 'h');
}

TEST(DarwinFixture, add2) {
    Darwin x(1, 1);
    Creature c(Species('h'));
    x.add_creature(c, NORTH, 10, 10);
    ASSERT_TRUE(x.board[0][0].valid == false);
}

TEST(DarwinFixture, add3) {
    Darwin x(1, 1);
    Creature c(Species('h'));
    x.add_creature(c, NORTH, 0, 0);
    ASSERT_TRUE(x.board[0][0].creature.species.sym == 'h');
}

// Darwin::print_board

TEST(DarwinFixture, board1) {
    Darwin x(1, 1);
    ostringstream os;
    x.print_board(0, os);
    ASSERT_TRUE(strcmp(os.str().c_str(), "Turn = 0.\n  0\n0 .\n") == 0);
}

TEST(DarwinFixture, board2) {
    Darwin x(1, 1);
    Creature c(Species('h'));
    x.add_creature(c, NORTH, 0, 0);
    ostringstream os;
    x.print_board(0, os);
    ASSERT_TRUE(strcmp(os.str().c_str(), "Turn = 0.\n  0\n0 .\n") != 0);
}

TEST(DarwinFixture, board3) {
    Darwin x(0, 0);
    ostringstream os;
    x.print_board(0, os);
    ASSERT_TRUE(strcmp(os.str().c_str(), "Turn = 0.\n  \n") == 0);
}
