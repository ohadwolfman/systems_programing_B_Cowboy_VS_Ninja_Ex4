#ifndef CPP_EX4_TRAINEDNINJA_HPP
#define CPP_EX4_TRAINEDNINJA_HPP
#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;

const int TrainedNinja_Speed = 12;
const int TrainedNinja_Power = 120;

namespace ariel{
    class TrainedNinja: public Ninja{
        public:
            TrainedNinja(string name, Point position):
                Ninja((name), OldNinja_Power, position, OldNinja_Speed) {}
    };
}


#endif //CPP_EX4_TRAINEDNINJA_HPP
