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

///////////////////////////////////////////////////////////////////////////
//////////////////////////////////SPECIES//////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, species_print_operator_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(if_enemy, 9);
  food.add_instruction(if_empty, 7);
  food.add_instruction(if_random, 5);
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);
  food.add_instruction(move_right, 0);
  food.add_instruction(go, 0);
  food.add_instruction(hop, 0);
  food.add_instruction(go, 0);
  ostringstream oss;
  oss << food;
  ASSERT_EQ("f", oss.str());
}

TEST(DarwinFixture, species_print_operator_test2) {
  srand(0);
  Species hopper('h');
  hopper.add_instruction(hop, 0);
  hopper.add_instruction(go, 0);
  ostringstream oss;
  oss << hopper;
  ASSERT_EQ("h", oss.str());
}

TEST(DarwinFixture, species_print_operator_test3) {
  srand(0);
  Species rover('r');
  rover.add_instruction(if_enemy, 9);
  ostringstream oss;
  oss << rover;
  ASSERT_EQ("r", oss.str());
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, species_eq_operator_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(if_enemy, 9);
  food.add_instruction(if_empty, 7);
  food.add_instruction(if_random, 5);
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);
  food.add_instruction(move_right, 0);
  food.add_instruction(go, 0);
  food.add_instruction(hop, 0);
  food.add_instruction(go, 0);

  Species food2('f');
  food2.add_instruction(if_enemy, 9);
  food2.add_instruction(if_empty, 7);
  food2.add_instruction(if_random, 5);
  food2.add_instruction(move_left, 0);
  food2.add_instruction(go, 0);
  food2.add_instruction(move_right, 0);
  food2.add_instruction(go, 0);
  food2.add_instruction(hop, 0);
  food2.add_instruction(go, 0);

  ASSERT_TRUE(food == food2);
}
TEST(DarwinFixture, species_eq_operator_test2) {
  srand(0);
  Species food('f');
  food.add_instruction(if_enemy, 9);
  food.add_instruction(if_empty, 7);
  food.add_instruction(if_random, 5);
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);
  food.add_instruction(move_right, 0);
  food.add_instruction(go, 0);
  food.add_instruction(hop, 0);
  food.add_instruction(go, 0);

  Species hopper('h');
  hopper.add_instruction(hop, 0);
  hopper.add_instruction(go, 0);

  ASSERT_FALSE(food == hopper);
}
TEST(DarwinFixture, species_eq_operator_test3) {
  Species rover('r');
  rover.add_instruction(if_enemy, 9);
  rover.add_instruction(if_empty, 7);
  rover.add_instruction(if_random, 5);
  rover.add_instruction(move_left, 0);
  rover.add_instruction(go, 0);

  Species rover2('r');
  rover2.add_instruction(if_enemy, 9);
  rover2.add_instruction(if_empty, 7);
  rover2.add_instruction(if_random, 5);
  rover2.add_instruction(move_left, 0);
  rover2.add_instruction(go, 0);

  ASSERT_TRUE(rover == rover2);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, add_instruction_size_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(if_enemy, 9);
  food.add_instruction(if_empty, 7);
  food.add_instruction(if_random, 5);
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);
  food.add_instruction(move_right, 0);
  food.add_instruction(go, 0);
  food.add_instruction(hop, 0);
  food.add_instruction(go, 0);
  ASSERT_EQ(food.num_lines, 9);
}

TEST(DarwinFixture, add_instruction_size_test2) {
  srand(0);
  Species food('f');
  food.add_instruction(if_enemy, 9);
  food.add_instruction(if_empty, 7);
  food.add_instruction(if_random, 5);
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);
  ASSERT_EQ(food.num_lines, 5);
}

