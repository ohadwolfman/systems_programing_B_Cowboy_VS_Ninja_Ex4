#ifndef CPP_EX4_CHARACTER_HPP
#define CPP_EX4_CHARACTER_HPP
#include "Point.hpp"
#include<string>

namespace ariel{
    class Character{ //Abstract Class
        private:
            Point position;
            int power;
            std::string name;
            bool teamMember;

    public:
            // Constructors
            Character(std::string name, Point& position): // 100 is arbitrary power rate
                name(name), position(position), power(100),teamMember(false){};

            Character(std::string name, Point& position, int power):
            name(name), position(position), power(power),teamMember(false){};
            virtual ~Character()  = default;

            // Methods
            void hit(int pointsToDecrease);
            std::string getName(){ return this->name; }
            int getPower(){ return this->power; }
            Point getLocation(){ return this->position; }
            void setName(std::string newName) { this->name = newName; }
            void setPower(int num) { this->power+=num; }
            void setLocation(Point newPoint) { this->position = newPoint; }

            bool isPlayingNow() const { return this->teamMember; }
            void startedToPlay() { this->teamMember = true; }

            bool isAlive();
            double distance(Character* other);
            virtual std::string print()=0;
    };
}

#endif //CPP_EX4_CHARACTER_HPP
