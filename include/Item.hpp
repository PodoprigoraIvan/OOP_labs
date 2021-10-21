#pragma once
#include "Player.hpp"

class Item : public Entity{
public:
    virtual void influence(Player& player) = 0;
    Item(int given_x, int given_y, Field* field);
};