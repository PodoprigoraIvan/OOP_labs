#include "../include/Entity.hpp"
#include "../include/Field.hpp"
#include <iostream>

Entity::Entity(int given_x, int given_y, Field* field){
    x = given_x;
    y = given_y;
    //std::cout << "\n=" << field->get_cell(x, y).is_free();
    field->get_cell(x, y).put_entity(this);
    //std::cout << "\n=" << field->get_cell(x, y).is_free();
    current_field = field;
    alive = true;
}

int Entity::get_x(){
    return x;
}

int Entity::get_y(){
    return y;
}

Entity::Entity_type Entity::get_type(){
    return type;
}

bool Entity::is_alive(){
    return alive;
}

void Entity::die(){
    alive = false;
    current_field->get_cell(x, y).remove_entity();
}

void Entity::change_position(int new_x, int new_y){
    current_field->get_cell(x, y).remove_entity();
    current_field->get_cell(new_x, new_y).put_entity(this);
    x = new_x;
    y = new_y;
}