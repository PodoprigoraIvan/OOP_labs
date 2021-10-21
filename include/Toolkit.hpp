#pragma once
#include "Item.hpp"

class Toolkit : public Item{
public:
    Toolkit(int given_x, int given_y, Field* field);
    void influence(Player& player);
};