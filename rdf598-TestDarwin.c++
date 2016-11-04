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
  Darwin x(1, 1);
  ASSERT_TRUE(x.dummy());
}

TEST(DarwinFixture, test1) {
	Darwin x1(8,8);
	Species tester('t');
	tester.addInstruction("right");
	tester.addInstruction("go 0");
	Creature c1(&tester, 2);
	x1.addCreature(c1, 4, 4);
}