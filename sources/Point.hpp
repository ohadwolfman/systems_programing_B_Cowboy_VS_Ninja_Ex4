#ifndef CPP_EX4_POINT_HPP
#define CPP_EX4_POINT_HPP
#include <string>

namespace ariel {
    class Point {
        private:
            double x, y;

        public:
            Point(double x, double y) : x(x), y(y) {};
            ~Point();
            double distance(Point &other);
            std::string print();
            void moveTowards(Point &source, Point &target, double distance);
            double getX(){ return this->x; }
            double getY(){ return this->y; }
    };
}


#endif //CPP_EX4_POINT_HPP
