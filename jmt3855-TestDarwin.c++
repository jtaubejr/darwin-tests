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

// -------
// Species
// -------

TEST(SpeciesFixture, AddingInstructions1) {
    Species f('f');
    f.add_instruction (instructions::left, 0);
    f.add_instruction (instructions::go, 0);

    ASSERT_EQ(f.instruction_set[0], instructions::left);
    ASSERT_EQ(f.instruction_set[1], instructions::go);
    ASSERT_EQ(f.is_additional[1], 0);
}

TEST(SpeciesFixture, AddingInstructions2) {
    Species h('h');
    h.add_instruction (instructions::hop, 0);
    h.add_instruction (instructions::go, 0);

    ASSERT_EQ(h.instruction_set[0], instructions::hop);
    ASSERT_EQ(h.instruction_set[1], instructions::go);
    ASSERT_EQ(h.is_additional[1], 0);
}

TEST(SpeciesFixture, AddingInstructions3) {
    Species r('r');
    r.add_instruction (instructions::if_enemy, 9);
    r.add_instruction (instructions::if_empty, 7);
    r.add_instruction (instructions::if_random, 5);
    r.add_instruction (instructions::left, 0);
    r.add_instruction (instructions::go, 0);
    r.add_instruction (instructions::right, 0);
    r.add_instruction (instructions::go, 0);
    r.add_instruction (instructions::hop, 0);
    r.add_instruction (instructions::go, 0);
    r.add_instruction (instructions::infect, 0);
    r.add_instruction (instructions::go, 0);

    ASSERT_EQ(r.instruction_set[0], instructions::if_enemy);
    ASSERT_EQ(r.is_additional[0], 9);
    ASSERT_EQ(r.instruction_set[1], instructions::if_empty);
    ASSERT_EQ(r.is_additional[1], 7);
    ASSERT_EQ(r.instruction_set[2], instructions::if_random);
    ASSERT_EQ(r.is_additional[2], 5);
    ASSERT_EQ(r.instruction_set[3], instructions::left);
    ASSERT_EQ(r.instruction_set[4], instructions::go);
    ASSERT_EQ(r.is_additional[4], 0);
    ASSERT_EQ(r.instruction_set[5], instructions::right);
    ASSERT_EQ(r.instruction_set[6], instructions::go);
    ASSERT_EQ(r.is_additional[6], 0);
    ASSERT_EQ(r.instruction_set[7], instructions::hop);
    ASSERT_EQ(r.instruction_set[8], instructions::go);
    ASSERT_EQ(r.is_additional[8], 0);
    ASSERT_EQ(r.instruction_set[9], instructions::infect);
    ASSERT_EQ(r.instruction_set[10], instructions::go);
    ASSERT_EQ(r.is_additional[10], 0);
}

TEST(CreatureFixture, CreatureConstructor1) {
    Species f('f');
    f.add_instruction (instructions::left, 0);
    f.add_instruction (instructions::go, 0);

    Creature food1(f, direction::West);
    Creature food2(f, direction::North);
    Creature food3(f, direction::East);
    Creature food4(f, direction::South);

    ASSERT_EQ(food1.direction, 0);
    ASSERT_EQ(food1.program_counter, 0);
    ASSERT_EQ(food2.direction, 1);
    ASSERT_EQ(food2.program_counter, 0);
    ASSERT_EQ(food3.direction, 2);
    ASSERT_EQ(food3.program_counter, 0);
    ASSERT_EQ(food4.direction, 3);
    ASSERT_EQ(food4.program_counter, 0);
}

TEST(DarwinFixture, World1) {
    Darwin world (2, 2, 1);

    ASSERT_EQ(world.rows, 2);
    ASSERT_EQ(world.columns, 2);
    ASSERT_EQ(world.turn, 1);
}

TEST(DarwinFixture, World2) {
    Darwin world (7, 11, 10);

    ASSERT_EQ(world.rows, 7);
    ASSERT_EQ(world.columns, 11);
    ASSERT_EQ(world.turn, 10);
}

TEST(DarwinFixture, AddCreature1) {
    Species f('f');
    f.add_instruction (instructions::left, 0);
    f.add_instruction (instructions::go, 0);

    Darwin world (2, 2, 1);
    Creature food1(f, direction::West);
    world.add_creature(food1, 0, 0);
    world.execute_program();

    assert(world.world[0][0] != NULL);
    assert(world.world[0][1] == NULL);
}

TEST(DarwinFixture, AddCreature2) {
    Species f('f');
    f.add_instruction (instructions::left, 0);
    f.add_instruction (instructions::go, 0);

    Darwin world (2, 2, 1);
    Creature food1(f, direction::West);
    Creature food2(f, direction::North);
    Creature food3(f, direction::East);
    Creature food4(f, direction::South);
    world.add_creature(food1, 0, 0);
    world.add_creature(food2, 0, 1);
    world.add_creature(food3, 1, 0);
    world.add_creature(food4, 1, 1);
    world.execute_program();

    assert(world.world[0][0] != NULL);
    assert(world.world[0][1] != NULL);
    assert(world.world[1][0] != NULL);
    assert(world.world[1][1] != NULL);
}

