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

TEST(DarwinTest, species_constructor_1) {
		Species x = Species('x');
		ASSERT_EQ(x.name, 'x');
}	

TEST(DarwinTest, species_constructor_2) {
		Species x = Species('y');
		ASSERT_EQ(x.name, 'y');
}	

TEST(DarwinTest, species_constructor_3) {
		Species x = Species('z');
		ASSERT_EQ(x.name, 'z');
}	

TEST(DarwinTest, species_assignment_operator_1) {
		Species x = Species('x');
		vector<pair<int,int>> list = vector<pair<int,int>>();
		ASSERT_EQ(x.instructions, list);
}	

TEST(DarwinTest, species_assignment_operator_2) {
		Species x = Species('x');
		Species y = x;
		ASSERT_EQ(x.instructions, y.instructions);
		ASSERT_EQ(x.name, y.name);
}	

TEST(DarwinTest, species_assignment_operator_3) {
		Species x = Species('x');
		Species y = x;
		ASSERT_EQ(x.instructions, y.instructions);
		ASSERT_EQ(x.name, y.name);
		Species z = Species('z');
		z.instructions.push_back(pair<int,int>(1,2));
		y = z;
		ASSERT_EQ(z.name, y.name);
		ASSERT_EQ(z.instructions, y.instructions);
}	

TEST(DarwinTest, species_addInstruction_1) {
		Species x = Species('x');
		pair<int,int> tuple = pair<int,int>();
		vector<pair<int,int>> list = vector<pair<int,int>>();
		list.push_back(tuple);
		x.addInstruction(0, 0);
		ASSERT_EQ(x.instructions, list);
}	

TEST(DarwinTest, species_addInstruction_2) {
		Species x = Species('x');
		pair<int,int> tuple = pair<int,int>();
		vector<pair<int,int>> list = vector<pair<int,int>>();
		list.push_back(tuple);
		tuple = pair<int,int>(1,8);
		list.push_back(tuple);
		x.addInstruction(0, 0);
		x.addInstruction(1, 8);
		ASSERT_EQ(x.instructions, list);
}	

TEST(DarwinTest, species_addInstruction_3) {
		Species x = Species('x');
		pair<int,int> tuple = pair<int,int>();
		vector<pair<int,int>> list = vector<pair<int,int>>();
		list.push_back(tuple);
		tuple = pair<int,int>(1,8);
		list.push_back(tuple);
		tuple = pair<int, int>(9,9);
		list.push_back(tuple);
		x.addInstruction(0, 0);
		x.addInstruction(1, 8);
		x.addInstruction(9,9);
		ASSERT_EQ(x.instructions, list);
}	

TEST(DarwinTest, species_equals_operator_1) {
		Species x1 = Species('x');
		Species x2 = Species('x');
		ASSERT_TRUE(x1 == x2); 
}

TEST(DarwinTest, species_equals_operator_2) {
		Species x = Species('x');
		Species y = Species('y');
		ASSERT_FALSE(x == y); 
}

TEST(DarwinTest, species_equals_operator_3) {
		Species x = Species('x');
		Species y = Species('y');
		ASSERT_FALSE(x == y); 
}

TEST(DarwinTest, species_equals_operator_4) {
		Species x1 = Species('x');
		x1.addInstruction(1,1);
		Species x2 = Species('x');
		x2.addInstruction(1,1);
		ASSERT_TRUE(x1 == x2); 
}

TEST(DarwinTest, species_equals_operator_5) {
		Species x1 = Species('x');
		x1.addInstruction(1,1);
		Species x2 = Species('x');
		x2.addInstruction(9,2);
		ASSERT_FALSE(x1 == x2); 
}

TEST(DarwinTest, species_getNextInstruction_1) {
		Species x = Species('x');
		x.addInstruction(0,0);
		pair<int,int> tuple = pair<int,int>(0,0);
		ASSERT_EQ(x.getNextInstruction(0), tuple);
}

TEST(DarwinTest, species_getNextInstruction_2) {
		Species x = Species('x');
		x.addInstruction(0,0);
		x.addInstruction(2,2);
		x.addInstruction(9,9);
		pair<int,int> tuple = pair<int,int>(9,9);
		ASSERT_EQ(x.getNextInstruction(2), tuple);
}