TEST(DarwinFixture, add_instruction_size_test3) {
  srand(0);
  Species food('f');

  food.add_instruction(if_enemy, 9);
  food.add_instruction(if_empty, 7);
  food.add_instruction(if_random, 5);
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 6);
  food.add_instruction(move_right, 0);
  food.add_instruction(go, 0);
  food.add_instruction(hop, 0);
  food.add_instruction(go, 0);
  food.add_instruction(infect, 0);
  food.add_instruction(go, 0);

  pair<Moves, int> four = food.program[4];
  ASSERT_EQ(get<0>(four), go);
  ASSERT_EQ(get<1>(four), 6);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, species_turn_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);
  Darwin t1(8, 8);
  Creature f1(&food, EAST);
  t1.add_creature(f1, 0, 0);
  ASSERT_EQ(food.species_turn(t1, f1, 0), 0);
}

TEST(DarwinFixture, species_turn_test2) {
  srand(0);
  Species hopper('h');
  hopper.add_instruction(hop, 0);
  hopper.add_instruction(go, 0);
  Darwin t1(8, 8);
  Creature h1(&hopper, NORTH);
  t1.add_creature(h1, 3, 3);
  ASSERT_EQ(hopper.species_turn(t1, h1, 0), 0);
}

TEST(DarwinFixture, species_turn_test3) {
  srand(0);
  Species rover('r');
  rover.add_instruction(if_enemy, 9);
  rover.add_instruction(if_empty, 7);
  rover.add_instruction(if_random, 5);
  rover.add_instruction(move_left, 0);
  rover.add_instruction(go, 0);
  rover.add_instruction(move_right, 0);
  rover.add_instruction(go, 0);
  rover.add_instruction(hop, 0);
  rover.add_instruction(go, 0);
  rover.add_instruction(infect, 0);
  rover.add_instruction(go, 0);
  Darwin t1(8, 8);
  Creature r1(&rover, EAST);
  t1.add_creature(r1, 0, 0);
  ASSERT_EQ(rover.species_turn(t1, t1.board[0], 0), 7);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, perform_next_instruct_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);
  Darwin t1(8, 8);
  Creature f1(&food, EAST);
  t1.add_creature(f1, 0, 0);
  ASSERT_EQ(food.perform_next_instruct(t1, f1, 0), 0);
}

TEST(DarwinFixture, perform_next_instruct_test2) {
  srand(0);
  Species hopper('h');
  hopper.add_instruction(hop, 0);
  hopper.add_instruction(go, 0);
  Darwin t1(8, 8);
  Creature h1(&hopper, NORTH);
  t1.add_creature(h1, 3, 3);
  ASSERT_EQ(hopper.perform_next_instruct(t1, h1, 0), 0);
}

TEST(DarwinFixture, perform_next_instruct_test3) {
  srand(0);
  Species rover('r');
  rover.add_instruction(if_enemy, 9);
  rover.add_instruction(if_empty, 7);
  rover.add_instruction(if_random, 5);
  rover.add_instruction(move_left, 0);
  rover.add_instruction(go, 0);
  rover.add_instruction(move_right, 0);
  rover.add_instruction(go, 0);
  rover.add_instruction(hop, 0);
  rover.add_instruction(go, 0);
  rover.add_instruction(infect, 0);
  rover.add_instruction(go, 0);
  Darwin t1(8, 8);
  Creature r1(&rover, EAST);
  t1.add_creature(r1, 0, 0);
  ASSERT_EQ(r1.direction, EAST);
  ASSERT_EQ(rover.species_turn(t1, t1.board[0], 0), 7);
}

///////////////////////////////////////////////////////////////////////////
/////////////////////////////////CREATURE//////////////////////////////////
///////////////////////////////////////////////////////////////////////////

// Creature *Creature::getAdjacent(Darwin &darwin) {

