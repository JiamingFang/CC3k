#include "Hero.h"
#include "Floor.h"
#include "Enemy.h"
#include "Helpers.h"




//int attackTable[] = {25, 25, 25, 25, 15};
//int defendTable[] = {25, 15, 25, 15, 20};
//int hpTable[] = {125, 150, 50, 120, 110};

Hero::Hero() {
    GoldNum = 0;
    floor = nullptr;
    attact_potion_num = 0;
    def_potion_num = 0;
}

Hero::~Hero() {}

Hero::Hero(Floor *f) {
    GoldNum = 0;
    floor = f;
}

int Hero::getGold() {
    return GoldNum;
}

char Hero::getTexture() {
    return '@';
}

void Hero::setFloor(Floor *f) {
    floor = f;
}

char Hero::getRace() {
    return race;
}

void Hero::Attack(Enemy *c) {

}

void Hero::takeDamage(Enemy *c) {
    cout << "take damage true" << endl;
}

void Hero::nextfloor() {
    cout << ATK << endl;
    cout << DEF << endl;
    cout << attact_potion_num << endl;
    cout << def_potion_num << endl;
    ATK -= (attact_potion_num * 5);
    DEF -= (def_potion_num * 5);
}

void Hero::usePotion(Potion *potion) {
    if (potion->getEffect() == "RH") {
        HP += 10;
        if (HP >= MaxHp) HP = MaxHp;
    } else if (potion->getEffect() == "PH") {
        HP -= 10;
    } else if (potion->getEffect() == "BA") {
        ATK += 5;
        attact_potion_num++;
    } else if (potion->getEffect() == "WA") {
        ATK -= 5;
        attact_potion_num--;
    } else if (potion->getEffect() == "BD") {
        DEF += 5;
        def_potion_num++;
    } else if (potion->getEffect() == "WD") {
        DEF -= 5;
        def_potion_num--;
    }
}


