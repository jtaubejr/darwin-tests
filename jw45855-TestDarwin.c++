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

using namespace std;

// ----
// test
// ----

TEST(DarwinFixture, darwin_constructor_1) {
    Darwin x(8, 8);
    ASSERT_EQ(x.num_rows,8);
    ASSERT_EQ(x.num_cols,8);
}

TEST(DarwinFixture, darwin_constructor_2) {
    try {
        Darwin x(0,0);
        ASSERT_EQ(true, false);
    } 
    catch (std::invalid_argument &e) {
        ASSERT_EQ(true, true);
    }
}

TEST(DarwinFixture, darwin_constructor_3) {
    try {
        Darwin x(-1,-1);
        ASSERT_EQ(true, false);
    } 
    catch (std::invalid_argument &e) {
        ASSERT_EQ(true, true);
    }
}

TEST(DarwinFixture, darwin_constructor_4) {
    Darwin x(5, 8);
    ASSERT_EQ(x.grid.size(), 5);
    ASSERT_EQ(x.grid[0].size(), 8);
}

TEST(DarwinFixture, add_creature_1) {
    try {
        Darwin x(8, 8);
        Species default_species;
        Creature test = Creature(&default_species, NORTH);
        x.add_creature(&test, 4, 4);
        ASSERT_EQ(&test, x.grid[4][4]);
        ASSERT_EQ(true, true);
    }
    catch (std::invalid_argument &e) {
        ASSERT_EQ(true, false);
    }
}

TEST(DarwinFixture, add_creature_2) {
    try {
        Darwin x(8, 8);
        Species default_species;
        Creature test = Creature(&default_species, NORTH);
        x.add_creature(&test, 8, 8);
        ASSERT_EQ(true, false);
    }
    catch (std::invalid_argument &e) {
        ASSERT_EQ(true, true);
    }
}

TEST(DarwinFixture, add_creature_3) {
    try {
        Darwin x(8, 8);
        Species default_species;
        Creature test = Creature(&default_species, NORTH);
        x.add_creature(&test, -1, -1);
        ASSERT_EQ(true, false);
    }
    catch (std::invalid_argument &e) {
        ASSERT_EQ(true, true);
    }
}

TEST(DarwinFixture, grab_neighbors_1) {
    Darwin x(8, 8);
    Species default_species;
    Creature test = Creature(&default_species, NORTH);
    Creature test2 = Creature(&default_species, NORTH);
    Creature test3 = Creature(&default_species, NORTH);
    Creature test4 = Creature(&default_species, NORTH);
    Creature test5 = Creature(&default_species, NORTH);
    x.add_creature(&test, 4, 4);
    x.add_creature(&test2, 3, 4);
    x.add_creature(&test3, 5, 4);
    x.add_creature(&test4, 4, 3);
    x.add_creature(&test5, 4, 5);
    Creature* neighbors[4];
    x.grab_neighbors(neighbors, 4, 4);
    ASSERT_EQ(neighbors[WEST], &test4);
    ASSERT_EQ(neighbors[NORTH], &test2);
    ASSERT_EQ(neighbors[SOUTH], &test3);
    ASSERT_EQ(neighbors[EAST], &test5);
}

TEST(DarwinFixture, grab_neighbors_2) {
    Darwin x(8, 8);
    Species default_species;
    Creature test = Creature(&default_species, NORTH);
    Creature test2 = Creature(&default_species, NORTH);
    Creature test3 = Creature(&default_species, NORTH);
    x.add_creature(&test, 1, 0);
    x.add_creature(&test2, 0, 0);
    x.add_creature(&test3, 1, 1);
    Creature* neighbors[4];
    x.grab_neighbors(neighbors, 1, 0);
    ASSERT_TRUE(neighbors[WEST] == NULL);
    ASSERT_EQ(neighbors[NORTH], &test2);
    ASSERT_TRUE(neighbors[SOUTH] == NULL);
    ASSERT_EQ(neighbors[EAST], &test3);
    cout << "WE GET HERE" << endl;
}

TEST(DarwinFixture, grab_neighbors_3) {
    Darwin x(8, 8);
    Species default_species;
    Creature test = Creature(&default_species, NORTH);
    Creature test2 = Creature(&default_species, NORTH);
    Creature test3 = Creature(&default_species, NORTH);
    x.add_creature(&test, 0, 7);
    x.add_creature(&test2, 1, 7);
    x.add_creature(&test3, 0, 6);
    Creature* neighbors[4];
    x.grab_neighbors(neighbors, 0, 7);
    ASSERT_TRUE(neighbors[NORTH] == NULL);
    ASSERT_EQ(neighbors[SOUTH], &test2);
    ASSERT_TRUE(neighbors[EAST] == NULL);
    ASSERT_EQ(neighbors[WEST], &test3);
}


