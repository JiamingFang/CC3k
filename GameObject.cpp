#include "GameObject.h"



// GameObject Constructor Implementation
GameObject::GameObject() = default;


// GameObject Destructor Implementation
GameObject::~GameObject() {
    cell = nullptr;
}



Cell *GameObject::getCell() const {
    return this->cell;
}



void GameObject::setCell(Cell *cell) {
    GameObject::cell = cell;
}

char GameObject::getTexture() {
    return texture;
}





