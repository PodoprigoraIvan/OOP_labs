#include "../include/Toolkit.hpp"

void Toolkit::influence(Player& player){
    player.increase_attack_range(1);
    die();
}

Toolkit::Toolkit(int given_x, int given_y, Field* field) : Item(given_x, given_y, field) {}