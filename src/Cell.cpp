#include "../include/Cell.hpp"

Cell::Cell(bool is_walkable, Cell_type cell_type):
    entity_on_cell(nullptr),
    walkable(is_walkable),
    type(cell_type)
    {}

Cell::Cell(){
    entity_on_cell = nullptr;
    walkable = true;
    type = SIMPLE_CELL;
}

bool Cell::is_walkable(){
    return walkable;
}

Cell::Cell_type Cell::get_type(){
    return type;
}

Entity& Cell::get_entity(){
    return *entity_on_cell;
}

void Cell::put_entity(Entity* entity){
    entity_on_cell = entity;
}

void Cell::remove_entity(){
    entity_on_cell = nullptr;
}

bool Cell::is_free(){
    return (entity_on_cell == nullptr);
}