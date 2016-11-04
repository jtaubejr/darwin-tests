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

// ----
// species constructors
// ----

TEST(Species, constructor_species1) {
	Species s('v');
	ASSERT_EQ(s.symbol, 'v');
}

TEST(Species, constructor_species2) {
	Species s('W');
	ASSERT_EQ(s.symbol, 'W');
}

TEST(Species, constructor_species3) {
	Species s;
	ASSERT_EQ(s.symbol, '.');
}

// ----
// creature constructors
// ----

TEST(Creature, constructor_creature1) {
	Species s('w');
	Creature c(&s, Direction::NORTH);
	ASSERT_EQ(c.direction, Direction::NORTH);
}

TEST(Creature, constructor_creature2) {
	Creature c;
	Species* cp = c.species;
	ASSERT_EQ(cp, nullptr);
}

// ----
// darwin constructors
// ----

TEST(Darwin, constructor_darwin1) {
    Darwin x(10, 10);
    ASSERT_EQ(x.row, 10);
    ASSERT_EQ(x.column, 10);
}

TEST(Darwin, constructor_darwin2) {
    Darwin x(1, 10);
    ASSERT_EQ(x.row, 1);
    ASSERT_EQ(x.column, 10);
}


// ----
// Creature Behaviors
// ----

TEST(Behavior, hoptest) {
	Darwin x(8, 8);
	Species hopper_species('h');

    char hopper[] = {'h'};
    char hopper1[] = {'g', '0'};

    hopper_species.addInstruction(hopper);
    hopper_species.addInstruction(hopper1);

    Creature c (&hopper_species, Direction::NORTH);
    x.addCreature(&c, 5, 5);

    for(int i = 0; i < 3; ++i){
   	   	x.nextTurn();
    }

    Creature* c1 = x.world[2][5];
    ASSERT_TRUE(*c1 == c);
}

TEST(Behavior, ifwalltest) {
	Darwin x(8, 8);
	Species walll('h');

    char wall[] = {'w', '2'};
    char wall1[] = {'h'};
    char wall2[] = {'r'};
	char wall3[] = {'g', '0'};

    walll.addInstruction(wall2);
    walll.addInstruction(wall1);

    Creature c (&walll, Direction::NORTH);
    x.addCreature(&c, 0, 0);

    for(int i = 0; i < 2; ++i){
   	   	x.nextTurn();
  	}

    Creature* c1 = x.world[0][1];
    ASSERT_TRUE(*c1 == c);
}

TEST(Behavior, ifemptytest) {
	Darwin x(8, 8);
	Species emptyy('h');

	char empty[] = {'0', '2'};
	char empty1[] = {'h'};
	char empty2[] = {'r'};

	emptyy.addInstruction(empty);
	emptyy.addInstruction(empty2);
	emptyy.addInstruction(empty1);
	Creature c (&emptyy, Direction::NORTH);

	x.addCreature(&c, 5, 5);

	x.nextTurn();
	x.nextTurn();

	Creature* c1 = x.world[4][5];
	ASSERT_TRUE(*c1 == c);
}

TEST(Behavior, ifEnemyTest) {
	Darwin x(8, 8);
	Species enemyy('h');
	char enemy[] = {'n', '2'};
	char enemy1[] = {'h'};
	char enemy2[] = {'r'};
	char enemy3[] = {'h'};

	enemyy.addInstruction(enemy);
	enemyy.addInstruction(enemy1);
	enemyy.addInstruction(enemy2);
	enemyy.addInstruction(enemy3);

	Species s;
	Creature c(&enemyy, Direction::NORTH);
	Creature dummy(&s, Direction::NORTH);

	x.addCreature(&dummy, 4, 5);
	x.addCreature(&c, 5, 5);

	x.nextTurn();
	x.nextTurn();

	Creature* c1 = x.world[5][6];
	ASSERT_TRUE(*c1 == c);
}

TEST(Behavior, LeftRightTest) {
	Darwin x(8, 8);
	Species leftRight('h');

	char lr[] = {'r'};
	char lr1[] = {'h'};
	char lr2[] = {'l'};
	char lr3[] = {'l'};
	char lr4[] = {'h'};

	leftRight.addInstruction(lr);
	leftRight.addInstruction(lr1);
	leftRight.addInstruction(lr2);
	leftRight.addInstruction(lr3);
	leftRight.addInstruction(lr4);

	Creature c(&leftRight, Direction::NORTH);

	x.addCreature(&c, 5, 5);

	for(int i = 0; i < 5; ++i) {
		x.nextTurn();
	}

	Creature* c1 = x.world[5][5];
	ASSERT_TRUE(*c1 == c);
}


