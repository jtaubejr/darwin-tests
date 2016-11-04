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
// Species
// ----

// Test for valid actions
TEST(DarwinFixture, species_add_action_1) {
  Species s = Species('a');
  s.add_action(HOP);
  ASSERT_TRUE(1 == 1);
}

TEST(DarwinFixture, species_add_action_2) {
  Species s = Species('a');
  s.add_action(LEFT);
  ASSERT_TRUE(1 == 1);
}

TEST(DarwinFixture, species_add_action_3) {
  Species s = Species('a');
  s.add_action(RIGHT);
  ASSERT_TRUE(1 == 1);
}

TEST(DarwinFixture, species_add_action_4) {
  Species s = Species('a');
  s.add_action(INFECT);
  ASSERT_TRUE(1 == 1);
}

// Test for valid controls
TEST(DarwinFixture, species_add_control_1) {
  Species s = Species('a');
  s.add_control(IF_EMPTY, 1);
  ASSERT_TRUE(1 == 1);
}

TEST(DarwinFixture, species_add_control_2) {
  Species s = Species('a');
  s.add_control(IF_WALL, 1);
  ASSERT_TRUE(1 == 1);
}

TEST(DarwinFixture, species_add_control_3) {
  Species s = Species('a');
  s.add_control(IF_ENEMY, 1);
  ASSERT_TRUE(1 == 1);
}

TEST(DarwinFixture, species_add_control_4) {
  Species s = Species('a');
  s.add_control(IF_RANDOM, 1);
  ASSERT_TRUE(1 == 1);
}

TEST(DarwinFixture, species_add_control_5) {
  Species s = Species('a');
  s.add_control(GO, 1);
  ASSERT_TRUE(1 == 1);
}

// ----
// Creature
// ----

// Tile in front
TEST(DarwinFixture, creature_tile_in_front_1) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, NORTH);
  std::pair<int, int> tile = c.tile_in_front(1, 1, 10, 10);
  ASSERT_EQ(tile, std::make_pair(0, 1));
}

TEST(DarwinFixture, creature_tile_in_front_2) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, EAST);
  std::pair<int, int> tile = c.tile_in_front(1, 1, 10, 10);
  ASSERT_EQ(tile, std::make_pair(1, 2));
}

TEST(DarwinFixture, creature_tile_in_front_3) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, WEST);
  std::pair<int, int> tile = c.tile_in_front(0, 0, 10, 10);
  ASSERT_EQ(tile, std::make_pair(-1, -1));
}

TEST(DarwinFixture, creature_tile_in_front_4) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, WEST);
  std::pair<int, int> tile = c.tile_in_front(0, 0, 10, 10);
  ASSERT_EQ(tile, std::make_pair(-1, -1));
}

TEST(DarwinFixture, creature_tile_in_front_5) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, EAST);
  std::pair<int, int> tile = c.tile_in_front(10, 10, 10, 10);
  ASSERT_EQ(tile, std::make_pair(-1, -1));
}

TEST(DarwinFixture, creature_tile_in_front_6) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, WEST);
  std::pair<int, int> tile = c.tile_in_front(1, 0, 10, 10);
  ASSERT_EQ(tile, std::make_pair(-1, -1));
}

TEST(DarwinFixture, creature_tile_in_front_7) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, NORTH);
  std::pair<int, int> tile = c.tile_in_front(1, 0, 10, 10);
  ASSERT_EQ(tile, std::make_pair(0, 0));
}

TEST(DarwinFixture, creature_tile_in_front_8) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, EAST);
  std::pair<int, int> tile = c.tile_in_front(10, 10, 10, 10);
  ASSERT_EQ(tile, std::make_pair(-1, -1));
}

TEST(DarwinFixture, creature_tile_in_front_9) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, EAST);
  std::pair<int, int> tile = c.tile_in_front(0, 0, 10, 10);
  ASSERT_EQ(tile, std::make_pair(0, 1));
}

// Infection
TEST(DarwinFixture, creature_infect_1) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Species t = Species('b');
  t.add_action(HOP);
  t.add_control(GO, 0);

  Creature a = Creature(&s, WEST);
  Creature b = Creature(&t, NORTH);
  a.infect(&b);

  ASSERT_EQ(b._species, &s);
}