bool Hero::move(std::string direction) {
    //if(floor->getCell(x,y).getObject() != nullptr && floor->getCell(x,y).getObject()->getTexture() == 'G'){
    //    pickGold(direction);
    //}
    int old_x = x;
    int old_y = y;
    if (direction == "no") {

        if (floor->getCell(x, y - 1).canAccess()) {
            if (floor->getCell(x, y - 1).getObject() != nullptr &&
                floor->getCell(x, y - 1).getObject()->getTexture() == 'G') {
                pickGold(direction);
                floor->getCell(x, y).deleteObject();
                this->y -= 1;
            } else if (floor->getCell(x, y - 1).getObject() == nullptr) {
                floor->getCell(x, y).deleteObject();
                this->y -= 1;
            }


        }

    } else if (direction == "so") {

        if (floor->getCell(x, y + 1).canAccess()) {
            if (floor->getCell(x, y + 1).getObject() != nullptr &&
                floor->getCell(x, y + 1).getObject()->getTexture() == 'G') {
                pickGold(direction);
                floor->getCell(x, y).deleteObject();
                this->y += 1;
            } else if (floor->getCell(x, y + 1).getObject() == nullptr) {
                floor->getCell(x, y).deleteObject();
                this->y += 1;
            }
        }
    } else if (direction == "ea") {
        if (floor->getCell(x + 1, y).canAccess()) {
            if (floor->getCell(x + 1, y).getObject() != nullptr &&
                floor->getCell(x + 1, y).getObject()->getTexture() == 'G') {
                pickGold(direction);
                floor->getCell(x, y).deleteObject();
                this->x += 1;
            } else if (floor->getCell(x + 1, y).getObject() == nullptr) {
                floor->getCell(x, y).deleteObject();
                this->x += 1;
            }
        }
    } else if (direction == "we") {

        if (floor->getCell(x - 1, y).canAccess()) {
            if (floor->getCell(x - 1, y).getObject() != nullptr &&
                floor->getCell(x - 1, y).getObject()->getTexture() == 'G') {
                pickGold(direction);
                floor->getCell(x, y).deleteObject();
                this->x -= 1;
            } else if (floor->getCell(x - 1, y).getObject() == nullptr) {
                floor->getCell(x, y).deleteObject();
                this->x -= 1;
            }

        }
    } else if (direction == "ne") {
        if (floor->getCell(x + 1, y - 1).canAccess()) {
            if (floor->getCell(x + 1, y - 1).getObject() != nullptr &&
                floor->getCell(x + 1, y - 1).getObject()->getTexture() == 'G') {
                pickGold(direction);
                floor->getCell(x, y).deleteObject();
                this->y -= 1;
                this->x += 1;
            } else if (floor->getCell(x + 1, y - 1).getObject() == nullptr) {
                floor->getCell(x, y).deleteObject();
                this->x += 1;
                this->y -= 1;
            }

        }

    } else if (direction == "nw") {
        if (floor->getCell(x - 1, y - 1).canAccess()) {
            if (floor->getCell(x - 1, y - 1).getObject() != nullptr &&
                floor->getCell(x - 1, y - 1).getObject()->getTexture() == 'G') {
                pickGold(direction);
                floor->getCell(x, y).deleteObject();
                this->y -= 1;
                this->x -= 1;
            } else if (floor->getCell(x - 1, y - 1).getObject() == nullptr) {
                floor->getCell(x, y).deleteObject();
                this->x -= 1;
                this->y -= 1;
            }

        }

    } else if (direction == "se") {
        if (floor->getCell(x + 1, y + 1).canAccess()) {
            if (floor->getCell(x + 1, y + 1).getObject() != nullptr &&
                floor->getCell(x + 1, y + 1).getObject()->getTexture() == 'G') {
                pickGold(direction);
                floor->getCell(x, y).deleteObject();
                this->y += 1;
                this->x += 1;
            } else if (floor->getCell(x + 1, y + 1).getObject() == nullptr) {
                floor->getCell(x, y).deleteObject();
                this->x += 1;
                this->y += 1;
            }

        }

    } else if (direction == "sw") {
        if (floor->getCell(x - 1, y + 1).canAccess()) {
            if (floor->getCell(x - 1, y + 1).getObject() != nullptr &&
                floor->getCell(x - 1, y + 1).getObject()->getTexture() == 'G') {
                pickGold(direction);
                floor->getCell(x, y).deleteObject();
                this->y += 1;
                this->x -= 1;
            } else if (floor->getCell(x - 1, y + 1).getObject() == nullptr) {
                floor->getCell(x, y).deleteObject();
                this->x -= 1;
                this->y += 1;
            }

        }

    }
    floor->getCell(x, y).setObject(this);
    this->setCell(&floor->getCell(x, y));


    if (floor->getCell(x, y).getTexture() == '/') {
        floor->init();
        nextfloor();
        floor->plusFloorNum();
    }
    if (old_x != x || old_y != y) {
        return true;
    } else {
        return false;
    }
}

