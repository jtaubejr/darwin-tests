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

    Species food('f');
    food.add_instr(LEFT);
    food.add_instr(GO, 0);

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */

    Species hopper('h');
    hopper.add_instr(HOP);
    hopper.add_instr(GO, 0);

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

    Species rover('r');
    rover.add_instr(IF_ENEMY, 9);
    rover.add_instr(IF_EMPTY, 7);
    rover.add_instr(IF_RANDOM, 5);
    rover.add_instr(LEFT);
    rover.add_instr(GO, 0);
    rover.add_instr(RIGHT);
    rover.add_instr(GO, 0);
    rover.add_instr(HOP);
    rover.add_instr(GO, 0);
    rover.add_instr(INFECT);
    rover.add_instr(GO, 0);

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

    Species trap('t');
    trap.add_instr(IF_ENEMY, 3);
    trap.add_instr(LEFT);
    trap.add_instr(GO, 0);
    trap.add_instr(INFECT);
    trap.add_instr(GO, 0);

    // best

    Species best('b');
    best.add_instr(IF_ENEMY, 9);
    best.add_instr(IF_EMPTY, 7);
    best.add_instr(IF_RANDOM, 5);
    best.add_instr(LEFT);
    best.add_instr(GO, 0);
    best.add_instr(RIGHT);
    best.add_instr(GO, 0);
    best.add_instr(HOP);
    best.add_instr(GO, 0);
    best.add_instr(INFECT);
    best.add_instr(GO, 0);

    // ----------
    // darwin 8x8
    // ----------
    /*
    8x8 Darwin
    Food,   facing east,  at (0, 0)
    Hopper, facing north, at (3, 3)
    Hopper, facing east,  at (3, 4)
    Hopper, facing south, at (4, 4)
    Hopper, facing west,  at (4, 3)
    Food,   facing north, at (7, 7)
    Simulate 5 moves.
    Print every grid.
    */

    try {
        cout << "*** Darwin 8x8 ***" << endl;

        Darwin x(8, 8);
        x.add_creature(Creature(food), EAST, 0, 0);
        x.add_creature(Creature(hopper), NORTH, 3, 3);
        x.add_creature(Creature(hopper), EAST, 3, 4);
        x.add_creature(Creature(hopper), SOUTH, 4, 4);
        x.add_creature(Creature(hopper), WEST, 4, 3);
        x.add_creature(Creature(food), NORTH, 7, 7);
        x.play(5);
    } catch (const invalid_argument&) {
        assert(false);
    } catch(const out_of_range&) {
        assert(false);
    }
    // ----------
    // darwin 7x9
    // ----------


    /*
    7x9 Darwin
    Trap,   facing south, at (0, 0)
    Hopper, facing east,  at (3, 2)
    Rover,  facing north, at (5, 4)
    Trap,   facing west,  at (6, 8)
    Simulate 5 moves.
    Print every grid.
    */

    try {
        cout << "*** Darwin 7x9 ***" << endl;
        srand(0);

        Darwin x(7, 9);
        x.add_creature(Creature(trap), SOUTH, 0, 0);
        x.add_creature(Creature(hopper), EAST, 3, 2);
        x.add_creature(Creature(rover), NORTH, 5, 4);
        x.add_creature(Creature(trap), WEST, 6, 8);
        x.play(5);
    } catch (const invalid_argument&) {
        assert(false);
    } catch(const out_of_range&) {
        assert(false);
    }

    // ------------
    // darwin 72x72
    // without best
    // ------------

    try {
        cout << "*** Darwin 72x72 without Best ***" << endl;
        srand(0);
    /*
    Randomly place the following creatures facing randomly.
    Call rand(), mod it with 5184 (72x72), and use that for the position
    in a row-major order grid.
    Call rand() again, mod it with 4 and use that for it's direction with
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
        Darwin x(72, 72);
        for(int i = 0; i < 10; ++i) {
            int position = rand() % 5184;
            int dir = rand() % 4;
            x.add_creature(Creature(food), dir, (position / 72), (position % 72));
        }

        for(int i = 0; i < 10; ++i) {
            int position = rand() % 5184;
            int dir = rand() % 4;
            x.add_creature(Creature(hopper), dir, (position / 72), (position % 72));
        }

        for(int i = 0; i < 10; ++i) {
            int position = rand() % 5184;
            int dir = rand() % 4;
            x.add_creature(Creature(rover), dir, (position / 72), (position % 72));
        }

        for(int i = 0; i < 10; ++i) {
            int position = rand() % 5184;
            int dir = rand() % 4;
            x.add_creature(Creature(trap), dir, (position / 72), (position % 72));
        }
        x.play(9);
        x.play(1000, 100, 1);
    } catch (const invalid_argument&) {
        assert(false);
    } catch (const out_of_range&) {
        assert(false);
    }
    // ------------
    // darwin 72x72
    // with best
    // ------------
    try {
        cout << "*** Darwin 72x72 with Best ***" << endl;
        srand(0);
    /*
    Randomly place the following creatures facing randomly.
    Call rand(), mod it with 5184 (72x72), and use that for the position
    in a row-major order grid.
    Call rand() again, mod it with 4 and use that for it's direction with
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
        Darwin x(72, 72);
        for(int i = 0; i < 10; ++i) {
            int position = rand() % 5184;
            int dir = rand() % 4;
            x.add_creature(Creature(food), dir, (position / 72), (position % 72));
        }

        for(int i = 0; i < 10; ++i) {
            int position = rand() % 5184;
            int dir = rand() % 4;
            x.add_creature(Creature(hopper), dir, (position / 72), (position % 72));
        }

        for(int i = 0; i < 10; ++i) {
            int position = rand() % 5184;
            int dir = rand() % 4;
            x.add_creature(Creature(rover), dir, (position / 72), (position % 72));
        }

        for(int i = 0; i < 10; ++i) {
            int position = rand() % 5184;
            int dir = rand() % 4;
            x.add_creature(Creature(trap), dir, (position / 72), (position % 72));
        }

        for(int i = 0; i < 10; ++i) {
            int position = rand() % 5184;
            int dir = rand() % 4;
            x.add_creature(Creature(best), dir, (position / 72), (position % 72));
        }
        x.play(9);
        x.play(1000, 100, 1);
    } catch (const invalid_argument&) {
        assert(false);
    } catch (const out_of_range&) {
        assert(false);
    }
    return 0;}