TEST(DarwinFixture, Hop1) {
    Species h('h');
    h.add_instruction (instructions::hop, 0);
    h.add_instruction (instructions::go, 0);

    Darwin world (2, 2, 1);
    Creature hop1(h, direction::South);
    world.add_creature(hop1, 0, 0);
    world.execute_program();

    assert(world.world[1][0] != NULL);
    assert(world.world[0][0] == NULL);
}

TEST(DarwinFixture, Hop2) {
    Species h('h');
    h.add_instruction (instructions::hop, 0);
    h.add_instruction (instructions::go, 0);

    Darwin world (2, 2, 1);
    Creature hop1(h, direction::North);
    world.add_creature(hop1, 1, 1);
    world.execute_program();

    assert(world.world[0][1] != NULL);
    assert(world.world[0][0] == NULL);
}

TEST(DarwinFixture, Hop3) {
    Species h('h');
    h.add_instruction (instructions::hop, 0);
    h.add_instruction (instructions::go, 0);

    Darwin world (2, 2, 1);
    Creature hop1(h, direction::West);
    world.add_creature(hop1, 1, 1);
    world.execute_program();

    assert(world.world[1][0] != NULL);
    assert(world.world[1][1] == NULL);
}

TEST(DarwinFixture, Hop4) {
    Species h('h');
    h.add_instruction (instructions::hop, 0);
    h.add_instruction (instructions::go, 0);

    Darwin world (2, 2, 1);
    Creature hop1(h, direction::East);
    world.add_creature(hop1, 0, 0);
    world.execute_program();

    assert(world.world[0][1] != NULL);
    assert(world.world[0][0] == NULL);
}

TEST(DarwinFixture, LeftHop1) {
    Species l('l');
    l.add_instruction (instructions::hop, 0);
    l.add_instruction (instructions::left, 0);
    l.add_instruction (instructions::go, 0);

    Darwin world (3, 3, 3);
    Creature l1(l, direction::South);
    world.add_creature(l1, 1, 1);
    world.execute_program();

    assert(world.world[2][2] != NULL);
    assert(world.world[1][1] == NULL);
    assert(world.world[2][1] == NULL);
}

TEST(DarwinFixture, RightHop1) {
    Species l('l');
    l.add_instruction (instructions::hop, 0);
    l.add_instruction (instructions::left, 0);
    l.add_instruction (instructions::go, 0);

    Darwin world (3, 3, 3);
    Creature l1(l, direction::South);
    world.add_creature(l1, 1, 1);
    world.execute_program();

    assert(world.world[2][2] != NULL);
    assert(world.world[1][1] == NULL);
    assert(world.world[2][1] == NULL);
}

TEST(DarwinFixture, Infect1) {
    Species t('t');
    t.add_instruction (instructions::if_enemy, 3);
    t.add_instruction (instructions::left, 0);
    t.add_instruction (instructions::go, 0);
    t.add_instruction (instructions::infect, 0);
    t.add_instruction (instructions::go, 0);

    Species h('h');
    h.add_instruction (instructions::hop, 0);
    h.add_instruction (instructions::go, 0);

    Darwin world (1, 3, 3);
    Creature t1(t, direction::West);
    world.add_creature(t1, 0, 0);
    Creature h1(h, direction::West);
    world.add_creature(h1, 0, 2);
    world.execute_program();

    ASSERT_EQ(h1.species.name_symbol, t1.species.name_symbol);
}

TEST(DarwinFixture, IfEmpty) {
    Species c('c');
    c.add_instruction (instructions::if_empty, 2);
    c.add_instruction (instructions::go, 4);
    c.add_instruction (instructions::hop, 0);
    c.add_instruction (instructions::go, 0);
    c.add_instruction (instructions::left, 0);
    c.add_instruction (instructions::hop, 0);

    Species f('f');
    f.add_instruction (instructions::left, 0);
    f.add_instruction (instructions::go, 0);

    Darwin world (4, 4, 3);
    Creature c1(c, direction::South);
    world.add_creature(c1, 1, 2);
    Creature f1(f, direction::North);
    world.add_creature(f1, 3, 2);
    world.execute_program();

    assert(world.world[2][3] != NULL);
}

TEST(DarwinFixture, IfWall) {
    Species h('h');
    h.add_instruction (instructions::if_wall, 3);
    h.add_instruction (instructions::hop, 0);
    h.add_instruction (instructions::go, 0);
    h.add_instruction (instructions::left, 0);
    h.add_instruction (instructions::go, 0);

    Darwin world (4, 4, 4);
    Creature h1(h, direction::East);
    world.add_creature(h1, 2, 1);
    world.execute_program();

    assert(world.world[2][1] == NULL);
    assert(world.world[1][3] != NULL);
}

TEST(DarwinFixture, IfRand) {
    Species r('r');
    r.add_instruction (instructions::if_random, 3);
    r.add_instruction (instructions::hop, 0);
    r.add_instruction (instructions::go, 0);
    r.add_instruction (instructions::left, 0);
    r.add_instruction (instructions::go, 0);

    Darwin world (2, 2, 1);
    Creature r1(r, direction::North);
    world.add_creature(r1, 1, 1);
    world.execute_program();

    if (rand() % 2) {
        assert(world.world[0][1] == NULL);
        assert(world.world[1][1] != NULL);
    }
    else if ((rand() % 2) == 0){
        assert(world.world[0][1] != NULL);
        assert(world.world[1][1] == NULL);
    }
}
