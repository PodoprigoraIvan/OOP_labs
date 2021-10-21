#include "../include/Trap.hpp"

void Trap::influence(Player& player){
    player.get_damage(1);
    die();
}

Trap::Trap(int given_x, int given_y, Field* field) : Item(given_x, given_y, field) {}