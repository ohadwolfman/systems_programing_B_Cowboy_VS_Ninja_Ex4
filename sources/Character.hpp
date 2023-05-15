#ifndef CPP_EX4_CHARACTER_HPP
#define CPP_EX4_CHARACTER_HPP
#include "Point.hpp"
using namespace std;

namespace ariel{
    class Character{
        private:
            Point position;
            int power;
            string name;

        public:
            Charactern(Point& position, int power, string name):
            position(position),power(power), name(name){};

            bool isAlive(){
                this->power > 0? 1: 0;
            }
            double distance(Character* other);

            void hit(int pointsToDecrease){
                this->power-=pointsToDecrease;
            }
            string getName(){ return this->name; }
            Point getLocation(){ return this->position; }
            void setName(string newName);
            void setLocation(Point newPoint);
            virtual string print() = 0;

    };
}

#endif //CPP_EX4_CHARACTER_HPP
