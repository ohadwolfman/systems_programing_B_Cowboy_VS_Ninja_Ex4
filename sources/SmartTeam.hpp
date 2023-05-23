#ifndef CPP_EX4_SMARTTEAM_HPP
#define CPP_EX4_SMARTTEAM_HPP
#include "Team.hpp"
using namespace std;

namespace ariel {
    class SmartTeam : public Team {

    public:
        SmartTeam (Character* leader) : Team(leader) {}

        string attack (Team* enemy_team);
    };
}
#endif //CPP_EX4_SMARTTEAM_HPP
