#ifndef CPP_EX4_CHARACTER_HPP
#define CPP_EX4_CHARACTER_HPP
#include "Point.hpp"
using namespace std;

namespace ariel{
    class Character{ //Abstract Class
        private:
            Point position;
            int power;
            string name;

        public:
            Charactern(string name, Point& position, int power = 100): // 100 is arbitrary power rate
            name(name),position(position),power(power){};


            void hit(int pointsToDecrease){ this->power-=pointsToDecrease; }
            string getName(){ return this->name; }
            string getPower(){ return this->power; }
            Point getLocation(){ return this->position; }
            void setName(string newName) { this->name = newName };
            void setPower(int num) { this->power+=num; }
            void setLocation(Point newPoint) { this->position = newPoint; }

            bool isAlive();
            double distance(Character* other);
            virtual string print() = 0;
    };
}

#endif //CPP_EX4_CHARACTER_HPP
