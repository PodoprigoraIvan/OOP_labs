#pragma once

#include "Entity.hpp"

class Entity;

class Cell{
public:
    enum Cell_type{
        SIMPLE_CELL,
        ENTRENCE_CELL,
        EXIT_CELL,
    };
    Cell(bool is_walkable, Cell_type cell_type);
    Cell();
    bool is_walkable();
    Cell_type get_type();
    Entity& get_entity();
    void put_entity(Entity* entity);
    void remove_entity();
    bool is_free();
private:
    bool walkable;
    Cell_type type;
    Entity* entity_on_cell;
};