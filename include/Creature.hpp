#pragma once
#include "Entity.hpp"

class Creature : public Entity{
protected:
    int health_points;
    int attack_points;
    int attack_range;
public:
    Creature(int given_x, int given_y, Field* field, int hp, int attack, int range);
    int get_hp();
    void get_damage(int dmg);
};