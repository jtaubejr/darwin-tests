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

#define WEST 0
#define NORTH 1
#define EAST 2
#define SOUTH 3

#define HOP 0
#define LEFT 1
#define RIGHT 2
#define INFECT 3

#define EMPTY 0
#define WALL 1
#define ENEMY 2
#define ALLY 3

using namespace std;

// ----
// test
// ----

TEST(DarwinFixture, species_constructor_1) {
    Species a('s');

    ASSERT_TRUE(true);

}
TEST(DarwinFixture, species_constructor_2) {
    ASSERT_TRUE(true);
    Species a('5');

}
TEST(DarwinFixture, species_constructor_3) {
    Species a;
    ASSERT_TRUE(true);

}
TEST(DarwinFixture, species_add_instruction_1) {
    Species a;
    a.add_instruction("left");
    ASSERT_TRUE(true);

}
TEST(DarwinFixture, species_add_instruction_2) {
    Species a;
    a.add_instruction("left");
    a.add_instruction("right");
    a.add_instruction("go 0");
    a.add_instruction("hop");
    a.add_instruction("infect");
    a.add_instruction("if_random");
    ASSERT_TRUE(true);

}
TEST(DarwinFixture, species_add_instruction_3) {
    Species a;
    a.add_instruction("applejuice");
    ASSERT_TRUE(true);

}
TEST(DarwinFixture, species_read_instruction_1) {
    Species a;
    a.add_instruction("left");
    ASSERT_TRUE(!a.read_instruction(0).compare("left"));

}
TEST(DarwinFixture, species_read_instruction_2) {
    Species a;
    a.add_instruction("right");
    a.add_instruction("right");
    a.add_instruction("left");
    ASSERT_TRUE(!a.read_instruction(2).compare("left"));

}
TEST(DarwinFixture, species_read_instruction_3) {
    Species a;
    a.add_instruction("right");
    a.add_instruction("sdfghjk");
    a.add_instruction("left");
    ASSERT_TRUE(!a.read_instruction(1).compare("sdfghjk"));

}
TEST(DarwinFixture, species_print_name_1) {
    Species a;

}
TEST(DarwinFixture, species_print_name_2) {
    Species a('a');

}
TEST(DarwinFixture, species_print_name_3) {
    Species a('@');
}

TEST(DarwinFixture, creature_constructor_1) {
    Species a;
    Creature b(a, NORTH);

}
TEST(DarwinFixture, creature_constructor_2) {
    Species a;
    Creature b(a, SOUTH);

}
TEST(DarwinFixture, creature_constructor_3) {
    Species a;
    Creature b(a, EAST);

}
TEST(DarwinFixture, creature_act_1) {
    Species a;
    a.add_instruction("hop");
    Creature b(a, NORTH);
    int action; int dir;
    b.act(0,0,0,0,action,dir);
    ASSERT_EQ(action,HOP);

}
TEST(DarwinFixture, creature_act_2) {
    Species a;
    a.add_instruction("if_empty 3");
    a.add_instruction("hop");
    a.add_instruction("hop");
    a.add_instruction("infect");
    Creature b(a, NORTH);
    int action; int dir;
    b.act(0,0,0,0,action,dir);
    ASSERT_EQ(action,INFECT);

}
TEST(DarwinFixture, creature_act_3) {
    Species a;
    a.add_instruction("if_enemy 3");
    a.add_instruction("hop");
    a.add_instruction("hop");
    a.add_instruction("infect");
    Creature b(a, NORTH);
    int action; int dir;
    b.act(ENEMY,0,0,0,action,dir);
    ASSERT_EQ(action,INFECT);

}
TEST(DarwinFixture, creature_print_name_1) {
    Species a;
    Creature b(a, NORTH);
    b.print_name();

}
TEST(DarwinFixture, creature_print_name_2) {
    Species a('z');
    Creature b(a, NORTH);
    b.print_name();

}
TEST(DarwinFixture, creature_print_name_3) {
    Species a('8');
    Creature b(a, NORTH);
    b.print_name();

}
TEST(DarwinFixture, creature_same_1) {
    Species a;
    Creature b(a, NORTH);
    Creature c(a, NORTH);
    ASSERT_TRUE(b.is_same_species(&c));

}
TEST(DarwinFixture, creature_same_2) {
    Species a;
    Creature b(a, NORTH);
    Creature c(a, EAST);
    ASSERT_TRUE(b.is_same_species(&c) && c.is_same_species(&b));

}
TEST(DarwinFixture, creature_same_3) {
    Species a;
    Species b;
    Creature c(a, NORTH);
    Creature d(b, WEST);
    ASSERT_FALSE(c.is_same_species(&d) || d.is_same_species(&c));

}
TEST(DarwinFixture, creature_infect_1) {
    Species a;
    Species b;
    Creature c(a, NORTH);
    Creature d(b, WEST);
    ASSERT_FALSE(c.is_same_species(&d) || d.is_same_species(&c));
    c.infect_with(&d);
    ASSERT_TRUE(c.is_same_species(&d) && d.is_same_species(&c));

}
TEST(DarwinFixture, creature_infect_2) {
    Species a;
    Creature c(a, NORTH);
    Creature d(a, WEST);
    ASSERT_TRUE(c.is_same_species(&d) && d.is_same_species(&c));
    c.infect_with(&d);
    ASSERT_TRUE(c.is_same_species(&d) && d.is_same_species(&c));

}
TEST(DarwinFixture, creature_infect_3) {
    Species a;
    Creature c(a, NORTH);
    Creature d(a, WEST);
    ASSERT_TRUE(c.is_same_species(&d) && d.is_same_species(&c));
    d.infect_with(&c);
    ASSERT_TRUE(c.is_same_species(&d) && d.is_same_species(&c));

}

