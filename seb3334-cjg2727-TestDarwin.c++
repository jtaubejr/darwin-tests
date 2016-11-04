// ------------------------------
// projects/darwin/TestDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// ------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "Darwin.h"
#include "gtest/gtest.h"
#include <iostream>

using namespace std;

// ----
// test
// ----

TEST(Species, Test_Species_Construction) {
  Species food('F');
  assert(food.symbol == 'F');
}

TEST(Species, Test_addInstruction) {
  Species food('F');
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  assert(food.size == 2);
}

TEST(Species, Test_addInstruction2) {
  Species food('F');
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  assert(food.program[1].i == GO);
}

TEST(Species, Test_addInstruction3) {
  Species food('F');
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(LEFT, 0);
  assert(food.size == 29);
}

TEST(Species, Test_get_next_instruction) {
  Species food('F');
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  assert(food.get_next_instruction(0).i == LEFT);
}

TEST(Species, Test_print_symbol) {
  Species food('F');
  assert(food.symbol == 'F');
}

TEST(Species, Test_print_symbol2) {
  Species food('R');
  assert(food.symbol == 'R');
}

TEST(Species, Test_print_symbol3) {
  Species food('H');
  assert(food.symbol == 'H');
}

TEST(Species, Test_print_symbol4) {
  Species food('W');
  assert(food.symbol == 'W');
}

TEST(Species, Test_print_symbol5) {
  Species food('L');
  assert(food.symbol == 'L');
}

TEST(Species, Test_print_symbol6) {
  Species food('Y');
  assert(food.symbol == 'Y');
}
TEST(Species, Test_print_symbol7) {
  Species food('A');
  assert(food.symbol == 'A');
}

TEST(Species, Test_print_symbol8) {
  Species food('B');
  assert(food.symbol == 'B');
}

TEST(Species, Test_print_symbol9) {
  Species food('C');
  assert(food.symbol == 'C');
}

TEST(Species, Test_print_symbol10) {
  Species food('D');
  assert(food.symbol == 'D');
}

TEST(Species, Test_print_symbol11) {
  Species food('E');
  assert(food.symbol == 'E');
}

TEST(Species, Test_print_symbol12) {
  Species food('X');
  assert(food.symbol == 'X');
}

TEST(Species, Test_copy_assignment) {
  Species food('F');
  Species hopper('H');
  food = hopper;
  assert(food.symbol == 'H');
}

TEST(Species, Test_copy_assignment2) {
  Species food('F');
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  Species hopper('H');
  hopper = food;
  assert(hopper.size == 2);
}

TEST(Species, Test_copy_assignment3) {
  Species food('F');
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  Species hopper('H');
  hopper = food;
  assert(hopper.program[1].i == GO);
}

TEST(Species, Test_copy_assignment4) {
  Species food('F');
  Species hopper('H');
  food = hopper;
  assert(food.symbol == 'H');
}

TEST(Species, Test_copy_assignment5) {
  Species food('F');
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  Species hopper('H');
  hopper = food;
  assert(hopper.size == 6);
}

TEST(Species, Test_copy_assignment6) {
  Species food('F');
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  food.add_instruction(LEFT, 0);
  food.add_instruction(GO, 0);
  Species hopper('H');
  hopper = food;
  assert(hopper.program[2].i == LEFT);
}

TEST(Creature, Test_left) {
  Species left('T');
  left.add_instruction(LEFT, 0);
  Creature test(left, NORTH);
  test.left();
  assert(test.direction == WEST);
}

TEST(Creature, Test_left2) {
  Species left('T');
  left.add_instruction(LEFT, 0);
  Creature test(left, WEST);
  test.left();
  assert(test.direction == SOUTH);
}

TEST(Creature, Test_left3) {
  Species left('T');
  left.add_instruction(LEFT, 0);
  Creature test(left, SOUTH);
  test.left();
  assert(test.direction == EAST);
}

TEST(Creature, Test_left4) {
  Species left('T');
  left.add_instruction(LEFT, 0);
  Creature test(left, EAST);
  test.left();
  assert(test.direction == NORTH);
}

