#include "doctest.h"
#include <iostream>
#include <cmath>
#include "sources/Point.hpp"
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
    CHECK_FALSE(c1.hasbullets());

    CHECK(c2.getName() == "Ron");
    CHECK(c3.getName() == "Voldemort");
    c3.setName("Tom_Riddle");
    CHECK(c3.getName() == "Tom_Riddle");

//    CHECK(n1.print() == "N: Name: Harry, Hit Points: 110, Location: (12.000000,12.000000)");
//    CHECK(n2.print() == "N: Name: Dambeldor, Location: (6.000000,8.000000)");
//    CHECK(c1.print() == "C: Name: Hermione, Hit Points: 110, Location: (4.000000,6.000000)");
//    CHECK(c2.print() == "C: Name: Ron, Hit Points: 70, Location: (12.000000,12.000000)");
//    CHECK(c3.print() == "C: Name: Tom_Riddle, Hit Points: 110, Location: (10.000000,1.000000)");
}

TEST_CASE("Test Point class") {
    Point p1(0,0);
    Point p2(1,1);
    Point p3(6,6);

    Point p4;
    p4 = p4.moveTowards(p1,p2,3); // The dist between p1 and p2 is less than 3, so p4 will initialize p2
    double x4 = p4.getX();
    double y4 = p4.getY();
    CHECK_EQ(x4, p2.getX());
    CHECK_EQ(y4, p2.getY());

    Point p5;
    p5 = p5.moveTowards(p1,p3,1);// The dist between p1 and p3 is more than 1
    double x5 = p5.getX();
    double y5 = p5.getY();
    CHECK_NE(x5, p3.getX());
    CHECK_NE(y5, p2.getY());

    CHECK((p1.distance(p2) == sqrt(2.0)));
    CHECK((p1.distance(p3) == sqrt(72.0)));
    CHECK((p1.distance(p4) == p1.distance(p2)));
}

TEST_CASE("Team class") {
    Point p1(1.0, 1.0);
    Point p2(4.0, 4.0);
    Cowboy* cowboy1 = new Cowboy("Harry", p1);
    Cowboy* cowboy2 = new Cowboy("Hermione", p2);
    Team teamC(cowboy1);
    teamC.add(cowboy2);
    CHECK(teamC.stillAlive() == 2);

    Point p3(12.0, 1.0);
    Point p4(10.0, 18.0);
    OldNinja* ninja1 = new OldNinja("Ishimoto", p3);
    TrainedNinja* ninja2 = new TrainedNinja("Samuraisan", p4);
    Team teamN(ninja1);
    teamN.add(ninja2);
    CHECK(teamN.stillAlive() == 2);
}
