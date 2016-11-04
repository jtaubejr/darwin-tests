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

// ----
// test
// ----

TEST(Species, addInstruction_test1)
{
	Grid grid (5,5);
	Species doggo = Species('d');
	doggo.addInstruction("hop");
	doggo.addInstruction("go 0");

	ASSERT_EQ(doggo.program[0], "hop");
	ASSERT_EQ(doggo.program[1], "go 0");
}

TEST(Species, addInstruction_test2)
{
	Grid grid (5,5);
	Species dogger = Species('d');

	dogger.addInstruction("if_enemy 9");
    dogger.addInstruction("if_empty 7");
    dogger.addInstruction("if_random 5");
    dogger.addInstruction("left");
    dogger.addInstruction("go 0");
    dogger.addInstruction("right");
    dogger.addInstruction("go 0");
    dogger.addInstruction("hop");
    dogger.addInstruction("go 0");
    dogger.addInstruction("infect");
    dogger.addInstruction("go 0");

	ASSERT_EQ(dogger.program[0], "if_enemy 9");
	ASSERT_EQ(dogger.program[1], "if_empty 7");
}

TEST(Species, addInstruction_test3)
{
	Grid grid (5,5);
	Species dogger = Species('d');

	dogger.addInstruction("if_enemy 9");
    dogger.addInstruction("if_empty 7");
    dogger.addInstruction("if_random 5");
    dogger.addInstruction("left");
    dogger.addInstruction("go 0");
    dogger.addInstruction("right");
    dogger.addInstruction("go 0");
    dogger.addInstruction("hop");
    dogger.addInstruction("go 0");
    dogger.addInstruction("infect");
    dogger.addInstruction("go 0");

	ASSERT_EQ(dogger.program[3], "left");
	ASSERT_EQ(dogger.program[4], "go 0");
}

TEST(Species, addInstruction_test4)
{
	Grid grid (5,5);
	Species dogger = Species('d');

	dogger.addInstruction("if_enemy 9");
    dogger.addInstruction("if_empty 7");
    dogger.addInstruction("if_random 5");
    dogger.addInstruction("left");
    dogger.addInstruction("go 0");
    dogger.addInstruction("right");
    dogger.addInstruction("go 0");
    dogger.addInstruction("hop");
    dogger.addInstruction("go 0");
    dogger.addInstruction("infect");
    dogger.addInstruction("go 0");

	ASSERT_EQ(dogger.program[5], "right");
	ASSERT_EQ(dogger.program[6], "go 0");
}

TEST(Species, addInstruction_test5)
{
	Grid grid (5,5);
	Species dogger = Species('d');

	dogger.addInstruction("if_enemy 9");
    dogger.addInstruction("if_empty 7");
    dogger.addInstruction("if_random 5");
    dogger.addInstruction("left");
    dogger.addInstruction("go 0");
    dogger.addInstruction("right");
    dogger.addInstruction("go 0");
    dogger.addInstruction("hop");
    dogger.addInstruction("go 0");
    dogger.addInstruction("infect");
    dogger.addInstruction("go 0");

	ASSERT_EQ(dogger.program[7], "hop");
	ASSERT_EQ(dogger.program[8], "go 0");
}

TEST(Species, addInstruction_test6)
{
	Grid grid (5,5);
	Species dogger = Species('d');

	dogger.addInstruction("if_enemy 9");
    dogger.addInstruction("if_empty 7");
    dogger.addInstruction("if_random 5");
    dogger.addInstruction("left");
    dogger.addInstruction("go 0");
    dogger.addInstruction("right");
    dogger.addInstruction("go 0");
    dogger.addInstruction("hop");
    dogger.addInstruction("go 0");
    dogger.addInstruction("infect");
    dogger.addInstruction("go 0");

	ASSERT_EQ(dogger.program[9], "infect");
	ASSERT_EQ(dogger.program[10], "go 0");
}