TEST(CreatureFixture, creature_default_1) {
    Creature test = Creature();
    ASSERT_TRUE(test.type == NULL);
}

TEST(CreatureFixture, creature_default_2) {
    Creature test = Creature();
    ASSERT_EQ(test.steps_done, 0);
}

TEST(CreatureFixture, creature_default_3) {
    Creature test = Creature();
    ASSERT_EQ(test.pc, 0);
}

TEST(CreatureFixture, creature_constructor_1) {
    Species default_species;
    Creature test = Creature(&default_species, NORTH);
    ASSERT_EQ(test.dir, NORTH);
    ASSERT_TRUE(test.is_empty());
}

TEST(CreatureFixture, creature_constructor_2) {
    Species default_species;
    Creature test = Creature(&default_species, WEST);
    ASSERT_TRUE(test.dir == WEST);
    ASSERT_TRUE(test.is_empty());
}

TEST(CreatureFixture, creature_constructor_3) {
    Species test_species("h");
    Creature test = Creature(&test_species, NORTH);
    ASSERT_TRUE(test.dir == NORTH);
    ASSERT_TRUE(test.type->name == "h");
    ASSERT_FALSE(test.is_empty());
}

TEST(CreatureFixture, creature_overload_1) {
    Species default_species;
    Creature test = Creature(&default_species, NORTH);
    ostringstream w;
    w << &test;
    ASSERT_EQ(w.str(), ".");
}

TEST(CreatureFixture, creature_overload_2) {
    Species s("f");
    Creature test = Creature(&s, NORTH);
    ostringstream w;
    w << &test;
    ASSERT_EQ(w.str(), "f");
}

TEST(CreatureFixture, creature_overload_3) {
    Species s("hello");
    Creature test = Creature(&s, NORTH);
    ostringstream w;
    w << &test;
    ASSERT_EQ(w.str(), "hello");
}

TEST(CreatureFixture, turn_left_1) {
    Species default_species;
    Creature test = Creature(&default_species, WEST);
    test.turn_left();
    ASSERT_EQ(test.dir, SOUTH);
}

TEST(CreatureFixture, turn_left_2) {
    Species default_species;
    Creature test = Creature(&default_species, NORTH);
    test.turn_left();
    ASSERT_EQ(test.dir, WEST);
}

TEST(CreatureFixture, turn_left_3) {
    Species default_species;
    Creature test = Creature(&default_species, SOUTH);
    test.turn_left();
    ASSERT_EQ(test.dir, EAST);
}

TEST(CreatureFixture, turn_left_4) {
    Species default_species;
    Creature test = Creature(&default_species, EAST);
    test.turn_left();
    ASSERT_EQ(test.dir, NORTH);
}

TEST(CreatureFixture, turn_right_1) {
    Species default_species;
    Creature test = Creature(&default_species, WEST);
    test.turn_right();
    ASSERT_EQ(test.dir, NORTH);
}

TEST(CreatureFixture, turn_right_2) {
    Species default_species;
    Creature test = Creature(&default_species, NORTH);
    test.turn_right();
    ASSERT_EQ(test.dir, EAST);
}

TEST(CreatureFixture, turn_right_3) {
    Species default_species;
    Creature test = Creature(&default_species, SOUTH);
    test.turn_right();
    ASSERT_EQ(test.dir, WEST);
}

TEST(CreatureFixture, turn_right_4) {
    Species default_species;
    Creature test = Creature(&default_species, EAST);
    test.turn_right();
    ASSERT_EQ(test.dir, SOUTH);
}

TEST(CreatureFixture, is_empty_1) {
    Species default_species;
    Creature test = Creature(&default_species, WEST);
    ASSERT_TRUE(test.is_empty());
}

TEST(CreatureFixture, is_empty_2) {
    Species s("hello");
    Creature test = Creature(&s, WEST);
    ASSERT_FALSE(test.is_empty());
}

TEST(CreatureFixture, is_empty_3) {
    Species s("f");
    Creature test = Creature(&s, WEST);
    ASSERT_FALSE(test.is_empty());
}

TEST(CreatureFixture, is_enemy_1) {
    Species default_species;
    Creature first = Creature(&default_species, WEST);
    Creature second = Creature(&default_species, WEST);
    ASSERT_FALSE(first.is_enemy(&second));
}

