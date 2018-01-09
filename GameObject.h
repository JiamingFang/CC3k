#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


#include <string>
#include "BaseObject.h"


class Cell;


class GameObject : public BaseObject {

protected:
    char texture;
    Cell *cell;

public:


    GameObject();                // constructor
    ~GameObject() override;      // destructor

    Cell *getCell() const;
    virtual char getTexture();
    void setCell(Cell *cell);
};


#endif
