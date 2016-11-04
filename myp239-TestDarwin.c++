#include "Darwin.h"
#include "gtest/gtest.h"

using namespace std;

//struct location
//    bool operator == (const location& other)      CHECK
//    bool operator != (const location& other)      CHECK
//    location space_ahead(const orientation& ortn) CHECK

TEST(Left_Turn, left_turn1) {
	Darwin darwin(8, 8);
	Species food("food");

	Creature c1(food);

	darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));
	darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(WEST, dir);
}

TEST(Left_Turn, left_turn2) {
	Darwin darwin(8, 8);
	Species food("food");

	Creature c1(food);

	darwin.addCreature(c1, WEST, pair<int, int>(0, 0));
	darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(SOUTH, dir);
}

TEST(Left_Turn, left_turn3) {
Darwin darwin(8, 8);
	Species food("food");

	Creature c1(food);

	darwin.addCreature(c1, SOUTH, pair<int, int>(0, 0));
	darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(EAST, dir);
}

TEST(Left_Turn, left_turn4) {
Darwin darwin(8, 8);
	Species food("food");

	Creature c1(food);

	darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
	darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(NORTH, dir);
}

TEST(Left_Turn, left_turn5) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(SOUTH, dir);
}

TEST(Left_Turn, left_turn6) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(EAST, dir);
}

TEST(Left_Turn, left_turn7) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(NORTH, dir);
}

TEST(Right_Turn, right_turn1) {
Darwin darwin(8, 8);
	Species food("food");

	Creature c1(food);

	darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));
	darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(EAST, dir);
}

TEST(Right_Turn, right_turn2) {
Darwin darwin(8, 8);
	Species food("food");

	Creature c1(food);

	darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
	darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(SOUTH, dir);
}

TEST(Right_Turn, right_turn3) {
Darwin darwin(8, 8);
	Species food("food");

	Creature c1(food);

	darwin.addCreature(c1, SOUTH, pair<int, int>(0, 0));
	darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(WEST, dir);
}

TEST(Right_Turn, right_turn4) {
Darwin darwin(8, 8);
	Species food("food");

	Creature c1(food);

	darwin.addCreature(c1, WEST, pair<int, int>(0, 0));
	darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(NORTH, dir);
}

TEST(Right_Turn, right_turn5) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(SOUTH, dir);
}

TEST(Right_Turn, right_turn6) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(WEST, dir);
}

TEST(Right_Turn, right_turn7) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(NORTH, dir);
}

TEST(Hop, hop1) {
	Darwin darwin(8, 8);

	Species hopper("hopper");
	hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Creature c1(hopper);

	darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
	darwin.step();
	Creature* c2 = darwin._locationToCreature[pair<int, int>(0, 1)];

	ASSERT_EQ(c1._id, c2->_id);
}

TEST(Hop, hop2) {
    Darwin darwin(8, 8);

    Species hopper("hopper");
    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Creature c1(hopper);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.step();
    darwin.step();
    Creature* c2 = darwin._locationToCreature[pair<int, int>(0, 2)];

    ASSERT_EQ(c1._id, c2->_id);
}

TEST(Hop, hop3) {
    Darwin darwin(8, 8);

    Species hopper("hopper");
    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Creature c1(hopper);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.step();
    darwin.step();
    darwin.step();
    Creature* c2 = darwin._locationToCreature[pair<int, int>(0, 3)];

    ASSERT_EQ(c1._id, c2->_id);
}

TEST(Hop, hop4) {
    Darwin darwin(8, 8);

    Species hopper("hopper");
    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Creature c1(hopper);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.step();
    darwin.step();
    darwin.step();
    darwin.step();
    Creature* c2 = darwin._locationToCreature[pair<int, int>(0, 4)];

    ASSERT_EQ(c1._id, c2->_id);
}

TEST(Hop, hop5) {
    Darwin darwin(8, 8);

    Species hopper("hopper");
    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Creature c1(hopper);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.step();
    darwin.step();
    darwin.step();
    darwin.step();
    darwin.step();
    Creature* c2 = darwin._locationToCreature[pair<int, int>(0, 5)];

    ASSERT_EQ(c1._id, c2->_id);
}

TEST(Infect, infect1)
{
    Darwin darwin(8, 8);

    Species infector("infector");
    Species food("food");

    infector.addInstruction(INFECT);
    infector.addInstruction(GO, 0);

    Creature c1(infector);
    Creature c2(food);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.addCreature(c2, EAST, pair<int, int>(0, 1));

    darwin.step();
    Creature* c3 = darwin._locationToCreature[pair<int, int>(0, 1)];

    ASSERT_EQ(c1.getSpecies().getName(), c3->getSpecies().getName());
}

