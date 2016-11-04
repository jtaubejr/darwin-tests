// -----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// -----------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range

#include "Darwin.h"

// ----
// main
// ----

int main () {
    using namespace std;

    // ----
    // food
    // ----

    /*
     0: left
     1: go 0
    */
    Species food = Species('f');
    food.addInstruction("left");
    food.addInstruction("go 0");

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */
    Species hopper = Species('h');
    hopper.addInstruction("hop");
    hopper.addInstruction("go 0");

    // -----
    // rover
    // -----

    /*
     0: if_enemy 9
     1: if_empty 7
     2: if_random 5
     3: left
     4: go 0
     5: right
     6: go 0
     7: hop
     8: go 0
     9: infect
    10: go 0
    */
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

    // ----
    // trap
    // ----

    /*
     0: if_enemy 3
     1: left
     2: go 0
     3: infect
     4: go 0
    */
    Species trap = Species('t');
    trap.addInstruction("if_enemy 3");
    trap.addInstruction("left");
    trap.addInstruction("go 0");
    trap.addInstruction("infect");
    trap.addInstruction("go 0");

    // ----------
    // darwin 8x8
    // ----------

//try{
    cout << "*** Darwin 8x8 ***" << endl;
    /*
    8x8 Darwin
    Food,   facing east,  at (0, 0)
    Hopper, facing north, at (3, 3)
    Hopper, facing east,  at (3, 4)
    Hopper, facing south, at (4, 4)
    Hopper, facing west,  at (4, 3)
    Food,   facing north, at (7, 7)
    */
    Grid grid(8, 8);
    Creature f_1(food, EAST);
    Creature f_2(food, NORTH);

    Creature h_1(hopper, NORTH);
    Creature h_2(hopper, EAST);
    Creature h_3(hopper, SOUTH);
    Creature h_4(hopper, WEST);

    grid.put_creature(f_1, 0, 0);
    grid.put_creature(f_2, 7, 7);

    grid.put_creature(h_1, 3, 3);
    grid.put_creature(h_2, 3, 4);
    grid.put_creature(h_3, 4, 4);
    grid.put_creature(h_4, 4, 3);

    grid.x_moves(5);

    /*
    Simulate 5 moves.
    Print every grid.
    */

    // ----------
    // darwin 7x9
    // ----------

    cout << "*** Darwin 7x9 ***" << endl;
    srand(0);

        Grid grid2(7, 9);
        Creature t__1(trap, 3);
        Creature t__2(trap, 0);
        Creature h__1(hopper, 2);
        Creature r__1(rover, 1);

        grid2.put_creature(t__1, 0, 0);
        grid2.put_creature(h__1, 3, 2);
        grid2.put_creature(r__1, 5, 4);
        grid2.put_creature(t__2, 6, 8);

        grid2.x_moves(5);
    /*
    7x9 Darwin
    Trap,   facing south, at (0, 0)
    Hopper, facing east,  at (3, 2)
    Rover,  facing north, at (5, 4)
    Trap,   facing west,  at (6, 8)
    Simulate 5 moves.
    Print every grid.
    */

    // ------------
    // darwin 72x72
    // without best
    // ------------

    cout << "*** Darwin 72x72 without Best ***" << endl;
    srand(0);

    Grid grid3(72,72);

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
    /*
    Randomly place the following creatures facing randomly.
    Call rand(), mod it with 5184 (72x72), and use that for the position
    in a row-major order grid.
    Call rand() again, mod it with 4 and use that for it's directionection with
    the ordering: west, north, east, south.
    Do that for each kind of creature.
    10 Food
    10 Hopper
    10 Rover
    10 Trap
    Simulate 1000 moves.
    Print the first 10 grids          (i.e. 0, 1, 2...9).
    Print every 100th grid after that (i.e. 100, 200, 300...1000).
    */

    // ------------
    // darwin 72x72
    // with best
    // ------------

    cout << "*** Darwin 72x72 with Best ***" << endl;
    srand(0);
    /*
    Randomly place the following creatures facing randomly.
    Call rand(), mod it with 5184 (72x72), and use that for the position
    in a row-major order grid.
    Call rand() again, mod it with 4 and use that for it's directionection with
    the ordering: 0:west, 1:north, 2:east, 3:south.
    Do that for each kind of creature.
    10 Food
    10 Hopper
    10 Rover
    10 Trap
    10 Best
    Simulate 1000 moves.
    Best MUST outnumber ALL other species for the bonus pts.
    Print the first 10 grids          (i.e. 0, 1, 2...9).
    Print every 100th grid after that (i.e. 100, 200, 300...1000).
    */

    return 0;}
