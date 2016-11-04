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

TEST(DarwinFixture, checkNorth1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('w', hopper.checkNorth(gameBoard, position)); 
    }

TEST(DarwinFixture, checkNorth2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(4,4);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('.', hopper.checkNorth(gameBoard, position)); 
    }

TEST(DarwinFixture, checkNorth3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,5);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('w', hopper.checkNorth(gameBoard, position)); 
    } 

TEST(DarwinFixture, checkSouth1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('.', hopper.checkSouth(gameBoard, position)); 
    } 

TEST(DarwinFixture, checkSouth2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(5,5);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('w', hopper.checkSouth(gameBoard, position)); 
    } 

TEST(DarwinFixture, checkSouth3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(5,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('w', hopper.checkSouth(gameBoard, position)); 
    } 

TEST(DarwinFixture, checkEast1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('.', hopper.checkEast(gameBoard, position)); 
    } 

TEST(DarwinFixture, checkEast2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(5,5);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('w', hopper.checkEast(gameBoard, position)); 
    } 

TEST(DarwinFixture, checkEast3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,5);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('w', hopper.checkEast(gameBoard, position)); 
    } 

TEST(DarwinFixture, checkWest1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('w', hopper.checkWest(gameBoard, position)); 
    } 

TEST(DarwinFixture, checkWest2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,5);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('.', hopper.checkWest(gameBoard, position)); 
    } 

TEST(DarwinFixture, checkWest3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(5,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ('w', hopper.checkWest(gameBoard, position)); 
    } 

TEST(DarwinFixture, hopNorth1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkNorth(gameBoard, position) != 'w')
        hopper.hopNorth(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first][position.second]); 
    } 

TEST(DarwinFixture, hopNorth2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(4,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkNorth(gameBoard, position) != 'w')
        hopper.hopNorth(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first-1][position.second]); 
    } 

TEST(DarwinFixture, hopNorth3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(4,4);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkNorth(gameBoard, position) != 'w')
        hopper.hopNorth(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first-1][position.second]); 
    }

TEST(DarwinFixture, hopSouth1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkSouth(gameBoard, position) != 'w')
        hopper.hopSouth(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first+1][position.second]); 
    }

TEST(DarwinFixture, hopSouth2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,4);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkSouth(gameBoard, position) != 'w')
        hopper.hopSouth(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first+1][position.second]); 
    }

TEST(DarwinFixture, hopSouth3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(4,4);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkSouth(gameBoard, position) != 'w')
        hopper.hopSouth(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first][position.second]); 
    }

TEST(DarwinFixture, hopEast1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkEast(gameBoard, position) != 'w')
        hopper.hopEast(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first][position.second+1]); 
    }

TEST(DarwinFixture, hopEast2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(4,4);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkEast(gameBoard, position) != 'w')
        hopper.hopEast(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first][position.second]); 
    }

TEST(DarwinFixture, hopEast3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(4,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkEast(gameBoard, position) != 'w')
        hopper.hopEast(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first][position.second+1]); 
    }

TEST(DarwinFixture, hopWest1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkWest(gameBoard, position) != 'w')
        hopper.hopWest(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first][position.second]); 
    }

TEST(DarwinFixture, hopWest2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(4,4);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkWest(gameBoard, position) != 'w')
        hopper.hopWest(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first][position.second-1]); 
    }

TEST(DarwinFixture, hopWest3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,4);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 
    gameBoard[position.first][position.second] = 'h';
    if(hopper.checkWest(gameBoard, position) != 'w')
        hopper.hopWest(gameBoard);

    ASSERT_EQ('h', gameBoard[position.first][position.second-1]); 
    }


