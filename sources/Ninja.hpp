#ifndef CPP_EX4_NINJA_HPP
#define CPP_EX4_NINJA_HPP
#include "Character.hpp"
#include "Point.hpp"

using namespace std;

namespace ariel{
    class Ninja: public Character{
        private:
            int speed;

        public:
            Ninja(string name, int power, Point position, int speed):
                Character(name, position, power),speed(speed){}
            void move(Character* other);
            void slash(Character* other);
    };
}
#endif //CPP_EX4_NINJA_HPP
