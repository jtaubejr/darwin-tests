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

TEST(DarwinFixture, species_print1){
    Species food('f');
    ostringstream os;
    os << food;
    ASSERT_EQ("f", os.str());}

TEST(DarwinFixture, species_print2){
    Species food('r');
    ostringstream os;
    os << food << " ";
    ASSERT_EQ("r ", os.str());}

TEST(DarwinFixture, species_print3){
    Species food('t');
    ostringstream os;
    os << food << food;
    ASSERT_EQ("tt", os.str());}

TEST(DarwinFixture, species_print4){
    Species food('f');
    ostringstream os;
    os << food << " " << food;
    ASSERT_EQ("f f", os.str());}

TEST(DarwinFixture, species_add_ins1){
    Species food('f');
    ins f0, f1;
    f0.k = keyword::left;
    f0.n = 0;
    f1.k = keyword::go;
    f1.n = 0;
    food.add_instruction(f0);
    food.add_instruction(f1);
    ASSERT_EQ(2, food._i.size());
}

TEST(DarwinFixture, species_add_ins2){
    Species food('f');
    ins f0, f1;
    f0.k = keyword::left;
    f0.n = 0;
    f1.k = keyword::go;
    f1.n = 0;
    food.add_instruction(f0);
    food.add_instruction(f1);
    food.add_instruction(f1);
    ASSERT_EQ(3, food._i.size());
}

TEST(DarwinFixture, species_add_ins3){
    Species food('f');
    ASSERT_EQ(0, food._i.size());
}

TEST(DarwinFixture, species_add_ins4){
    Species food('f');
    ins f0, f1;
    f0.k = keyword::left;
    f0.n = 0;
    f1.k = keyword::go;
    f1.n = 0;
    food.add_instruction(f0);
    food.add_instruction(f1);
    ASSERT_EQ(f1.k, food._i[1].k);
    ASSERT_EQ(f1.n, food._i[1].n);
}

TEST(DarwinFixture, species_next_action1){
	Species food('f');
	Creature f(&food,W);
	int pc = 0;
	dir d = dir::W;
    ins f0, f1;
    f0.k = keyword::left;
    f0.n = 0;
    f1.k = keyword::go;
    f1.n = 0;
	food.add_instruction(f0);
	food.add_instruction(f1);
	keyword k = food.next_action(0,0,2,2,&f,false,pc,d);
	ASSERT_EQ(keyword::left, k);
	ASSERT_EQ(1, pc);
}

TEST(DarwinFixture, species_next_action2){
    Species food('f');
    Creature f(&food,W);
    int pc = 0;
    dir d = dir::W;
    ins f0, f1;
    f0.k = keyword::left;
    f0.n = 0;
    f1.k = keyword::go;
    f1.n = 0;
    food.add_instruction(f0);
    food.add_instruction(f1);
    keyword k = food.next_action(0,0,2,2,&f,false,pc,d);
    ASSERT_EQ(keyword::left, k);
    ASSERT_EQ(1, pc);
    keyword k2 = food.next_action(0,0,2,2,&f,false,pc,d);
    ASSERT_EQ(keyword::left,k2);
    ASSERT_EQ(1,pc);
}

TEST(DarwinFixture, species_next_action3){
    Species trap('t');
    ins t0, t1, t2, t3;
    t0.k = keyword::if_enemy;
    t0.n = 3;
    t1.k = keyword::left;
    t1.n = 0;
    t2.k = keyword::go;
    t2.n = 0;
    t3.k = keyword::infect;
    t3.n = 0;
    trap.add_instruction(t0);
    trap.add_instruction(t1);
    trap.add_instruction(t2);
    trap.add_instruction(t3);
    trap.add_instruction(t2);
    Creature t(&trap,dir::E);
    Species food('f');
    Creature f(&food,dir::N);
    int pc = 0;
    dir d = dir::E;
    keyword k = trap.next_action(0,0,2,2,&f,true,pc,d);
    ASSERT_EQ(keyword::infect,k);
    ASSERT_EQ(4,pc);   
}

