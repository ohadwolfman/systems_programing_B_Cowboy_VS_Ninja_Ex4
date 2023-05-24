#include "Ninja.hpp"
#include <cmath>
#include <iostream>
#include <exception>
using namespace std;

namespace ariel{
    string Ninja::print() {
        string str = "N: ";
        if (!isAlive()) {
            str += "Name: " + getName() + ", Location: " + getLocation().print()+ '\n';
        } else {
            str += "Name: " + getName() + ", Hit Points: " + to_string(getPower()) + ", Location: " +
                   getLocation().print() + '\n';
        }
        return str;
    }

    void Ninja::move(Character* other) {
//        if (!isAlive() || !other->isAlive()) {
//            return;
//        }
        this->setLocation(Point::moveTowards(this->getLocation(), other->getLocation(),this->speed));
//        double dx = other->getLocation().getX() - this->getLocation().getX();
//        double dy = other->getLocation().getY() - this->getLocation().getY();
//        double actualDistance = sqrt((dx * dx) + (dy * dy));
//        if (actualDistance <= this->speed) {
//            this->setLocation(other->getLocation());
//        } else {
//            double norm = this->speed / actualDistance;
//
//            // Update Ninja's position based on the direction and distance
//            this->setLocation(Point(this->getLocation().getX() + norm * dx, this->getLocation().getY() + norm * dy));
//        }
    }

    void Ninja::slash(Character* other) {
        if(!this->isAlive()){
            throw runtime_error("Your character is dead, you cant attack");
        }
        if(!other->isAlive()){
            throw runtime_error("Your enemy is dead, you cant attack him");
        }
        if(this == other){
            throw runtime_error("Cant attack yourself");
        }
        if (this->distance(other) <= 1.0) {
            other->hit(40);
        }
    }
}
