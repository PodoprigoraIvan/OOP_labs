#include "../include/Creature.hpp"

Creature::Creature(int given_x, int given_y, Field* field, int hp, int attack, int range) : Entity(given_x, given_y, field) {
    type = CREATURE;
    attack_points = attack;
    health_points = hp;
    attack_range = range;
}

void Creature::get_damage(int dmg){
    health_points -= dmg;
    if (health_points <= 0)
        die();
}

int Creature::get_hp(){
    return health_points;
}