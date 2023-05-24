#include "Ninja.hpp"
#include <cmath>
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
        if (!isAlive() || !other->isAlive()) {
            return;
        }
        double dx = other->getLocation().getX() - this->getLocation().getX();
        double dy = other->getLocation().getY() - this->getLocation().getY();
        double actualDistance = sqrt((dx * dx) + (dy * dy));
        if (actualDistance <= this->speed) {
            this->setLocation(other->getLocation());
        } else {
            double norm = this->speed / actualDistance;

            // Update Ninja's position based on the direction and distance
            this->setLocation(Point(this->getLocation().getX() + norm * dx, other->getLocation().getY() + norm * dy));
        }
    }

    void Ninja::slash(Character *other) {
        if (this->isAlive() && this->distance(other) <= 1.0) {
            other->hit(40);
        }
    }
}
