#pragma once
#include "IEnemy.hpp"
#include "IMovable.hpp"
#include "Patrolling.hpp"

class Jumper : public Patrolling, public IMovable, public IEnemy {
public:
    Jumper(int given_x, int given_y, Field* field, int hp, int attack, int range);
    void move(Direction direction);
    void next_action(Player& player);
    bool is_player_reachable(Player &player);
    void attack(Player& player);
};