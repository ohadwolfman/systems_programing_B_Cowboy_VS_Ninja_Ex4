#include "Character.hpp"
#include "Point.hpp"

using namespace std;

namespace ariel{
    double Character::distance(Character* other){
        return sqrt(double(pow(this->getLocation().getX() - other->getLocation().getX(), 2)
        + pow(this->getLocation().getY() - other->getLocation().getY(), 2)));
    }

    void Character::setName(string newName){
        this->name = newName;
    }
    void Character::setLocation(Point newPoint){
        this->position = newPoint;
    }
}
