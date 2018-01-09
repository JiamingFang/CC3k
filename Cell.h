#ifndef CELL_H
#define CELL_H


#include "BaseObject.h"

class GameObject;

class Cell : public BaseObject {
private:
    char texture;                 // space - | . + # / -
    GameObject* object = nullptr;

public:

    Cell(char texture, int x, int y);

    ~Cell();

    char getTexture();   // new

    void setTexture(char texture);

    bool canAccess();
    bool canRandom();
    bool isStair();

    GameObject *getObject() const;
    void deleteObject();

    void setObject(GameObject *object);

};


#endif 