TEST(CreatureFixture, is_enemy_2) {
    Species default_species;
    Species s("f");
    Creature first = Creature(&default_species, WEST);
    Creature second = Creature(&s, WEST);
    ASSERT_TRUE(second.is_enemy(&first));
}

TEST(CreatureFixture, is_enemy_3) {
    Species default_species;
    Species s("roy");
    Creature first = Creature(&default_species, WEST);
    Creature second = Creature(&s, WEST);
    ASSERT_TRUE(first.is_enemy(&second));
}

TEST(CreatureFixture, hop_1) {
    Darwin x(8, 8);
    Species hopper("h");
    Species default_species;
    Creature hopper1 = Creature(&hopper, NORTH);
    Creature default1 = Creature(&default_species, NORTH);
    x.add_creature(&hopper1, 3, 3);
    x.add_creature(&default1, 2, 3);
    hopper1.hop(&default1);
    ASSERT_EQ(default1.type->name, "h");
    ASSERT_EQ(hopper1.type->name, ".");
    ASSERT_TRUE(hopper1.is_empty());
}


TEST(CreatureFixture, hop_2) {
    Darwin x(8, 8);
    Species hopper("h");
    Species default_species;
    Creature hopper1 = Creature(&hopper, NORTH);
    Creature default1 = Creature(&default_species, NORTH);
    Creature default2 = Creature(&default_species, NORTH);
    x.add_creature(&hopper1, 3, 3);
    x.add_creature(&default1, 2, 3);
    x.add_creature(&default2, 1, 3);
    hopper1.hop(&default1);
    default1.hop(&default2);
    ASSERT_EQ(default2.type->name, "h");
    ASSERT_EQ(default1.type->name, ".");
    ASSERT_EQ(hopper1.type->name, ".");
}

TEST(CreatureFixture, hop_3) {
    Darwin x(8, 8);
    Species hopper("h");
    Species default_species;
    Creature hopper1 = Creature(&hopper, NORTH);
    Creature hopper2 = Creature(&hopper, NORTH);
    x.add_creature(&hopper1, 3, 3);
    x.add_creature(&hopper2, 2, 3);
    hopper1.hop(&hopper2);
    ASSERT_EQ(hopper2.type->name, "h");
    ASSERT_EQ(hopper1.type->name, "h");
}


TEST(CreatureFixture, infect_1) {
    Darwin x(8, 8);
    Species hopper("h");
    Species lol("l");
    Creature hopper1 = Creature(&hopper, NORTH);
    Creature lol1 = Creature(&lol, NORTH);
    lol1.pc = 100;
    x.add_creature(&hopper1, 3, 3);
    x.add_creature(&lol1, 2, 3);
    hopper1.infect(&lol1);
    ASSERT_EQ(lol1.type->name, "h");
    ASSERT_EQ(lol1.pc, 0);
    ASSERT_EQ(hopper1.type->name, "h");
}

TEST(CreatureFixture, infect_2) {
    Darwin x(8, 8);
    Species hopper("h");
    Creature hopper1 = Creature(&hopper, NORTH);
    Creature hopper2 = Creature(&hopper, NORTH);
    hopper2.pc = 100;
    x.add_creature(&hopper1, 3, 3);
    x.add_creature(&hopper2, 2, 3);
    hopper2.infect(&hopper1);
    ASSERT_EQ(hopper2.pc, 100);
}

TEST(SpeciesFixture, species_default_1) {
    Species default_species;
    ASSERT_EQ(default_species.name, ".");
}

TEST(SpeciesFixture, species_default_2) {
    Species default_species;
    ASSERT_EQ(default_species.instructions.size(), 0);
}

TEST(SpeciesFixture, species_constructor_1) {
    Species s("lol");
    ASSERT_EQ(s.name, "lol");
}

TEST(SpeciesFixture, species_constructor_2) {
    Species s("swag");
    ASSERT_EQ(s.name, "swag");
}

TEST(SpeciesFixture, species_constructor_3) {
    Species s("roy");
    ASSERT_EQ(s.name, "roy");
}

TEST(SpeciesFixture, species_overload_1) {
    Species default_species;
    ostringstream w;
    w << &default_species;
    ASSERT_EQ(w.str(), ".");
}

TEST(SpeciesFixture, species_overload_2) {
    Species h("h");
    ostringstream w;
    w << &h;
    ASSERT_EQ(w.str(), "h");
}

