#pragma once
#include "IEnemy.hpp"
#include "Creature.hpp"

class MagicTower : public Creature, public IEnemy{
public:
    MagicTower(int given_x, int given_y, Field* field, int hp, int attack, int range);
    void next_action(Player& player);
    bool is_player_reachable(Player &player);
    void attack(Player& player);
};