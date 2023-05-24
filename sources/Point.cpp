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

    double Point::distance(const Point& other) const {
        double dx = this->x - other.x;
        double dy = this->y - other.y;
        return sqrt((dx*dx) + (dy*dy));
    }

    // returns the closest point to target exceed the max distance from the source point
    Point Point::moveTowards(const Point& source, const Point& target, double max_distance) {
        if (max_distance < 0) {
            throw invalid_argument("distance must be non-negative");
        }

        double dx = target.x - source.x;
        double dy = target.y - source.y;
        double actualDistance = sqrt((dx*dx) + (dy*dy));
        if (actualDistance <= max_distance) {
            return target;
        }
        else {
            double norm = max_distance / actualDistance;
            return Point{source.x + norm*dx, source.y + norm*dy};
        }
    }
}

