#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>
#include <vector>
#include "Hero.h"
#include "Floor.h"

class Cell;

using namespace std;

class Display {
private:
    string name;
    int gold;
    int hp;
    int atk;
    int def;
    string action;
    Floor *floor;

public:
    Display();

    ~Display();

    void updateAction(string action);

    void setFloor(Floor *f);

    void update(Hero* hero);

    void render() const;
};




#endif