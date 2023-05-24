#include "Character.hpp"
#include "Point.hpp"
#include <math.h>
#include<string>
#include<iostream>

using namespace std;

namespace ariel{
    double Character::distance(Character* other){
        return sqrt(double(pow(this->getLocation().getX() - other->getLocation().getX(), 2)
        + pow(this->getLocation().getY() - other->getLocation().getY(), 2)));
    }
    void Character::hit(int pointsToDecrease){
        if(pointsToDecrease<0){
            throw invalid_argument("Please insert non negative value");
        }
        this->power-=pointsToDecrease;
    }

//    string Character::print(){
//        if(!isAlive())
//            return "name: ("+name  + "), Locatin: " + position.print();
//        return "name: "+name + ", health: "+to_string(power)  + ", Locatin: " + position.print();
//    }

    bool Character::isAlive(){
        return (this->getPower() > 0);
    }
}