TEST(DarwinFixture, species_next_action4){
    Species food('f');
    Creature f(&food,W);
    int pc = 0;
    dir d = dir::W;
    ins f0, f1;
    f0.k = keyword::right;
    f0.n = 0;
    f1.k = keyword::go;
    f1.n = 0;
    food.add_instruction(f0);
    food.add_instruction(f1);
    keyword k = food.next_action(0,0,2,2,&f,false,pc,d);
    ASSERT_EQ(keyword::right, k);
    ASSERT_EQ(1, pc);
}

TEST(DarwinFixture, species_next_action5){
    Species hopper('h');
    ins h0;
    h0.k = keyword::hop;
    h0.n=0;
    hopper.add_instruction(h0);
    int pc = 0;
    dir d = dir::E;
    keyword k = hopper.next_action(0,0,2,2,nullptr,false,pc,d);
    ASSERT_EQ(keyword::hop, k);
    ASSERT_EQ(1, pc);
}

TEST(DarwinFixture, species_next_action6){
    Species control('c');
    ins c0,c1,c2,c3,c4;
    c0.k = keyword::if_empty;
    c0.n = 3;
    c1.k = keyword::left;
    c1.n = 0;
    c2.k = keyword::go;
    c2.n = 0;
    c3.k = keyword::right;
    c3.n = 0;
    c4.k = keyword::go;
    c4.n = 0;
    int pc = 0;
    dir d = dir::E;
    Creature c(&control,d);
    control.add_instruction(c0);
    control.add_instruction(c1);
    control.add_instruction(c2);
    control.add_instruction(c3);
    control.add_instruction(c4);
    // we put something in front of the creatue so it should give us left
    keyword k = control.next_action(0,0,2,2,&c,false,pc,d);
    ASSERT_EQ(keyword::left, k);
    ASSERT_EQ(2,pc);
}

TEST(DarwinFixture, species_next_action7){
    Species control('c');
    ins c0,c1,c2,c3,c4;
    c0.k = keyword::if_empty;
    c0.n = 3;
    c1.k = keyword::left;
    c1.n = 0;
    c2.k = keyword::go;
    c2.n = 0;
    c3.k = keyword::right;
    c3.n = 0;
    c4.k = keyword::go;
    c4.n = 0;
    int pc = 0;
    dir d = dir::W;
    control.add_instruction(c0);
    control.add_instruction(c1);
    control.add_instruction(c2);
    control.add_instruction(c3);
    control.add_instruction(c4);
    // we put the creature facing a wall so it should give us left
    keyword k = control.next_action(0,0,2,2,nullptr,false,pc,d);
    ASSERT_EQ(keyword::left, k);
    ASSERT_EQ(2,pc);
}

TEST(DarwinFixture, species_next_action8){
    Species control('c');
    ins c0,c1,c2,c3,c4;
    c0.k = keyword::if_empty;
    c0.n = 3;
    c1.k = keyword::left;
    c1.n = 0;
    c2.k = keyword::go;
    c2.n = 0;
    c3.k = keyword::right;
    c3.n = 0;
    c4.k = keyword::go;
    c4.n = 0;
    int pc = 0;
    dir d = dir::E;
    control.add_instruction(c0);
    control.add_instruction(c1);
    control.add_instruction(c2);
    control.add_instruction(c3);
    control.add_instruction(c4);
    // we put nothing in front of the creature so it should give us right
    keyword k = control.next_action(0,0,2,2,nullptr,false,pc,d);
    ASSERT_EQ(keyword::right, k);
    ASSERT_EQ(4,pc);
}

TEST(DarwinFixture, species_next_action9){
    Species control('c');
    ins c0,c1,c2,c3,c4;
    c0.k = keyword::if_wall;
    c0.n = 3;
    c1.k = keyword::left;
    c1.n = 0;
    c2.k = keyword::go;
    c2.n = 0;
    c3.k = keyword::right;
    c3.n = 0;
    c4.k = keyword::go;
    c4.n = 0;
    int pc = 0;
    dir d = dir::W;
    control.add_instruction(c0);
    control.add_instruction(c1);
    control.add_instruction(c2);
    control.add_instruction(c3);
    control.add_instruction(c4);
    // we faced the creature toward a wall so it should give us right
    keyword k = control.next_action(0,0,2,2,nullptr,false,pc,d);
    ASSERT_EQ(keyword::right, k);
    ASSERT_EQ(4,pc);
}

