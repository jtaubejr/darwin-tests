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
#include <sstream> // istringtstream, ostringstream
#include <string>  // string

using namespace std;

// ----------------------------------
// Test _rows and _cols set correctly
// ----------------------------------

TEST(DarwinFixture, DarwinConstructorTest1) {
  Darwin x(8, 8);
  ASSERT_EQ(x._rows, 8);
  ASSERT_EQ(x._cols, 8);
}

// ----------------------------------------------
// Test _grid size correctly set to _rows * _cols
// ----------------------------------------------

TEST(DarwinFixture, DarwinConstructorTest2) {
  Darwin x(8, 8);
  ASSERT_EQ((int)x._grid.size(), 8 * 8);
}

// -------------------------------------------------
// Test _grid default values are set correctly to -1
// -------------------------------------------------

TEST(DarwinFixture, DarwinConstructorTest3) {
  Darwin x(8, 8);
  ASSERT_EQ(x._grid[0], -1);
  ASSERT_EQ(x._grid[(int)x._grid.size() - 1], -1);
}

// -----------------------------------------
// Test _creatures vector is initially empty
// -----------------------------------------

TEST(DarwinFixture, DarwinConstructorTest4) {
  Darwin x(8, 8);
  ASSERT_EQ(x._creatures.size(), 0);
}

// ---------------------------------------
// Test a board that contains no creatures
// and thus does not branch in advance()
// ---------------------------------------

TEST(DarwinFixture, DarwinActionTestEmptyGrid) {
  Darwin x(8, 8);

  x.advance();

  ASSERT_EQ(x._grid[0], -1);
  ASSERT_EQ(x._grid[(int)x._grid.size() - 1], -1);
}

// -------------------------------------------------------------
// Test that HOP, LEFT, RIGHT, and INFECT are executed correctly
// -------------------------------------------------------------

TEST(DarwinFixture, DarwinActionTestHOP) {
  Darwin x(1, 2);
  Species testSpecies('#');
  testSpecies.addInstruction(Instruction::HOP);

  Creature testCreature(testSpecies, Direction::EAST);

  x.addCreature(testCreature, 0, 0);

  x.advance();

  ASSERT_EQ(x._grid[1], 0);
}

// performs a full hop circle
TEST(DarwinFixture, DarwinActionTestHOP2) {
  Darwin x(2, 2);
  Species testSpecies('1');

  testSpecies.addInstruction(Instruction::HOP);
  testSpecies.addInstruction(Instruction::RIGHT);
  testSpecies.addInstruction(Instruction::GO, 0);

  Creature testCreature(testSpecies, Direction::EAST);

  x.addCreature(testCreature, 0, 0);

  x.advance();

  ASSERT_EQ(x._grid[0], -1);

  x.advance();
  x.advance();

  ASSERT_EQ(x._grid[1], -1);

  x.advance();
  x.advance();

  ASSERT_EQ(x._grid[3], -1);

  x.advance();
  x.advance();

  ASSERT_EQ(x._grid[2], -1);
}

TEST(DarwinFixture, DarwinActionTestLEFT) {
  Darwin x(1, 1);
  Species testSpecies('#');
  testSpecies.addInstruction(Instruction::LEFT);

  Creature testCreature(testSpecies, Direction::WEST);

  x.addCreature(testCreature, 0, 0);

  x.advance();

  ASSERT_EQ(x._creatures[x._grid[0]]._dir, Direction::SOUTH);
}

TEST(DarwinFixture, DarwinActionTestRIGHT) {
  Darwin x(1, 1);
  Species testSpecies('#');
  testSpecies.addInstruction(Instruction::RIGHT);

  Creature testCreature(testSpecies, Direction::WEST);

  x.addCreature(testCreature, 0, 0);

  x.advance();

  ASSERT_EQ(x._creatures[x._grid[0]]._dir, Direction::NORTH);
}

TEST(DarwinFixture, DarwinActionTestINFECT) {
  Darwin x(1, 2);
  Species testSpecies1('a');
  Species testSpecies2('b');

  testSpecies1.addInstruction(Instruction::INFECT);

  // This instruction should logically never be executed
  testSpecies2.addInstruction(Instruction::LEFT);

  Creature testCreature1(testSpecies1, Direction::EAST);
  Creature testCreature2(testSpecies2, Direction::WEST);

  x.addCreature(testCreature1, 0, 0);
  x.addCreature(testCreature2, 0, 1);

  x.advance();

  ASSERT_TRUE(x._creatures[x._grid[0]] == x._creatures[x._grid[1]]);
}

