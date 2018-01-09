#include <iostream>
#include "Display.h"

Display::Display(){
    floor = nullptr;
}

Display::~Display() {
    floor = nullptr;
}
void Display::updateAction(string a) {
    action = a;
}

void Display::update( Hero *hero) {
    if(hero->getRace() == 'S'){
        name = "Shade";
    }else if(hero->getRace() == 'D'){
        name = "Drow";
    }else if(hero->getRace() == 'V'){
        name = "Vampire";
    }else if(hero->getRace() == 'T'){
        name = "Troll";
    }else if(hero->getRace() == 'G'){
        name = "Goblin";
    }

    atk = hero->getAtk();
    hp = hero->getHp();
    def = hero->getDef();
    gold = hero->getGold();
}


void Display::setFloor(Floor *f) {
    floor = f;
}

void Display::render() const {
    for(int i = 0; i < 25; i++){
        for(int j = 0; j < 79; j++){
            if(floor->getCell(j,i).getObject() == nullptr) {
                cout << floor->getCell(j, i).getTexture();
            }
            else{
                cout << floor->getCell(j, i).getObject()->getTexture();
            }
        }
        cout << endl;
    }
    cout << "Race: " << name << " " << "Gold: " << gold << "                                       " << "Floor " << floor->GetFloorNum() << endl;
    cout << "HP: " << hp << endl;
    cout << "ATK: " << atk << endl;
    cout << "DEF: " << def << endl;
    cout << "Action: " << action << endl;
}