#include "Cowboy.hpp"
using namespace std;

namespace ariel{
    string Cowboy::print() {
        string str = "C : ";
        if (!isAlive()) {
            str += "Name: (" + getName() + "), Location:" +
                   getLocation().print()
                   + '\n';
        } else {
            str += "Name: " + getName() + ", Hit Points:" + " (" + to_string(getPower()) + ") " + ", Location: " +
                   getLocation().print() + '\n';
        }
        return str;
    }

    void Cowboy::shoot(Character* other){
        if (this->isAlive()){
            if(this->hasbullets()==1){
                --this->numBullets;
                other->hit(10);
            }
            else{ // has no bullets
                this->reload();
            }
        }
    }

}