TEST(Infect, infect2)
{
    Darwin darwin(8, 8);

    Species infector("infector");
    Species food("food");

    infector.addInstruction(INFECT);
    infector.addInstruction(GO, 0);

    Creature c1(infector);
    Creature c2(food);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.addCreature(c2, EAST, pair<int, int>(0, 1));

    darwin.step();
    Creature* c3 = darwin._locationToCreature[pair<int, int>(0, 1)];

    ASSERT_EQ(c1.getSpecies().getName(), c3->getSpecies().getName());
}

TEST(Infect, infect3)
{
    Darwin darwin(8, 8);

    Species infector("infector");
    Species food("food");

    infector.addInstruction(INFECT);
    infector.addInstruction(GO, 0);

    Creature c1(infector);
    Creature c2(food);
    Creature c6(food);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.addCreature(c2, EAST, pair<int, int>(0, 1));

    darwin.step();
    Creature* c3 = darwin._locationToCreature[pair<int, int>(0, 1)];

    ASSERT_EQ(c1.getSpecies().getName(), c3->getSpecies().getName());
}

TEST(Infect, infect4)
{
    Darwin darwin(8, 8);

    Species infector("infector");
    Species food("food");

    infector.addInstruction(INFECT);
    infector.addInstruction(GO, 0);

    Creature c1(infector);
    Creature c2(food);
    Creature c6(food);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.addCreature(c2, EAST, pair<int, int>(0, 1));
    darwin.addCreature(c6, EAST, pair<int, int>(0, 2));

    darwin.step();
    Creature* c3 = darwin._locationToCreature[pair<int, int>(0, 1)];

    ASSERT_EQ(c1.getSpecies().getName(), c3->getSpecies().getName());
}

TEST(Infect, infect5)
{
    Darwin darwin(8, 8);

    Species infector("infector");
    Species food("food");

    infector.addInstruction(INFECT);
    infector.addInstruction(GO, 0);

    Creature c1(infector);
    Creature c2(food);
    Creature c6(food);
    Creature c7(food);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.addCreature(c2, EAST, pair<int, int>(0, 1));
    darwin.addCreature(c6, EAST, pair<int, int>(0, 2));
    darwin.addCreature(c7, EAST, pair<int, int>(0, 3));

    darwin.step();
    Creature* c3 = darwin._locationToCreature[pair<int, int>(0, 1)];

    ASSERT_EQ(c1.getSpecies().getName(), c3->getSpecies().getName());
}

TEST(Generate_Random_Position, generate_random_position1)
{
    int x = 50;
    int y = 50;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_LT(p1.first, x);
}

TEST(Generate_Random_Position, generate_random_position2)
{
    int x = 50;
    int y = 50;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_LT(p1.second, y);
}

TEST(Generate_Random_Position, generate_random_position3)
{
    int x = 100;
    int y = 100;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_LT(p1.first, x);
}

TEST(Generate_Random_Position, generate_random_position4)
{
    int x = 100;
    int y = 100;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_LT(p1.second, y);
}

TEST(Generate_Random_Position, generate_random_position5)
{
    int x = 150;
    int y = 150;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_LT(p1.first, x);
}

TEST(Generate_Random_Position, generate_random_position6)
{
    int x = 150;
    int y = 150;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_LT(p1.second, y);
}

TEST(Generate_Random_Position, generate_random_position7)
{
    int x = 200;
    int y = 200;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_LT(p1.first, x);
}

TEST(Generate_Random_Position, generate_random_position8)
{
    int x = 200;
    int y = 200;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_LT(p1.second, y);
}

TEST(Generate_Random_Position, generate_random_position9)
{
    int x = 100;
    int y = 100;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_GE(p1.first, 0);
}

TEST(Generate_Random_Position, generate_random_position10)
{
    int x = 100;
    int y = 100;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_GE(p1.second, 0);
}

TEST(Generate_Random_Position, generate_random_position11)
{
    int x = 150;
    int y = 150;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_GE(p1.first, 0);
}

TEST(Generate_Random_Position, generate_random_position12)
{
    int x = 150;
    int y = 150;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_GE(p1.second, 0);
}

TEST(Generate_Random_Position, generate_random_position13)
{
    int x = 10;
    int y = 10;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_GE(p1.first, 0);
}

TEST(Generate_Random_Position, generate_random_position14)
{
    int x = 10;
    int y = 10;
    Darwin darwin(x, y);

    pair<int, int> p1 = darwin.generateRandomPosition();

    ASSERT_GE(p1.second, 0);
}

