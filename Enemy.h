#ifndef ENEMY_H
#define ENEMY_H

#include <vector>
#include "Character.h"
#include "Hero.h"
#include "Treasure.h"
#include "Floor.h"

class Hero;
class DragonHoard;

enum EnemyType {
    EnemyTypeHuman = 0, //H
    EnemyTypeDwarf, // D
    EnemyTypeElf, // E
    EnemyTypeOrcs, // O
    EnemyTypeMerchant, // M
    EnemyTypeDragon, // D
    EnemyTypeHalfling,// H
};

class Enemy : public Character {
private:
    bool action;
protected:
    //Game::Game* game;
    Floor *floor;
    EnemyType type;
    Hero *hero;
public:
    //   EnEnemy::builder(type, x,y)

    static Enemy *builder(EnemyType type);

    Enemy();
    void chang_action();

    bool get_action();
    void setHero(Hero* h);


    void setFloor(Floor *f);

    Enemy(EnemyType type);

    //void setGame(Game *g);

    char getTexture() override;

    EnemyType getType();


    void nextTurn(); // attack or random move

    virtual void Attack(Hero *h);

    virtual void takeDamageFrom(Hero *c);

    virtual Treasure* dropGold() {return nullptr;}
};

///////////////////////////////////////////////////////////////////////////////////

class Human : public Enemy { // 140 HP, 20 Atk, 20 Def, Drop 2 normal piles of gold.
   // EnemyType type;
public:
    Human(EnemyType type);

    ~Human();

    void Attack(Hero *hero) override;

    void takeDamageFrom(Hero *c) override;

    Treasure* dropGold();

};

class Dwarf : public Enemy { // 100 HP, 20 Atk, 30 Def, vampire lose 2

public:
    Dwarf(EnemyType type);

    ~Dwarf();

    void Attack(Hero *hero) override;

    void takeDamageFrom(Hero *hero) override;

    void addGold(int num);

};

class Elf : public Enemy { // 140 HP, 30 Atk, 10 Def

public:
    Elf(EnemyType type);

    ~Elf();

    void Attack(Hero *hero) override;

    void takeDamageFrom(Hero *hero) override;

    void addGold(int num);

};

class Orcs : public Enemy { // 180 HP, 30 Atk, 25 Def

public:
    Orcs(EnemyType type);

    ~Orcs();

    void Attack(Hero *hero) override;

    void takeDamageFrom(Hero *hero) override;

    void addGold(int num);
};

class Merchant : public Enemy { // 30 HP, 70 Atk, 5 Def

public:

    Merchant(EnemyType type);

    static bool Hostile; // make change


    ~Merchant();

    void Attack(Hero *hero) override;

    void takeDamageFrom(Hero *hero) override;

    Treasure* dropGold();

};

class Dragon : public Enemy { // 150 HP, 20 Atk, 20 Def

    DragonHoard *hoard;
public:
    void setHoard(DragonHoard *h);

    Dragon(EnemyType type, DragonHoard *hoard);

    ~Dragon();

    void Attack(Hero *hero) override;

    void takeDamageFrom(Hero *hero) override;

};


class Halfling : public Enemy { // 100 HP, 15 Atk, 20 Def
public:
    Halfling(EnemyType type);

    ~Halfling();

    void Attack(Hero *hero) override;

    void takeDamageFrom(Hero *hero) override;

    void addGold(int num);

};


#endif