TEST(DarwinFixture, Infect1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> hopPos = make_pair(0,1);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", hopPos, hop); 

    pair<int, int> rovePos = make_pair(0,0);
    vector<int> roveVector(1, ENEMY);
    vector<int> roveControl(1, 9);
    Program rove(roveVector, roveControl);
    rove.addInstruction(EMPTY, 7);
    rove.addInstruction(RANDOM, 5);
    rove.addInstruction(LEFT, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(RIGHT, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(HOP, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(INFECT, 0);
    rove.addInstruction(GO, 0);

    Creature rover(EAST, 0, "rover", rovePos, rove); 

    gameBoard[hopPos.first][hopPos.second] = 'h';
    gameBoard[rovePos.first][rovePos.second] = 'r';
    if(rover.checkEast(gameBoard, rovePos) != 'w')
        rover.infect(gameBoard);

    ASSERT_EQ('r', gameBoard[hopPos.first][hopPos.second]); 
    }

TEST(DarwinFixture, Infect2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> hopPos = make_pair(1,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", hopPos, hop); 

    pair<int, int> rovePos = make_pair(0,0);
    vector<int> roveVector(1, ENEMY);
    vector<int> roveControl(1, 9);
    Program rove(roveVector, roveControl);
    rove.addInstruction(EMPTY, 7);
    rove.addInstruction(RANDOM, 5);
    rove.addInstruction(LEFT, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(RIGHT, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(HOP, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(INFECT, 0);
    rove.addInstruction(GO, 0);

    Creature rover(SOUTH, 0, "rover", rovePos, rove); 

    gameBoard[hopPos.first][hopPos.second] = 'h';
    gameBoard[rovePos.first][rovePos.second] = 'r';
    if(rover.checkSouth(gameBoard, rovePos) != 'w')
        rover.infect(gameBoard);

    ASSERT_EQ('r', gameBoard[hopPos.first][hopPos.second]); 
    }

TEST(DarwinFixture, Infect3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> hopPos = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", hopPos, hop); 

    pair<int, int> rovePos = make_pair(0,1);
    vector<int> roveVector(1, ENEMY);
    vector<int> roveControl(1, 9);
    Program rove(roveVector, roveControl);
    rove.addInstruction(EMPTY, 7);
    rove.addInstruction(RANDOM, 5);
    rove.addInstruction(LEFT, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(RIGHT, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(HOP, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(INFECT, 0);
    rove.addInstruction(GO, 0);

    Creature rover(WEST, 0, "rover", rovePos, rove); 

    gameBoard[hopPos.first][hopPos.second] = 'h';
    gameBoard[rovePos.first][rovePos.second] = 'r';
    if(rover.checkWest(gameBoard, rovePos) != 'w')
        rover.infect(gameBoard);

    ASSERT_EQ('r', gameBoard[hopPos.first][hopPos.second]); 
    }

TEST(DarwinFixture, if_empty1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ(true, hopper.if_empty(gameBoard)); 
    } 


TEST(DarwinFixture, if_empty2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(NORTH, 0, "hopper", position, hop); 


    ASSERT_EQ(false, hopper.if_empty(gameBoard)); 
    } 

TEST(DarwinFixture, if_empty3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(EAST, 0, "hopper", position, hop); 


    ASSERT_EQ(true, hopper.if_empty(gameBoard)); 
    } 

TEST(DarwinFixture, if_wall1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(NORTH, 0, "hopper", position, hop); 


    ASSERT_EQ(true, hopper.if_wall(gameBoard)); 
    } 

TEST(DarwinFixture, if_wall2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(WEST, 0, "hopper", position, hop); 


    ASSERT_EQ(true, hopper.if_wall(gameBoard)); 
    } 

TEST(DarwinFixture, if_wall3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ(false, hopper.if_wall(gameBoard)); 
    } 

TEST(DarwinFixture, if_enemy1) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 


    ASSERT_EQ(false, hopper.if_enemy(gameBoard)); 
    } 

TEST(DarwinFixture, if_enemy2) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 

    pair<int, int> rovePos = make_pair(1,0);
    vector<int> roveVector(1, ENEMY);
    vector<int> roveControl(1, 9);
    Program rove(roveVector, roveControl);
    rove.addInstruction(EMPTY, 7);
    rove.addInstruction(RANDOM, 5);
    rove.addInstruction(LEFT, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(RIGHT, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(HOP, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(INFECT, 0);
    rove.addInstruction(GO, 0);

    Creature rover(WEST, 0, "rover", rovePos, rove); 

    gameBoard[position.first][position.second] = 'h';
    gameBoard[rovePos.first][rovePos.second] = 'r';

    ASSERT_EQ(true, hopper.if_enemy(gameBoard)); 
    } 

TEST(DarwinFixture, if_enemy3) {
    vector<vector<char>> gameBoard(5, vector<char>(5,'.'));
    pair<int, int> position = make_pair(0,0);

    vector<int> hopVector(1, HOP);
    Program hop(hopVector, hopVector);
    hop.addInstruction(GO, 0); 
    Creature hopper(SOUTH, 0, "hopper", position, hop); 

    pair<int, int> rovePos = make_pair(1,0);
    vector<int> roveVector(1, ENEMY);
    vector<int> roveControl(1, 9);
    Program rove(roveVector, roveControl);
    rove.addInstruction(EMPTY, 7);
    rove.addInstruction(RANDOM, 5);
    rove.addInstruction(LEFT, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(RIGHT, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(HOP, 0);
    rove.addInstruction(GO, 0);
    rove.addInstruction(INFECT, 0);
    rove.addInstruction(GO, 0);

    Creature rover(NORTH, 0, "rover", rovePos, rove); 

    gameBoard[position.first][position.second] = 'h';
    gameBoard[rovePos.first][rovePos.second] = 'r';

    ASSERT_EQ(true, rover.if_enemy(gameBoard)); 
    } 

