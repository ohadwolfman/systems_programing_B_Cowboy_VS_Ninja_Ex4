#include "Ninja.hpp"
using namespace std;

namespace ariel{
    string Character::print() {
        string toPrint = "";
        if (this->isAlive()) {
            toPrint << this->name << " has " << this->power << "hit power, and located in " <<
                    '(' << this->position.getX() << ',' << this->position.getY() << ')';
        }
        else{
            toPrint << "N(" << this->name << ')';
        }
        return toPrint;
    }
    void Ninja::move(Character* other){
        Point currLoc = this->getLocation();
        Point goalLoc = other->getLocation();
        double dist = this->distance(other);

        // Normalized the distances on x&y axis by the total distance
        double dx = (goalLoc.getX() - currLoc.getX())/dist;
        double dy = (goalLoc.getY() - currLoc.getY())/dist;

        // Update Ninja's position based on the direction and distance
        this->setLocation(Point(dx,dy));
    }

    void Ninja::slash(Character* other){
        if(this->isAlive() && this->distance(other)<1.0){
            other->hit(40);
        }
    }
}