TEST(SpeciesFixture, species_overload_3) {
    Species lol("lol");
    ostringstream w;
    w << &lol;
    ASSERT_EQ(w.str(), "lol");
}

TEST(SpeciesFixture, add_instruction_1) {
    Species lol("lol");
    lol.add_instruction(make_pair(HOP, 0));
    ASSERT_EQ(lol.instructions.size(), 1);
}

TEST(SpeciesFixture, add_instruction_2) {
    Species default_species;
    default_species.add_instruction(make_pair(HOP, 0));
    ASSERT_EQ(true, true);
}

TEST(SpeciesFixture, add_instruction_3) {
    Species lol("lol");
    lol.add_instruction(make_pair(HOP, 0));
    lol.add_instruction(make_pair(HOP, 0));
    lol.add_instruction(make_pair(HOP, 0));
    lol.add_instruction(make_pair(HOP, 0));
    lol.add_instruction(make_pair(HOP, 0));
    ASSERT_EQ(lol.instructions.size(), 5);
}

TEST(SpeciesFixture, is_default_1) {
    Species lol("lol");
    bool result = lol.is_default();
    ASSERT_EQ(result, false);
}

TEST(SpeciesFixture, is_default_2) {
    Species default_species;
    bool result = default_species.is_default();
    ASSERT_EQ(result, true);
}

TEST(SpeciesFixture, is_default_3) {
    Species f("f");
    bool result = f.is_default();
    ASSERT_EQ(result, false);
}

TEST(SpeciesFixture, is_same_1) {
    Species f("f");
    Species h("h");
    bool result = f.is_same(&h);
    ASSERT_EQ(result, false);
}

TEST(SpeciesFixture, is_same_2) {
    Species f("f");
    Species f1("f");
    bool result = f.is_same(&f);
    ASSERT_EQ(result, true);
}

TEST(SpeciesFixture, is_same_3) {
    Species default_species;
    bool result = default_species.is_same(&default_species);
    ASSERT_EQ(result, true);
}

TEST(SpeciesFixture, species_step_1) {
    Darwin x(8, 8);
    Species hopper("h");
    Species default_species;
    hopper.add_instruction(make_pair(HOP, 0));
    Creature hopper1 = Creature(&hopper, NORTH);
    Creature default1 = Creature(&default_species, NORTH);
    x.add_creature(&hopper1, 3, 3);
    x.add_creature(&default1, 2, 3);
    int result = hopper.step(0, &hopper1, &default1);
    ASSERT_EQ(default1.type->name, "h");
    ASSERT_EQ(hopper1.type->name, ".");
    ASSERT_TRUE(hopper1.is_empty());
    ASSERT_EQ(result, 1);
}

TEST(SpeciesFixture, species_step_2) {
    Darwin x(8, 8);
    Species hopper("h");
    Species f("f");
    hopper.add_instruction(make_pair(INFECT, 0));
    Creature hopper1 = Creature(&hopper, NORTH);
    Creature f1 = Creature(&f, NORTH);
    x.add_creature(&hopper1, 3, 3);
    x.add_creature(&f1, 2, 3);
    int result = hopper.step(0, &hopper1, &f1);
    ASSERT_EQ(f1.type->name, "h");
    ASSERT_EQ(hopper1.type->name, "h");
    ASSERT_EQ(result, 1);
}

TEST(SpeciesFixture, species_step_3) {
    Darwin x(8, 8);
    Species hopper("h");
    Species default_species;
    hopper.add_instruction(make_pair(LEFT, 0));
    Creature hopper1 = Creature(&hopper, NORTH);
    Creature default1 = Creature(&default_species, NORTH);
    x.add_creature(&hopper1, 3, 3);
    x.add_creature(&default1, 2, 3);
    int result = hopper.step(0, &hopper1, &default1);
    ASSERT_EQ(hopper1.dir, WEST);
    ASSERT_EQ(result, 1);
}

TEST(SpeciesFixture, species_step_4) {
    Darwin x(8, 8);
    Species hopper("h");
    Species default_species;
    hopper.add_instruction(make_pair(RIGHT, 0));
    Creature hopper1 = Creature(&hopper, NORTH);
    Creature default1 = Creature(&default_species, NORTH);
    x.add_creature(&hopper1, 3, 3);
    x.add_creature(&default1, 2, 3);
    int result = hopper.step(0, &hopper1, &default1);
    ASSERT_EQ(hopper1.dir, EAST);
    ASSERT_EQ(result, 1);
}




