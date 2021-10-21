#pragma once
#include "Item.hpp"

class Medkit : public Item {
public:
    Medkit(int given_x, int given_y, Field* field);
    void influence(Player& player);
};