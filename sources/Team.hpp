#ifndef CPP_EX4_TEAM_HPP
#define CPP_EX4_TEAM_HPP
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

const int Max_Members = 10;

namespace ariel {
    class Team {
        private:
            vector<Character *> warriors;
            size_t warriors_count;
            Character* leader;

        public:
            Team (Character* leader);

            virtual ~Team () {
                for (size_t i = 0; i < warriors_count; i++) {
                    delete warriors.at(i);
                }
            }

            void add (Character*);
            void attack (Team*);
            int stillAlive () const;
            virtual void print () const;

            Character* getLeader () const { return this->leader };
            vector <Character*> getWarriors() const { return this->warriors };
            size_t getWarriorsCount () const { return this->warriors_count };
            static Character* getClosest (Team*, Character*);


    protected:
            void setLeader (Character*);
    };
}
#endif //CPP_EX4_TEAM_HPP
