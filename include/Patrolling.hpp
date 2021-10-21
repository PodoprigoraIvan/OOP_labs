#pragma once

#include <vector>
#include "IMovable.hpp"
#include "Creature.hpp"

class Patrolling : public Creature{
public:
    Patrolling(int given_x, int given_y, Field* field, int hp, int attack, int range);
protected:
    std::vector<Direction> patrol_pattern;
    int direction_index;
    void increase_index();
};