TEST(DarwinFixture, getAdjacent_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, EAST);
  Creature f2(&food, WEST);
  t1.add_creature(f1, 0, 0);
  t1.add_creature(f2, 0, 1);

  Creature *c1 = t1.board[0].getAdjacent(t1);
  Creature *c2 = &(t1.board[1]);

  ASSERT_TRUE(c1 == c2);
}
TEST(DarwinFixture, getAdjacent_test2) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, SOUTH);
  Creature f2(&food, WEST);
  t1.add_creature(f1, 0, 0);
  t1.add_creature(f2, 1, 0);

  Creature *c1 = t1.board[0].getAdjacent(t1);
  Creature *c2 = &(t1.board[8]);

  ASSERT_TRUE(c1 == c2);
}
TEST(DarwinFixture, getAdjacent_test3) {
  srand(0);
  Species hopper('h');
  hopper.add_instruction(hop, 0);
  hopper.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&hopper, WEST);
  Creature f2(&hopper, WEST);
  t1.add_creature(f1, 0, 1);
  t1.add_creature(f2, 0, 0);

  Creature *c1 = t1.board[1].getAdjacent(t1);
  Creature *c2 = &(t1.board[0]);

  ASSERT_TRUE(c1 == c2);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, creature_copy_assign_test1) {
  srand(0);
  Species hopper('h');
  hopper.add_instruction(hop, 0);
  hopper.add_instruction(go, 0);
  Creature f1(&hopper, WEST);

  Creature temp;
  temp = f1;

  ASSERT_EQ(f1.species, temp.species);
  ASSERT_EQ(f1.pc, temp.pc);
  ASSERT_EQ(f1.direction, temp.direction);
}

TEST(DarwinFixture, creature_copy_assign_test2) {
  srand(0);
  Species hopper('h');
  hopper.add_instruction(hop, 0);
  hopper.add_instruction(go, 0);
  Creature f1(&hopper, WEST);

  Creature temp;
  temp = f1;

  ASSERT_EQ(f1.species, temp.species);
  ASSERT_EQ(f1.pc, temp.pc);
  ASSERT_EQ(f1.direction, temp.direction);
}

TEST(DarwinFixture, creature_copy_assign_test3) {
  srand(0);
  Species rover('r');
  rover.add_instruction(if_enemy, 9);
  Creature f1(&rover, WEST);

  Creature temp;
  temp = f1;

  ASSERT_EQ(f1.species, temp.species);
  ASSERT_EQ(f1.pc, temp.pc);
  ASSERT_EQ(f1.direction, temp.direction);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, creature_print_operator_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(if_enemy, 9);
  food.add_instruction(if_empty, 7);
  food.add_instruction(if_random, 5);
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);
  food.add_instruction(move_right, 0);
  food.add_instruction(go, 0);
  food.add_instruction(hop, 0);
  food.add_instruction(go, 0);

  Creature r1(&food, EAST);

  ostringstream oss;
  oss << r1;
  ASSERT_EQ("f", oss.str());
}

TEST(DarwinFixture, creature_print_operator_test2) {
  srand(0);
  Species hopper('h');
  hopper.add_instruction(hop, 0);
  hopper.add_instruction(go, 0);

  Creature r1(&hopper, EAST);

  ostringstream oss;
  oss << r1;

  ASSERT_EQ("h", oss.str());
}

TEST(DarwinFixture, creature_print_operator_test3) {
  srand(0);
  Species rover('r');
  rover.add_instruction(if_enemy, 9);

  Creature r1(&rover, EAST);

  ostringstream oss;
  oss << r1;
  ASSERT_NE("k", oss.str());
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, start_turn_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, WEST);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].pc, -1);
  t1.board[0].start_turn(t1);
  ASSERT_EQ(t1.board[0].pc, 0);
}

TEST(DarwinFixture, start_turn_test2) {
  srand(0);
  Species hopper('h');
  hopper.add_instruction(hop, 0);
  hopper.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&hopper, WEST);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].pc, -1);
  t1.board[0].start_turn(t1);
  ASSERT_EQ(t1.board[0].pc, 0);
}

TEST(DarwinFixture, start_turn_test3) {
  srand(0);
  Species food('f');
  food.add_instruction(if_enemy, 9);
  food.add_instruction(if_empty, 7);
  food.add_instruction(if_random, 5);
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);
  food.add_instruction(move_right, 0);
  food.add_instruction(go, 0);
  food.add_instruction(hop, 0);
  food.add_instruction(go, 0);
  ;

  Darwin t1(8, 8);
  Creature f1(&food, EAST);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].pc, -1);
  t1.board[0].start_turn(t1);
  ASSERT_EQ(t1.board[0].pc, 7);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, turn_left_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, WEST);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].direction, WEST);
  t1.board[0].turn_left();
  ASSERT_EQ(t1.board[0].direction, SOUTH);
}

