#include "../include/Jumper.hpp"
#include <cmath>

Jumper::Jumper(int given_x, int given_y, Field* field, int hp, int attack, int range): Patrolling(given_x, given_y, field, hp, attack, range) {
    patrol_pattern = {RIGHT, RIGHT, RIGHT, DOWN, DOWN, DOWN, LEFT, LEFT, LEFT, UP, UP, UP};
}

void Jumper::move(Direction direction){
    int new_x = get_x();
    int new_y = get_y();
    switch(direction){
        case UP:
            if (new_y - 2 >= 0){
                if (current_field->get_cell(new_x, new_y - 2).is_free() && current_field->get_cell(new_x, new_y - 2).is_walkable()){
                    new_y = new_y - 2;
                }
            } else if (new_y - 1 >= 0){
                if (current_field->get_cell(new_x, new_y - 1).is_free() && current_field->get_cell(new_x, new_y - 1).is_walkable()){
                   new_y = new_y - 1;
                }
            }
            break;
        case DOWN:
            if (new_y + 2 < current_field->get_height()){
                if (current_field->get_cell(new_x, new_y + 2).is_free() && current_field->get_cell(new_x, new_y + 2).is_walkable()){
                    new_y = new_y + 2;
                }
            } else if (new_y + 1 < current_field->get_height()){
                if (current_field->get_cell(new_x, new_y + 1).is_free() && current_field->get_cell(new_x, new_y + 1).is_walkable()){
                    new_y = new_y + 1;
                }
            }
            break;
        case RIGHT:
            if (new_x + 2 < current_field->get_width()){
                if (current_field->get_cell(new_x + 2, new_y).is_free() && current_field->get_cell(new_x + 2, new_y).is_walkable()){
                    new_x = new_x + 2;
                }
            } else if (new_x + 1 < current_field->get_width()){
                if (current_field->get_cell(new_x + 1, new_y).is_free() && current_field->get_cell(new_x + 1, new_y).is_walkable()){
                    new_x = new_x + 1;
                }
            } 
            break;
        case LEFT:
            if (new_x - 2 >= 0){
                if (current_field->get_cell(new_x - 2, new_y).is_free() && current_field->get_cell(new_x - 2, new_y).is_walkable()){
                    new_x = new_x - 2;
                }
            } else if (new_x - 1 >= 0){
                if (current_field->get_cell(new_x - 1, new_y).is_free() && current_field->get_cell(new_x - 1, new_y).is_walkable()){
                    new_x = new_x - 1;
                }
            }
            break;
    }
    if (new_x == get_x() && new_y == get_y())
        return;
    change_position(new_x, new_y);
}


bool Jumper::is_player_reachable(Player &player){
    if (abs(get_x() - player.get_x()) <= attack_range && abs(get_y() - player.get_y()) <= attack_range){
        return true;
    } else {
        return false;
    }
}

void Jumper::next_action(Player& player){
    if (is_player_reachable(player)){
        attack(player);
    } else {
        move(patrol_pattern[direction_index]);
        increase_index();
    }
}

void Jumper::attack(Player& player){
    player.get_damage(attack_points);
}