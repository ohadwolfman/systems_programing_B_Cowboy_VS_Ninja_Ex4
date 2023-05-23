#include "Ninja.hpp"
using namespace std;

namespace ariel{
    string Ninja::print() {
        string str = "N: ";
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

    void Ninja::move(Character* other){
        Point currLoc = this->getLocation();
        Point goalLoc = other->getLocation();
        double dist = this->distance(other);

        // Normalized the distances on x&y axis by the total distance
        double dx = (goalLoc.getX() - currLoc.getX())/dist;
        double dy = (goalLoc.getY() - currLoc.getY())/dist;

        dx*= this->speed;
        dy*= this->speed;

        // Update Ninja's position based on the direction and distance
        this->setLocation(Point(dx,dy));
    }

    void Ninja::slash(Character* other){
        if(this->isAlive() && this->distance(other) <= 1.0){
            other->hit(40);
        }
    }
}
