#ifndef CPP_EX4_TEAM2_HPP
#define CPP_EX4_TEAM2_HPP
#include "Team.hpp"
#include <iostream>
#include <vector>

namespace ariel {
    class Team2 : public Team {

    private:
        vector<Character*> warriors;

    public:
        Team2 (Character* leader) : Team(leader) {}
        void attack (Team* other);
        void print() override;
    };
}
#endif //CPP_EX4_TEAM2_HPP
