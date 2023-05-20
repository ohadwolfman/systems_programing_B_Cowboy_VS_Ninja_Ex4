#include "Team.hpp"
#include <vector>
#include <algorithm>
using namespace std;

namespace ariel{
    Team::Team (Character* leader){

    }
    void Team::add(Character* warrior){
        if(this->size == 10){
            throw runtime_error ("Team can be 10 warriors maximum");
        }
        else if(warrior.isInTheTeam){
            throw runtime_error ("This warrior is already in the team");
        }
        else{ // (this->size < 10)
            (this->warriors).push_back(warrior);
        }
    }

    void Team::attack (Team* team){
        if(!(team->stillAlive())){
            throw runtime_error("No member is alive in the team");
        }
        if(team == nullptr){
            throw invalid_argument("Invalid team pointer");
        }
        if(this == team){
            throw runtime_error("Dont attack yourself");
        }



    }
    int Team::stillAlive () const{

    }
    virtual void Team::print () const{

    }
    static Character* Team::getClosest(Team*, Character*){

    }

    void Team::setLeader (Character* newleader){
        this->leader = newleader;
    }

    bool Team::isInTheTeam(Character* warrior){
        for(int i=0; i<this->size; ++i){
            if(this->warriors.at(i) == warrior){ return true; }
        }
        return false;
    }
}