TEST(DarwinFixture, turn_left_test2) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, NORTH);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].direction, NORTH);
  t1.board[0].turn_left();
  ASSERT_EQ(t1.board[0].direction, WEST);
}

TEST(DarwinFixture, turn_left_test3) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, EAST);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].direction, EAST);
  t1.board[0].turn_left();
  ASSERT_EQ(t1.board[0].direction, NORTH);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, turn_right_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, WEST);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].direction, WEST);
  t1.board[0].turn_right();
  ASSERT_EQ(t1.board[0].direction, NORTH);
}

TEST(DarwinFixture, turn_right_test2) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, NORTH);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].direction, NORTH);
  t1.board[0].turn_right();
  ASSERT_EQ(t1.board[0].direction, EAST);
}

TEST(DarwinFixture, turn_right_test3) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, EAST);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].direction, EAST);
  t1.board[0].turn_right();
  ASSERT_EQ(t1.board[0].direction, SOUTH);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, hop_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, EAST);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].species, f1.species);
  ASSERT_EQ(t1.board[0].pc, f1.pc);
  ASSERT_EQ(t1.board[0].direction, f1.direction);
  t1.board[0].hop(t1);
  ASSERT_EQ(t1.board[1].species, f1.species);
  ASSERT_EQ(t1.board[1].pc, f1.pc);
  ASSERT_EQ(t1.board[1].direction, f1.direction);
}

TEST(DarwinFixture, hop_test2) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, SOUTH);
  t1.add_creature(f1, 0, 0);

  ASSERT_EQ(t1.board[0].species, f1.species);
  ASSERT_EQ(t1.board[0].pc, f1.pc);
  ASSERT_EQ(t1.board[0].direction, f1.direction);
  t1.board[0].hop(t1);
  ASSERT_EQ(t1.board[8].species, f1.species);
  ASSERT_EQ(t1.board[8].pc, f1.pc);
  ASSERT_EQ(t1.board[8].direction, f1.direction);
}

TEST(DarwinFixture, hop_test3) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, SOUTH);
  t1.add_creature(f1, 3, 3);

  ASSERT_EQ(t1.board[27].species, f1.species);
  ASSERT_EQ(t1.board[27].pc, f1.pc);
  ASSERT_EQ(t1.board[27].direction, f1.direction);
  t1.board[27].hop(t1);
  ASSERT_EQ(t1.board[35].species, f1.species);
  ASSERT_EQ(t1.board[35].pc, f1.pc);
  ASSERT_EQ(t1.board[35].direction, f1.direction);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, infect_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, EAST);
  Creature f2(&food, EAST);
  t1.add_creature(f1, 0, 0);
  t1.add_creature(f2, 0, 1);

  t1.board[0].infect(t1);
  ASSERT_EQ(t1.board[1].species, f1.species);
}

TEST(DarwinFixture, infect_test2) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, SOUTH);
  Creature f2(&food, EAST);
  t1.add_creature(f1, 0, 0);
  t1.add_creature(f2, 1, 0);

  t1.board[0].infect(t1);
  ASSERT_EQ(t1.board[8].species, f1.species);
}

TEST(DarwinFixture, infect_test3) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, NORTH);
  Creature f2(&food, EAST);
  t1.add_creature(f1, 1, 1);
  t1.add_creature(f2, 0, 1);

  t1.board[9].infect(t1);
  ASSERT_EQ(t1.board[1].species, f1.species);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, check_empty_test1) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, EAST);
  t1.add_creature(f1, 0, 0);

  ASSERT_TRUE(t1.board[0].check_empty(t1));
}

TEST(DarwinFixture, check_empty_test2) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, EAST);
  Creature f2(&food, EAST);
  t1.add_creature(f1, 0, 0);
  t1.add_creature(f2, 0, 1);

  ASSERT_FALSE(t1.board[0].check_empty(t1));
}

