#ifndef HERO_H
#define HERO_H


#include "Character.h"
#include "potion.h"

class Floor;
class Enemy;

/*enum HeroType {
    HeroTypeShade = 0,
    HeroTypeDrow,
    HeroTypeVampire,
    HeroTypeTroll,
    HeroTypeGoblin,
    HeroTypeMax,
};*/


class Hero : public Character {
private:
    int attact_potion_num;
    int def_potion_num;
    int floornum;


protected:
    int GoldNum;
    char race;
    int MaxHp;
    Floor *floor;

public:


    Hero();
    Hero(Floor *floor);
    ~Hero();

    void setFloor(Floor* f);

    char getRace();

    char getTexture() override;

    virtual void Attack(Enemy *c);

    virtual void takeDamage(Enemy *c);


    bool move(std::string direction);

    bool pickPotion(std::string direction);

    string usePotion(string direction);

    void pickGold(std::string direction);

    bool attack(std::string direction );

    void nextfloor(); // deal with permant potion (buff)

    //void pickupGold(std::string direction); // might ot might not need

    void usePotion(Potion *potion); // use the potion

    void addGold(int gold);

    int getGold();
};

//////////////////////////////////////////////////////////////////////////////////////

class Shade : public Hero {
public:
    Shade();

    ~Shade();

    void Attack(Enemy *c) override;

    void takeDamage(Enemy *c) override;


};

class Drow : public Hero {
public:
    Drow();

    ~Drow();

    void Attack(Enemy *c) override;

    void takeDamage(Enemy *c) override;

};

class Vampire : public Hero {
public:

    Vampire();

    ~Vampire();

    void Attack(Enemy *c) override;

    void takeDamage(Enemy *c) override;

};

class Troll : public Hero {
public:
    Troll();

    ~Troll();

    void Attack(Enemy *c) override;

    void takeDamage(Enemy *c) override;
};

class Goblin : public Hero {
public:

    Goblin();

    ~Goblin();

    void Attack(Enemy *c) override;

    void takeDamage(Enemy *c) override;

    void stealGold(Enemy *e);

};

#endif
