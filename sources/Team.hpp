#ifndef CPP_EX4_TEAM_HPP
#define CPP_EX4_TEAM_HPP
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include <vector>
using namespace std;

const int Max_Members = 10;

namespace ariel {
    class Team {
        private:
            std::vector<Character *> warriors;
            size_t size;
            Character* leader;

        public:
            Team (Character* leader);

            virtual ~Team();

            void add (Character*);
            void attack (Team*);
            int stillAlive () const;
            virtual void print () const;

            Character* getLeader () const { return this->leader; }
            std::vector<Character*>& getTeam() { return this->warriors; }
            size_t getTeamSize () const { return this->size; }
            Character* getClosest (Team* team, Character* ourLeader);
            bool isInTheTeam(Character* warrior);

    protected:
            void setLeader (Character*);
    };
}
#endif //CPP_EX4_TEAM_HPP
