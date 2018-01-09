#include "Character.h"

int Character::getHp() const {
    return this->HP;
}

int Character::getAtk() const {
    return this->ATK;
}

int Character::getDef() const {
    return this->DEF;
}


void Character::setHp(int Hp) {
    Character::HP = Hp;
}

void Character::setAtk(int Atk) {
    Character::ATK = Atk;
}

void Character::setDef(int Def) {
    Character::DEF = Def;
}

bool Character::alive(){
    return this->HP > 0;
}

void Character::resetTurn() {
    cur_turn = false;
}

Character:: Character(){}


Character::~Character() {}

//virtual void attack(Character* c){}

//virtual void takeDemage(Character* c){}
