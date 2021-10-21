#pragma once
#include "Player.hpp"

class IEnemy{
public:
    virtual void next_action(Player& player) = 0;
    virtual bool is_player_reachable(Player &player) = 0;
    virtual void attack(Player& player) = 0;
};