TEST(CreatureClass, creatureSpecies1)
{
    Species s("testSpecies");
    Creature c(s);

    ASSERT_EQ(c.getSpecies().getName(), "testSpecies");
}

TEST(CreatureClass, creatureSpecies2)
{
    Species s("");
    Creature c(s);

    ASSERT_EQ(c.getSpecies().getName(), "");
}

TEST(CreatureClass, creatureSpecies3)
{
    Species a("a");
    Species b("b");

    Creature c(a);

    ASSERT_EQ(c.getSpecies().getName(), "a");

    c.setSpecies(b);

    ASSERT_EQ(c.getSpecies().getName(), "b");
}

TEST(CreatureClass, resetSpeciesPC1)
{
    Species s("s");
    s.addInstruction(LEFT);
    s.addInstruction(RIGHT);
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);

    Species b("b");

    Creature c(s);
    c._programCounter = 2;

    c.setSpecies(b);

    ASSERT_EQ(c.getSpecies().getName(), "b");
    ASSERT_EQ(c._programCounter, 0);
}

TEST(CreatureClass, resetSpeciesPC2)
{
    Species s("s");
    s.addInstruction(LEFT);
    s.addInstruction(RIGHT);

    Species b("b");

    Creature c(s);
    c._programCounter = 2;

    c.setSpecies(b);

    ASSERT_EQ(c.getSpecies().getName(), "b");
    ASSERT_EQ(c._programCounter, 0);
}

TEST(CreatureClass, resetSpeciesPC3)
{
    Species s("s");
    s.addInstruction(HOP);
    s.addInstruction(GO, 0);

    Species b("b");

    Creature c(s);
    c._programCounter = 2;

    c.setSpecies(b);

    ASSERT_EQ(c.getSpecies().getName(), "b");
    ASSERT_EQ(c._programCounter, 0);
}

TEST(CreatureClass, resetSpeciesPC4)
{
    Species s("s");
    s.addInstruction(LEFT);

    Species b("b");

    Creature c(s);
    c._programCounter = 2;

    c.setSpecies(b);

    ASSERT_EQ(c.getSpecies().getName(), "b");
    ASSERT_EQ(c._programCounter, 0);
}

TEST(CreatureClass, resetSpeciesPC5)
{
    Species s("s");

    Species b("b");

    Creature c(s);
    c._programCounter = 2;

    c.setSpecies(b);

    ASSERT_EQ(c.getSpecies().getName(), "b");
    ASSERT_EQ(c._programCounter, 0);
}

TEST(DarwinClass, validPosition1)
{
    Darwin d(8, 8);
    pair<int, int> in(7, 7);

    ASSERT_EQ(d.validPosition(in), true);
}

TEST(DarwinClass, validPosition2)
{
    Darwin d(7, 7);
    pair<int, int> out(1, 7);

    ASSERT_EQ(d.validPosition(out), false);
}

TEST(DarwinClass, validPosition3)
{
    Darwin d(7, 7);
    pair<int, int> out(7, 7);

    ASSERT_EQ(d.validPosition(out), false);
}

TEST(DarwinClass, validPosition4)
{
    Darwin d(7, 7);
    pair<int, int> out(7, 7);

    ASSERT_NE(d.validPosition(out), true);
}

TEST(DarwinClass, validPosition5)
{
    Darwin d(7, 7);
    pair<int, int> out(7, 7);

    ASSERT_NE(d.validPosition(out), true);
}

TEST(DarwinClass, validPosition6)
{
    Darwin d(7, 7);
    pair<int, int> out(7, 7);

    ASSERT_NE(d.validPosition(out), true);
}

TEST(DarwinClass, hasCreature1)
{
    Darwin d(8, 8);
    Species s("");
    Creature c(s);

    d.addCreature(c, WEST, pair<int, int>(0, 0));

    ASSERT_EQ(d.hasCreature(pair<int, int>(0, 0)), true);
}

TEST(DarwinClass, hasCreature2)
{
    Darwin d(8, 8);
    Species s("");
    Creature c(s);

    d.addCreature(c, WEST, pair<int, int>(2, 2));

    ASSERT_EQ(d.hasCreature(pair<int, int>(2, 2)), true);
}

TEST(DarwinClass, hasCreature3)
{
    Darwin d(8, 8);
    Species s("");
    Creature c(s);

    d.addCreature(c, WEST, pair<int, int>(0, 0));
    
    ASSERT_EQ(d.hasCreature(pair<int, int>(1, 1)), false);
}