void Hero::pickGold(std::string direction) {
    if (direction == "no") {
        if (floor->getCell(x, y - 1).getObject()->getTexture() == 'G') { // slicing problem ,find solution
            Treasure *t = dynamic_cast<Treasure *>(floor->getCell(x, y - 1).getObject());
            addGold(t->getAmount());
            floor->getCell(x, y - 1).deleteObject();
        }

    } else if (direction == "so") {
        if (floor->getCell(x, y + 1).getObject()->getTexture() == 'G') { // slicing problem ,find solution
            Treasure *t = dynamic_cast<Treasure *>(floor->getCell(x, y + 1).getObject());
            addGold(t->getAmount());
            floor->getCell(x, y + 1).deleteObject();
        }
    } else if (direction == "ea") {
        if (floor->getCell(x + 1, y).getObject()->getTexture() == 'G') { // slicing problem ,find solution
            Treasure *t = dynamic_cast<Treasure *>(floor->getCell(x + 1, y).getObject());
            addGold(t->getAmount());
            floor->getCell(x + 1, y).deleteObject();
        }
    } else if (direction == "we") {
        if (floor->getCell(x - 1, y).getObject()->getTexture() == 'G') { // slicing problem ,find solution
            Treasure *t = dynamic_cast<Treasure *>(floor->getCell(x - 1, y).getObject());
            addGold(t->getAmount());
            floor->getCell(x - 1, y).deleteObject();
        }
    } else if (direction == "ne") {
        if (floor->getCell(x + 1, y - 1).getObject()->getTexture() == 'G') { // slicing problem ,find solution
            Treasure *t = dynamic_cast<Treasure *>(floor->getCell(x + 1, y - 1).getObject());
            addGold(t->getAmount());
            floor->getCell(x + 1, y - 1).deleteObject();
        }

    } else if (direction == "nw") {
        if (floor->getCell(x - 1, y - 1).getObject()->getTexture() == 'G') { // slicing problem ,find solution
            Treasure *t = dynamic_cast<Treasure *>(floor->getCell(x - 1, y - 1).getObject());
            addGold(t->getAmount());
            floor->getCell(x - 1, y - 1).deleteObject();
        }

    } else if (direction == "se") {
        if (floor->getCell(x + 1, y + 1).getObject()->getTexture() == 'G') { // slicing problem ,find solution
            Treasure *t = dynamic_cast<Treasure *>(floor->getCell(x + 1, y + 1).getObject());
            addGold(t->getAmount());
            floor->getCell(x + 1, y + 1).deleteObject();
        }

    } else if (direction == "sw") {
        if (floor->getCell(x - 1, y + 1).getObject()->getTexture() == 'G') { // slicing problem ,find solution
            Treasure *t = dynamic_cast<Treasure *>(floor->getCell(x - 1, y + 1).getObject());
            addGold(t->getAmount());
            floor->getCell(x - 1, y + 1).deleteObject();
        }

    }
}

