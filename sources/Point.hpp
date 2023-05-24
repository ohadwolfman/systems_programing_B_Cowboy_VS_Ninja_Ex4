#ifndef CPP_EX4_POINT_HPP
#define CPP_EX4_POINT_HPP
#include <string>

namespace ariel {
    class Point {
        private:
            double x, y;

        public:
            Point() : x(0.0), y(0.0) {};
            Point(int x, int y) : x(double (x)), y(double (y)) {};
            Point(double x, double y) : x(x), y(y) {};
            double distance(const Point& other) const;
            std::string print();
            Point moveTowards(Point &source, Point &target, double distance);
            double getX(){ return this->x; }
            double getY(){ return this->y; }
    };
}


#endif //CPP_EX4_POINT_HPP
