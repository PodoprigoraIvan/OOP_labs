#include "../include/MagicTower.hpp"
#include <cmath>

MagicTower::MagicTower(int given_x, int given_y, Field* field, int hp, int attack, int range): Creature(given_x, given_y, field, hp, attack, range) {

}

bool MagicTower::is_player_reachable(Player& player){
    if (abs(get_x() - player.get_x()) <= attack_range && abs(get_y() - player.get_y()) <= attack_range){
        return true;
    } else {
        return false;
    }
}

void MagicTower::attack(Player& player){
    player.get_damage(attack_points);
}

void MagicTower::next_action(Player& player){
    if (is_player_reachable(player)){
        attack(player);
    }
}