TEST(Species, addInstruction_test7)
{
	Grid grid (5,5);
	Species pupper = Species('p');
	pupper.addInstruction("hello this is a custom inst");
	pupper.addInstruction("this should be invalid but pass");

	ASSERT_EQ(pupper.program[0], "hello this is a custom inst");
	ASSERT_EQ(pupper.program[1], "this should be invalid but pass");
}

TEST(Grid, put_creature_test1)
{
	Grid grid (2, 2);
	Species doggo = Species('d');
	Creature d1 = Creature(doggo, NORTH);
	grid.put_creature(d1, 0, 1);


	ASSERT_TRUE(grid.world[0][1] != 0);
}

TEST(Grid, put_creature_test2)
{
	Grid grid (3, 3);
	Species doggo = Species('d');
	Creature d1 = Creature(doggo, NORTH);
	Creature d2 = Creature(doggo, WEST);
	Creature d3 = Creature(doggo, SOUTH);
	Creature d4 = Creature(doggo, EAST);
	grid.put_creature(d1, 0, 0);
	grid.put_creature(d2, 0, 1);
	grid.put_creature(d3, 1, 0);
	grid.put_creature(d4, 1, 1);


	ASSERT_TRUE(grid.world[0][0] != 0);
	ASSERT_TRUE(grid.world[0][1] != 0);
	ASSERT_TRUE(grid.world[1][0] != 0);
	ASSERT_TRUE(grid.world[1][1] != 0);
}

TEST(Grid, execute_test1)
{
	Grid grid(5,5);

	Species hopper = Species('h');

	hopper.addInstruction("hop");
	hopper.addInstruction("go 0");

	Creature h1 = Creature(hopper, EAST);
	Creature h2 = Creature(hopper, SOUTH);

	grid.put_creature(h1, 1, 1);
	grid.put_creature(h2, 4, 4);


	grid.execute(*grid.world[1][1], 1, 1);
	grid.execute(*grid.world[4][4], 4, 4);

	ASSERT_TRUE(grid.world[1][2] != 0);
	ASSERT_TRUE(grid.world[4][4] != 0);

}

TEST(Grid, execute_test2)
{
	Grid grid(5,5);

	Species food = Species('f');

	food.addInstruction("left");
	food.addInstruction("go 0");

	Creature f1 = Creature(food, NORTH);
	Creature f2 = Creature(food, SOUTH);

	grid.put_creature(f1, 1, 1);
	grid.put_creature(f2, 4, 4);

	grid.execute(*grid.world[1][1], 1, 1);
	grid.execute(*grid.world[4][4], 4, 4);

	ASSERT_TRUE(grid.world[1][1] != 0);
	ASSERT_TRUE(grid.world[4][4] != 0);

}

TEST(Grid, execute_test3)
{
	Grid grid(5,5);

	Species food = Species('f');

	food.addInstruction("right");
	food.addInstruction("go 0");

	Creature f1 = Creature(food, NORTH);
	Creature f2 = Creature(food, SOUTH);

	grid.put_creature(f1, 1, 1);
	grid.put_creature(f2, 4, 4);

	grid.execute(*grid.world[1][1], 1, 1);
	grid.execute(*grid.world[4][4], 4, 4);

	ASSERT_TRUE(grid.world[1][1] != 0);
	ASSERT_TRUE(grid.world[4][4] != 0);

}

TEST(Grid, x_moves1)
{
	srand(0);

	Grid grid2(7, 9);

	Species trap = Species('t');
	trap.addInstruction("if_enemy 3");
    trap.addInstruction("left");
    trap.addInstruction("go 0");
    trap.addInstruction("infect");
    trap.addInstruction("go 0");

    Species hopper = Species('h');
    hopper.addInstruction("hop");
    hopper.addInstruction("go 0");

    Species rover = Species('r');
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

    Creature t__1(trap, 3);
    Creature t__2(trap, 0);
    Creature h__1(hopper, 2);
    Creature r__1(rover, 1);

    grid2.put_creature(t__1, 0, 0);
    grid2.put_creature(h__1, 3, 2);
    grid2.put_creature(r__1, 5, 4);
    grid2.put_creature(t__2, 6, 8);

    grid2.x_moves(5);

    ASSERT_TRUE(grid2.world[5][8] != 0);
    ASSERT_TRUE(grid2.world[6][8] != 0);
    ASSERT_TRUE(grid2.world[6][2] != 0);
}