TEST(DarwinFixture, DarwinHopFailureTest1) {
  Darwin x(1, 3);
  Species testSpecies1('a');
  Species testSpecies2('b');

  testSpecies1.addInstruction(Instruction::HOP);
  testSpecies2.addInstruction(Instruction::HOP);

  Creature testCreature1(testSpecies1, Direction::EAST);
  Creature testCreature2(testSpecies2, Direction::EAST);

  x.addCreature(testCreature1, 0, 0);
  x.addCreature(testCreature2, 0, 1);

  x.advance();

  ASSERT_TRUE(x._grid[0] == 0);
  ASSERT_TRUE(x._grid[2] == 1);
}

TEST(DarwinFixture, DarwinHopFailureTest2) {
  Darwin x(1, 2);
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::HOP);

  Creature testCreature(testSpecies, Direction::EAST);

  x.addCreature(testCreature, 0, 1);

  x.advance();

  ASSERT_TRUE(x._grid[1] == 0);
}

// Test of each path it is possible to take when constructing neighbors struct
// in advance
// if unsuccessful, a segfault will be triggered, else successful
TEST(DarwinFixture, DarwinNeighborStructTest) {
  Darwin x(5, 4);
  Species testSpecies1('a');
  Species testSpecies2('b');
  Species testSpecies3('c');
  Species testSpecies4('d');
  Species testSpecies5('e');
  Species testSpecies6('f');
  Species testSpecies7('g');
  Species testSpecies8('h');

  testSpecies1.addInstruction(Instruction::LEFT);
  testSpecies2.addInstruction(Instruction::LEFT);
  testSpecies3.addInstruction(Instruction::LEFT);
  testSpecies4.addInstruction(Instruction::LEFT);
  testSpecies5.addInstruction(Instruction::LEFT);
  testSpecies6.addInstruction(Instruction::LEFT);
  testSpecies7.addInstruction(Instruction::LEFT);
  testSpecies8.addInstruction(Instruction::LEFT);

  Creature testCreature1(testSpecies1, Direction::EAST);
  Creature testCreature2(testSpecies2, Direction::EAST);
  Creature testCreature3(testSpecies3, Direction::EAST);
  Creature testCreature4(testSpecies4, Direction::EAST);
  Creature testCreature5(testSpecies5, Direction::EAST);
  Creature testCreature6(testSpecies6, Direction::EAST);
  Creature testCreature7(testSpecies7, Direction::EAST);
  Creature testCreature8(testSpecies8, Direction::EAST);

  x.addCreature(testCreature1, 0, 3);
  x.addCreature(testCreature2, 1, 1);
  x.addCreature(testCreature3, 2, 2);
  x.addCreature(testCreature4, 3, 1);
  x.addCreature(testCreature5, 3, 2);
  x.addCreature(testCreature6, 3, 3);
  x.addCreature(testCreature7, 4, 0);
  x.addCreature(testCreature8, 4, 2);

  x.advance();

  // if we got here no segfault so every neighbor path is succcessful
  ASSERT_TRUE(true);
}

// -----------------------------------------
// Test that a Creature is succesfully added
// to the _creatures vertex
// -----------------------------------------

TEST(DarwinFixture, DarwinAddCreatureTest1) {
  Darwin x(1, 1);
  Species testSpecies('#');
  testSpecies.addInstruction(Instruction::HOP);

  Creature testCreature(testSpecies, Direction::WEST);

  // Assert that there are currently no Creatures in
  // the _creatures vector
  ASSERT_EQ((int)x._creatures.size(), 0);

  // Add the Creature
  x.addCreature(testCreature, 0, 0);

  // Assert that there is now exactly one Creature in
  // the _creatures vector
  ASSERT_EQ((int)x._creatures.size(), 1);

  // Assert that the Creature that was added is
  // the creature in the vector, by comparing species
  ASSERT_TRUE(testCreature == x._creatures[0]);
}

// -----------------------------------
// Test that multiple Creatures can be
// added to the _creatures vertex
// -----------------------------------