TEST(DarwinFixture, darwin_constructor_1) {
    Darwin x;

}
TEST(DarwinFixture, darwin_constructor_2) {
    Darwin x(0,0);

}
TEST(DarwinFixture, darwin_constructor_3) {
    Darwin x(413,612);

}
TEST(DarwinFixture, darwin_turn_1) {
    Darwin x;
    Species a;
    a.add_instruction("if_random 6");
    a.add_instruction("if_wall 4");
    a.add_instruction("left");
    a.add_instruction("go 0");
    a.add_instruction("right");
    a.add_instruction("go 0");
    a.add_instruction("infect");
    a.add_instruction("go 0");
    Creature b(a, NORTH);
    x.add_creature(b, 4,4);
    x.turn();
    x.turn();
    x.turn();
    x.turn();
    x.turn();
    x.turn();

}
TEST(DarwinFixture, darwin_turn_2) {
    Darwin x;
    Species a;
    a.add_instruction("if_wall 3");
    a.add_instruction("hop");
    a.add_instruction("go 0"); 
    a.add_instruction("left");
    a.add_instruction("go 0");
    Creature b(a, NORTH);
    x.add_creature(b, 4,4);
    x.turn();
    x.turn();
    x.turn();
    x.turn();
    x.turn();
    x.turn();

}
TEST(DarwinFixture, darwin_turn_3) { 
    Darwin x;
    Species a;
    a.add_instruction("left");
    a.add_instruction("go 0");
    Creature b0(a, NORTH);
    Creature b1(a, NORTH);
    Creature b2(a, NORTH);
    Creature b3(a, NORTH);
    x.add_creature(b0, 3,4);
    x.add_creature(b1, 5,4);
    x.add_creature(b2, 4,3);
    x.add_creature(b3, 4,5);

    Species c;
    c.add_instruction("if_enemy 3");
    c.add_instruction("hop");
    c.add_instruction("go 0");
    c.add_instruction("left");
    c.add_instruction("go 0");
    Creature d(c, NORTH);
    x.add_creature(d, 4,4);

    x.turn();
    x.turn();
    x.turn();
    x.turn();
    x.turn();
    x.turn();

}
TEST(DarwinFixture, darwin_print_1) { 
//Test by visual confirmation until I make print an operator
    Darwin x;
    Species a('$');
    Creature b0(a, NORTH);
    Creature b1(a, NORTH);
    Creature b2(a, NORTH);
    Creature b3(a, NORTH);
    x.add_creature(b0, 3,3);
    x.add_creature(b1, 3,4);
    x.add_creature(b2, 4,3);
    x.add_creature(b3, 4,4);
   
    x.print();
}
TEST(DarwinFixture, darwin_print_2) {
    Darwin x;
    Species a('Q');
    Creature b0(a, NORTH);
    Creature b1(a, NORTH);
    Creature b2(a, NORTH);
    Creature b3(a, NORTH);
    x.add_creature(b0, 0,0);
    x.add_creature(b1, 0,7);
    x.add_creature(b2, 7,0);
    x.add_creature(b3, 7,7);
   
    x.print();
}
TEST(DarwinFixture, darwin_print_3) {
    Darwin x(4,4);
    Species a('x');
    Creature b0(a, NORTH);
    Creature b1(a, NORTH);
    Creature b2(a, NORTH);
    Creature b3(a, NORTH);
    Creature b4(a, NORTH);
    Creature b5(a, NORTH);
    Creature b6(a, NORTH);
    Creature b7(a, NORTH);
    x.add_creature(b0, 0,0);
    x.add_creature(b1, 0,2);
    x.add_creature(b2, 1,1);
    x.add_creature(b3, 1,3);
    x.add_creature(b0, 2,0);
    x.add_creature(b1, 2,2);
    x.add_creature(b2, 3,1);
    x.add_creature(b3, 3,3);
   
   
    x.print();

}
TEST(DarwinFixture, darwin_add_1) {
    Darwin x;
    Species a;
    Creature b(a, NORTH);
    x.add_creature(b,0,0);

}
TEST(DarwinFixture, darwin_add_2) {
    Darwin x;
    Species a;
    Creature b(a, NORTH);
    x.add_creature(b,0,0);
    x.add_creature(b, 7,7);

}
TEST(DarwinFixture, darwin_add_3) {
    Darwin x;
    Species a;
    Creature b(a, NORTH);
    Species c;
    Creature d(a, NORTH);
    x.add_creature(d,4,5);
    x.add_creature(d,4,4);

}
TEST(DarwinFixture, darwin_check_1) {
    Darwin x(1,1);
    ASSERT_EQ(x.check_location(0,0, nullptr), EMPTY);

}
TEST(DarwinFixture, darwin_check_2) {
    Darwin x(1,1);
    Species a;
    Creature b(a, NORTH);
    x.add_creature(b,0,0);
    ASSERT_EQ(x.check_location(0,0, nullptr), ENEMY);

}
TEST(DarwinFixture, darwin_check_3) {
    Darwin x(1,1);
    Species a;
    Creature b(a, NORTH);
    x.add_creature(b,0,0);
    ASSERT_EQ(x.check_location(1,0, nullptr), WALL);

}
TEST(DarwinFixture, darwin_hop_1) {
    Darwin x;
    Species a;
    Creature b(a, NORTH);
    x.add_creature(b,4,4);
    x.hop(4,4, NORTH);

}
TEST(DarwinFixture, darwin_hop_2) {
    Darwin x;
    Species a;
    Creature b(a, NORTH);
    x.add_creature(b,4,4);
    x.hop(4,4, SOUTH);

}
TEST(DarwinFixture, darwin_hop_3) {
    Darwin x(1,1);
    Species a;
    Creature b(a, NORTH);
    x.add_creature(b,0,0);
    x.hop(0,0, EAST);

}
TEST(DarwinFixture, darwin_infect_1) {
    Darwin x;
    Species a;
    Creature b(a, NORTH);
    Species c;
    Creature d(a, NORTH);
    x.add_creature(b,4,4);
    x.add_creature(d,3,4);

    x.infect(4,4,NORTH);
    ASSERT_TRUE(b.is_same_species(&d));

}
TEST(DarwinFixture, darwin_infect_2) {
    Darwin x;
    Species a;
    Creature b(a, NORTH);
    Species c;
    Creature d(a, NORTH);
    x.add_creature(b,4,4);
    x.add_creature(d,5,4);

    x.infect(4,4,SOUTH);
    ASSERT_TRUE(b.is_same_species(&d));

}
TEST(DarwinFixture, darwin_infect_3) {
    Darwin x;
    Species a;
    Creature b(a, NORTH);
    Species c;
    Creature d(a, NORTH);
    x.add_creature(b,4,4);
    x.add_creature(d,4,5);

    x.infect(4,4,EAST);
    ASSERT_TRUE(b.is_same_species(&d));

}













