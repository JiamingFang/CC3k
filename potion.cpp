#include "potion.h"

Potion::Potion(string effect): Item(), potionEffect{effect}  {}


Potion::~Potion() {}

string Potion::getEffect(){
    return potionEffect;
}


char Potion::getTexture() {
    return 'P';
}