TEST(DarwinFixture, creature_infect_2) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Species t = Species('b');
  t.add_action(HOP);
  t.add_control(GO, 0);

  Creature a = Creature(&s, WEST);
  Creature b = Creature(&s, NORTH);
  a.infect(&b);

  ASSERT_EQ(b._species, &s);
}

TEST(DarwinFixture, creature_infect_3) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Species t = Species('b');
  t.add_action(HOP);
  t.add_control(GO, 0);

  Creature a = Creature(&s, WEST);
  Creature b = Creature(&t, NORTH);
  b._counter = 1;

  a.infect(&b);

  ASSERT_EQ(b._counter, 0);
}

TEST(DarwinFixture, creature_infect_4) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);
  s.add_action(INFECT);
  s.add_control(GO, 0);

  Species t = Species('b');
  t.add_action(HOP);
  t.add_control(GO, 0);

  Creature a = Creature(&s, WEST);
  Creature b = Creature(&t, NORTH);
  b._counter = 3;

  a.infect(&b);

  ASSERT_EQ(b._counter, 0);
}

TEST(DarwinFixture, creature_infect_5) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature a = Creature(&s, WEST);
  Creature b = Creature(&s, NORTH);
  b._counter = 1;

  a.infect(&b);

  ASSERT_EQ(b._counter, 1);
}

TEST(DarwinFixture, creature_infect_6) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Species t = Species('b');
  t.add_action(HOP);
  t.add_control(GO, 0);

  Species u = Species('c');
  u.add_action(HOP);
  u.add_control(GO, 0);

  Creature a = Creature(&s, WEST);
  Creature b = Creature(&t, NORTH);
  Creature c = Creature(&u, EAST);

  a.infect(&b);
  a.infect(&c);

  ASSERT_EQ(b._species, &s);
  ASSERT_EQ(c._species, &s);
}

TEST(DarwinFixture, creature_infect_7) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Species t = Species('b');
  t.add_action(HOP);
  t.add_control(GO, 0);

  Species u = Species('c');
  u.add_action(HOP);
  u.add_control(GO, 0);

  Creature a = Creature(&s, WEST);
  Creature b = Creature(&t, NORTH);
  Creature c = Creature(&u, EAST);

  a.infect(&b);
  b.infect(&c);

  ASSERT_EQ(b._species, &s);
  ASSERT_EQ(c._species, &s);
}

TEST(DarwinFixture, creature_infect_8) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Species t = Species('b');
  t.add_action(HOP);
  t.add_control(GO, 0);

  Species u = Species('c');
  u.add_action(HOP);
  u.add_control(GO, 0);

  Creature a = Creature(&s, WEST);
  Creature b = Creature(&t, NORTH);
  Creature c = Creature(&u, EAST);

  a.infect(&b);
  c.infect(&b);

  ASSERT_EQ(b._species, &u);
}

// Turn left
TEST(DarwinFixture, creature_turn_left_1) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, EAST);
  c.turn_left();

  ASSERT_EQ(c._direction, NORTH);
}

TEST(DarwinFixture, creature_turn_left_2) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, NORTH);
  c.turn_left();

  ASSERT_EQ(c._direction, WEST);
}

TEST(DarwinFixture, creature_turn_left_3) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, WEST);
  c.turn_left();

  ASSERT_EQ(c._direction, SOUTH);
}

TEST(DarwinFixture, creature_turn_left_4) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, SOUTH);
  c.turn_left();

  ASSERT_EQ(c._direction, EAST);
}

// Turn right
TEST(DarwinFixture, creature_turn_right_1) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, SOUTH);
  c.turn_right();

  ASSERT_EQ(c._direction, WEST);
}

TEST(DarwinFixture, creature_turn_right_2) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, WEST);
  c.turn_right();

  ASSERT_EQ(c._direction, NORTH);
}

TEST(DarwinFixture, creature_turn_right_3) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, NORTH);
  c.turn_right();

  ASSERT_EQ(c._direction, EAST);
}

