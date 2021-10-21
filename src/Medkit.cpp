#include "../include/Medkit.hpp"

void Medkit::influence(Player& player){
    player.heal(5);
}

Medkit::Medkit(int given_x, int given_y, Field* field) : Item(given_x, given_y, field) {}