TEST(DarwinFixture, check_empty_test3) {
  srand(0);
  Species food('f');
  food.add_instruction(move_left, 0);
  food.add_instruction(go, 0);

  Darwin t1(8, 8);
  Creature f1(&food, SOUTH);
  t1.add_creature(f1, 0, 0);

  ASSERT_TRUE(t1.board[0].check_empty(t1));
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, is_empty_creature1) {
  Darwin d(4, 4);
  ASSERT_TRUE(d.board[0].is_empty_creature());
}

TEST(DarwinFixture, is_empty_creature2) {
  Darwin d(5, 5);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, NORTH);
  d.add_creature(t1, 0, 0);
  ASSERT_FALSE(d.board[0].is_empty_creature());
}

TEST(DarwinFixture, is_empty_creature3) {
  Creature c;
  ASSERT_TRUE(c.is_empty_creature());
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, check_enemy1) {
  Darwin d(2, 2);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, NORTH);
  d.add_creature(t1, 0, 0);
  ASSERT_FALSE(d.board[0].check_enemy(d));
}

TEST(DarwinFixture, check_enemy2) {
  Darwin d(2, 2);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, EAST);
  d.add_creature(t1, 0, 0);
  ASSERT_FALSE(d.board[0].check_enemy(d));
}

TEST(DarwinFixture, check_enemy3) {
  Darwin d(2, 2);
  Species test('t');
  Species enemy('e');
  test.add_instruction(hop, 0);
  Creature t1(&test, EAST);
  Creature e1(&enemy, WEST);
  d.add_creature(t1, 0, 0);
  d.add_creature(e1, 0, 1);
  ASSERT_TRUE(d.board[0].check_enemy(d));
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, check_wall1) {
  Darwin d(5, 5);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, NORTH);
  d.add_creature(t1, 0, 4);
  ASSERT_TRUE(d.board[4].check_wall(d));
}

TEST(DarwinFixture, check_wall2) {
  Darwin d(8, 8);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, WEST);
  d.add_creature(t1, 3, 0);
  ASSERT_TRUE(d.board[24].check_wall(d));
}

TEST(DarwinFixture, check_wall3) {
  Darwin d(10, 10);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, SOUTH);
  d.add_creature(t1, 5, 5);
  ASSERT_FALSE(d.board[55].check_wall(d));
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////DARWIN//////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, darwin_print1) {
  Darwin d(1, 1);
  ostringstream oss;
  oss << d;
  ASSERT_EQ("Turn = 0.\n  0\n0 .\n\n", oss.str());
}

TEST(DarwinFixture, darwin_print2) {
  Darwin d(2, 2);
  d.start();
  ostringstream oss;
  oss << d;
  ASSERT_EQ("Turn = 1.\n  01\n0 ..\n1 ..\n\n", oss.str());
}

TEST(DarwinFixture, darwin_print3) {
  Darwin d(0, 0);
  ostringstream oss;
  oss << d;
  ASSERT_EQ("Turn = 0.\n  \n\n", oss.str());
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, find_index_of_creature1) {
  Darwin d(4, 4);
  Species test('t');
  test.add_instruction(hop, 0);
  test.add_instruction(go, 0);
  Creature t1(&test, NORTH);
  d.add_creature(t1, 2, 2);
  ASSERT_EQ(d.find_index_of_creature(d.board[5]), 5);
}

TEST(DarwinFixture, find_index_of_creature2) {
  Darwin d(3, 3);
  Species test('t');
  test.add_instruction(hop, 0);
  test.add_instruction(go, 0);
  Creature t1(&test, NORTH);
  d.add_creature(t1, 0, 0);
  ASSERT_EQ(d.find_index_of_creature(d.board[0]), 0);
}