TEST(DarwinTest, species_getNextInstruction_3) {
		Species x = Species('x');
		x.addInstruction(0,0);
		x.addInstruction(2,2);
		x.addInstruction(9,9);
		pair<int,int> tuple = pair<int,int>(2,2);
		ASSERT_EQ(x.getNextInstruction(1), tuple);
}

TEST(DarwinTest, species_print_1) {
		ostringstream w;
		Species x = Species('x');
		x.printSpecies(w);
		ASSERT_EQ(w.str(), "x");
}

TEST(DarwinTest, species_print_2) {
		ostringstream w;
		Species x = Species('x');
		x.printSpecies(w);
		x.printSpecies(w);
		ASSERT_EQ(w.str(), "xx");
}

TEST(DarwinTest, species_print_3) {
		ostringstream w;
		Species x = Species('x');
		x.printSpecies(w);
		x.printSpecies(w);
		Species y = Species('y');
		y.printSpecies(w);
		y.printSpecies(w);
		ASSERT_EQ(w.str(), "xxyy");
}

///////////////////
// CREATURE TEST //
///////////////////

TEST(DarwinTest, creature_default_constructor_1) {
		Creature c = Creature();
		ASSERT_EQ(c.specie, nullptr);
}

TEST(DarwinTest, creature_default_constructor_2) {
		Creature c = Creature();
		ASSERT_EQ(c.pc, 0);
}

TEST(DarwinTest, creature_default_constructor_3) {
		Creature c = Creature();
		ASSERT_EQ(c.direction, NORTH);
}

TEST(DarwinTest, creature_default_constructor_4) {
		Creature c = Creature();
		ASSERT_EQ(c.direction, 1);
}

TEST(DarwinTest, creature_default_constructor_5) {
		Creature c = Creature();
		ASSERT_EQ(c.takenActionThisTurn, true);
}

TEST(DarwinTest, creature_copy_constructor_1) {
		Species s = Species('x');
		Creature c = Creature(&s, NORTH);
		ASSERT_EQ(c.specie->name, 'x');
		ASSERT_EQ(c.specie->instructions, s.instructions);
		ASSERT_EQ(c.pc, 0);
		ASSERT_EQ(*(c.specie), s);
		ASSERT_EQ(c.direction, NORTH);
		ASSERT_FALSE(c.takenActionThisTurn);
}
TEST(DarwinTest, creature_copy_constructor_2) {
		Species s = Species('y');
		s.addInstruction(1,1);
		Creature c = Creature(&s, EAST);
		ASSERT_EQ(c.specie->name, 'y');
		ASSERT_EQ(c.specie->instructions, s.instructions);
		ASSERT_EQ(c.pc, 0);
		ASSERT_EQ(*(c.specie), s);
		ASSERT_EQ(c.direction, EAST);
		ASSERT_FALSE(c.takenActionThisTurn);

}

TEST(DarwinTest, creature_copy_constructor_3) {
		Species s = Species('y');
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		Creature c = Creature(&s, EAST);
		ASSERT_EQ(c.specie->name, 'y');
		ASSERT_EQ(c.specie->instructions, s.instructions);
		ASSERT_EQ(c.pc, 0);
		ASSERT_EQ(*(c.specie), s);
		ASSERT_EQ(c.direction, EAST);
		ASSERT_FALSE(c.takenActionThisTurn);
}

TEST(DarwinTest, creature_assignment_operator_1) {
		Species s = Species('s');
		Creature c = Creature(&s, NORTH);
		Creature d = Creature();
		ASSERT_EQ(c.specie->name, 's');
		ASSERT_EQ(d.specie, nullptr);	
		d = c;
		ASSERT_TRUE( *(d.specie) == *(c.specie));
}


TEST(DarwinTest, creature_assignment_operator_2) {
		Species s = Species('s');
		s.addInstruction(1,1);
		Creature c = Creature(&s, NORTH);
		Creature d = Creature();
		ASSERT_EQ(c.specie->name, 's');
		ASSERT_EQ(d.specie, nullptr);	
		d = c;
		ASSERT_TRUE( *(d.specie) == *(c.specie));
}

