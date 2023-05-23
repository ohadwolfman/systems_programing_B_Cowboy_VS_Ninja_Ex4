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
        return std::sqrt((dx*dx) + (dy*dy));
    }

    void Point::moveTowards(Point& source, Point& target, double distance){
        cout <<"i found and i won't tell you"<<endl;
    }
}