TEST(DarwinFixture, DarwinAddCreatureTest2) {
  Darwin x(1, 2);
  Species testSpecies1('a');
  testSpecies1.addInstruction(Instruction::HOP);

  Species testSpecies2('b');
  testSpecies2.addInstruction(Instruction::HOP);

  Creature testCreature1(testSpecies1, Direction::WEST);
  Creature testCreature2(testSpecies2, Direction::WEST);

  // Assert that there are currently no Creatures in
  // the _creatures vector
  ASSERT_EQ((int)x._creatures.size(), 0);

  // Add the Creatures
  x.addCreature(testCreature1, 0, 0);
  x.addCreature(testCreature2, 0, 1);

  // Assert that there are now exactly two Creatures in
  // the _creatures vector
  ASSERT_EQ((int)x._creatures.size(), 2);

  // Assert that the Creatures are different by comparing
  // their species
  ASSERT_FALSE(x._creatures[0] == x._creatures[1]);
}

// ---------------------------------------------------
// Test that Creatures are added to the grid correctly
// ---------------------------------------------------

TEST(DarwinFixture, DarwinAddCreatureTest3) {
  Darwin x(1, 1);
  Species testSpecies('#');
  testSpecies.addInstruction(Instruction::HOP);

  Creature testCreature(testSpecies, Direction::WEST);

  // Assert that there are currently no Creatures in
  // the _creatures vector
  ASSERT_EQ((int)x._creatures.size(), 0);

  // Add the Creature
  x.addCreature(testCreature, 0, 0);

  // Assert that there is now exactly one Creature in
  // the _creatures vector
  ASSERT_EQ((int)x._creatures.size(), 1);

  // Assert that the Creature was added to the
  // grid at the correct location
  ASSERT_EQ(x._grid[0], 0);
}

// -------------------------------------------
// Test that the Species constructor correctly
// sets each of its member variables
// -------------------------------------------

TEST(DarwinFixture, SpeciesConstructorTest1) {
  Species testSpecies('a');
  ASSERT_EQ((int)testSpecies._instructions.size(), 0);
}

TEST(DarwinFixture, SpeciesConstructorTest2) {
  Species testSpecies('a');
  ASSERT_EQ((int)testSpecies._parameter.size(), 0);
}

TEST(DarwinFixture, SpeciesConstructorTest3) {
  Species testSpecies('a');
  ASSERT_EQ(testSpecies._name, 'a');
}

TEST(DarwinFixture, ControlFlowTest1) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::IF_WALL, 2);
  testSpecies.addInstruction(Instruction::LEFT);
  testSpecies.addInstruction(Instruction::RIGHT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::WALL;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 3);
  ASSERT_EQ(ER._inst, Instruction::RIGHT);
}

TEST(DarwinFixture, ControlFlowTest2) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::IF_WALL, 2);
  testSpecies.addInstruction(Instruction::LEFT);
  testSpecies.addInstruction(Instruction::RIGHT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::EMPTY;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 2);
  ASSERT_EQ(ER._inst, Instruction::LEFT);
}

TEST(DarwinFixture, ControlFlowTest3) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::IF_EMPTY, 2);
  testSpecies.addInstruction(Instruction::LEFT);
  testSpecies.addInstruction(Instruction::RIGHT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::EMPTY;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 3);
  ASSERT_EQ(ER._inst, Instruction::RIGHT);
}

TEST(DarwinFixture, ControlFlowTest4) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::IF_EMPTY, 2);
  testSpecies.addInstruction(Instruction::LEFT);
  testSpecies.addInstruction(Instruction::RIGHT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::WALL;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 2);
  ASSERT_EQ(ER._inst, Instruction::LEFT);
}

TEST(DarwinFixture, ControlFlowTest5) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::IF_ENEMY, 2);
  testSpecies.addInstruction(Instruction::LEFT);
  testSpecies.addInstruction(Instruction::RIGHT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::ENEMY;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 3);
  ASSERT_EQ(ER._inst, Instruction::RIGHT);
}

TEST(DarwinFixture, ControlFlowTest6) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::IF_ENEMY, 2);
  testSpecies.addInstruction(Instruction::LEFT);
  testSpecies.addInstruction(Instruction::RIGHT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::FRIEND;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 2);
  ASSERT_EQ(ER._inst, Instruction::LEFT);
}

TEST(DarwinFixture, ControlFlowTest7) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::GO, 2);
  testSpecies.addInstruction(Instruction::LEFT);
  testSpecies.addInstruction(Instruction::RIGHT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::FRIEND;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 3);
  ASSERT_EQ(ER._inst, Instruction::RIGHT);
}

TEST(DarwinFixture, ControlFlowTest8) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::NOP);
  testSpecies.addInstruction(Instruction::LEFT);
  testSpecies.addInstruction(Instruction::RIGHT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::FRIEND;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 0);
  ASSERT_EQ(ER._inst, Instruction::HOP);
}