TEST(DarwinClass, hasCreature4)
{
    Darwin d(8, 8);
    Species s("");
    Creature c(s);

    d.addCreature(c, WEST, pair<int, int>(0, 0));
    
    ASSERT_NE(d.hasCreature(pair<int, int>(1, 1)), true);
}

TEST(DarwinClass, hasCreature5)
{
    Darwin d(8, 8);
    Species s("");
    Creature c(s);

    d.addCreature(c, EAST, pair<int, int>(0, 0));
    
    ASSERT_NE(d.hasCreature(pair<int, int>(1, 1)), true);
}

TEST(DarwinClass, hasCreature6)
{
    Darwin d(8, 8);
    Species s("");
    Creature c(s);

    d.addCreature(c, NORTH, pair<int, int>(0, 0));
    
    ASSERT_NE(d.hasCreature(pair<int, int>(1, 1)), true);
}

TEST(DarwinClass, hasCreature7)
{
    Darwin d(8, 8);
    Species s("");
    Creature c(s);

    d.addCreature(c, SOUTH, pair<int, int>(0, 0));
    
    ASSERT_NE(d.hasCreature(pair<int, int>(1, 1)), true);
}

TEST(DarwinClass, hasCreature8)
{
    Darwin d(8, 8);
    Species s("");
    Creature c(s);
    Creature c1(s);

    d.addCreature(c, WEST, pair<int, int>(0, 0));
    d.addCreature(c1, WEST, pair<int, int>(0, 0));
    
    ASSERT_NE(d.hasCreature(pair<int, int>(1, 1)), true);
}

TEST(DarwinClass, facingDirection1)
{
    Darwin d(2, 2);
    Species s("");
    Creature c(s);

    d.addCreature(c, EAST, pair<int, int>(0, 0));

    pair<int, int> location = d.getFacingPosition(c);

    ASSERT_EQ(location.first, 0);
    ASSERT_EQ(location.second, 1);
}

TEST(DarwinClass, facingDirection2)
{
    Darwin d(1, 1);
    Species s("");
    Creature c(s);

    d.addCreature(c, EAST, pair<int, int>(0, 0));

    pair<int, int> location = d.getFacingPosition(c);
    ASSERT_EQ(location.first, 0);
    ASSERT_EQ(location.second, 1);
}

TEST(DarwinClass, facingDirection3)
{
    Darwin d(2, 2);

    Species s("");
    Creature c(s);

    pair<int, int> location = d.getFacingPosition(c);

    ASSERT_EQ(location.first, -1);
    ASSERT_EQ(location.second, -1);
}

TEST(DarwinClass, facingDirection4)
{
    Darwin d(2, 2);

    Species s("");
    Creature c(s);
    Creature c1(s);

    pair<int, int> location = d.getFacingPosition(c);

    ASSERT_EQ(location.first, -1);
    ASSERT_EQ(location.second, -1);
}

TEST(DarwinClass, facingDirection5)
{
    Darwin d(2, 2);

    Species s("");
    Creature c(s);

    pair<int, int> location = d.getFacingPosition(c);

    ASSERT_EQ(location.first, -1);
    ASSERT_EQ(location.second, -1);
}

TEST(DarwinClass, facingDirection6)
{
    Darwin d(2, 2);

    Species s("");
    Species s1("s1");
    Species s2("s2");
    Species s3("s3");
    Species s4("s4");
    Creature c(s);

    pair<int, int> location = d.getFacingPosition(c);

    ASSERT_EQ(location.first, -1);
    ASSERT_EQ(location.second, -1);
}

TEST(DarwinClass, facingDirection7)
{
    Darwin d(2, 2);

    Species s("");
    Species s1("s1");
    Species s2("s2");
    Creature c(s);

    pair<int, int> location = d.getFacingPosition(c);

    ASSERT_EQ(location.first, -1);
    ASSERT_EQ(location.second, -1);
}

TEST(DarwinClass, facingDirection8)
{
    Darwin d(2, 2);

    Species s("");
    Creature c(s);

    pair<int, int> location = d.getFacingPosition(c);

    ASSERT_EQ(location.first, -1);
    ASSERT_EQ(location.second, -1);
}






















TEST(Not_Left_Turn, not_left_turn1) {
    Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));
    darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Left_Turn, not_left_turn2) {
    Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, WEST, pair<int, int>(0, 0));
    darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Left_Turn, not_left_turn3) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, SOUTH, pair<int, int>(0, 0));
    darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Left_Turn, not_left_turn4) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Left_Turn, not_left_turn5) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Left_Turn, not_left_turn6) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Left_Turn, not_left_turn7) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    darwin.processTurn(c1, true); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Right_Turn, not_right_turn1) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));
    darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Right_Turn, not_right_turn2) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, EAST, pair<int, int>(0, 0));
    darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_EQ(SOUTH, dir);
}

