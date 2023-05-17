#ifndef CPP_EX4_YOUNGNINJA_HPP
#define CPP_EX4_YOUNGNINJA_HPP
#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;

const int YoungNinja_Speed = 14;
const int YoungNinja_Power = 100;

namespace ariel{
    class YoungNinja: public Ninja{
        public:
            OldNinja (string name, Point position) :
                Ninja(name, OldNinja_Power, position, OldNinja_Speed) {}
    };
}

#endif //CPP_EX4_YOUNGNINJA_HPP
