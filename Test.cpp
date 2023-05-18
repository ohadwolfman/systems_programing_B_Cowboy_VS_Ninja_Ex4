#include "doctest.h"
#include <iostream>
#include "sources/Team.hpp"
#include "sources/Character.hpp"
using namespace ariel;
using namespace std;

TEST_CASE("The character class") {
    Point p1(2.0, 4.0);
    Point p2(6.0, 8.0);
    Point p3(4.0, 6.0);
    Character character1("Harry", p1);
    Character character2("Ron", p2);
    Character character3("Hermione", p3);

    CHECK(character1.isAlive());
    CHECK(character2.isAlive());

    CHECK(character1.distance(&character2) == character2.distance(&character1));

    character1.hit(100);
    CHECK_FALSE(character1.isAlive());
    character2.hit(30);
    CHECK(character2.isAlive());

    CHECK(character3.getName() == "Hermione");
    character3.setName("Snape");
    CHECK(character3.getName() == "Snape");

    CHECK(character1.print() == "The character Harry is dead");
    CHECK(character2.print() == "The character Ron has 70 hit power, and located in (6.0,8.0)");
    CHECK(character3.print() == "The character Snape has 100 hit power, and located in (4.0,6.0)");

    Character character4(character2);
    CHECK(character4.isAlive());
    CHECK(character4.getName() == "Ron");
    character4.setLocation(Point(4.2,2.2));
    CHECK(character4.getLocation() == Point(4.2,2.2));
}

//TEST_CASE("Test Team class") {
//
//}
