#include "Cell.h"
#include "GameObject.h"



Cell::Cell(char texture, int x, int y) : texture(texture), BaseObject(x, y) {}

bool Cell::canAccess() {
    return texture == '.' || texture == '+' || texture == '#' || texture == '/';
}

bool Cell::canRandom() {
    return texture == '.' && object == nullptr;
}

bool Cell::isStair() {
    return texture == '/';
}

GameObject* Cell::getObject() const {
    return object;
}


void Cell::setObject(GameObject *object) {
    Cell::object = object;
}

char Cell::getTexture() {
    return texture;
}

void Cell::deleteObject() {
    object = nullptr;
}

void Cell::setTexture(char texture) {
    Cell::texture = texture;
}

Cell::~Cell() {
}



