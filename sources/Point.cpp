#include "Point.hpp"
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

namespace ariel{
    string Point::print() {
        string output = "(" + to_string(this->x) + "," + to_string(this->y) + ")";
        return output;
    }

    double Point::distance(Point& other){
        double dx = this->x - other.x;
        double dy = this->y - other.y;
        return sqrt((dx*dx) + (dy*dy));
    }

    // returns the closest point to target exceed the max distance from the source point
    Point Point::moveTowards(Point& source, Point& target, double max_distance){
        if (max_distance < 0) {
            throw invalid_argument("distance must be non-negative");
        }

        double dx = target.getX() - source.getX();
        double dy = target.getY() - source.getY();
        double actualDistance = sqrt((dx*dx) + (dy*dy));
        if (actualDistance <= max_distance) {
            return target;
        }
        else {
            double norm = max_distance / actualDistance;
            return Point(source.getX() + norm*dx, source.getY() + norm*dy);
        }
    }
}