TEST(Grid, x_moves2)
{
	Grid grid2(10, 10);

	Species food = Species('f');
    food.addInstruction("left");
    food.addInstruction("go 0");

	Species trap = Species('t');
	trap.addInstruction("if_enemy 3");
    trap.addInstruction("left");
    trap.addInstruction("go 0");
    trap.addInstruction("infect");
    trap.addInstruction("go 0");

    Species hopper = Species('h');
    hopper.addInstruction("hop");
    hopper.addInstruction("go 0");

    Species rover = Species('r');
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

    Creature f_1(food, EAST);
    Creature f_2(food, NORTH);

    Creature h_1(hopper, NORTH);
    Creature h_2(hopper, EAST);
    Creature h_3(hopper, SOUTH);
    Creature h_4(hopper, WEST);

    grid2.put_creature(f_1, 0, 0);
    grid2.put_creature(f_2, 7, 7);

    grid2.put_creature(h_1, 3, 3);
    grid2.put_creature(h_2, 3, 4);
    grid2.put_creature(h_3, 4, 4);
    grid2.put_creature(h_4, 4, 3);

    grid2.x_moves(10);

    ASSERT_TRUE(grid2.world[0][0] != 0);
    ASSERT_TRUE(grid2.world[3][9] != 0);
    ASSERT_TRUE(grid2.world[9][4] != 0);

}

