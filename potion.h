#ifndef _POTION_H
#define _POTION_H

#include "Item.h"

using namespace std;


class Potion: public Item {
public:
    Potion(string effect);
    ~Potion();

    string getEffect();
    char getTexture();



private:
    string potionEffect;	// potionEffect: "RA" "BA" "BD" "PH" "WA" "WD"
    bool revealed = false;

};
#endif

