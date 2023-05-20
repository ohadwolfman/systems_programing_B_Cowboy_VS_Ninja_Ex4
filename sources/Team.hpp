#ifndef CPP_EX4_TEAM_HPP
#define CPP_EX4_TEAM_HPP
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"

const int Max_Members = 10;

namespace ariel {
    class Team {
        private:
            vector<Character *> warriors;
            size_t size;
            Character* leader;

        public:
            Team (Character* leader);

            virtual ~Team () {
                for (size_t i = 0; i < size; i++) {
                    delete warriors[i];
                }
            }

            void add (Character*);
            void attack (Team*);
            int stillAlive () const;
            virtual void print () const;

            Character* getLeader () const { return this->leader };
            vector <Character*>& getTeam() const { return this->warriors };
            size_t getTeamSize () const { return this->size };
            static Character* getClosest (Team*, Character*);
            bool isInTheTeam(Character* warrior);

    protected:
            void setLeader (Character*);
    };
}
#endif //CPP_EX4_TEAM_HPP
