#include "Cowboy.hpp"
using namespace std;

namespace ariel{
    string Character::print() {
        string toPrint = "";
        if (this->isAlive()) {
            toPrint << this->name << " has " << this->power << "hit power, and located in " <<
                    '(' << this->position.getX() << ',' << this->position.getY() << ')';
        }
        else{
            toPrint << 'C(' << this->name << ')';
        }
        return toPrint;
    }
    void Cowboy::shoot(Character* other){
        if (this->isAlive() && this->hasbullets()){
            --this->numBullets;
            other->hit(10);
        }
        else
    }

}
