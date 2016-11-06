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

// -----------
// test Darwin
// -----------


// -----------
// addCreature
// -----------

TEST(DarwinFixture1, addCreature1) {
    Darwin test(8, 8, 5);
    Species food;

    Creature f1(&food, 2, 'f');
    test.addCreature(f1, 'f', 0, 0);

    ASSERT_TRUE(test._board[0][0] == 'f');
}

TEST(DarwinFixture2, addCreature2) {
    Darwin test(8, 8, 5);
    Species rover;

    Creature r1(&rover, 2, 'r');
    test.addCreature(r1, 'r', 2, 6);

    ASSERT_TRUE(test._board[2][6] == 'r');
}

TEST(DarwinFixture3, addCreature3) {
    Darwin test(8, 8, 5);
    Species trap;

    Creature t1(&trap, 2, 't');
    test.addCreature(t1, 't', 3, 7);

    ASSERT_TRUE(test._board[3][7] == 't');
}

TEST(DarwinFixture4, addCreature4) {
    Darwin test(8, 8, 5);
    Species hopper;

    Creature h1(&hopper, 2, 'h');
    test.addCreature(h1, 'h', 4, 1);

    ASSERT_TRUE(test._board[4][1] == 'h');
}

// -----------
// changeBoard
// -----------

TEST(DarwinFixture5, changeBoard1) {
	Darwin test(5, 5, 5);
    Species rover;

    Creature r1(&rover, 2, 'r');
    test.addCreature(r1, 'r', 2, 3);
    test.changeBoard(0, 2, 4, 'e');

    // ASSERT_TRUE(true);
    ASSERT_TRUE(test._board[2][4] == 'r');
    ASSERT_TRUE(test._board[2][3] == '.');
}

TEST(DarwinFixture6, changeBoard2) {
    Darwin test(5, 5, 5);
    Species hopper;

    Creature h1(&hopper, 3, 'h');
    test.addCreature(h1, 'h', 1, 2);
    test.changeBoard(0, 2, 2, 's');

    // ASSERT_TRUE(true);
    ASSERT_TRUE(test._board[2][2] == 'h');
    ASSERT_TRUE(test._board[1][2] == '.');
}

TEST(DarwinFixture7, changeBoard3) {
    Darwin test(5, 5, 5);
    Species hopper;

    Creature h1(&hopper, 1, 'h');
    test.addCreature(h1, 'h', 4, 4);
    test.changeBoard(0, 3, 4, 'n');

    // ASSERT_TRUE(true);
    ASSERT_TRUE(test._board[3][4] == 'h');
    ASSERT_TRUE(test._board[4][4] == '.');
}

TEST(DarwinFixture8, changeBoard4) {
    Darwin test(5, 5, 5);
    Species hopper;

    Creature h1(&hopper, 0, 'h');
    test.addCreature(h1, 'h', 3, 2);
    test.changeBoard(0, 3, 1, 'w');

    // ASSERT_TRUE(true);
    ASSERT_TRUE(test._board[3][1] == 'h');
    ASSERT_TRUE(test._board[3][2] == '.');
}

// -----------
// startDarwin
// -----------

// TEST(DarwinFixture9, startDarwin1) {
//     srand(0);
// 	Darwin test (8, 8, 5);
//     Species rover;
//     rover.addInstruction("if_enemy 9");
//     rover.addInstruction("if_empty 7");
//     rover.addInstruction("if_random 5");
//     rover.addInstruction("left");
//     rover.addInstruction("go 0");
//     rover.addInstruction("right");
//     rover.addInstruction("go 0");
//     rover.addInstruction("hop");
//     rover.addInstruction("go 0");
//     rover.addInstruction("infect");
//     rover.addInstruction("go 0");

//     Creature r1(&rover, 2, 'r');
//     test.addCreature(r1, 'r', 2, 3);
//     test.startDarwin();
//     for (int i = 0; i < (int)test._board.size(); ++i) {
//         for (int j = 0; j < (int)test._board[0].size(); ++j) {
//             if (i == 2 && j == 7) {
//                 ASSERT_TRUE(test._board[i][j] == 'r');
//             }
//             else {
//                 ASSERT_TRUE(test._board[i][j] == '.');
//             }
//         }
//     }
// }

