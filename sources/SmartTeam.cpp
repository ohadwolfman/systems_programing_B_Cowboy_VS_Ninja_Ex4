#include "SmartTeam.hpp"

namespace ariel{
    string SmartTeam::attack(Team* enemy_team) {
        string output = "(" + to_string(enemy_team->stillAlive()) + "," + to_string(this->stillAlive()) + ")";
        return output;
    }
}