TEST(DarwinFixture, creature_turn_right_4) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Creature c = Creature(&s, EAST);
  c.turn_right();

  ASSERT_EQ(c._direction, SOUTH);
}

// ----
// Darwin
// ----

// Add creatures
TEST(DarwinFixture, add_creature_1) {
  Darwin<10, 10> darwin;
  ASSERT_EQ(darwin._creatures.size(), 0);
}

TEST(DarwinFixture, add_creature_2) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Darwin<8, 8> d;
  d.add_creature(s, NORTH, 1, 1);
  ASSERT_EQ(d._creatures.size(), 1);
}

TEST(DarwinFixture, add_creature_3) {
  Species s = Species('a');
  s.add_action(HOP);
  s.add_control(GO, 0);

  Darwin<8, 8> d;
  d.add_creature(s, NORTH, 1, 1);
  d.add_creature(s, NORTH, 2, 1);
  d.add_creature(s, NORTH, 3, 1);
  d.add_creature(s, NORTH, 4, 1);
  ASSERT_EQ(d._creatures.size(), 4);
}

TEST(DarwinFixture, add_creature_4) {
  Species s = Species('a');
  Species t = Species('b');

  Darwin<8, 8> d;
  d.add_creature(s, NORTH, 1, 1);
  d.add_creature(t, EAST, 5, 5);
  ASSERT_EQ(d._creatures.size(), 2);
}

TEST(DarwinFixture, add_creature_5) {
  Species s = Species('a');
  Species t = Species('b');
  Species u = Species('c');
  u.add_control(GO, 1);

  Darwin<8, 8> d;
  d.add_creature(s, NORTH, 1, 1);
  d.add_creature(t, EAST, 5, 5);
  d.add_creature(u, NORTH, 1, 2);
  d.add_creature(u, EAST, 5, 2);
  ASSERT_EQ(d._creatures.size(), 4);
}

// Simulate
TEST(DarwinFixture, simulate) {
  Species food = Species('f');
  food.add_action(LEFT);
  food.add_control(GO, 0);

  Species hopper = Species('h');
  hopper.add_action(HOP);
  hopper.add_control(GO, 0);

  Species rover = Species('r');
  rover.add_control(IF_ENEMY, 9);
  rover.add_control(IF_EMPTY, 7);
  rover.add_control(IF_RANDOM, 5);
  rover.add_action(LEFT);
  rover.add_control(GO, 0);
  rover.add_action(RIGHT);
  rover.add_control(GO, 0);
  rover.add_action(HOP);
  rover.add_control(GO, 0);
  rover.add_action(INFECT);
  rover.add_control(GO, 0);

  Species trap = Species('t');
  trap.add_control(IF_ENEMY, 3);
  trap.add_action(LEFT);
  trap.add_control(GO, 0);
  trap.add_action(INFECT);
  trap.add_control(GO, 0);

  Darwin<8, 8> d8x8;
  d8x8.add_creature(food, EAST, 0, 0);
  d8x8.add_creature(hopper, NORTH, 3, 3);
  d8x8.add_creature(hopper, EAST, 3, 4);
  d8x8.add_creature(hopper, SOUTH, 4, 4);
  d8x8.add_creature(hopper, WEST, 4, 3);
  d8x8.add_creature(food, NORTH, 7, 7);

  for (int i = 0; i < 5; i++) {
    d8x8.simulate();
  }

  Creature c1 = d8x8._creatures[std::make_pair(0, 0)];
  ASSERT_EQ(c1._species, &food);

  Creature c2 = d8x8._creatures[std::make_pair(0, 3)];
  ASSERT_EQ(c2._species, &hopper);

  Creature c3 = d8x8._creatures[std::make_pair(3, 7)];
  ASSERT_EQ(c3._species, &hopper);

  Creature c4 = d8x8._creatures[std::make_pair(4, 0)];
  ASSERT_EQ(c4._species, &hopper);

  Creature c5 = d8x8._creatures[std::make_pair(7, 4)];
  ASSERT_EQ(c5._species, &hopper);

  Creature c6 = d8x8._creatures[std::make_pair(7, 7)];
  ASSERT_EQ(c6._species, &food);
}