TEST(DarwinTest, creature_assignment_operator_3) {
		Species s = Species('s');
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		Creature c = Creature(&s, NORTH);
		Creature d = Creature();
		ASSERT_EQ(c.specie->name, 's');
		ASSERT_EQ(d.specie, nullptr);	
		d = c;
		Creature e = d;
		ASSERT_TRUE( *(e.specie) == *(c.specie));
}

TEST(DarwinTest, creature_getNextInstruction_1) {
		Species s = Species('s');
		s.addInstruction(0,0);
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		Creature c = Creature(&s, NORTH);
		pair<int,int> inst = c.getNextInstruction(0);
		ASSERT_EQ(inst.first, 0);
		ASSERT_EQ(inst.second, 0);
}

TEST(DarwinTest, creature_getNextInstruction_2) {
		Species s = Species('s');
		s.addInstruction(0,0);
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		Creature c = Creature(&s, NORTH);
		pair<int,int> inst = c.getNextInstruction(1);
		ASSERT_EQ(inst.first, 1);
		ASSERT_EQ(inst.second, 1);
}

TEST(DarwinTest, creature_getNextInstruction_3) {
		Species s = Species('s');
		s.addInstruction(0,0);
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		Creature c = Creature(&s, NORTH);
		pair<int,int> inst = c.getNextInstruction(2);
		ASSERT_EQ(inst.first, 2);
		ASSERT_EQ(inst.second,2);
}

TEST(DarwinTest, creature_getNextInstruction_4) {
		Species s = Species('s');
		Creature c = Creature();
		pair<int,int> inst = c.getNextInstruction(2);
		ASSERT_EQ(inst.first, -1);
		ASSERT_EQ(inst.second,-1);
}

TEST(DarwinTest, creature_getNextInstruction_5) {
		Species s = Species('s');
		s.addInstruction(0,0);
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		s.addInstruction(3,3);
		s.addInstruction(4,4);
		Creature c = Creature(&s, NORTH);
		pair<int,int> inst = c.getNextInstruction(0);
		ASSERT_EQ(inst.first, 0);
		ASSERT_EQ(inst.second, 0);
		ASSERT_TRUE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_getNextInstruction_6) {
		Species s = Species('s');
		s.addInstruction(0,0);
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		s.addInstruction(3,3);
		s.addInstruction(4,4);
		Creature c = Creature(&s, NORTH);
		pair<int,int> inst = c.getNextInstruction(0);
		ASSERT_EQ(inst.first, 0);
		ASSERT_EQ(inst.second, 0);
		ASSERT_TRUE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_getNextInstruction_7) {
		Species s = Species('s');
		s.addInstruction(0,0);
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		s.addInstruction(3,3);
		s.addInstruction(4,4);
		Creature c = Creature(&s, NORTH);
		pair<int,int> inst = c.getNextInstruction(1);
		ASSERT_EQ(inst.first, 1);
		ASSERT_EQ(inst.second, 1);
		ASSERT_TRUE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_getNextInstruction_8) {
		Species s = Species('s');
		s.addInstruction(0,0);
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		s.addInstruction(3,3);
		s.addInstruction(4,4);
		Creature c = Creature(&s, NORTH);
		pair<int,int> inst = c.getNextInstruction(2);
		ASSERT_EQ(inst.first, 2);
		ASSERT_EQ(inst.second, 2);
		ASSERT_TRUE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_getNextInstruction_9) {
		Species s = Species('s');
		s.addInstruction(0,0);
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		s.addInstruction(3,3);
		s.addInstruction(4,4);
		Creature c = Creature(&s, NORTH);
		pair<int,int> inst = c.getNextInstruction(3);
		ASSERT_EQ(inst.first, 3);
		ASSERT_EQ(inst.second, 3);
		ASSERT_TRUE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_getNextInstruction_10) {
		Species s = Species('s');
		s.addInstruction(0,0);
		s.addInstruction(1,1);
		s.addInstruction(2,2);
		s.addInstruction(3,3);
		s.addInstruction(4,4);
		Creature c = Creature(&s, NORTH);
		pair<int,int> inst = c.getNextInstruction(4);
		ASSERT_EQ(inst.first, 4);
		ASSERT_EQ(inst.second, 4);
		ASSERT_FALSE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_inFront_1) {
		Species s = Species('s');
		Creature c = Creature(&s, NORTH);
		pair<int,int> dir = c.inFront(0,0);
		ASSERT_EQ(dir.first, -1);
		ASSERT_EQ(dir.second, 0);
}
TEST(DarwinTest, creature_inFront_2) {
		Species s = Species('s');
		Creature c = Creature(&s, EAST);
		pair<int,int> dir = c.inFront(0,0);
		ASSERT_EQ(dir.first, 0);
		ASSERT_EQ(dir.second, 1);
}

