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
        string print();
    };
}
#endif //CPP_EX4_COWBOY_HPP
