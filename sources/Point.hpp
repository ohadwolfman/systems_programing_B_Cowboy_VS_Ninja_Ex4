#ifndef CPP_EX4_POINT_HPP
#define CPP_EX4_POINT_HPP
using namespace std;

namespace ariel {
    class Point {
        private:
            double x, y;

        public:
            Point(double x, double y) : x(x), y(y) {};
            ~Point();
            double distance(Point &other);
            void print() {
                cout << '(' << this->x << ',' << this->y << ')' << endl;
            }
            void moveTowards(Point &source, Point &target, double distance);
            double getX(){ return this->x; }
            double getY(){ return this->y; }
    };
}


#endif //CPP_EX4_POINT_HPP
