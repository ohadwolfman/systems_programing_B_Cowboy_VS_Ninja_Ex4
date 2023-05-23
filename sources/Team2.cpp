#include "Team2.hpp"


namespace ariel{
    string Team2::attack(Team* enemy_team) {
        string output = "(" + to_string(enemy_team->stillAlive()) + "," + to_string(this->stillAlive()) + ")";
        return output;
    }
}
