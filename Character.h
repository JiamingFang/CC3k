#ifndef CHARACTER_H
#define CHARACTER_H


#include "GameObject.h"

class Character : public GameObject {
protected:
    int HP;
    int ATK;
    int DEF;
    bool cur_turn;

public:
    bool alive();

    void resetTurn();

    int getHp() const;

    int getAtk() const;

    int getDef() const;

    void setHp(int Hp);

    void setAtk(int Atk);

    void setDef(int Def);


    Character();

    virtual ~Character();
};



#endif 
