#pragma once
#include "Item.hpp"
#include "../include/Player.hpp"

class Player;

class Grindstone : public Item {
public:
    Grindstone(int given_x, int given_y, Field* field);
    void influence(Player& player);
};