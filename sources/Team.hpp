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
            array<Character *, Max_Members> warriors;
            size_t warriors_count;
            Character* leader;

        public:
            Team (Character *);

            virtual ~Team () {
                for (size_t i = 0; i < warriors_count; i++) {
                    delete warriors.at(i);
                }
            }

            void add (Character*);
            virtual void attack (Team*);
            int stillAlive () const;
            static Character* getClosest (Team*, Character*);

            virtual void print () const;

            Character* getLeader () const { return this->leader };
            array <Character*, Max_Members> getWarriors() const { return this->warriors };
            size_t getWarriorsCount () const { return this->warriors_count };

        protected:
            void SetWarriorsCount (size_t);
            void setLeader (Character*);
    };
}
#endif //CPP_EX4_TEAM_HPP
