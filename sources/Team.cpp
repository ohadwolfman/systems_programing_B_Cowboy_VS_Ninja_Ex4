#include "Team.hpp"
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

namespace ariel{
    Team::Team (Character* leader) {
        this->leader = leader;
        this->warriors.push_back(leader);
        this->size = 1;
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

    // Usage: if (instanceof<BaseClass>(ptr)) { ... } check if ptr is instanceof BaseClass
    template<typename Base, typename T>
    inline bool instanceof(const T*) {
        return std::is_base_of<Base, T>::value;
    }

    void Team::attack (Team* other){
        if(!(other->stillAlive())){
            throw runtime_error("No member is alive in the team");
        }
        if(other == nullptr){
            throw invalid_argument("Invalid team pointer");
        }
        if(this == other){
            throw runtime_error("Dont attack yourself");
        }

        // Check if our leader is alive
        if(!(this->leader->isAlive())){
            Character* newLeader = this->getClosest(this, this->leader);
            if(newLeader){ // check that nullptr wasn't returned
                this->setLeader(newLeader);
            }
            else{ // returned nullptr while setting newLeader
                cout << "There is no alive warrior in the team"
                exit();
            }
        }

        // Choose enemy to attack
        Character* closestEnemy = other->getClosest(other,this->leader);

        // Check that didn't return nullptr as closest enemy
        if (!closestEnemy) { exit(); }

        // passing on all the members - cowboys and after that ninjas
        for (int i=0; i<this->size; i++){
            Character* currentMember = warriors.at(i);
            if (instanceof<Cowboy>(currentMember)){
                if(currentMember->isAlive()){
                    closestEnemy->hit(currentMember->getPower());
                }

            }
        }
        for (int i=0; i<this->size; i++){
            Character* currentMember = warriors.at(i);
            if (instanceof<Ninja>(currentMember)){
                if(currentMember->isAlive()){
                    closestEnemy->hit(currentMember->getPower());
                }
            }
        }



    }
    int Team::stillAlive () const{

    }
    virtual void Team::print () const{

    }

    Character* Team::getClosest(Team* team, Character* ourLeader){
        double minDist = INT_MAX;
        Character* closest = nullptr; //default value

        for (Character* member = team->warriors.begin(); member != team->warriors.end(); ++member){
            if(member->isAlive()) {
                if (member->distance(ourLeader) < minDist) {
                    minDist = member->distance(ourLeader);
                    closest = member;
                }
            }
        }
        return closest;
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
