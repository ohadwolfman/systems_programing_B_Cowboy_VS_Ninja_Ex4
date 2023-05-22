#include "Point.hpp"
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

namespace ariel{
    Point::~Point(){
        delete this.x;
        delete this.y;
        delete this;
    }
    void Point::print() {
        std::cout << "(" << this->x << "," << this->y << ")" << std::endl;
    }
    double Point::distance(Point& other){
        return sqrt(double(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
    }
    void Point::moveTowards(Point& source, Point& target, double distance){
        cout <<"i found and i won't tell you"<<endl;
    }
}