TEST(Not_Right_Turn, not_right_turn3) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, SOUTH, pair<int, int>(0, 0));
    darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Right_Turn, not_right_turn4) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, WEST, pair<int, int>(0, 0));
    darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Right_Turn, not_right_turn5) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Right_Turn, not_right_turn6) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}

TEST(Not_Right_Turn, not_right_turn7) {
Darwin darwin(8, 8);
    Species food("food");

    Creature c1(food);

    darwin.addCreature(c1, NORTH, pair<int, int>(0, 0));

    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    darwin.processTurn(c1, false); // true indicates left turn
    
    Direction dir = darwin._creatureToState[&c1].dir;

    ASSERT_NE(4, dir);
}







TEST(Not_Hop, not_hop1) {
    Darwin darwin(8, 8);

    Species hopper("hopper");
    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Creature c1(hopper);

    darwin.addCreature(c1, WEST, pair<int, int>(0, 0));
    darwin.step();
    Creature* c2 = darwin._locationToCreature[pair<int, int>(0, 0)];

    ASSERT_EQ(c1._id, c2->_id);
}

TEST(Not_Hop, not_hop2) {
    Darwin darwin(8, 8);

    Species hopper("hopper");
    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Creature c1(hopper);

    darwin.addCreature(c1, WEST, pair<int, int>(0, 0));
    darwin.step();
    darwin.step();
    Creature* c2 = darwin._locationToCreature[pair<int, int>(0, 0)];

    ASSERT_EQ(c1._id, c2->_id);
}

TEST(Not_Not_Hop, not_hop3) {
    Darwin darwin(8, 8);

    Species hopper("hopper");
    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Creature c1(hopper);

    darwin.addCreature(c1, WEST, pair<int, int>(0, 0));
    darwin.step();
    darwin.step();
    darwin.step();
    Creature* c2 = darwin._locationToCreature[pair<int, int>(0, 0)];

    ASSERT_EQ(c1._id, c2->_id);
}

TEST(Not_Hop, not_hop4) {
    Darwin darwin(8, 8);

    Species hopper("hopper");
    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Creature c1(hopper);

    darwin.addCreature(c1, WEST, pair<int, int>(0, 0));
    darwin.step();
    darwin.step();
    darwin.step();
    darwin.step();
    Creature* c2 = darwin._locationToCreature[pair<int, int>(0, 0)];

    ASSERT_EQ(c1._id, c2->_id);
}

TEST(Not_Hop, not_hop5) {
    Darwin darwin(8, 8);

    Species hopper("hopper");
    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    Creature c1(hopper);

    darwin.addCreature(c1, WEST, pair<int, int>(0, 0));
    darwin.step();
    darwin.step();
    darwin.step();
    darwin.step();
    darwin.step();
    Creature* c2 = darwin._locationToCreature[pair<int, int>(0, 0)];

    ASSERT_EQ(c1._id, c2->_id);
}

TEST(Add_Instruction, add_instruction1) {
    Species hopper("hopper");

    hopper.addInstruction(HOP);
    hopper.addInstruction(GO, 0);

    ASSERT_EQ(hopper._program.size(), 2);
}

TEST(Add_Instruction, add_instruction2) {
    Species food("food");

    food.addInstruction(LEFT);
    food.addInstruction(GO, 0);
    // Never reached in a sane world
    food.addInstruction(LEFT);
    food.addInstruction(GO, 0);

    ASSERT_EQ(food._program.size(), 4);
}

TEST(Add_Instruction, add_instruction3) {
    Species test("test");

    test.addInstruction(HOP);
    test.addInstruction(HOP);
    test.addInstruction(HOP);

    ASSERT_EQ(test._program.size(), 3);
}

TEST(Add_Instruction, add_instruction4) {
    Species test("test");

    test.addInstruction(HOP);
    test.addInstruction(HOP);
    test.addInstruction(HOP);
    test.addInstruction(HOP);

    ASSERT_EQ(test._program.size(), 4);
}

TEST(Add_Instruction, add_instruction5) {
    Species test("test");

    test.addInstruction(HOP);
    test.addInstruction(HOP);
    test.addInstruction(HOP);
    test.addInstruction(HOP);
    test.addInstruction(HOP);

    ASSERT_EQ(test._program.size(), 5);
}

TEST(Add_Instruction, add_instruction6) {
    Species test("test");

    ASSERT_EQ(test._program.size(), 0);
}