TEST(DarwinFixture, species_next_action10){
    Species control('c');
    ins c0,c1,c2,c3,c4;
    c0.k = keyword::if_wall;
    c0.n = 3;
    c1.k = keyword::left;
    c1.n = 0;
    c2.k = keyword::go;
    c2.n = 0;
    c3.k = keyword::right;
    c3.n = 0;
    c4.k = keyword::go;
    c4.n = 0;
    int pc = 0;
    dir d = dir::E;
    control.add_instruction(c0);
    control.add_instruction(c1);
    control.add_instruction(c2);
    control.add_instruction(c3);
    control.add_instruction(c4);
    // we faced the creature away from a wall so it should give us left
    keyword k = control.next_action(0,0,2,2,nullptr,false,pc,d);
    ASSERT_EQ(keyword::left, k);
    ASSERT_EQ(2,pc);
}

TEST(DarwinFixture, species_next_action11){
    srand(0);
    Species control('c');
    ins c0,c1,c2,c3,c4;
    c0.k = keyword::if_random;
    c0.n = 3;
    c1.k = keyword::left;
    c1.n = 0;
    c2.k = keyword::go;
    c2.n = 0;
    c3.k = keyword::right;
    c3.n = 0;
    c4.k = keyword::go;
    c4.n = 0;
    int pc = 0;
    dir d = dir::E;
    control.add_instruction(c0);
    control.add_instruction(c1);
    control.add_instruction(c2);
    control.add_instruction(c3);
    control.add_instruction(c4);
    // we know that random will give us odd so we should get right
    keyword k = control.next_action(0,0,2,2,nullptr,false,pc,d);
    ASSERT_EQ(keyword::right, k);
    ASSERT_EQ(4,pc);
}

TEST(DarwinFixture, creature_print1){
    Species food('r');
    Creature f1(&food, dir::N);
    ostringstream os;
    os << f1 << " ";
    ASSERT_EQ("r ", os.str());
}

TEST(DarwinFixture, creature_print2){
    Species food('r');
    Creature f1(&food, dir::N);
    ostringstream os;
    os << f1 << " "<<f1;
    ASSERT_EQ("r r", os.str());
}

TEST(DarwinFixture, creature_print3){
    Species food('r');
    Creature f1(&food, dir::N);
    ostringstream os;
    os << f1 << f1;
    ASSERT_EQ("rr", os.str());
}

TEST(DarwinFixture, creature_take_turn1){
    Species food('f');
    ins f0, f1;
    f0.k = keyword::left;
    f0.n = 0;
    f1.k = keyword::go;
    f1.n = 0;
    food.add_instruction(f0);
    food.add_instruction(f1);
    Creature f(&food,dir::W);
    tuple<int, int> result = f.take_turn(1,0,0,2,2,nullptr,nullptr,nullptr,nullptr);
    ASSERT_EQ(0,get<0>(result));
    ASSERT_EQ(0,get<1>(result));
}

TEST(DarwinFixture, creature_take_turn2){
    Species hopper('h');
    ins h0,h1;
    h0.k = keyword::hop;
    h0.n=0;
    h1.k = keyword::go;
    h1.n = 0;
    hopper.add_instruction(h0);
    hopper.add_instruction(h1);
    Creature h(&hopper,dir::E);
    tuple<int, int> result = h.take_turn(1,0,0,2,2,nullptr,nullptr,nullptr,nullptr);
    ASSERT_EQ(0,get<0>(result));
    ASSERT_EQ(1,get<1>(result));    
}