TEST(DarwinFixture, find_index_of_creature3) {
  Darwin d(5, 5);
  Species test('t');
  test.add_instruction(hop, 0);
  test.add_instruction(go, 0);
  Creature t1(&test, NORTH);
  d.add_creature(t1, 4, 4);
  ASSERT_EQ(d.find_index_of_creature(d.board[24]), 24);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, darwin_bounds1) {
  Darwin d(20, 20);
  ASSERT_TRUE(d.bounds_check(120, 134, false));
}

TEST(DarwinFixture, darwin_bounds2) {
  Darwin d(10, 10);
  ASSERT_FALSE(d.bounds_check(9, 10, false));
}

TEST(DarwinFixture, darwin_bounds3) {
  Darwin d(20, 20);
  ASSERT_FALSE(d.bounds_check(121, -2, true));
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, darwin_convert1) {
  Darwin d(10, 10);
  ASSERT_EQ(d.convert_to_index(2, 3), 23);
}

TEST(DarwinFixture, darwin_convert2) {
  Darwin d(20, 20);
  ASSERT_EQ(d.convert_to_index(10, 10), 210);
}

TEST(DarwinFixture, darwin_convert3) {
  Darwin d(3, 3);
  ASSERT_EQ(d.convert_to_index(0, 0), 0);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, add_creature1) {
  Darwin d(5, 5);
  Species test('t');
  test.add_instruction(hop, 0);
  test.add_instruction(go, 0);
  Creature t1(&test, NORTH);
  ASSERT_TRUE(d.add_creature(t1, 2, 2));
}

TEST(DarwinFixture, add_creature2) {
  Darwin d(10, 10);
  Species test('t');
  test.add_instruction(hop, 0);
  test.add_instruction(go, 0);
  Creature t1(&test, NORTH);
  ASSERT_FALSE(d.add_creature(t1, 100, 100));
}

TEST(DarwinFixture, add_creature3) {
  Darwin d(1, 1);
  Species test('t');
  test.add_instruction(hop, 0);
  test.add_instruction(go, 0);
  Creature t1(&test, NORTH);
  ASSERT_TRUE(d.add_creature(t1, 0, 0));
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, get_all_adjacent1) {
  Darwin d(1, 1);
  Species test('t');
  test.add_instruction(hop, 0);
  test.add_instruction(go, 0);
  Creature t1(&test, NORTH);
  d.add_creature(t1, 0, 0);
  vector<Creature *> adj = d.get_all_adjacent(d.board[0]);
  ASSERT_EQ(adj[0], nullptr);
  ASSERT_EQ(adj[1], nullptr);
  ASSERT_EQ(adj[2], nullptr);
  ASSERT_EQ(adj[3], nullptr);
}

TEST(DarwinFixture, get_all_adjacent2) {
  Darwin d(10, 10);
  Species test('t');
  test.add_instruction(hop, 0);
  test.add_instruction(go, 0);
  Creature t1(&test, NORTH);
  Creature t2(&test, NORTH);
  d.add_creature(t1, 0, 0);
  d.add_creature(t2, 0, 1);
  vector<Creature *> adj = d.get_all_adjacent(d.board[0]);
  ASSERT_EQ(adj[0], nullptr);
  ASSERT_FALSE((*adj[1]).is_empty_creature());
  ASSERT_TRUE((*adj[2]).is_empty_creature());
  ASSERT_EQ(adj[3], nullptr);
}

TEST(DarwinFixture, get_all_adjacent3) {
  Darwin d(4, 4);
  Species test('t');
  test.add_instruction(hop, 0);
  test.add_instruction(go, 0);
  Creature t1(&test, NORTH);
  d.add_creature(t1, 2, 2);
  vector<Creature *> adj = d.get_all_adjacent(d.board[10]);
  ASSERT_TRUE((*adj[0]).is_empty_creature());
  ASSERT_TRUE((*adj[1]).is_empty_creature());
  ASSERT_TRUE((*adj[2]).is_empty_creature());
  ASSERT_TRUE((*adj[3]).is_empty_creature());
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, darwin_start1) {
  Darwin d(4, 4);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, SOUTH);
  d.add_creature(t1, 0, 0);
  ASSERT_EQ(d.turn_count, 0);
  d.start();
  ASSERT_EQ(d.turn_count, 1);
  ASSERT_FALSE(d.board[4].is_empty_creature());
  ASSERT_TRUE(d.turn_board[4] = d.turn_count);
}

