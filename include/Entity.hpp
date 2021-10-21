#pragma once

#include "Field.hpp"

class Entity{
public:
    Entity(int given_x, int given_y, Field* field);
    enum Entity_type{
        CREATURE,
        ITEM
    };
    Entity_type get_type();
    int get_x();
    int get_y();
    bool is_alive();
    void change_position(int new_x, int new_y);
    virtual ~Entity() = default;
protected:
    void die();
    bool alive;
    int x;
    int y;
    Field* current_field;
    Entity_type type;
};