TEST(DarwinFixture, creature_take_turn3){
    Species trap('t');
    ins t0, t1, t2, t3;
    t0.k = keyword::if_enemy;
    t0.n = 3;
    t1.k = keyword::left;
    t1.n = 0;
    t2.k = keyword::go;
    t2.n = 0;
    t3.k = keyword::infect;
    t3.n = 0;
    trap.add_instruction(t0);
    trap.add_instruction(t1);
    trap.add_instruction(t2);
    trap.add_instruction(t3);
    trap.add_instruction(t2);
    Creature t(&trap,dir::E);
    Species food('f');
    Creature f(&food,dir::N);
    tuple<int, int> res = t.take_turn(1,0,0,2,2,nullptr,nullptr,&f,nullptr);
    // the trap should infect the food
    ASSERT_EQ(0,get<0>(res));
    ASSERT_EQ(0,get<1>(res));    
    ASSERT_EQ(&trap,f._s);
}

TEST(DarwinFixture, creature_take_turn4){
    Species food('f');
    ins f0, f1;
    f0.k = keyword::left;
    f0.n = 0;
    f1.k = keyword::go;
    f1.n = 0;
    food.add_instruction(f0);
    food.add_instruction(f1);
    Creature f(&food,dir::W);
    tuple<int, int> res = f.take_turn(1,0,0,2,2,nullptr,nullptr,nullptr,nullptr);
    // make sure turning left works
    ASSERT_EQ(0,get<0>(res));
    ASSERT_EQ(0,get<1>(res)); 
    ASSERT_EQ(dir::S,f._d);
}

TEST(DarwinFixture, creature_take_turn5){
    Species food('f');
    ins f0, f1;
    f0.k = keyword::right;
    f0.n = 0;
    f1.k = keyword::go;
    f1.n = 0;
    food.add_instruction(f0);
    food.add_instruction(f1);
    Creature f(&food,dir::W);
    tuple<int, int> res = f.take_turn(1,0,0,2,2,nullptr,nullptr,nullptr,nullptr);
    // make sure turning right works
    ASSERT_EQ(0,get<0>(res));
    ASSERT_EQ(0,get<1>(res)); 
    ASSERT_EQ(dir::N,f._d);
}

TEST(DarwinFixture, creature_take_turn6){
    Species hopper('h');
    ins h0,h1;
    h0.k = keyword::hop;
    h0.n=0;
    h1.k = keyword::go;
    h1.n = 0;
    hopper.add_instruction(h0);
    hopper.add_instruction(h1);
    Creature h(&hopper,dir::E);
    tuple<int, int> result = h.take_turn(0,0,0,2,2,nullptr,nullptr,nullptr,nullptr);
    // the hopper shouldn't move b/c we're telling it that we're on turn zero
    ASSERT_EQ(0,get<0>(result));
    ASSERT_EQ(0,get<1>(result));    
}

TEST(DarwinFixture, darwin_construct){
    Darwin board(12,13);
    ASSERT_EQ(12,board._grid.size());
    ASSERT_EQ(13,board._grid[0].size());
}

TEST(DarwinFixture, darwin_print1){
    Darwin board(2,2);
    ostringstream os;
    os << board;
    ASSERT_EQ("Turn = 0.\n  01\n0 ..\n1 ..\n",os.str());
}

TEST(DarwinFixture, darwin_print2){
    Species s('s');
    Creature c(&s,dir::W);
    Darwin d(2,2);
    d.add_creature(0,0,&c);
    ostringstream os;
    os << d;
    ASSERT_EQ("Turn = 0.\n  01\n0 s.\n1 ..\n",os.str());
}

TEST(DarwinFixture, darwin_next_turn1){
    Darwin d(2,2);
    d.next_turn();
    ASSERT_EQ(1,d._turn);
}

TEST(DarwinFixture, darwin_next_turn2){
    Species hopper('h');
    ins h0,h1;
    h0.k = keyword::hop;
    h0.n=0;
    h1.k = keyword::go;
    h1.n = 0;
    hopper.add_instruction(h0);
    hopper.add_instruction(h1);
    Creature h(&hopper,dir::E);
    Darwin d(2,2);
    d.add_creature(0,0,&h);
    d.next_turn();
    ostringstream os;
    os << d;
    ASSERT_EQ("Turn = 1.\n  01\n0 .h\n1 ..\n",os.str());
}