TEST(DarwinFixture, ControlFlowTest9) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::IF_WALL, 2);
  testSpecies.addInstruction(Instruction::LEFT);
  testSpecies.addInstruction(Instruction::GO, 1);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::WALL;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 2);
  ASSERT_EQ(ER._inst, Instruction::LEFT);
}

TEST(DarwinFixture, ControlFlowTest10) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::IF_WALL, 2);
  testSpecies.addInstruction(Instruction::IF_ENEMY, 3);
  testSpecies.addInstruction(Instruction::RIGHT);
  testSpecies.addInstruction(Instruction::LEFT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::ENEMY;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 4);
  ASSERT_EQ(ER._inst, Instruction::LEFT);
}

TEST(DarwinFixture, ControlFlowTest11) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::IF_WALL, 2);
  testSpecies.addInstruction(Instruction::IF_ENEMY, 3);
  testSpecies.addInstruction(Instruction::RIGHT);
  testSpecies.addInstruction(Instruction::LEFT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::FRIEND;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 3);
  ASSERT_EQ(ER._inst, Instruction::RIGHT);
}

TEST(DarwinFixture, ControlFlowTest12) {
  Species testSpecies('a');

  testSpecies.addInstruction(Instruction::IF_WALL, 2);
  testSpecies.addInstruction(Instruction::IF_ENEMY, 3);
  testSpecies.addInstruction(Instruction::IF_EMPTY, 4);
  testSpecies.addInstruction(Instruction::LEFT);
  testSpecies.addInstruction(Instruction::RIGHT);

  std::vector<Entity> neighbors(4);
  neighbors[Direction::WEST] = Entity::WALL;
  neighbors[Direction::NORTH] = Entity::WALL;
  neighbors[Direction::EAST] = Entity::WALL;
  neighbors[Direction::SOUTH] = Entity::WALL;

  ExecutionResult ER =
      testSpecies.executeProgram(neighbors, Direction::NORTH, 0);
  ASSERT_EQ(ER._pc, 4);
  ASSERT_EQ(ER._inst, Instruction::LEFT);
}

TEST(DarwinFixture, CreatureConstructorTest1) {
  Species species('#');
  species.addInstruction(Instruction::HOP);
  Creature creature(species, Direction::WEST);
  ASSERT_EQ(creature._dir, Direction::WEST);
}

TEST(DarwinFixture, CreatureConstructorTest2) {
  Species species('#');
  species.addInstruction(Instruction::HOP);
  Creature creature(species, Direction::WEST);
  ASSERT_EQ(creature._species._name, '#');
}

TEST(DarwinFixture, CreatureConstructorTest3) {
  Species species('#');
  species.addInstruction(Instruction::HOP);
  Creature creature(species, Direction::EAST);
  ASSERT_EQ(creature._dir, Direction::EAST);
}

TEST(DarwinFixture, CreatureConstructorTest4) {
  Species species('#');
  species.addInstruction(Instruction::LEFT);
  Creature creature(species, Direction::WEST);
  ASSERT_EQ(creature._species._instructions[0], Instruction::LEFT);
}

TEST(DarwinFixture, CreatureConstructorTest5) {
  Species species('#');
  species.addInstruction(Instruction::HOP);
  species.addInstruction(Instruction::RIGHT);
  Creature creature(species, Direction::WEST);
  ASSERT_EQ(creature._species._instructions[1], Instruction::RIGHT);
}

TEST(DarwinFixture, CreatureConstructorTest6) {
  Species species('#');
  species.addInstruction(Instruction::GO, 9);
  Creature creature(species, Direction::WEST);
  ASSERT_EQ(creature._species._parameter[0], 9);
}

TEST(DarwinFixture, CreatureConstructorTest7) {
  Species species('#');
  species.addInstruction(Instruction::GO, 9);
  Creature creature(species, Direction::WEST);
  ASSERT_EQ((int)creature._species._instructions.size(), 1);
}

TEST(DarwinFixture, CreatureConstructorTest8) {
  Species species('#');
  species.addInstruction(Instruction::GO, 9);
  Creature creature(species, Direction::WEST);
  ASSERT_EQ((int)creature._species._parameter.size(), 1);
}

TEST(DarwinFixture, CreatureEqualityTest1) {
  Species species('#');
  species.addInstruction(Instruction::HOP);
  Creature creature1(species, Direction::WEST);
  Creature creature2(species, Direction::WEST);
  ASSERT_TRUE(creature1 == creature2);
}

