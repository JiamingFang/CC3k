#ifndef BASEOBJECT_H
#define BASEOBJECT_H
#include <string>
#include <iostream>

class BaseObject {
protected:
    int x;
    int y;
public:

    BaseObject();
    BaseObject(int x, int y);

    virtual ~BaseObject();

    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
};


#endif
