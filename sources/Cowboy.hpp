#ifndef CPP_EX4_COWBOY_HPP
#define CPP_EX4_COWBOY_HPP
#include "Character.hpp"
#include "Point.hpp"

using namespace std;

namespace ariel{
    class Cowboy: public Character{
        private:
            numBullets;

        public:
        Cowboy(string name, Point position):
            Character(name, 110, position),numBullets(6){}
        string print();
        void shoot(Character* other);
        bool hasboollets(){ this->numBullets>0? 1: 0; }
        void reload(){this->numBullets +=6 }
    };
}
#endif //CPP_EX4_COWBOY_HPP
