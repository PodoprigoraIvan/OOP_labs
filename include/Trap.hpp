#pragma once
#include "Item.hpp"

class Trap : public Item{
public:
    Trap(int given_x, int given_y, Field* field);
    void influence(Player& player);
};