TEST(DarwinTest, creature_inFront_3) {
		Species s = Species('s');
		Creature c = Creature(&s, SOUTH);
		pair<int,int> dir = c.inFront(0,0);
		ASSERT_EQ(dir.first, 1);
		ASSERT_EQ(dir.second, 0);
}


TEST(DarwinTest, creature_inFront_4) {
		Species s = Species('s');
		Creature c = Creature(&s, WEST);
		pair<int,int> dir = c.inFront(0,0);
		ASSERT_EQ(dir.first, 0);
		ASSERT_EQ(dir.second, -1);
}

TEST(DarwinTest, creature_isCreatureEnemy_1) {
		Species s = Species('s');
		Species r = Species('r');
		Creature c = Creature(&s, NORTH);
		Creature d = Creature(&r, NORTH);
		ASSERT_TRUE(c.isCreatureEnemy(d));
}

TEST(DarwinTest, creature_isCreatureEnemy_2) {
		Species s = Species('s');
		Species r = Species('s');
		Creature c = Creature(&s, NORTH);
		Creature d = Creature(&r, NORTH);
		ASSERT_FALSE(c.isCreatureEnemy(d));
}

TEST(DarwinTest, creature_isCreatureEnemy_3) {
		Species s = Species('s');
		Species r = Species('s');
		Creature c = Creature(&s, NORTH);
		Creature d = Creature(&r, NORTH);
		ASSERT_FALSE(d.isCreatureEnemy(c));
}

TEST(DarwinTest, creature_isCreatureEnemy_4) {
		Species s = Species('s');
		s.addInstruction(1,1);
		Species r = Species('s');
		Creature c = Creature(&s, NORTH);
		Creature d = Creature(&r, NORTH);
		ASSERT_TRUE(d.isCreatureEnemy(c));
}

TEST(DarwinTest, creature_isCreatureEnemy_5) {
		Species s = Species('s');
		s.addInstruction(1,1);
		Species r = Species('s');
		r.addInstruction(1,1);
		Creature c = Creature(&s, NORTH);
		Creature d = Creature(&r, NORTH);
		ASSERT_FALSE(d.isCreatureEnemy(c));
}

TEST(DarwinTest, creature_isCreatureEnemy_6) {
		Species s = Species('s');
		s.addInstruction(1,1);
		Species r = Species('s');
		r.addInstruction(1,1);
		r.addInstruction(2,2);
		Creature c = Creature(&s, NORTH);
		Creature d = Creature(&r, NORTH);
		ASSERT_TRUE(d.isCreatureEnemy(c));
}

TEST(DarwinTest, creature_isCreatureAsleep_1) {
		Species s = Species('s');
		Creature c = Creature(&s, NORTH);
		ASSERT_FALSE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_isCreatureAsleep_2) {
		Creature c = Creature();
		ASSERT_TRUE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_isCreatureAsleep_3) {
		Creature c = Creature();
		c.takenActionThisTurn = false;
		ASSERT_FALSE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_wakeCreature_1) {
		Species s = Species('s');
		Creature c = Creature(&s, NORTH);
		ASSERT_FALSE(c.isCreatureAsleep());
		c.wakeCreature();
		ASSERT_FALSE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_wakeCreature_2) {
		Creature c = Creature();
		ASSERT_TRUE(c.isCreatureAsleep());
		c.wakeCreature();
		ASSERT_FALSE(c.isCreatureAsleep());
}

