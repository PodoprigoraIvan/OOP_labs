#include "../include/Grindstone.hpp"

void Grindstone::influence(Player& player){
    player.increase_attack_points(1);
    die();
}

Grindstone::Grindstone(int given_x, int given_y, Field* field) : Item(given_x, given_y, field) {}