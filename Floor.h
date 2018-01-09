#ifndef FLOOR_H
#define FLOOR_H
#include <string>
#include <iostream>
#include <vector>
#include "Cell.h"
#include "Character.h"
#include "Chamber.h"
#include "Hero.h"


class Enemy;
class Treasure;
class Potion;

using namespace std;

class Floor {
private:
    static const int ROW = 79;
    static const int COL = 25;
    static const int MAX_ENEMIES = 20;

    int floorNumber;
    vector<vector<Cell>> map;
    vector<Enemy*> enemies; // edit it to pointer..
    vector<Potion*> potions;
    vector<Treasure*> treasures;
    Hero* hero;
    void clear(); // clear the map
    Chamber Chamber0;
    Chamber Chamber1;
    Chamber Chamber2;
    Chamber Chamber3;
    Chamber Chamber4;
    Chamber* Chambers[5] = {&Chamber0, &Chamber1, &Chamber2, &Chamber3, &Chamber4};

public:

    void chang_action_for_enemies();
    Floor(Hero *hero);

    ~Floor();

    void setHero(Hero* h);

    void initHero(int Chamber_num);

    void initStair(int Chamber_num);

    void initEnemies();

    void initPotions();

    void initTreasures();

    int GetFloorNum();

    void plusFloorNum();

    void init();

    void nextTurn(); // loop enemies to move or attack.

    Cell& getCell(int x, int y);
};


#endif
