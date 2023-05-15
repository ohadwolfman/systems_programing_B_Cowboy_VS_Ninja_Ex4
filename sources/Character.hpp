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
                this->power == 0? 0: 1;
            }
            double distance(Character* other);
            void hit(int pointsToDecrease){
                this->power-=pointsToDecrease;
            }
            string getName(){ return this->name; }
            Point getLocation(){ return this->position; }
            void setName();
            void setLocation();
            virtual string print() = 0;

    };
}

#endif //CPP_EX4_CHARACTER_HPP