TEST(DarwinFixture10, startDarwin1) {
    srand(0);
    int turns = 5;
    Darwin test (5, 5, turns);
    Species rover;
    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");

    Creature r1(&rover, 2, 'r');
    test.addCreature(r1, 'r', 2, 3);

    for (int i = 0; i < turns + 1; ++i) { // turn tracker
        test.startDarwin();
    }
    for (int i = 0; i < (int)test._board.size(); ++i) {
        for (int j = 0; j < (int)test._board[0].size(); ++j) {
            if (i == 4 && j == 4) {
                ASSERT_TRUE(test._board[i][j] == 'r');
            }
            else {
                ASSERT_TRUE(test._board[i][j] == '.');
            }
        }
    }
}

// -------------
// findDirection
// -------------

TEST(DarwinFixture11, findDirection1) {
    Darwin test (5, 5, 5);
    Species hopper;
    int x = 2;
    int y = 2;

    Creature h1(&hopper, 3, 'h');
    test.addCreature(h1, 'h', 2, 2);
    char dir = h1.findDirection(x, y);
    ASSERT_TRUE(dir == 's');
}

TEST(DarwinFixture12, findDirection2) {
    Darwin test (5, 5, 5);
    Species hopper;
    int x = 4;
    int y = 3;

    Creature h1(&hopper, 0, 'h');
    test.addCreature(h1, 'h', 4, 3);
    char dir = h1.findDirection(x, y);
    ASSERT_TRUE(dir == 'w');
}

TEST(DarwinFixture13, findDirection3) {
    Darwin test (5, 5, 5);
    Species rover;
    int x = 3;
    int y = 1;

    Creature r1(&rover, 1, 'r');
    test.addCreature(r1, 'r', 3, 1);
    char dir = r1.findDirection(x, y);
    ASSERT_TRUE(dir == 'n');
}

TEST(DarwinFixture14, findDirection4) {
    Darwin test (5, 5, 5);
    Species rover;
    int x = 2;
    int y = 0;

    Creature r1(&rover, 2, 'r');
    test.addCreature(r1, 'r', 2, 0);
    char dir = r1.findDirection(x, y);
    ASSERT_TRUE(dir == 'e');
}

// -------------
// test Creature
// -------------


// -------------
// changeSpecies
// -------------

TEST(DarwinFixture15, changeSpecies1) {
    Darwin test (5, 5, 5);
    Species hopper;
    Species rover;

    Creature h1(&hopper, 3, 'h');
    Creature r1(&rover, 2, 'h');
    test.addCreature(h1, 'h', 2, 2);
    test.addCreature(r1, 'r', 1, 3);
    h1.changeSpecies(&r1);
    ASSERT_TRUE(h1._sp == r1._sp);
}

TEST(DarwinFixture16, changeSpecies2) {
    Darwin test (5, 5, 5);
    Species hopper;
    Species rover;

    Creature h1(&hopper, 3, 'h');
    Creature r1(&rover, 2, 'h');
    test.addCreature(h1, 'h', 1, 1);
    test.addCreature(r1, 'r', 3, 3);
    h1.changeSpecies(&r1);
    ASSERT_TRUE(h1._sp == r1._sp);
}

TEST(DarwinFixture17, changeSpecies3) {
    Darwin test (5, 5, 5);
    Species hopper;
    Species rover;

    Creature h1(&hopper, 3, 'h');
    Creature r1(&rover, 2, 'h');
    test.addCreature(h1, 'h', 3, 2);
    test.addCreature(r1, 'r', 0, 2);
    h1.changeSpecies(&r1);
    ASSERT_TRUE(h1._sp == r1._sp);
}

TEST(DarwinFixture18, changeSpecies4) {
    Darwin test (5, 5, 5);
    Species hopper;
    Species rover;

    Creature h1(&hopper, 3, 'h');
    Creature r1(&rover, 2, 'h');
    test.addCreature(h1, 'h', 3, 4);
    test.addCreature(r1, 'r', 3, 0);
    h1.changeSpecies(&r1);
    ASSERT_TRUE(h1._sp == r1._sp);
}

// ---------
// findInstr
// ---------

TEST(DarwinFixture19, findInstr1) {
    srand(0);
    Darwin test (5, 5, 5);
    Species hopper;
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");

    Creature h1(&hopper, 2, 'h');
    Creature r1(&rover, 3, 'r');
    test.addCreature(h1, 'h', 3, 2);
    test.addCreature(r1, 'r', 2, 2);

    int instr = r1.findInstr('r', 'h');

    ASSERT_TRUE(instr == 3);
}

TEST(DarwinFixture20, findInstr2) {
    srand(0);
    Darwin test (5, 5, 5);
    Species hopper;

    hopper.addInstruction("hop");
    hopper.addInstruction("go 0");

    Creature h1(&hopper, 1, 'h');
    test.addCreature(h1, 'r', 3, 3);

    int instr = h1.findInstr('h', '.');

    ASSERT_TRUE(instr == 0);
}