TEST(Behavior, LeftRightTest1) {
    Darwin darwin(8, 8);
    Species species('f');

    char instruction[] = {'h'};
    char instruction1[] = {'g', '2'};
    char instruction2[] = {'r'};
    char instruction3[] = {'h'};
    char instruction4[] = {'g', '5'};
    char instruction5[] = {'l'};
    char instruction6[] = {'h'};
    char instruction7[] = {'g', '0'};

    species.addInstruction(instruction);
    species.addInstruction(instruction1);
    species.addInstruction(instruction2);
    species.addInstruction(instruction3); 
    species.addInstruction(instruction4);
    species.addInstruction(instruction5);
    species.addInstruction(instruction6);
    species.addInstruction(instruction7);

    Creature creature(&species, Direction::NORTH);
    darwin.addCreature(&creature, 5, 5);
    for(int i = 0; i < 6; ++i) {
        darwin.nextTurn();
    }

    Creature* c = darwin.world[2][6];
    ASSERT_TRUE(*c == creature);
}



TEST(Behavior, infect) {
	Darwin x(8, 8);
	Species infect('h');
	Species dummy('o');

	char one[] = {'h'};
	char one1[] = {'r'};
	dummy.addInstruction(one);
	dummy.addInstruction(one1);

	char two[] = {'r'};
	char two1[] = {'g', '2'};
	char two2[] = {'i'};
	infect.addInstruction(two);
	infect.addInstruction(two1);
	infect.addInstruction(two2);

	Creature first(&dummy, Direction::NORTH);
	Creature second(&infect, Direction::SOUTH);

	x.addCreature(&first, 5, 5);
	x.addCreature(&second, 4, 6);

	x.nextTurn();
	x.nextTurn();

	Creature* infecter = x.world[4][6];
	Creature* infected = x.world[4][5];
	ASSERT_TRUE(*infected == *infecter);
}

TEST(Behavior, infect1) {
    Darwin darwin(8, 8);
    Species species1('V');
    Species species2('M');
    char instruction[] = {'h'};
    char instruction1[] = {'0', '1'};
    char instruction2[] = {'0', '1'};
    char instruction3[] = {'r'};
    species1.addInstruction(instruction);
    species1.addInstruction(instruction1);
    species1.addInstruction(instruction2);
    species1.addInstruction(instruction3);
    Creature creature1(&species1, Direction::NORTH);
    darwin.addCreature(&creature1, 5, 5);
    Creature creature2(&species2, Direction::NORTH);
    darwin.addCreature(&creature2, 3, 5);
    darwin.printWorld();
    for(int i = 0; i < 3; ++i) {
    	darwin.nextTurn();
    	darwin.printWorld();
    }
    Creature* c = darwin.world[3][5];
    Creature* c1 = darwin.world[4][5];
    ASSERT_TRUE(creature1 == *c1);
    ASSERT_TRUE(creature2 == *c);
}


TEST(Behavior, General1) {
    srand(0);
    Darwin x(8, 8);

    Species gen('h');
    Species s;

    char gene[] = {'n', '9'};
    char gen1[] = {'0', '7'};
    char gen2[] = {'?', '5'};
    char gen4[] = {'l'};
    char gen5[] = {'g', '0'};
    char gen6[] = {'r'};
    char gen7[] = {'g', '0'};
    char gen8[] = {'h'};
    char gen9[] = {'g', '0'};
    char gen10[] = {'i'};
    char gen11[] = {'g', '0'};

    gen.addInstruction(gene);
    gen.addInstruction(gen1);
    gen.addInstruction(gen2);
    gen.addInstruction(gen4);
    gen.addInstruction(gen5);
    gen.addInstruction(gen6);
    gen.addInstruction(gen7);
    gen.addInstruction(gen8);
    gen.addInstruction(gen9);
    gen.addInstruction(gen10);
    gen.addInstruction(gen11);


    Creature c(&gen, Direction::NORTH);
    Creature c1(&gen, Direction::NORTH);
    Creature c2(&gen, Direction::NORTH);
    Creature c3(&gen, Direction::NORTH);
    Creature c4(&gen, Direction::NORTH);

    Creature still(&s, Direction::NORTH);
    Creature still1(&s, Direction::NORTH);
    Creature still2(&s, Direction::NORTH);
    Creature still3(&s, Direction::NORTH);
    Creature still4(&s, Direction::NORTH);

    x.addCreature(&c, 5, 5);
    x.addCreature(&c1, 3, 1);
    x.addCreature(&c2, 1, 3);
    x.addCreature(&c3, 4, 4);
    x.addCreature(&c4, 3, 7);

    x.addCreature(&still, 0, 4);
    x.addCreature(&still1, 4, 4);
    x.addCreature(&still2, 2, 1);
    x.addCreature(&still3, 6, 2);
    x.addCreature(&still4, 6, 4);

    for(int i = 0; i < 10; ++i) {
        x.nextTurn();
        // x.printWorld();
    }

    Creature* plz = x.world[0][1];
    Creature* fam = x.world[1][0];

    ASSERT_TRUE(*plz == *fam);
}