bool Hero::attack(std::string direction) {
    if (direction == "no") {
        if (floor->getCell(x, y - 1).getObject() != nullptr &&
            (floor->getCell(x, y - 1).getObject()->getTexture() == 'H' ||
             floor->getCell(x, y - 1).getObject()->getTexture() == 'W' ||
             floor->getCell(x, y - 1).getObject()->getTexture() == 'E' ||
             floor->getCell(x, y - 1).getObject()->getTexture() == 'O' ||
             floor->getCell(x, y - 1).getObject()->getTexture() == 'M' ||
            floor->getCell(x, y - 1).getObject()->getTexture() == 'D' ||
            floor->getCell(x, y - 1).getObject()->getTexture() == 'L') ){
            Enemy *enemy = dynamic_cast<Enemy *>(floor->getCell(x, y - 1).getObject());
            Attack(enemy);
            return true;
        } else {
            return false;
        }
    } else if (direction == "so") {
        if (floor->getCell(x, y + 1).getObject() != nullptr &&
            (floor->getCell(x, y + 1).getObject()->getTexture() == 'H' ||
             floor->getCell(x, y + 1).getObject()->getTexture() == 'W' ||
             floor->getCell(x, y + 1).getObject()->getTexture() == 'E' ||
             floor->getCell(x, y + 1).getObject()->getTexture() == 'O' ||
             floor->getCell(x, y + 1).getObject()->getTexture() == 'M' ||
             floor->getCell(x, y + 1).getObject()->getTexture() == 'D' ||
             floor->getCell(x, y + 1).getObject()->getTexture() == 'L')) {
            Enemy *enemy = dynamic_cast<Enemy *>(floor->getCell(x, y + 1).getObject());
            Attack(enemy);
            return true;
        } else {
            return false;
        }
    } else if (direction == "ea") {
        if (floor->getCell(x + 1, y).getObject() != nullptr &&
            (floor->getCell(x + 1, y).getObject()->getTexture() == 'H' ||
             floor->getCell(x + 1, y).getObject()->getTexture() == 'W' ||
             floor->getCell(x + 1, y).getObject()->getTexture() == 'E' ||
             floor->getCell(x + 1, y).getObject()->getTexture() == 'O' ||
             floor->getCell(x + 1, y).getObject()->getTexture() == 'M' ||
             floor->getCell(x + 1, y).getObject()->getTexture() == 'D' ||
             floor->getCell(x + 1, y).getObject()->getTexture() == 'L')) {
            Enemy *enemy = dynamic_cast<Enemy *>(floor->getCell(x + 1, y).getObject());
            Attack(enemy);
            return true;
        } else {
            return false;
        }
    } else if (direction == "we") {
        if (floor->getCell(x - 1, y).getObject() != nullptr &&
            (floor->getCell(x - 1, y).getObject()->getTexture() == 'H' ||
             floor->getCell(x - 1, y).getObject()->getTexture() == 'W' ||
             floor->getCell(x - 1, y).getObject()->getTexture() == 'E' ||
             floor->getCell(x - 1, y).getObject()->getTexture() == 'O' ||
             floor->getCell(x -1, y).getObject()->getTexture() == 'M' ||
             floor->getCell(x - 1, y).getObject()->getTexture() == 'D' ||
             floor->getCell(x - 1, y).getObject()->getTexture() == 'L')) {
            Enemy *enemy = dynamic_cast<Enemy *>(floor->getCell(x - 1, y).getObject());
            Attack(enemy);
            return true;
        } else {
            return false;
        }
    } else if (direction == "ne") {
        if (floor->getCell(x + 1, y- 1).getObject() != nullptr &&
            (floor->getCell(x + 1, y- 1).getObject()->getTexture() == 'H' ||
             floor->getCell(x + 1, y- 1).getObject()->getTexture() == 'W' ||
             floor->getCell(x + 1, y- 1).getObject()->getTexture() == 'E' ||
             floor->getCell(x + 1, y- 1).getObject()->getTexture() == 'O' ||
             floor->getCell(x + 1, y- 1).getObject()->getTexture() == 'M' ||
             floor->getCell(x + 1, y- 1).getObject()->getTexture() == 'D' ||
             floor->getCell(x + 1, y- 1).getObject()->getTexture() == 'L')) {
            Enemy *enemy = dynamic_cast<Enemy *>(floor->getCell(x + 1, y- 1).getObject());
            Attack(enemy);
            return true;
        } else {
            return false;
        }
    } else if (direction == "nw") {
        if (floor->getCell(x - 1, y- 1).getObject() != nullptr &&
            (floor->getCell(x - 1, y- 1).getObject()->getTexture() == 'H' ||
             floor->getCell(x - 1, y- 1).getObject()->getTexture() == 'W' ||
             floor->getCell(x - 1, y- 1).getObject()->getTexture() == 'E' ||
             floor->getCell(x - 1, y- 1).getObject()->getTexture() == 'O' ||
             floor->getCell(x -1, y- 1).getObject()->getTexture() == 'M' ||
             floor->getCell(x - 1, y- 1).getObject()->getTexture() == 'D' ||
             floor->getCell(x - 1, y- 1).getObject()->getTexture() == 'L')) {
            Enemy *enemy = dynamic_cast<Enemy *>(floor->getCell(x - 1, y- 1).getObject());
            Attack(enemy);
            return true;
        } else {
            return false;
        }
    } else if (direction == "se") {
        if (floor->getCell(x + 1, y + 1).getObject() != nullptr &&
            (floor->getCell(x + 1, y + 1).getObject()->getTexture() == 'H' ||
             floor->getCell(x + 1, y + 1).getObject()->getTexture() == 'W' ||
             floor->getCell(x + 1, y + 1).getObject()->getTexture() == 'E' ||
             floor->getCell(x + 1, y + 1).getObject()->getTexture() == 'O' ||
             floor->getCell(x + 1, y + 1).getObject()->getTexture() == 'M' ||
             floor->getCell(x + 1, y + 1).getObject()->getTexture() == 'D' ||
             floor->getCell(x + 1, y + 1).getObject()->getTexture() == 'L')) {
            Enemy *enemy = dynamic_cast<Enemy *>(floor->getCell(x + 1, y + 1).getObject());
            Attack(enemy);
            return true;
        } else {
            return false;
        }
    } else if (direction == "sw") {
        if (floor->getCell(x- 1, y + 1).getObject() != nullptr &&
            (floor->getCell(x- 1, y + 1).getObject()->getTexture() == 'H' ||
             floor->getCell(x- 1, y + 1).getObject()->getTexture() == 'W' ||
             floor->getCell(x- 1, y + 1).getObject()->getTexture() == 'E' ||
             floor->getCell(x- 1, y + 1).getObject()->getTexture() == 'O' ||
             floor->getCell(x- 1, y + 1).getObject()->getTexture() == 'M' ||
             floor->getCell(x- 1, y + 1).getObject()->getTexture() == 'D' ||
             floor->getCell(x- 1, y + 1).getObject()->getTexture() == 'L')) {
            Enemy *enemy = dynamic_cast<Enemy *>(floor->getCell(x- 1, y + 1).getObject());
            Attack(enemy);
            return true;
        } else {
            return false;
        }
    }
}