TEST(Creature, Test_right) {
  Species right('T');
  right.add_instruction(RIGHT, 0);
  Creature test(right, NORTH);
  test.right();
  assert(test.direction == EAST);
}

TEST(Creature, Test_right2) {
  Species right('T');
  right.add_instruction(RIGHT, 0);
  Creature test(right, EAST);
  test.right();
  assert(test.direction == SOUTH);
}

TEST(Creature, Test_right3) {
  Species right('T');
  right.add_instruction(RIGHT, 0);
  Creature test(right, SOUTH);
  test.right();
  assert(test.direction == WEST);
}

TEST(Creature, Test_right4) {
  Species right('T');
  right.add_instruction(RIGHT, 0);
  Creature test(right, WEST);
  test.right();
  assert(test.direction == NORTH);
}

TEST(Creature, Test_Creature_copy_assignment) {
  Species test('T');
  test.add_instruction(RIGHT, 0);
  Species two('W');
  Creature first(test, WEST);
  Creature second(two, NORTH);
  second = first;
  assert(second.direction == WEST);
}

TEST(Creature, Test_Creature_copy_assignment2) {
  Species test('T');
  test.add_instruction(RIGHT, 0);
  Species two('W');
  Creature first(test, WEST);
  Creature second(two, NORTH);
  second = first;
  assert(second.species.symbol == 'T');
}

TEST(Creature, Test_Creature_copy_assignment3) {
  Species test('X');
  test.add_instruction(RIGHT, 0);
  Species two('Y');
  Creature first(test, WEST);
  Creature second(two, NORTH);
  second = first;
  assert(second.species.symbol == 'X');
}

TEST(Creature, Test_Creature_copy_assignment4) {
  Species test('B');
  test.add_instruction(RIGHT, 0);
  Species two('S');
  Creature first(test, WEST);
  Creature second(two, NORTH);
  second = first;
  assert(second.species.symbol == 'B');
}

TEST(Creature, Test_Creature_copy_assignment5) {
  Species test('P');
  test.add_instruction(RIGHT, 0);
  Species two('F');
  Creature first(test, WEST);
  Creature second(two, NORTH);
  second = first;
  assert(second.species.symbol == 'P');
}

TEST(Creature, Test_Creature_copy_assignment6) {
  Species test('R');
  test.add_instruction(RIGHT, 0);
  Species two('N');
  Creature first(test, WEST);
  Creature second(two, NORTH);
  second = first;
  assert(second.species.symbol == 'R');
}

TEST(Creature, Test_Creature_copy_assignment7) {
  Species test('R');
  test.add_instruction(RIGHT, 0);
  Species two('N');
  Creature first(test, WEST);
  Creature second(two, EAST);
  second = first;
  assert(second.direction == WEST);
}

TEST(Creature, Test_Creature_copy_assignment8) {
  Species test('R');
  test.add_instruction(RIGHT, 0);
  Species two('N');
  Creature first(test, SOUTH);
  Creature second(two, NORTH);
  second = first;
  assert(second.direction == SOUTH);
}

TEST(Creature, Test_Creature_copy_assignment9) {
  Species test('R');
  test.add_instruction(RIGHT, 0);
  Species two('N');
  Creature first(test, EAST);
  Creature second(two, NORTH);
  second = first;
  assert(second.direction == EAST);
}

TEST(Darwin, Test_add_creature) {
  Darwin board(4, 4);
  Species food('F');
  board.add_creature(food, 1, 1, NORTH);
  assert(board.board[board.col * 1 + 1].species.symbol == 'F');
}

TEST(Darwin, Test_add_creature2) {
  Darwin board(8, 8);
  Species food('H');
  board.add_creature(food, 2, 7, NORTH);
  assert(board.board[board.col * 2 + 7].species.symbol == 'H');
}

TEST(Darwin, Test_add_creature3) {
  Darwin board(8, 8);
  Species food('H');
  Species blerg('b');
  Species x('x');
  board.add_creature(food, 2, 7, NORTH);
  board.add_creature(blerg, 1, 1, WEST);
  board.add_creature(x, 5, 5, SOUTH);
  assert(board.board[board.col * 2 + 7].species.symbol == 'H');
}

