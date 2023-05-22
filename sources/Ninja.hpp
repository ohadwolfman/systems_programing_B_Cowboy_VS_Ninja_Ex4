#ifndef CPP_EX4_NINJA_HPP
#define CPP_EX4_NINJA_HPP
#include "Character.hpp"
#include "Point.hpp"

using namespace std;

namespace ariel{
    class Ninja: public Character{ // Abstract Class
        private:
            int speed;

        public:
            Ninja(string name, Point position, int power, int speed):
                Character(name, position, power),speed(speed){}
            virtual void move(Character* other) = 0;
            void slash(Character* other);
            int getSpeed() { return this->speed; }
    };
}
#endif //CPP_EX4_NINJA_HPP
