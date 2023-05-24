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
        ~Cowboy() override = default;
        string print() override;
        void shoot(Character* other);
        bool hasboolets(){
            if(this->numBullets > 0)
                return 1;
            return 0;
        }
        void reload();
        int getNumBullets(){ return this->numBullets; }
    };
}
#endif //CPP_EX4_COWBOY_HPP
