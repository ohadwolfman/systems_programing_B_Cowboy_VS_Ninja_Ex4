#include "Character.hpp"
#include "Point.hpp"

using namespace std;

namespace ariel{
    double Character::distance(Character* other){
        return sqrt(double(pow(this->getLocation().getX() - other->getLocation().getX(), 2)
        + pow(this->getLocation().getY() - other->getLocation().getY(), 2)));
    }

    virtual string Character::print(){
        string toPrint = "";
        if (this->isAlive()) {
            toPrint << "The character " << this->name << " has " << this->power << "hit power, and located in " <<
                    '(' << this->position.getX() << ',' << this->position.getY() << ')';
        }
        else{
            toPrint << "The character" << this->name << "is dead";
        }
        return toPrint;
    }
    bool isAlive(){
        this->power > 0? 1: 0;
    }
}
