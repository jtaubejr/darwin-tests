//-----------------------------
// projects/darwin/RunDarwin.c++
// Copyright (C) 2016
// Glenn P. Downing
// -----------------------------

// --------
// includes
// --------

#include <cassert>   // assert
#include <cstdlib>   // rand, srand
#include <iostream>  // cout, endl
#include <stdexcept> // invalid_argument, out_of_range

#include "Darwin.h"

// ----
// main
// ----

int main () {
    using namespace std;

    // ----
    // food
    // ----

    /*
     0: left
     1: go 0
    */

    // ------
    // hopper
    // ------

    /*
     0: hop
     1: go 0
    */

    // -----
    // rover
    // -----

    /*
     0: if_enemy 9
     1: if_empty 7
     2: if_random 5
     3: left
     4: go 0
     5: right
     6: go 0
     7: hop
     8: go 0
     9: infect
    10: go 0
    */

    // ----
    // trap
    // ----

    /*
     0: if_enemy 3
     1: left
     2: go 0
     3: infect
     4: go 0
    */

    // ----------
    // darwin 8x8
    // ----------

    cout << "*** Darwin 8x8 ***" << endl;
    
    Darwin simulator(8, 8);
    
    Species f1("f","east");
    simulator.placeInGrid((Species*)&f1, 0, 0);
    
    Species f2("f","north");
    simulator.placeInGrid((Species*)&f2, 7, 7);
    
    Species h1("h","north");
    simulator.placeInGrid((Species*)&h1, 3, 3);
    
    Species h2("h","east");
    simulator.placeInGrid((Species*)&h2, 3, 4);
    
    Species h3("h","south");
    simulator.placeInGrid((Species*)&h3, 4, 4);

    Species h4("h","west");
    simulator.placeInGrid((Species*)&h4, 4, 3);

    simulator.startDarwin(5);


    // ----------
    // darwin 7x9
    // ----------

    cout << "*** Darwin 7x9 ***" << endl;
    srand(0);

    Darwin simulator2(9, 7);

    Species t21("t","south");
    simulator2.placeInGrid((Species*)&t21, 0, 0);

    Species t22("t","west");
    simulator2.placeInGrid((Species*)&t22, 6, 8);
    
    Species h21("h","east");
    simulator2.placeInGrid((Species*)&h21, 3, 2);

    Species r21("r","north");
    simulator2.placeInGrid((Species*)&r21, 5, 4);

    simulator2.startDarwin(5);

    // ------------
    // darwin 72x72
    // without best
    // ------------

    cout << "*** Darwin 72x72 without Best ***" << endl;
    srand(0);
    Darwin simulator3(72, 72);

    int val = rand() % 5184;
    Species f30("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f30, val/72, val%72);

    val = rand() % 5184;
    Species f31("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f31, val/72 ,val%72);

    val = rand() % 5184;    
    Species f32("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f32, val/72 ,val%72);
   
    val = rand() % 5184;    
    Species f33("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f33, val/72 ,val%72);

    val = rand() % 5184;    
    Species f34("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f34, val/72 ,val%72);

    val = rand() % 5184;    
    Species f35("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f35, val/72 ,val%72);

    val = rand() % 5184;    
    Species f36("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f36, val/72 ,val%72);

    val = rand() % 5184;    
    Species f37("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f37, val/72 ,val%72);

    val = rand() % 5184;    
    Species f38("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f38, val/72 ,val%72);

    val = rand() % 5184;
    Species f39("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f39, val/72 ,val%72);



    val = rand() % 5184;
    Species h30("h", rand() % 4);
    simulator3.placeInGrid((Species*) &h30, val/72, val%72);

    val = rand() % 5184;
    Species h31("h", rand() % 4);
    simulator3.placeInGrid((Species*) &h31, val/72 ,val%72);

    val = rand() % 5184;    
    Species h32("h", rand() % 4);
    simulator3.placeInGrid((Species*) &h32, val/72 ,val%72);
   
    val = rand() % 5184;    
    Species h33("h", rand() % 4);
    simulator3.placeInGrid((Species*) &h33, val/72 ,val%72);

    val = rand() % 5184;    
    Species h34("h", rand() % 4);
    simulator3.placeInGrid((Species*) &h34, val/72 ,val%72);

    val = rand() % 5184;    
    Species h35("h", rand() % 4);
    simulator3.placeInGrid((Species*) &h35, val/72 ,val%72);

    val = rand() % 5184;    
    Species h36("h", rand() % 4);
    simulator3.placeInGrid((Species*) &h36, val/72 ,val%72);

    val = rand() % 5184;    
    Species h37("h", rand() % 4);
    simulator3.placeInGrid((Species*) &h37, val/72 ,val%72);

    val = rand() % 5184;    
    Species h38("h", rand() % 4);
    simulator3.placeInGrid((Species*) &h38, val/72 ,val%72);

    val = rand() % 5184;
    Species h39("h", rand() % 4);
    simulator3.placeInGrid((Species*) &h39, val/72 ,val%72);




    val = rand() % 5184;
    Species r30("r", rand() % 4);
    simulator3.placeInGrid((Species*) &r30, val/72, val%72);

    val = rand() % 5184;
    Species r31("r", rand() % 4);
    simulator3.placeInGrid((Species*) &r31, val/72 ,val%72);

    val = rand() % 5184;    
    Species r32("r", rand() % 4);
    simulator3.placeInGrid((Species*) &r32, val/72 ,val%72);
   
    val = rand() % 5184;    
    Species r33("r", rand() % 4);
    simulator3.placeInGrid((Species*) &r33, val/72 ,val%72);

    val = rand() % 5184;    
    Species r34("r", rand() % 4);
    simulator3.placeInGrid((Species*) &r34, val/72 ,val%72);

    val = rand() % 5184;    
    Species r35("r", rand() % 4);
    simulator3.placeInGrid((Species*) &r35, val/72 ,val%72);

    val = rand() % 5184;    
    Species r36("r", rand() % 4);
    simulator3.placeInGrid((Species*) &r36, val/72 ,val%72);

    val = rand() % 5184;    
    Species r37("r", rand() % 4);
    simulator3.placeInGrid((Species*) &r37, val/72 ,val%72);

    val = rand() % 5184;    
    Species r38("r", rand() % 4);
    simulator3.placeInGrid((Species*) &r38, val/72 ,val%72);

    val = rand() % 5184;
    Species r39("r", rand() % 4);
    simulator3.placeInGrid((Species*) &r39, val/72 ,val%72);




    val = rand() % 5184;
    Species t30("t", rand() % 4);
    simulator3.placeInGrid((Species*) &t30, val/72, val%72);

    val = rand() % 5184;
    Species t31("t", rand() % 4);
    simulator3.placeInGrid((Species*) &t31, val/72 ,val%72);

    val = rand() % 5184;    
    Species t32("t", rand() % 4);
    simulator3.placeInGrid((Species*) &t32, val/72 ,val%72);
   
    val = rand() % 5184;    
    Species t33("t", rand() % 4);
    simulator3.placeInGrid((Species*) &t33, val/72 ,val%72);

    val = rand() % 5184;    
    Species t34("t", rand() % 4);
    simulator3.placeInGrid((Species*) &t34, val/72 ,val%72);

    val = rand() % 5184;    
    Species t35("t", rand() % 4);
    simulator3.placeInGrid((Species*) &t35, val/72 ,val%72);

    val = rand() % 5184;    
    Species t36("t", rand() % 4);
    simulator3.placeInGrid((Species*) &t36, val/72 ,val%72);

    val = rand() % 5184;    
    Species t37("t", rand() % 4);
    simulator3.placeInGrid((Species*) &t37, val/72 ,val%72);

    val = rand() % 5184;    
    Species t38("t", rand() % 4);
    simulator3.placeInGrid((Species*) &t38, val/72 ,val%72);

    val = rand() % 5184;
    Species t39("t", rand() % 4);
    simulator3.placeInGrid((Species*) &t39, val/72 ,val%72);

    simulator3.startDarwin(1000);

    // ------------
    // darwin 72x72
    // with best
    // ------------

    cout << "*** Darwin 72x72 with Best ***" << endl;
    srand(0);
    Darwin simulator4(72, 72);

    val = rand() % 5184;
    Species f40("f", rand() % 4);
    simulator4.placeInGrid((Species*) &f40, val/72, val%72);

    val = rand() % 5184;
    Species f41("f", rand() % 4);
    simulator4.placeInGrid((Species*) &f41, val/72 ,val%72);

    val = rand() % 5184;    
    Species f42("f", rand() % 4);
    simulator4.placeInGrid((Species*) &f42, val/72 ,val%72);
   
    val = rand() % 5184;    
    Species f43("f", rand() % 4);
    simulator3.placeInGrid((Species*) &f43, val/72 ,val%72);

    val = rand() % 5184;    
    Species f44("f", rand() % 4);
    simulator4.placeInGrid((Species*) &f44, val/72 ,val%72);

    val = rand() % 5184;    
    Species f45("f", rand() % 4);
    simulator4.placeInGrid((Species*) &f45, val/72 ,val%72);

    val = rand() % 5184;    
    Species f46("f", rand() % 4);
    simulator4.placeInGrid((Species*) &f46, val/72 ,val%72);

    val = rand() % 5184;    
    Species f47("f", rand() % 4);
    simulator4.placeInGrid((Species*) &f47, val/72 ,val%72);

    val = rand() % 5184;    
    Species f48("f", rand() % 4);
    simulator4.placeInGrid((Species*) &f48, val/72 ,val%72);

    val = rand() % 5184;
    Species f49("f", rand() % 4);
    simulator4.placeInGrid((Species*) &f49, val/72 ,val%72);



    val = rand() % 5184;
    Species h40("h", rand() % 4);
    simulator4.placeInGrid((Species*) &h40, val/72, val%72);

    val = rand() % 5184;
    Species h41("h", rand() % 4);
    simulator4.placeInGrid((Species*) &h41, val/72 ,val%72);

    val = rand() % 5184;    
    Species h42("h", rand() % 4);
    simulator4.placeInGrid((Species*) &h42, val/72 ,val%72);
   
    val = rand() % 5184;    
    Species h43("h", rand() % 4);
    simulator4.placeInGrid((Species*) &h43, val/72 ,val%72);

    val = rand() % 5184;    
    Species h44("h", rand() % 4);
    simulator4.placeInGrid((Species*) &h44, val/72 ,val%72);

    val = rand() % 5184;    
    Species h45("h", rand() % 4);
    simulator4.placeInGrid((Species*) &h45, val/72 ,val%72);

    val = rand() % 5184;    
    Species h46("h", rand() % 4);
    simulator4.placeInGrid((Species*) &h46, val/72 ,val%72);

    val = rand() % 5184;    
    Species h47("h", rand() % 4);
    simulator4.placeInGrid((Species*) &h47, val/72 ,val%72);

    val = rand() % 5184;    
    Species h48("h", rand() % 4);
    simulator4.placeInGrid((Species*) &h48, val/72 ,val%72);

    val = rand() % 5184;
    Species h49("h", rand() % 4);
    simulator4.placeInGrid((Species*) &h49, val/72 ,val%72);




    val = rand() % 5184;
    Species r40("r", rand() % 4);
    simulator4.placeInGrid((Species*) &r40, val/72, val%72);

    val = rand() % 5184;
    Species r41("r", rand() % 4);
    simulator4.placeInGrid((Species*) &r41, val/72 ,val%72);

    val = rand() % 5184;    
    Species r42("r", rand() % 4);
    simulator4.placeInGrid((Species*) &r42, val/72 ,val%72);
   
    val = rand() % 5184;    
    Species r43("r", rand() % 4);
    simulator4.placeInGrid((Species*) &r43, val/72 ,val%72);

    val = rand() % 5184;    
    Species r44("r", rand() % 4);
    simulator4.placeInGrid((Species*) &r44, val/72 ,val%72);

    val = rand() % 5184;    
    Species r45("r", rand() % 4);
    simulator4.placeInGrid((Species*) &r45, val/72 ,val%72);

    val = rand() % 5184;    
    Species r46("r", rand() % 4);
    simulator4.placeInGrid((Species*) &r46, val/72 ,val%72);

    val = rand() % 5184;    
    Species r47("r", rand() % 4);
    simulator4.placeInGrid((Species*) &r47, val/72 ,val%72);

    val = rand() % 5184;    
    Species r48("r", rand() % 4);
    simulator4.placeInGrid((Species*) &r48, val/72 ,val%72);

    val = rand() % 5184;
    Species r49("r", rand() % 4);
    simulator4.placeInGrid((Species*) &r49, val/72 ,val%72);



    val = rand() % 5184;
    Species t40("t", rand() % 4);
    simulator4.placeInGrid((Species*) &t40, val/72, val%72);

    val = rand() % 5184;
    Species t41("t", rand() % 4);
    simulator4.placeInGrid((Species*) &t41, val/72 ,val%72);

    val = rand() % 5184;    
    Species t42("t", rand() % 4);
    simulator4.placeInGrid((Species*) &t42, val/72 ,val%72);
   
    val = rand() % 5184;    
    Species t43("t", rand() % 4);
    simulator4.placeInGrid((Species*) &t43, val/72 ,val%72);

    val = rand() % 5184;    
    Species t44("t", rand() % 4);
    simulator4.placeInGrid((Species*) &t44, val/72 ,val%72);

    val = rand() % 5184;    
    Species t45("t", rand() % 4);
    simulator4.placeInGrid((Species*) &t45, val/72 ,val%72);

    val = rand() % 5184;    
    Species t46("t", rand() % 4);
    simulator4.placeInGrid((Species*) &t46, val/72 ,val%72);

    val = rand() % 5184;    
    Species t47("t", rand() % 4);
    simulator4.placeInGrid((Species*) &t47, val/72 ,val%72);

    val = rand() % 5184;    
    Species t48("t", rand() % 4);
    simulator4.placeInGrid((Species*) &t48, val/72 ,val%72);

    val = rand() % 5184;
    Species t49("t", rand() % 4);
    simulator4.placeInGrid((Species*) &t49, val/72 ,val%72);



    val = rand() % 5184;
    Species b40("b", rand() % 4);
    simulator4.placeInGrid((Species*) &b40, val/72, val%72);

    val = rand() % 5184;
    Species b41("b", rand() % 4);
    simulator4.placeInGrid((Species*) &b41, val/72 ,val%72);

    val = rand() % 5184;    
    Species b42("b", rand() % 4);
    simulator4.placeInGrid((Species*) &b42, val/72 ,val%72);
   
    val = rand() % 5184;    
    Species b43("b", rand() % 4);
    simulator4.placeInGrid((Species*) &b43, val/72 ,val%72);

    val = rand() % 5184;    
    Species b44("b", rand() % 4);
    simulator4.placeInGrid((Species*) &b44, val/72 ,val%72);

    val = rand() % 5184;    
    Species b45("b", rand() % 4);
    simulator4.placeInGrid((Species*) &b45, val/72 ,val%72);

    val = rand() % 5184;    
    Species b46("b", rand() % 4);
    simulator4.placeInGrid((Species*) &b46, val/72 ,val%72);

    val = rand() % 5184;    
    Species b47("b", rand() % 4);
    simulator4.placeInGrid((Species*) &b47, val/72 ,val%72);

    val = rand() % 5184;    
    Species b48("b", rand() % 4);
    simulator4.placeInGrid((Species*) &b48, val/72 ,val%72);

    val = rand() % 5184;
    Species b49("b", rand() % 4);
    simulator4.placeInGrid((Species*) &b49, val/72 ,val%72);




    simulator4.startDarwin(1000);


    return 0;}
