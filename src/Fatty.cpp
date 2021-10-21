#include "../include/Fatty.hpp"
#include <cmath>

Fatty::Fatty(int given_x, int given_y, Field* field, int hp, int attack, int range) : Patrolling(given_x, given_y, field, hp, attack, range) {
    patrol_pattern = {LEFT, LEFT, LEFT, LEFT, RIGHT, RIGHT, RIGHT, RIGHT};
}

void Fatty::move(Direction direction){
    int new_x = get_x();
    int new_y = get_y();
    switch(direction){
        case UP:
            if (new_y - 1 >= 0){
                if (current_field->get_cell(new_x, new_y - 1).is_free() && current_field->get_cell(new_x, new_y - 1).is_walkable()){
                    new_y--;
                }
            }
            break;
        case DOWN:
            if (new_y + 1 < current_field->get_height()){
                if (current_field->get_cell(new_x, new_y + 1).is_free() && current_field->get_cell(new_x, new_y + 1).is_walkable()){
                    new_y++;
                }
            }
            break;
        case RIGHT:
            if (new_x + 1 < current_field->get_width()){
                if (current_field->get_cell(new_x + 1, new_y).is_free() && current_field->get_cell(new_x + 1, new_y).is_walkable()){
                    new_x++;
                }
            } 
            break;
        case LEFT:
            if (new_x - 1 >= 0){
                if (current_field->get_cell(new_x - 1, new_y).is_free() && current_field->get_cell(new_x - 1, new_y).is_walkable()){
                    new_x--;
                }
            }
            break;
    }
    if (new_x == get_x() && new_y == get_y())
        return;
    change_position(new_x, new_y);
}


bool Fatty::is_player_reachable(Player &player){
    if (abs(get_x() - player.get_x()) <= attack_range && abs(get_y() - player.get_y()) <= attack_range){
        return true;
    } else {
        return false;
    }
}

void Fatty::next_action(Player& player){
    if (is_player_reachable(player)){
        attack(player);
    } else {
        move(patrol_pattern[direction_index]);
        increase_index();
    }
}

void Fatty::attack(Player& player){
    player.get_damage(attack_points);
}