TEST(Darwin, Test_add_creature4) {
  Darwin board(8, 8);
  Species best('b');
  best.add_instruction(IF_ENEMY, 2);
  best.add_instruction(GO, 7);
  best.add_instruction(INFECT);
  best.add_instruction(GO, 0);
  best.add_instruction(IF_EMPTY, 6);
  best.add_instruction(LEFT);
  best.add_instruction(HOP);
  best.add_instruction(GO, 0);
  board.add_creature(best, 2, 7, NORTH);
  assert(board.board[board.col * 2 + 7].species.symbol == 'b');
}

TEST(Darwin, Test_add_creature5) {
  Darwin board(8, 8);
  Species rover('r');
  rover.add_instruction(IF_ENEMY, 9);
  rover.add_instruction(IF_EMPTY, 7);
  rover.add_instruction(IF_RANDOM, 5);
  rover.add_instruction(LEFT);
  rover.add_instruction(GO, 0);
  rover.add_instruction(RIGHT);
  rover.add_instruction(GO, 0);
  rover.add_instruction(HOP);
  rover.add_instruction(GO, 0);
  rover.add_instruction(INFECT);
  rover.add_instruction(GO, 0);
  board.add_creature(rover, 2, 7, NORTH);
  assert(board.board[board.col * 2 + 7].species.symbol == 'r');
}

TEST(Darwin, Test_add_creature6) {
  Darwin board(8, 8);
  Species food('W');
  food.add_instruction(LEFT);
  food.add_instruction(GO, 0);
  board.add_creature(food, 2, 7, NORTH);
  assert(board.board[board.col * 2 + 7].species.symbol == 'W');
}

TEST(Darwin, Test_add_creature7) {
  Darwin board(8, 8);
  Species trap('t');
  trap.add_instruction(IF_ENEMY, 3);
  trap.add_instruction(LEFT);
  trap.add_instruction(GO, 0);
  trap.add_instruction(INFECT);
  trap.add_instruction(GO, 0);
  board.add_creature(trap, 2, 4, SOUTH);
  assert(board.board[board.col * 2 + 4].species.symbol == 't');
}

TEST(Cohesion, Test_run_simulation) {
  Darwin board(8, 8);
  Species hopper('h');
  hopper.add_instruction(HOP);
  hopper.add_instruction(GO, 0);
  board.add_creature(hopper, 2, 4, SOUTH);
  board.run_simulation(2, -1);
  assert(board.board[board.col * 4 + 4].species.symbol == 'h');
}

TEST(Cohesion, Test_run_simulation2) {
  Darwin board(8, 8);
  Species trap('t');
  trap.add_instruction(IF_ENEMY, 3);
  trap.add_instruction(LEFT);
  trap.add_instruction(GO, 0);
  trap.add_instruction(INFECT);
  trap.add_instruction(GO, 0);
  board.add_creature(trap, 2, 4, SOUTH);
  board.run_simulation(3, -1);
  assert(board.board[board.col * 2 + 4].direction == WEST);
}

TEST(Cohesion, Test_run_simulation3) {
  Darwin board(8, 8);
  Species food('f');
  food.add_instruction(LEFT);
  food.add_instruction(GO, 0);
  Species rover('r');
  rover.add_instruction(IF_ENEMY, 9);
  rover.add_instruction(IF_EMPTY, 7);
  rover.add_instruction(IF_RANDOM, 5);
  rover.add_instruction(LEFT);
  rover.add_instruction(GO, 0);
  rover.add_instruction(RIGHT);
  rover.add_instruction(GO, 0);
  rover.add_instruction(HOP);
  rover.add_instruction(GO, 0);
  rover.add_instruction(INFECT);
  rover.add_instruction(GO, 0);
  board.add_creature(food, 2, 4, SOUTH);
  board.add_creature(rover, 2, 5, WEST);
  board.run_simulation(8, -1);
  assert(board.board[board.col * 7 + 4].species.symbol == 'r');
  assert(board.board[board.col * 7 + 5].species.symbol == 'r');
}