TEST(DarwinTest, creature_printCreature_1) {
		Creature c = Creature();
		ostringstream w;
		c.printCreature(w);
		ASSERT_EQ(w.str(), ".");
}
TEST(DarwinTest, creature_printCreature_2) {
		Creature c = Creature();
		ostringstream w;
		c.printCreature(w);
		c.printCreature(w);
		ASSERT_EQ(w.str(), "..");
}

TEST(DarwinTest, creature_printCreature_3) {
		Species s = Species('s');
		Creature d = Creature(&s, NORTH);
		Creature c = Creature();
		ostringstream w;
		c.printCreature(w);
		c.printCreature(w);
		d.printCreature(w);
		ASSERT_EQ(w.str(), "..s");
}

TEST(DarwinTest, creature_printCreature_4) {
		Species s = Species('s');
		Creature d = Creature(&s, NORTH);
		Creature c = Creature();
		ostringstream w;
		c.printCreature(w);
		c.printCreature(w);
		d.printCreature(w);
		d.printCreature(w);
		ASSERT_EQ(w.str(), "..ss");
}

///////////////////
// DARWIN TEST ////
///////////////////

TEST(DarwinTest, darwin_constructor_1) {
		Darwin d = Darwin(1,1);
		ASSERT_EQ(d.rows, 1);
		ASSERT_EQ(d.cols, 1);
		ASSERT_EQ(d.turnsSimulated, 0);
		ASSERT_EQ(d.grid.size(), 1);
		ASSERT_EQ(d.grid[0].size(), 1);
		ASSERT_EQ(d.currentRow, 0);
		ASSERT_EQ(d.currentCol, 0);
		ASSERT_EQ(d.forwardRow, 0);
		ASSERT_EQ(d.forwardCol, 0);
}

TEST(DarwinTest, darwin_constructor_2) {
		Darwin d = Darwin(100,100);
		ASSERT_EQ(d.rows, 100);
		ASSERT_EQ(d.cols, 100);
		ASSERT_EQ(d.turnsSimulated, 0);
		ASSERT_EQ(d.grid.size(), 100);
		ASSERT_EQ(d.grid[0].size(), 100);
		ASSERT_EQ(d.currentRow, 0);
		ASSERT_EQ(d.currentCol, 0);
		ASSERT_EQ(d.forwardRow, 0);
		ASSERT_EQ(d.forwardCol, 0);
}

TEST(DarwinTest, darwin_constructor_3) {
		Darwin d = Darwin(1000,1000);
		ASSERT_EQ(d.rows, 1000);
		ASSERT_EQ(d.cols, 1000);
		ASSERT_EQ(d.turnsSimulated, 0);
		ASSERT_EQ(d.grid.size(), 1000);
		ASSERT_EQ(d.grid[0].size(), 1000);
		ASSERT_EQ(d.currentRow, 0);
		ASSERT_EQ(d.currentCol, 0);
		ASSERT_EQ(d.forwardRow, 0);
		ASSERT_EQ(d.forwardCol, 0);
}

TEST(DarwinTest, darwin_addCreature_1) {
		Darwin d = Darwin(1,1);
		ASSERT_EQ(d.grid[0][0].specie, nullptr);
		Species s = Species('s');
		Creature c1 = Creature(&s, NORTH);
		d.addCreature(c1, 0,0);
		Creature c2 = d.grid[0][0];
		ASSERT_EQ( *(c1.specie), *(c2.specie));
		ASSERT_EQ(c2.direction, NORTH);
		ASSERT_FALSE(c2.takenActionThisTurn);
}

TEST(DarwinTest, darwin_addCreature_2) {
		Darwin d = Darwin(1,1);
		ASSERT_EQ(d.grid[0][0].specie, nullptr);
		Species s = Species('s');
		s.addInstruction(0,0);
		Creature c1 = Creature(&s, NORTH);
		d.addCreature(c1, 0,0);
		Creature c2 = d.grid[0][0];
		ASSERT_EQ( *(c1.specie), *(c2.specie));
		ASSERT_EQ(c2.direction, NORTH);
		ASSERT_FALSE(c2.takenActionThisTurn);
		ASSERT_EQ(c1.getNextInstruction(0), c2.getNextInstruction(0));
}

