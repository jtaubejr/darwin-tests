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

using namespace std;

// ----
// test
// ----

// << operator for darwin board
TEST(DarwinFixture, darwin_const) {
    Darwin x(2 , 2);
    ostringstream w;
    w << x;
    ASSERT_EQ("Turn = 0\n  01\n0 ..\n1 ..\n\n", w.str());}   

TEST(DarwinFixture, darwin_const1) {
    Darwin x(3 , 3);
    ostringstream w;
    w << x;
    ASSERT_EQ("Turn = 0\n  012\n0 ...\n1 ...\n2 ...\n\n", w.str());}

TEST(DarwinFixture, darwin_const2) {
    Darwin x(4, 4);
    ostringstream w;
    w << x;
    ASSERT_EQ("Turn = 0\n  0123\n0 ....\n1 ....\n2 ....\n3 ....\n\n", w.str());}

// Basic darwin constructor 
TEST(DarwinFixture, darwin_const3) {
    Darwin dar(5, 10);
    ASSERT_EQ(5, dar.rows);
    ASSERT_EQ(10, dar.cols);
}

// Darwin constructor with big board
TEST(DarwinFixture, darwin_const5) {
    Darwin dar(100, 100);
    ASSERT_EQ(100, dar.rows);
    ASSERT_EQ(100, dar.cols);
}

// valid space
TEST(DarwinFixture, darwin_valid1) {
    Darwin d(3, 3);
    ASSERT_TRUE(d.valid_space(1, 2));
}

// invalid space with positive numbers
TEST(DarwinFixture, darwin_valid2) {
    Darwin d(3, 3);
    ASSERT_FALSE(d.valid_space(4, 4));
}

// invalid space with negative numbers
TEST(DarwinFixture, darwin_valid3) {
    Darwin d(3, 3);
    ASSERT_FALSE(d.valid_space(0, -1));
}

// species constructor with passed in label
TEST(DarwinFixture, species_const1) {
    Species food('f');
    ASSERT_EQ('f', food.rep);
}

// species print operator
TEST(DarwinFixture, spcies_print) {
    Species p('p');
    ostringstream w;
    w << p;
    ASSERT_EQ('p', *(w.str().c_str()));
}


// species print operator
TEST(DarwinFixture, spcies_print2) {
    Species p('b');
    ostringstream w;
    w << p;
    ASSERT_EQ('b', *(w.str().c_str()));
}  


// species print operator
TEST(DarwinFixture, species_print3) {
    Species p('p');
    ostringstream w;
    w << p;
    ASSERT_FALSE('g' == *(w.str().c_str()));
} 

// creature print operator 
TEST(DarwinFixture, creature_print2) {
    Species food('f');
    Creature c1(food, Direction::N);
    ostringstream w;
    w << c1;
    ASSERT_EQ('f', *(w.str().c_str()));
}


// creature print operator 
TEST(DarwinFixture, creature_print3) {
    Species food('b');
    Creature c1(food, Direction::N);
    ostringstream w;
    w << c1;
    ASSERT_EQ('b', *(w.str().c_str()));
}


// creature print operator 
TEST(DarwinFixture, creature_print4) {
    Species food('f');
    Creature c1(food, Direction::N);
    ostringstream w;
    w << c1;
    ASSERT_FALSE('g' == *(w.str().c_str()));
}

// Test the == operator 
TEST(DarwinFixture, it_equals) {
    Darwin dar(3, 3);
    Darwin_It d1(dar);
    Darwin_It d2 = dar.begin();
    ASSERT_TRUE(d1 == d2);
}


// Test the == operator  with bigger board
TEST(DarwinFixture, it_equals2) {
    Darwin dar(4, 4);
    Darwin_It d1(dar);
    Darwin_It d2 = dar.begin();
    ASSERT_TRUE(d1 == d2);
}

TEST(DarwinFixture, it_equals3) {
    Darwin dar(3, 3);
    Darwin_It d1(dar);
    Darwin_It d2 = ++d1;
    ++d1;
    ASSERT_FALSE(d1 == d2);
}
 
// Test the increment operator
TEST(DarwinFixture, it_increment2) {
    Darwin dar(3, 3);
    Darwin_It d1(dar);
    Darwin_It d2(dar);
    ++d1;
    ++d2;
    ASSERT_TRUE(d1 == d2);
}


// Test the increment operator
TEST(DarwinFixture, it_increment3) {
    Darwin dar(3, 3);
    Darwin_It d1(dar);
    Darwin_It d2(dar);
    ++d1;
    ASSERT_FALSE(d1 == d2);
}


