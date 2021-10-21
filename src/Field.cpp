#include "../include/Cell.hpp"
#include "../include/Field.hpp"
#include <algorithm>
#include <iostream>

Field::Field(int given_width, int given_height){
    height = given_height;
    width = given_width;
    cell_array = new Cell*[height];
    for (int i = 0; i < height; i++)
    {
        cell_array[i] = new Cell[width];
        for (int j = 0; j < width; j++)
            cell_array[i][j] = Cell(true, Cell::SIMPLE_CELL);
    }
    cell_array[0][0] = Cell(true, Cell::ENTRENCE_CELL);
    cell_array[height - 1][width - 1] = Cell(true, Cell::EXIT_CELL);
}

Field::Field(const Field& other_field) : Field(other_field.width, other_field.height){
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cell_array[i][j] = other_field.cell_array[i][j];
        }
    }
}

Field& Field::operator=(const Field& other_field){
    if (&other_field == this)
        return *this;
    for (int i = 0; i < height; i++){
        delete []cell_array[i];
    }
    delete []cell_array;
    height = other_field.height;
    width = other_field.width;
    cell_array = new Cell*[height];
    for (int i = 0; i < height; i++)
    {
        cell_array[i] = new Cell[width];
    }
    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            cell_array[i][j] = other_field.cell_array[i][j];
        }
    }
    return *this;
}

Field::Field(Field&& other_field){
    std::swap(cell_array, other_field.cell_array);
    std::swap(height, other_field.height);
    std::swap(width, other_field.width);
}

Field& Field::operator=(Field&& other_field){
    if (&other_field == this)
        return *this;
    std::swap(cell_array, other_field.cell_array);
    std::swap(height, other_field.height);
    std::swap(width, other_field.width);
    return *this;
}

Field::~Field(){
    for (int i = 0; i < height; i++){
        delete []cell_array[i];
    }
    delete []cell_array;
}

Cell& Field::get_cell(int x, int y){
    return cell_array[y][x];
}

int Field::get_width(){
    return width;
}

int Field::get_height(){
    return height;
}