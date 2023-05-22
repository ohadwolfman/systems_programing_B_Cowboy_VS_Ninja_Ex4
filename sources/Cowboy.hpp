#ifndef CPP_EX4_COWBOY_HPP
#define CPP_EX4_COWBOY_HPP
#include "Character.hpp"
#include "Point.hpp"

using namespace std;

namespace ariel{
    class Cowboy: public Character{
        private:
            int numBullets;

        public:
        Cowboy(string name, Point position):
            Character(name, position, 110),numBullets(6){}
        //~Cowboy() override = default;
        string print() override;
        void shoot(Character* other);
        bool hasbullets(){
            if(this->numBullets > 0)
                return true;
            return false;
        }
        void reload(){ this->numBullets +=6; }
    };
}
#endif //CPP_EX4_COWBOY_HPP
