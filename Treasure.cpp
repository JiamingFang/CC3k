#include "Treasure.h"


using namespace std;


Treasure::Treasure(){
    size = "";
    amount = 0;
    pickUp = false;
}

Treasure::~Treasure() = default;

char Treasure::getTexture() {
    return 'G';
}

int Treasure::getAmount() {
    return amount;
}

Small::Small(){
    size = "small";
    amount = 1;
    pickUp = false;
}


Small::~Small() = default;



Normal::Normal(int Num, bool p){ // edit it for dropping the gold
    size = "normal";
    this->Num = Num;
    amount = 2*Num;
    pickUp = p;
}


int Normal::getNum() {
    return this->Num;
}


Normal::~Normal() = default;

MerchantHoard::MerchantHoard(){
    size = "merchant";
    amount = 4;
    pickUp = true;
}

MerchantHoard::~MerchantHoard() = default;

DragonHoard::DragonHoard(){
    size = "dragon";
    amount = 6;
    pickUp = true;
    d = nullptr;
}

DragonHoard::~DragonHoard() = default;


Dragon* DragonHoard::getDragon(){ // edit it for losing the return type
    return d;
}

void DragonHoard::deleteDragon(){
    d = nullptr;
}

void DragonHoard::setDragon(Dragon *dragon) {
    d = dragon;
}

void DragonHoard::setPickable(bool b) {
    pickable = b;
}