TEST(DarwinFixture, darwin_start2) {
  Darwin d(10, 10);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, EAST);
  d.add_creature(t1, 0, 0);
  ASSERT_EQ(d.turn_count, 0);
  d.start();
  d.start();
  d.start();
  d.start();
  ASSERT_EQ(d.turn_count, 4);
  ASSERT_FALSE(d.board[4].is_empty_creature());
  ASSERT_TRUE(d.turn_board[4] = d.turn_count);
}

TEST(DarwinFixture, darwin_start3) {
  Darwin d(4, 4);
  for (int i = 0; i < 20; ++i) {
    d.start();
  }
  ASSERT_EQ(d.turn_count, 20);
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, darwin_hop1) {
  Darwin d(5, 5);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, EAST);
  d.add_creature(t1, 0, 0);
  d.do_hop(d.board[0], &d.board[1]);
  ASSERT_TRUE(d.board[0].is_empty_creature());
  ASSERT_FALSE(d.board[1].is_empty_creature());
}

TEST(DarwinFixture, darwin_hop2) {
  Darwin d(10, 10);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, WEST);
  d.add_creature(t1, 2, 2);
  d.do_hop(d.board[22], &d.board[21]);
  ASSERT_TRUE(d.board[22].is_empty_creature());
  ASSERT_FALSE(d.board[21].is_empty_creature());
}

TEST(DarwinFixture, darwin_hop3) {
  Darwin d(2, 2);
  Species test('t');
  test.add_instruction(hop, 0);
  Creature t1(&test, SOUTH);
  d.add_creature(t1, 0, 0);
  d.do_hop(d.board[0], &d.board[2]);
  ASSERT_TRUE(d.board[0].is_empty_creature());
  ASSERT_FALSE(d.board[2].is_empty_creature());
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////

TEST(DarwinFixture, darwin_infect1) {
  Darwin d(6, 6);
  Species test('t');
  test.add_instruction(hop, 0);
  Species infected('i');
  infected.add_instruction(hop, 0);
  Creature t1(&test, EAST);
  Creature t2(&infected, WEST);
  d.add_creature(t1, 0, 1);
  d.add_creature(t2, 0, 0);
  d.do_infect(d.board[0], &d.board[1]);
  ASSERT_EQ((*d.board[0].species), (*d.board[1].species));
  ASSERT_EQ((*d.board[0].species).print_rep, 'i');
  ASSERT_EQ((*d.board[1].species).print_rep, 'i');
}

TEST(DarwinFixture, darwin_infect2) {
  Darwin d(7, 7);
  Species test('t');
  test.add_instruction(hop, 0);
  Species infected('i');
  infected.add_instruction(hop, 0);
  Creature t1(&test, EAST);
  Creature t2(&infected, SOUTH);
  d.add_creature(t1, 1, 0);
  d.add_creature(t2, 0, 0);
  d.do_infect(d.board[0], &d.board[7]);
  ASSERT_EQ((*d.board[0].species), (*d.board[7].species));
  ASSERT_EQ((*d.board[0].species).print_rep, 'i');
  ASSERT_EQ((*d.board[7].species).print_rep, 'i');
}

TEST(DarwinFixture, darwin_infect3) {
  Darwin d(3, 3);
  Species test('t');
  test.add_instruction(hop, 0);
  Species infected('i');
  infected.add_instruction(hop, 0);
  Creature t1(&test, EAST);
  Creature t2(&infected, WEST);
  d.add_creature(t1, 0, 1);
  d.add_creature(t2, 0, 0);
  d.do_infect(d.board[1], &d.board[0]);
  ASSERT_EQ((*d.board[1].species), (*d.board[1].species));
  ASSERT_EQ((*d.board[1].species).print_rep, 't');
  ASSERT_EQ((*d.board[0].species).print_rep, 't');
}

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////