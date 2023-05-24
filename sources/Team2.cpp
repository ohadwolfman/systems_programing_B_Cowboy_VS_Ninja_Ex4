#include "Team2.hpp"


namespace ariel{
    void Team2::attack(Team* other){
        if(other == nullptr){
            throw invalid_argument("A nullptr has been given");
        }
        if(!(other->stillAlive())){
            throw runtime_error("No member is alive in the enemies team");
        }
        if(this == other){
            throw runtime_error("Dont attack yourself");
        }
        if (this->stillAlive() == 0){
            throw runtime_error("All of your warriors are dead, you cant attack");
        }

        // Check if our leader is alive
        if(!(this->getLeader()->isAlive())){
            Character* newLeader = this->getClosest(this, this->getLeader());
            if(newLeader){ // check that nullptr wasn't returned
                this->setLeader(newLeader);
            }
            else{ // returned nullptr while setting newLeader
                cout << "There is no alive warrior in the team";
                return;
            }
        }

        // Choose enemy to attack
        Character* closestEnemy = other->getClosest(other,this->getLeader());

        // Check that didn't return nullptr as closest enemy
        if (!closestEnemy) { return; }

        // passing on all the members, by insertion order
        for (size_t i=0; i < this->getTeamSize(); i++){
            if(!(closestEnemy->isAlive())){ // if the current enemy to attack isn't live anymore
                closestEnemy = other->getClosest(other,this->getLeader());
                if(!closestEnemy){ // if nullptr was returned
                    cout<<"no enemy to attack anymore"<<endl;
                    return;
                }
            }
            Character* currentMember = warriors.at(i);
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(currentMember)){
                if(cowboy->isAlive()){
                    if(cowboy->hasboolets() && closestEnemy->isAlive()) {
                        cowboy->shoot(closestEnemy);
                    }
                    else{
                        cowboy->reload();
                    }
                }
            }
            if (Ninja* ninja = dynamic_cast<Ninja*>(currentMember)) {
                if (currentMember->isAlive()) {
                    if (ninja->distance(closestEnemy) <= 1.0 && closestEnemy->isAlive()) {
                        ninja->slash(closestEnemy);
                    } else {
                        ninja->move(closestEnemy);
                    }
                }
            }
        }
    }

    void Team2::print() {
        for(Character* member : getTeam()) {
            cout << member->print() << endl;
        }
    }
}
