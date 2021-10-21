#include "../include/Item.hpp"

Item::Item(int given_x, int given_y, Field* field) : Entity(given_x, given_y, field) {
    type = ITEM;
}