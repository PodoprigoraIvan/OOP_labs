#pragma once
#include "Cell.hpp" 

class Cell;

class Field {
    Cell ** cell_array;
    int height;
    int width;
public:
    Field(int width, int height);
    Field(const Field& other_field);
    Field& operator=(const Field& other_field);
    Field(Field&& other_field);
    Field& operator=(Field&& other_field);
    Cell& get_cell(int x, int y);
    int get_width();
    int get_height();
    ~Field();
};