TEST(DarwinFixture21, findInstr3) {
    srand(0);
    Darwin test (5, 5, 5);
    Species hopper;

    hopper.addInstruction("hop");
    hopper.addInstruction("go 0");

    Creature h1(&hopper, 0, 'h');
    test.addCreature(h1, 'r', 1, 0);

    int instr = h1.findInstr('h', '.');

    ASSERT_TRUE(instr == 0);
}

TEST(DarwinFixture22, findInstr4) {
    srand(0);
    Darwin test (5, 5, 5);
    Species hopper;

    hopper.addInstruction("hop");
    hopper.addInstruction("go 0");

    Creature h1(&hopper, 2, 'h');
    test.addCreature(h1, 'r', 2, 3);

    int instr = h1.findInstr('h', '.');

    ASSERT_TRUE(instr == 0);
}


// -----------
// test Species
// -----------


// ----------
// numOfInstr
// ----------

TEST(DarwinFixture23, numOfInstr1) {
    Species food;

    food.addInstruction("left");
    food.addInstruction("go 0");

    int num = food.numOfInstr();
    ASSERT_TRUE(num == 2);
}

TEST(DarwinFixture24, numOfInstr2) {
    Species hopper;

    hopper.addInstruction("hop");
    hopper.addInstruction("go 0");

    int num = hopper.numOfInstr();
    ASSERT_TRUE(num == 2);
}

TEST(DarwinFixture25, numOfInstr3) {
    Species trap;

    trap.addInstruction("if_enemy 3");
    trap.addInstruction("left");
    trap.addInstruction("go 0");
    trap.addInstruction("infect");
    trap.addInstruction("go 0");
    
    int num = trap.numOfInstr();
    ASSERT_TRUE(num == 5);
}

TEST(DarwinFixture26, numOfInstr4) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    int num = rover.numOfInstr();
    ASSERT_TRUE(num == 11);
}

// --------------
// addInstruction
// --------------

TEST(DarwinFixture27, addInstruction1) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    
    int num = rover._program.size();
    ASSERT_TRUE(rover._program[num - 1] == "if_random 5");
}

TEST(DarwinFixture28, addInstruction2) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    ASSERT_TRUE(rover._program[0] == "if_enemy 9");
}

TEST(DarwinFixture29, addInstruction3) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    ASSERT_TRUE(rover._program[1] == "if_empty 7");
}
TEST(DarwinFixture30, addInstruction4) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    ASSERT_TRUE(rover._program[3] == "left");
}

TEST(DarwinFixture31, addInstruction5) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    ASSERT_TRUE(rover._program[4] == "go 0");
}

TEST(DarwinFixture32, addInstruction6) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    ASSERT_TRUE(rover._program[5] == "right");
}

TEST(DarwinFixture33, addInstruction7) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    ASSERT_TRUE(rover._program[6] == "go 0");
}

TEST(DarwinFixture34, addInstruction8) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    ASSERT_TRUE(rover._program[7] == "hop");
}

// ---------
// instrRcvr
// ---------

TEST(DarwinFixture35, instrRcvr1) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    string instr = rover.instrRcvr(5);
    ASSERT_TRUE(instr == "right");
}

TEST(DarwinFixture36, instrRcvr2) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    string instr = rover.instrRcvr(7);
    ASSERT_TRUE(instr == "hop");
}

TEST(DarwinFixture37, instrRcvr3) {
    Species rover;

    rover.addInstruction("if_enemy 9");
    rover.addInstruction("if_empty 7");
    rover.addInstruction("if_random 5");
    rover.addInstruction("left");
    rover.addInstruction("go 0");
    rover.addInstruction("right");
    rover.addInstruction("go 0");
    rover.addInstruction("hop");
    rover.addInstruction("go 0");
    rover.addInstruction("infect");
    rover.addInstruction("go 0");
    
    string instr = rover.instrRcvr(2);
    ASSERT_TRUE(instr == "if_random 5");
}

// ----
// eval
// ----

TEST(DarwinFixture38, eval1) {
    Species rover;
    int val = rover.eval("hop");
    ASSERT_TRUE(val == 0);
}

TEST(DarwinFixture39, eval2) {
    Species rover;
    int val = rover.eval("if_empty");
    ASSERT_TRUE(val == 4);
}
TEST(DarwinFixture40, eval3) {
    Species rover;
    int val = rover.eval("infect");
    ASSERT_TRUE(val == 3);
}