#ifndef TREASURE_H
#define TREASURE_H

#include "Item.h"
#include "Enemy.h"
#include <string>
#include <iostream>
using namespace std;


class Dragon;
class Potion;
class Enemy;

using namespace std;


class Dragon;
class Potion;
class Hero;
class Enemy;


class Treasure: public Item{
protected:
    string size;
    int amount;      //the size of the gold
    bool pickUp;     //whether the gold needs to be picked up or adds to player automatically
public:
    int getAmount();
    char getTexture();
    Treasure();
    virtual ~Treasure();

};

class Small: public Treasure{
public:
    Small();
    ~Small();
};

class Normal: public Treasure{ // edit it for dropGold
    int Num;
public:
    int getNum();
    Normal(int Num, bool pickUp);
    ~Normal();
};

class MerchantHoard: public Treasure{
public:
    MerchantHoard();
    ~MerchantHoard();
};

class DragonHoard: public Treasure{
    Dragon *d;
    bool pickable;
public:
    DragonHoard();
    ~DragonHoard();
    void setDragon(Dragon * dragon);
    Dragon* getDragon();
    void deleteDragon(); // error
    void setPickable(bool b);
};



#endif