TEST(DarwinFixture, CreatureEqualityTest2) {
  Species species1('a');
  Species species2('b');
  species1.addInstruction(Instruction::HOP);
  species2.addInstruction(Instruction::HOP);
  Creature creature1(species1, Direction::WEST);
  Creature creature2(species2, Direction::WEST);
  ASSERT_FALSE(creature1 == creature2);
}

TEST(DarwinFixture, CreatureEqualityTest3) {
  Species species('#');
  species.addInstruction(Instruction::HOP);
  Creature creature(species, Direction::WEST);
  ASSERT_TRUE(creature == creature);
}

TEST(DarwinFixture, SpeciesEqualityTest1) {
  Species species1('a');
  Species species2('a');
  species1.addInstruction(Instruction::HOP);
  species2.addInstruction(Instruction::HOP);
  ASSERT_TRUE(species1 == species2);
}

TEST(DarwinFixture, SpeciesEqualityTest2) {
  Species species1('a');
  Species species2('b');
  species1.addInstruction(Instruction::HOP);
  species2.addInstruction(Instruction::HOP);
  ASSERT_FALSE(species1 == species2);
}

TEST(DarwinFixture, SpeciesEqualityTest3) {
  Species species('#');
  ASSERT_TRUE(species == species);
}

TEST(DarwinFixture, ActionConstructorTest1) {
  struct Action action(Instruction::HOP, Direction::WEST);
  ASSERT_EQ(action._inst, Instruction::HOP);
  ASSERT_EQ(action._dir, Direction::WEST);
}

TEST(DarwinFixture, ActionConstructorTest2) {
  struct Action action(Instruction::LEFT, Direction::WEST);
  ASSERT_EQ(action._inst, Instruction::LEFT);
  ASSERT_EQ(action._dir, Direction::WEST);
}

TEST(DarwinFixture, ActionConstructorTest3) {
  struct Action action(Instruction::RIGHT, Direction::WEST);
  ASSERT_EQ(action._inst, Instruction::RIGHT);
  ASSERT_EQ(action._dir, Direction::WEST);
}

TEST(DarwinFixture, ActionConstructorTest4) {
  struct Action action(Instruction::INFECT, Direction::WEST);
  ASSERT_EQ(action._inst, Instruction::INFECT);
  ASSERT_EQ(action._dir, Direction::WEST);
}

TEST(DarwinFixture, ActionConstructorTest5) {
  struct Action action(Instruction::IF_EMPTY, Direction::WEST);
  ASSERT_EQ(action._inst, Instruction::IF_EMPTY);
  ASSERT_EQ(action._dir, Direction::WEST);
}

TEST(DarwinFixture, ActionConstructorTest6) {
  struct Action action(Instruction::IF_WALL, Direction::WEST);
  ASSERT_EQ(action._inst, Instruction::IF_WALL);
  ASSERT_EQ(action._dir, Direction::WEST);
}

TEST(DarwinFixture, ExecutionResultTest1) {
  struct ExecutionResult executionResult(Instruction::IF_WALL, 4);
  ASSERT_EQ(executionResult._inst, Instruction::IF_WALL);
  ASSERT_EQ(executionResult._pc, 4);
}

TEST(DarwinFixture, ExecutionResultTest2) {
  struct ExecutionResult executionResult(Instruction::IF_WALL, 0);
  ASSERT_EQ(executionResult._inst, Instruction::IF_WALL);
  ASSERT_EQ(executionResult._pc, 0);
}

TEST(DarwinFixture, ExecutionResultTest3) {
  struct ExecutionResult executionResult(Instruction::IF_RANDOM, 0);
  ASSERT_EQ(executionResult._inst, Instruction::IF_RANDOM);
  ASSERT_EQ(executionResult._pc, 0);
}

TEST(DarwinFixture, ExecutionResultTest4) {
  struct ExecutionResult executionResult(Instruction::IF_ENEMY, 0);
  ASSERT_EQ(executionResult._inst, Instruction::IF_ENEMY);
  ASSERT_EQ(executionResult._pc, 0);
}

TEST(DarwinFixture, ExecutionResultTest5) {
  struct ExecutionResult executionResult(Instruction::GO, 0);
  ASSERT_EQ(executionResult._inst, Instruction::GO);
  ASSERT_EQ(executionResult._pc, 0);
}

TEST(DarwinFixture, ExecutionResultTest6) {
  struct ExecutionResult executionResult(Instruction::IF_WALL, 2);
  ASSERT_EQ(executionResult._inst, Instruction::IF_WALL);
  ASSERT_EQ(executionResult._pc, 2);
}
