#include "Character.hpp"
#include "Point.hpp"
#include <math.h>
#include<string>
using namespace std;

namespace ariel{
    double Character::distance(Character* other){
        return sqrt(double(pow(this->getLocation().getX() - other->getLocation().getX(), 2)
        + pow(this->getLocation().getY() - other->getLocation().getY(), 2)));
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
