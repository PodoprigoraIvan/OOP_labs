#include "../include/Player.hpp"
#include "../include/Item.hpp"
#include "../include/Cell.hpp"

Player::Player(int given_x, int given_y, Field* field, int hp, int attack, int range) : Creature(given_x, given_y, field, hp, attack, range) {
    attack_range = range;
    level_passed = false;
}

void Player::heal(int add_hp){
    health_points += add_hp;
}

void Player::increase_attack_points(int add_attack_points){
    attack_points += add_attack_points;
}

void Player::increase_attack_range(int add_attack_range){
    attack_range += add_attack_range;
}

bool Player::is_level_passed(){
    return level_passed;
}

void Player::move(Direction direction){
    int new_x = get_x();
    int new_y = get_y();
    switch(direction){
        case UP:
            if (new_y > 0)
                new_y--;
            break;
        case DOWN:
            if (new_y < current_field->get_height() - 1) 
                new_y++;
            break;
        case RIGHT:
            if (new_x < current_field->get_width() - 1)
                new_x++;
            break;
        case LEFT:
            if (new_x > 0)
                new_x--;
            break;
    }
    if (new_x == get_x() && new_y == get_y())
        return;
    if (current_field->get_cell(new_x, new_y).is_walkable() == false)
        return;
    if (current_field->get_cell(new_x, new_y).is_free() == false)
        if (current_field->get_cell(new_x, new_y).get_entity().get_type() == CREATURE){
            return;
        } else if (current_field->get_cell(new_x, new_y).get_entity().get_type() == ITEM) {
            Item& item = static_cast<Item&>(current_field->get_cell(new_x, new_y).get_entity());
            item.influence(*this);
        }
    change_position(new_x, new_y);
    if (current_field->get_cell(new_x, new_y).get_type() == Cell::EXIT_CELL){
        level_passed = true;
    }
}

void Player::attack(Direction direction){
    int x;
    int y;
    int i;
    switch (direction){
        case UP:
        x = get_x();
        y = get_y();
        i = 1;
        while (y - i >= 0 && i <= attack_range){
            if (current_field->get_cell(x, y - i).is_free() == false)
                if (current_field->get_cell(x, y - i).get_entity().get_type() == CREATURE)
                    static_cast<Creature&>(current_field->get_cell(x, y - i).get_entity()).get_damage(attack_points);
            i++;
        }
        break;
        case DOWN:
        x = get_x();
        y = get_y();
        i = 1;
        while (y + i < current_field->get_height() && i <= attack_range){
            if (current_field->get_cell(x, y + i).is_free() == false)
                if (current_field->get_cell(x, y + i).get_entity().get_type() == CREATURE)
                    static_cast<Creature&>(current_field->get_cell(x, y + i).get_entity()).get_damage(attack_points);
            i++;
        }
        break;
        case RIGHT:
        x = get_x();
        y = get_y();
        i = 1;
        while (x + i < current_field->get_width() && i <= attack_range){
            if (current_field->get_cell(x + i, y).is_free() == false)
                if (current_field->get_cell(x + i, y).get_entity().get_type() == CREATURE)
                    static_cast<Creature&>(current_field->get_cell(x + i, y).get_entity()).get_damage(attack_points);
            i++;
        }
        break;
        case LEFT:
        x = get_x();
        y = get_y();
        i = 1;
        while (x - i >= 0 && i <= attack_range){
            if (current_field->get_cell(x - i, y).is_free() == false)
                if (current_field->get_cell(x - i, y).get_entity().get_type() == CREATURE)
                    static_cast<Creature&>(current_field->get_cell(x - i, y).get_entity()).get_damage(attack_points);
            i++;
        }
    }
}