string Hero::usePotion(string direction) {
    if (direction == "no") {
        Potion *p = dynamic_cast<Potion *>(floor->getCell(x, y - 1).getObject());
        usePotion(p);
        string effect = p->getEffect();
        floor->getCell(x, y - 1).deleteObject();
        return effect;

    } else if (direction == "so") {
        Potion *p = dynamic_cast<Potion *>(floor->getCell(x, y + 1).getObject());
        usePotion(p);
        string effect = p->getEffect();
        floor->getCell(x, y + 1).deleteObject();
        return effect;
    } else if (direction == "ea") {
        Potion *p = dynamic_cast<Potion *>(floor->getCell(x + 1, y).getObject());
        usePotion(p);
        string effect = p->getEffect();
        floor->getCell(x + 1, y).deleteObject();
        return effect;
    } else if (direction == "we") {
        Potion *p = dynamic_cast<Potion *>(floor->getCell(x - 1, y).getObject());
        usePotion(p);
        string effect = p->getEffect();
        floor->getCell(x - 1, y).deleteObject();
        return effect;
    } else if (direction == "ne") {
        Potion *p = dynamic_cast<Potion *>(floor->getCell(x + 1, y - 1).getObject());
        usePotion(p);
        string effect = p->getEffect();
        floor->getCell(x + 1, y - 1).deleteObject();
        return effect;
    } else if (direction == "nw") {
        Potion *p = dynamic_cast<Potion *>(floor->getCell(x - 1, y - 1).getObject());
        usePotion(p);
        string effect = p->getEffect();
        floor->getCell(x - 1, y - 1).deleteObject();
        return effect;
    } else if (direction == "se") {
        Potion *p = dynamic_cast<Potion *>(floor->getCell(x + 1, y + 1).getObject());
        usePotion(p);
        string effect = p->getEffect();
        floor->getCell(x + 1, y + 1).deleteObject();
        return effect;
    } else if (direction == "sw") {
        Potion *p = dynamic_cast<Potion *>(floor->getCell(x - 1, y + 1).getObject());
        usePotion(p);
        string effect = p->getEffect();
        floor->getCell(x - 1, y + 1).deleteObject();
        return effect;
    }
}

bool Hero::pickPotion(std::string direction) {
    if (direction == "no") {
        if (floor->getCell(x, y - 1).getObject() != nullptr &&
            floor->getCell(x, y - 1).getObject()->getTexture() == 'P') {
            return true;
        } else {
            return false;
        }

    } else if (direction == "so") {
        if (floor->getCell(x, y + 1).getObject() != nullptr &&
            floor->getCell(x, y + 1).getObject()->getTexture() == 'P') {
            return true;
        } else {
            return false;
        }
    } else if (direction == "ea") {
        if (floor->getCell(x + 1, y).getObject() != nullptr &&
            floor->getCell(x + 1, y).getObject()->getTexture() == 'P') {
            return true;
        } else {
            return false;
        }
    } else if (direction == "we") {
        if (floor->getCell(x - 1, y).getObject() != nullptr &&
            floor->getCell(x - 1, y).getObject()->getTexture() == 'P') {
            return true;
        } else {
            return false;
        }
    } else if (direction == "ne") {
        if (floor->getCell(x + 1, y - 1).getObject() != nullptr &&
            floor->getCell(x + 1, y - 1).getObject()->getTexture() == 'P') {
            return true;
        } else {
            return false;
        }

    } else if (direction == "nw") {
        if (floor->getCell(x - 1, y - 1).getObject() != nullptr &&
            floor->getCell(x - 1, y - 1).getObject()->getTexture() == 'P') {
            return true;
        } else {
            return false;
        }

    } else if (direction == "se") {
        if (floor->getCell(x + 1, y + 1).getObject() != nullptr &&
            floor->getCell(x + 1, y + 1).getObject()->getTexture() == 'P') {
            return true;
        } else {
            return false;
        }

    } else if (direction == "sw") {
        if (floor->getCell(x - 1, y + 1).getObject() != nullptr &&
            floor->getCell(x - 1, y + 1).getObject()->getTexture() == 'P') {
            return true;
        } else {
            return false;
        }

    }
}

