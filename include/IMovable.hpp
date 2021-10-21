#pragma once

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class IMovable{
public:
    virtual void move(Direction direction) = 0;
};