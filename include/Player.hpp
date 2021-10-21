#pragma once
#include "Creature.hpp"
#include "IMovable.hpp"

class Player : public Creature, public IMovable{
    bool level_passed;
public:
    Player(int given_x, int given_y, Field* field, int hp, int attack, int range);
    bool is_level_passed();
    void heal(int add_hp);
    void increase_attack_points(int add_attack_points);
    void increase_attack_range(int add_attack_range);
    void move(Direction direction);
    void attack(Direction direction);
};