TEST(DarwinTest, darwin_addCreature_3) {
		Darwin d = Darwin(1,1);
		ASSERT_EQ(d.grid[0][0].specie, nullptr);
		Species s = Species('s');
		s.addInstruction(0,0);
		Creature c1 = Creature(&s, NORTH);
		d.addCreature(c1, 0,0);
		Creature c2 = d.grid[0][0];
		ASSERT_EQ( *(c1.specie), *(c2.specie));
		ASSERT_EQ(c2.direction, NORTH);
		ASSERT_FALSE(c2.takenActionThisTurn);
		ASSERT_EQ(c1.getNextInstruction(0), c2.getNextInstruction(0));
}

TEST(DarwinTest, darwin_inBound_1) {
		Darwin d = Darwin(3,3);
		ASSERT_TRUE(d.inBounds(1,1));
}

TEST(DarwinTest, darwin_inBound_2) {
		Darwin d = Darwin(3,3);
		ASSERT_FALSE(d.inBounds(3,1));
}

TEST(DarwinTest, darwin_inBound_3) {
		Darwin d = Darwin(3,3);
		ASSERT_FALSE(d.inBounds(1,3));
}


TEST(DarwinTest, darwin_inBound_4) {
		Darwin d = Darwin(3,3);
		ASSERT_FALSE(d.inBounds(-1,1));
}

TEST(DarwinTest, darwin_inBound_5) {
		Darwin d = Darwin(3,3);
		ASSERT_FALSE(d.inBounds(1,-1));
}

TEST(DarwinTest, darwin_wakeAllCreatures_1) {
		Darwin d = Darwin(1,1);
		ASSERT_TRUE(d.grid[0][0].takenActionThisTurn);
		d.wakeAllCreatures();
		ASSERT_FALSE(d.grid[0][0].takenActionThisTurn);
}

TEST(DarwinTest, darwin_wakeAllCreatures_2) {
		Darwin d = Darwin(2,2);
		ASSERT_TRUE(d.grid[1][1].takenActionThisTurn);
		d.wakeAllCreatures();
		ASSERT_FALSE(d.grid[1][1].takenActionThisTurn);
}

TEST(DarwinTest, darwin_wakeAllCreatures_3) {
		Darwin d = Darwin(5,5);
		ASSERT_TRUE(d.grid[4][4].takenActionThisTurn);
		d.wakeAllCreatures();
		ASSERT_FALSE(d.grid[4][4].takenActionThisTurn);
}

TEST(DarwinTest, darwin_print_1) {
		Darwin d = Darwin(1,1);
		ostringstream w;
		d.printDarwin(w);
		ASSERT_EQ(w.str(), "Turn = 0.\n  0\n0 .\n");
}

TEST(DarwinTest, darwin_print_2) {
		Darwin d = Darwin(1,2);
		ostringstream w;
		d.printDarwin(w);
		ASSERT_EQ(w.str(), "Turn = 0.\n  01\n0 ..\n");
}


TEST(DarwinTest, darwin_print_3) {
		Darwin d = Darwin(3,3);
		ostringstream w;
		d.printDarwin(w);
		ASSERT_EQ(w.str(), "Turn = 0.\n  012\n0 ...\n1 ...\n2 ...\n");
}

TEST(DarwinTest, darwin_print_4) {
		Darwin d = Darwin(3,3);
		ostringstream w;
		
		Species s = Species('s');
		Creature c = Creature(&s, SOUTH);

		d.addCreature(c, 0,0);
		d.addCreature(c, 2,2);
		d.printDarwin(w);
		ASSERT_EQ(w.str(), "Turn = 0.\n  012\n0 s..\n1 ...\n2 ..s\n");
}

