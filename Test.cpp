#include "doctest.h"
#include <iostream>
#include "sources/Team.hpp"
#include "sources/Character.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("Cowboy and Ninja classes") {
    Point p1(2.0, 2.0);
    Point p2(6.0, 8.0);
    Point p3(4.0, 6.0);
    Point p4(12.0, 12.0);
    Point p5(10.0, 1.0);

    TrainedNinja n1("Harry", p1);
    OldNinja n2("Dambeldor", p2);
    Cowboy c1("Hermione", p3);
    Cowboy c2("Ron", p4);
    Cowboy c3("Voldemort", p5);

    CHECK(n1.isAlive());
    CHECK(n2.isAlive());
    CHECK(c1.isAlive());
    CHECK(c2.isAlive());
    CHECK(c3.isAlive());

    CHECK(n1.distance(&c1) == c1.distance(&n1));

    int powerBefore = c2.getPower();
    n1.slash(&c2);
    CHECK(c2.getPower() == powerBefore);
    n1.move(&c2);
    n1.slash(&c2);
    CHECK_FALSE(c2.getPower() == powerBefore);

    for(size_t i = 0; i<5; i++){ // Old ninja has 150 power pints
        c1.shoot(&n2);
        c2.shoot(&n2);
        c3.shoot(&n2);
    }
    CHECK_FALSE(n2.isAlive());
    CHECK(c1.hasbullets());
    CHECK(c2.hasbullets());
    CHECK(c3.hasbullets());
    c1.shoot(&n1);
    CHECK(c1.hasbullets());

    CHECK(c2.getName() == "Ron");
    CHECK(c3.getName() == "Voldemort");
    c3.setName("Tom_Riddle");
    CHECK(c3.getName() == "Tom_Riddle");

    CHECK(n1.print() == "N: Name: Harry, Hit Points: 110, Location: (12.000000,12.000000)");
    CHECK(n2.print() == "N: Name: Dambeldor, Location: (6.000000,8.000000)");
    CHECK(c1.print() == "C: Name: Hermione, Hit Points: 110, Location: (4.000000,6.000000)");
    CHECK(c2.print() == "C: Name: Ron, Hit Points: 70, Location: (12.000000,12.000000)");
    CHECK(c3.print() == "C: Name: Tom_Riddle, Hit Points: 110, Location: (10.000000,1.000000)");
}

//TEST_CASE("Test Team class") {
//
//}