TEST(Grid, x_moves_big1)
{
	Grid grid3(100, 100);

	Species food = Species('f');
    food.addInstruction("left");
    food.addInstruction("go 0");

	Species trap = Species('t');
	trap.addInstruction("if_enemy 3");
    trap.addInstruction("left");
    trap.addInstruction("go 0");
    trap.addInstruction("infect");
    trap.addInstruction("go 0");

    Species hopper = Species('h');
    hopper.addInstruction("hop");
    hopper.addInstruction("go 0");

    Species rover = Species('r');
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

 		srand(0);

        int position = rand() % 5184;
        int direction = rand() % 4;
        Creature f1(food, direction);
        grid3.put_creature(f1, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f2(food, direction);
        grid3.put_creature(f2, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f3(food, direction);
        grid3.put_creature(f3, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f4(food, direction);
        grid3.put_creature(f4, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f5(food, direction);
        grid3.put_creature(f5, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f6(food, direction);
        grid3.put_creature(f6, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f7(food, direction);
        grid3.put_creature(f7, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f8(food, direction);
        grid3.put_creature(f8, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f9(food, direction);
        grid3.put_creature(f9, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f10(food, direction);
        grid3.put_creature(f10, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h1(hopper, direction);
        grid3.put_creature(h1, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h2(hopper, direction);
        grid3.put_creature(h2, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h3(hopper, direction);
        grid3.put_creature(h3, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h4(hopper, direction);
        grid3.put_creature(h4, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h5(hopper, direction);
        grid3.put_creature(h5, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h6(hopper, direction);
        grid3.put_creature(h6, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h7(hopper, direction);
        grid3.put_creature(h7, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h8(hopper, direction);
        grid3.put_creature(h8, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h9(hopper, direction);
        grid3.put_creature(h9, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h10(hopper, direction);
        grid3.put_creature(h10, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r1(rover, direction);
        grid3.put_creature(r1, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r2(rover, direction);
        grid3.put_creature(r2, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r3(rover, direction);
        grid3.put_creature(r3, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r4(rover, direction);
        grid3.put_creature(r4, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r5(rover, direction);
        grid3.put_creature(r5, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r6(rover, direction);
        grid3.put_creature(r6, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r7(rover, direction);
        grid3.put_creature(r7, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r8(rover, direction);
        grid3.put_creature(r8, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r9(rover, direction);
        grid3.put_creature(r9, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r10(rover, direction);
        grid3.put_creature(r10, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t1(trap, direction);
        grid3.put_creature(t1, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t2(trap, direction);
        grid3.put_creature(t2, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t3(trap, direction);
        grid3.put_creature(t3, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t4(trap, direction);
        grid3.put_creature(t4, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t5(trap, direction);
        grid3.put_creature(t5, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t6(trap, direction);
        grid3.put_creature(t6, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t7(trap, direction);
        grid3.put_creature(t7, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t8(trap, direction);
        grid3.put_creature(t8, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t9(trap, direction);
        grid3.put_creature(t9, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t10(trap, direction);
        grid3.put_creature(t10, position / 72, position % 72);

        grid3.x_moves(1000, 10, 100);

    ASSERT_TRUE(grid3.world[0][19] != 0);
}

TEST(Grid, x_moves_big2)
{
	Grid grid3(80, 80);

	Species food = Species('f');
    food.addInstruction("left");
    food.addInstruction("go 0");

	Species trap = Species('t');
	trap.addInstruction("if_enemy 3");
    trap.addInstruction("left");
    trap.addInstruction("go 0");
    trap.addInstruction("infect");
    trap.addInstruction("go 0");

    Species hopper = Species('h');
    hopper.addInstruction("hop");
    hopper.addInstruction("go 0");

    Species rover = Species('r');
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

 		srand(0);

        int position = rand() % 5184;
        int direction = rand() % 4;
        Creature f1(food, direction);
        grid3.put_creature(f1, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f2(food, direction);
        grid3.put_creature(f2, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f3(food, direction);
        grid3.put_creature(f3, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f4(food, direction);
        grid3.put_creature(f4, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f5(food, direction);
        grid3.put_creature(f5, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f6(food, direction);
        grid3.put_creature(f6, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f7(food, direction);
        grid3.put_creature(f7, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f8(food, direction);
        grid3.put_creature(f8, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f9(food, direction);
        grid3.put_creature(f9, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature f10(food, direction);
        grid3.put_creature(f10, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h1(hopper, direction);
        grid3.put_creature(h1, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h2(hopper, direction);
        grid3.put_creature(h2, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h3(hopper, direction);
        grid3.put_creature(h3, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h4(hopper, direction);
        grid3.put_creature(h4, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h5(hopper, direction);
        grid3.put_creature(h5, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h6(hopper, direction);
        grid3.put_creature(h6, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h7(hopper, direction);
        grid3.put_creature(h7, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h8(hopper, direction);
        grid3.put_creature(h8, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h9(hopper, direction);
        grid3.put_creature(h9, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature h10(hopper, direction);
        grid3.put_creature(h10, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r1(rover, direction);
        grid3.put_creature(r1, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r2(rover, direction);
        grid3.put_creature(r2, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r3(rover, direction);
        grid3.put_creature(r3, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r4(rover, direction);
        grid3.put_creature(r4, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r5(rover, direction);
        grid3.put_creature(r5, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r6(rover, direction);
        grid3.put_creature(r6, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r7(rover, direction);
        grid3.put_creature(r7, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r8(rover, direction);
        grid3.put_creature(r8, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r9(rover, direction);
        grid3.put_creature(r9, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature r10(rover, direction);
        grid3.put_creature(r10, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t1(trap, direction);
        grid3.put_creature(t1, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t2(trap, direction);
        grid3.put_creature(t2, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t3(trap, direction);
        grid3.put_creature(t3, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t4(trap, direction);
        grid3.put_creature(t4, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t5(trap, direction);
        grid3.put_creature(t5, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t6(trap, direction);
        grid3.put_creature(t6, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t7(trap, direction);
        grid3.put_creature(t7, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t8(trap, direction);
        grid3.put_creature(t8, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t9(trap, direction);
        grid3.put_creature(t9, position / 72, position % 72);

        position = rand() % 5184;
        direction = rand() % 4;
        Creature t10(trap, direction);
        grid3.put_creature(t10, position / 72, position % 72);

        grid3.x_moves(1000, 10, 100);

    ASSERT_TRUE(grid3.world[0][19] != 0);
}		