void Hero::addGold(int gold) {
    this->GoldNum += gold;
}

/*Hero *Hero::builder(HeroType type) {
    switch (type) {
        case HeroTypeShade:
            return new Shade(HeroTypeShade);
        case HeroTypeDrow:
            return new Drow(HeroTypeDrow);
        case HeroTypeVampire:
            return new Vampire(HeroTypeVampire);
        case HeroTypeTroll:
            return new Troll(HeroTypeTroll);
        case HeroTypeGoblin:
            return new Goblin(HeroTypeGoblin);
    }
}*/

Shade::Shade() {
    race = 'S';
    MaxHp = 125;//125
    HP = 125;//125
    ATK = 25;//25
    DEF = 25;//25
}

Drow::Drow() {
    race = 'D';
    MaxHp = 150;
    HP = 150;
    ATK = 25;
    DEF = 15;
}


Vampire::Vampire() {
    race = 'V';
    MaxHp = 99999999;
    HP = 50;
    ATK = 25;
    DEF = 25;
}

Troll::Troll() {
    race = 'T';
    MaxHp = 120;
    HP = 120;
    ATK = 25;
    DEF = 15;
}


Goblin::Goblin() {
    race = 'G';
    MaxHp = 110;
    HP = 110;
    ATK = 15;
    DEF = 20;
}


Shade::~Shade() {}

Drow::~Drow() {}

Vampire::~Vampire() {}

Troll::~Troll() {}

Goblin::~Goblin() {}

void Shade::Attack(Enemy *c) {
    c->takeDamageFrom(this);
}


void Shade::takeDamage(Enemy *c) {
    //cout << Helpers::CalcDamage(c->getAtk(), DEF) << endl;//test
    this->HP -= Helpers::CalcDamage(c->getAtk(), DEF);
}

void Drow::Attack(Enemy *c) {
    c->takeDamageFrom(this);
}


void Drow::takeDamage(Enemy *c) {
    HP -= Helpers::CalcDamage(c->getAtk(), DEF);
}


void Vampire::Attack(Enemy *c) {
    c->takeDamageFrom(this);
    if (c->getTexture() == 'D') { this->HP -= 5; }
    else this->HP += 5;
}


void Vampire::takeDamage(Enemy *c) {
    HP -= Helpers::CalcDamage(c->getAtk(), DEF);
}

void Troll::Attack(Enemy *c) {
    c->takeDamageFrom(this);

    if (cur_turn == false) {
        this->HP += 5;
        cur_turn = true;
    }
    if (this->HP >= this->MaxHp) { this->HP = this->MaxHp; }
}

void Troll::takeDamage(Enemy *c) {
    HP -= Helpers::CalcDamage(c->getAtk(), DEF);
    if (cur_turn == false) {
        this->HP += 5;
        cur_turn = true;
    }
    if (this->HP >= this->MaxHp) { this->HP = this->MaxHp; }
}

void Goblin::Attack(Enemy *c) {
    c->takeDamageFrom(this);
}

void Goblin::takeDamage(Enemy *c) {
    if (c->getTexture() == 'O') {
        HP -= (1.5 * Helpers::CalcDamage(c->getAtk(), DEF));
    } else {
        HP -= Helpers::CalcDamage(c->getAtk(), DEF);
    }

}

void Goblin::stealGold(Enemy *e) {
    if (e->getHp() == 0) {
        GoldNum += 5;
    }

}