TEST(DarwinTest, darwin_print_5) {
		Darwin d = Darwin(3,3);
		ostringstream w;
		
		Species s = Species('s');
		s.addInstruction(LEFT, 0);
		Creature c = Creature(&s, SOUTH);
		Creature e = Creature(&s, NORTH);

		pair<int,int> inst = pair<int,int>(LEFT, 0);
		pair<int,int> actualInst = s.getNextInstruction(0);
		ASSERT_EQ(inst, actualInst);
		
		d.addCreature(c, 1,1);
		d.addCreature(e, 2,2);

		Creature& c1 = d.grid[1][1];
		Creature& e1 = d.grid[2][2];

		d.printDarwin(w);
		ASSERT_EQ(w.str(), "Turn = 0.\n  012\n0 ...\n1 .s.\n2 ..s\n");
		ASSERT_EQ(c1.direction, SOUTH);
		ASSERT_EQ(e1.direction, NORTH);
	
		actualInst = c.getNextInstruction(0);
		ASSERT_EQ(c.direction, EAST);

		d.simulateTurns(1);

		c1 = d.grid[1][1];	
		e1 = d.grid[2][2];

		ASSERT_EQ(c1.direction, EAST);
		ASSERT_EQ(e1.direction, WEST);
}

TEST(DarwinTest, darwin_print_6) {
		Darwin d = Darwin(3,3);
		ostringstream w;
		
		Species s = Species('s');
		s.addInstruction(LEFT, 0);
		Creature c = Creature(&s, SOUTH);
		Creature e = Creature(&s, NORTH);

		pair<int,int> inst = pair<int,int>(LEFT, 0);
		pair<int,int> actualInst = s.getNextInstruction(0);
		ASSERT_EQ(inst, actualInst);
		
		d.addCreature(c, 1,1);
		d.addCreature(e, 2,2);

		Creature& c1 = d.grid[1][1];
		Creature& e1 = d.grid[2][2];

		d.printDarwin(w);
		ASSERT_EQ(w.str(), "Turn = 0.\n  012\n0 ...\n1 .s.\n2 ..s\n");
		ASSERT_EQ(c1.direction, SOUTH);
		ASSERT_EQ(e1.direction, NORTH);
	
		actualInst = c.getNextInstruction(0);
		ASSERT_EQ(c.direction, EAST);

		d.simulateTurns(1);

		c1 = d.grid[1][1];	
		e1 = d.grid[2][2];

		ASSERT_EQ(c1.direction, EAST);
		ASSERT_EQ(e1.direction, WEST);
}

TEST(DarwinTest, darwin_print_7) {
		Species h = Species('h');
		h.addInstruction(HOP, 0);
 		h.addInstruction(GO, 0);	
		Darwin d = Darwin(3,3);
		d.addCreature(Creature(&h, SOUTH), 0,1);
		ostringstream w;	
		d.printDarwin(w);
		ASSERT_EQ(w.str(), "Turn = 0.\n  012\n0 .h.\n1 ...\n2 ...\n");

		d.simulateTurns(1);

		w.str("");
		d.printDarwin(w);
		ASSERT_EQ(w.str(), "Turn = 1.\n  012\n0 ...\n1 .h.\n2 ...\n");
}

TEST(DarwinTest, darwin_print_8) {
		Species r = Species('r');
    r.addInstruction(IF_ENEMY, 9);
    r.addInstruction(IF_EMPTY, 7);
    r.addInstruction(IF_RANDOM, 5);
    r.addInstruction(LEFT, 0);
    r.addInstruction(GO, 0);
    r.addInstruction(RIGHT, 0);
    r.addInstruction(GO, 0);
    r.addInstruction(HOP, 0);
    r.addInstruction(GO, 0);
    r.addInstruction(INFECT, 0);
    r.addInstruction(GO, 0);

		Darwin d = Darwin(3,3);
		d.addCreature(Creature(&r, SOUTH), 0,0);
		ostringstream w;
		d.printDarwin(w);
	
		ASSERT_EQ(w.str(), "Turn = 0.\n  012\n0 r..\n1 ...\n2 ...\n");
		d.simulateTurns(1);
		w.str("");
		d.printDarwin(w);
		ASSERT_EQ(w.str(), "Turn = 1.\n  012\n0 ...\n1 r..\n2 ...\n");


}











