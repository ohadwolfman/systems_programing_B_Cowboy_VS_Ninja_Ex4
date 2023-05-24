#include "Team.hpp"
#include "Character.hpp"
#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <iostream>
using namespace std;

namespace ariel{
    Team::Team (Character* leader) {
        if(!leader->isPlayingNow()) {
            this->leader = leader;
            this->warriors.push_back(leader);
            this->size = 1;
            leader->startedToPlay();
        }
        else{
            throw runtime_error("This character is already playing");
        }
    }

    Team::~Team() {
        for (Character* member : warriors) {
            delete member;
        }
    }

    void Team::add(Character* warrior){
        if (!warrior){
            throw invalid_argument("A nullptr has been given");
        }
        if(warrior->isPlayingNow()){
            throw runtime_error("This character is already playing");
        }
        if(this->size == 10){
            throw runtime_error ("Team can be 10 warriors maximum");
        }
        else if(this->isInTheTeam(warrior)){
            throw runtime_error ("This warrior is already in the team");
        }
        else{ // (this->size < 10)
            warrior->startedToPlay();
            (this->warriors).push_back(warrior);
            ++this->size;
        }
    }

    // Usage: if (instanceof<BaseClass>(ptr)) { ... } check if ptr is instanceof BaseClass
    template<typename Base, typename T>
    inline bool instanceof(const T*) {
        return std::is_base_of<Base, T>::value;
    }

    void Team::attack (Team* other){
        if(!(other->stillAlive())){
            throw runtime_error("No member is alive in the enemies team");
        }
//        if(other== nullptr){
//            throw invalid_argument("A nullptr has been given");
//        }
        if(this == other){
            throw runtime_error("Dont attack yourself");
        }
        if (this->stillAlive() == 0){
            throw runtime_error("All of your warriors are dead, you cant attack");
        }

        // Check if our leader is alive
        if(!(this->leader->isAlive())){
            Character* newLeader = this->getClosest(this, this->leader);
            if(newLeader){ // check that nullptr wasn't returned
                this->setLeader(newLeader);
            }
            else{ // returned nullptr while setting newLeader
                cout << "There is no alive warrior in the team";
                return;
            }
        }

        // Choose enemy to attack
        Character* closestEnemy = other->getClosest(other,this->leader);

        // Check that didn't return nullptr as closest enemy
        if (!closestEnemy) { return; }

        // passing on all the members that instance of cowboys
        for (size_t i=0; i< this->size; i++){
            if(!(closestEnemy->isAlive())){ // if the current enemy to attack isn't live anymore
                Character* closestEnemy = other->getClosest(other,this->leader);
                if(!closestEnemy){ // if nullptr was returned
                    cout<<"no enemy to attack anymore"<<endl;
                    return;
                }
            }
            Character* currentMember = warriors.at(i);
            if (Cowboy* cowboy = dynamic_cast<Cowboy*>(currentMember)){
                if(cowboy->isAlive()){
                    if(cowboy->hasboolets()) {
                        cowboy->shoot(closestEnemy);
                    }
                    else{
                        cowboy->reload();
                    }
                }
            }
        }
        // passing on all the members that instance of ninjas
        for (size_t i=0; i< this->size; i++){
            if(!(closestEnemy->isAlive())){ // if the current enemy to attack isn't live anymore
                Character* closestEnemy = other->getClosest(other,this->leader);
                if(!closestEnemy){ // if nullptr was returned
                    cout<<"no enemy to attack anymore"<<endl;
                    return;
                }
            }
            Character* currentMember = warriors.at(i);
            if (Ninja* ninja = dynamic_cast<Ninja*>(currentMember)) {
                if (currentMember->isAlive()) {
                    if (ninja->distance(closestEnemy) <= 1.0) {
                        ninja->slash(closestEnemy);
                    } else {
                        ninja->move(closestEnemy);
                    }
                }
            }
        }
    }

    int Team::stillAlive () const{
        int count_alive = 0;
        for(size_t i=0; i< this->size; ++i){
            Character* curr = this->warriors.at(i);
            if(curr->isAlive()){ ++count_alive; }
        }
        return count_alive;
    }

    void Team::print (){
        for(size_t i=0; i<this->size; ++i){
            Character* curr = this->warriors.at(i);
            if(curr->isAlive()){
                curr->print(); }
        }
    }

    Character* Team::getClosest(Team* team, Character* ourLeader){
        double minDist = INT_MAX;
        Character* closest = nullptr; //default value

        for (size_t i = 0; i < this->size; i++){
            Character* member = team->warriors.at(i);
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
        for(size_t i=0; i< this->size; ++i){
            if(this->warriors.at(i) == warrior){ return true; }
        }
        return false;
    }
}
