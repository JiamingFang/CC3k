#include "BaseObject.h"

int BaseObject::getX() const {
    return x;
}

int BaseObject::getY() const {
    return y;
}

void BaseObject::setX(int x) {
    BaseObject::x = x;
}

void BaseObject::setY(int y) {
    BaseObject::y = y;
}

BaseObject::BaseObject(int x, int y): x{x}, y{y} {}

BaseObject::BaseObject() = default;

BaseObject::~BaseObject() = default;



