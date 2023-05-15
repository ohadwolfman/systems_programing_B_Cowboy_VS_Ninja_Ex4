#ifndef CPP_EX4_OLDNINJA_HPP
#define CPP_EX4_OLDNINJA_HPP
#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;

const int OldNinja_Speed = 8;
const int OldNinja_Power = 150;

namespace ariel{
    class OldNinja: public Ninja{
        private:
            int speed;

        public:
            OldNinja (string name, Point position) :
                Ninja((name), OldNinja_Power, position, OldNinja_Speed) {}
    };
}

#endif //CPP_EX4_OLDNINJA_HPP
