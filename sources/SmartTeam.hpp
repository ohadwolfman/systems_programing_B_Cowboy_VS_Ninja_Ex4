#ifndef CPP_EX4_SMARTTEAM_HPP
#define CPP_EX4_SMARTTEAM_HPP
#include "Team.hpp"

namespace ariel {
    class SmartTeam : public Team {

    public:
        SmartTeam (Character* leader) : Team(leader) {}

        void attack (Team* enemy_team) override;

        void print() const override;
    };
}
#endif //CPP_EX4_SMARTTEAM_HPP
