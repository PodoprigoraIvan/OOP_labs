#include "../include/Patrolling.hpp"

void Patrolling::increase_index(){
    if (direction_index != patrol_pattern.size() - 1){
        direction_index++;
    } else {
        direction_index = 0;
    }
}

Patrolling::Patrolling(int given_x, int given_y, Field* field, int hp, int attack, int range) : Creature(given_x, given_y, field, hp, attack, range) {
    direction_index = 0;
}