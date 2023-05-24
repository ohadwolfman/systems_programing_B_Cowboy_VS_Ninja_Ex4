#include "Cowboy.hpp"
#include <iostream>
#include <exception>
using namespace std;

namespace ariel{
    string Cowboy::print() {
        string str = "C: ";
        if (!isAlive()) {
            str += "Name: " + getName() + ", Location: " + getLocation().print() + '\n';
        } else {
            str += "Name: " + getName() + ", Hit Points: " + to_string(getPower()) + ", Location: " +
                   getLocation().print() + '\n';
        }
        return str;
    }
    void Cowboy::reload(){
        if(!this->isAlive()){
            throw runtime_error("Dead cowboy can not reload");
        }
        this->numBullets = 6;
    }

    void Cowboy::shoot(Character* other){
        if(!this->isAlive()){
            throw runtime_error("Your character is dead, you cant attack");
        }
        if(!other->isAlive()){
            throw runtime_error("Your enemy is dead, you cant attack him!!");
        }
        if(this == other){
            throw runtime_error("Can't attack yourself");
        }
        if (this->isAlive()){
            if(this->hasboolets()==1){
                --this->numBullets;
                other->hit(10);
            }
//            else{ // has no bullets
//                this->reload();
//            }
        }
    }

}
