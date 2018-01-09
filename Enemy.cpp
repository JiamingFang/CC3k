#include "Enemy.h"
#include "Helpers.h"


using namespace std;


int attackTable[] = {20, 20, 30, 30, 70, 20, 15};
int defendTable[] = {20, 30, 10, 25, 5, 20, 20};
int hpTable[] = {140, 100, 140, 180, 30, 150, 100};

bool Merchant::Hostile = false;

//void Enemy::setGame(Game *g) {
//    game = g;
//}

void Enemy::chang_action() {
    action=!action;
}

bool Enemy::get_action() {
    return action;
}
Enemy::Enemy(EnemyType type) {
    this->type = type;
    ATK = attackTable[type];
    DEF = defendTable[type];
    HP = hpTable[type];
    action = true;
}

void Enemy::setHero(Hero *h) {
    hero = h;
}

void Enemy::setFloor(Floor *f) {
    floor = f;
}

EnemyType Enemy::getType() {
    return this->type;
}

void Enemy::Attack(Hero *h) {
}

void Enemy::takeDamageFrom(Hero *c) {}

Enemy *Enemy::builder(EnemyType type) {
    switch (type) {
        case EnemyTypeHuman:
            return new Human(EnemyTypeHuman);
        case EnemyTypeDwarf:
            return new Dwarf(EnemyTypeDwarf);
        case EnemyTypeElf:
            return new Elf(EnemyTypeElf);
        case EnemyTypeOrcs:
            return new Orcs(EnemyTypeOrcs);
        case EnemyTypeMerchant:
            return new Merchant(EnemyTypeMerchant);
        case EnemyTypeHalfling:
            return new Halfling(EnemyTypeHalfling);
    }
}

char Enemy::getTexture() {
    if (type == 0) {
        return 'H';
    } else if (type == 1) {
        return 'W';
    } else if (type == 2) {
        return 'E';
    } else if (type == 3) {
        return 'O';
    } else if (type == 4) {
        return 'M';
    } else if (type == 5) {
        return 'D';
    } else {
        return 'L';
    }
}


Human::Human(EnemyType) : Enemy{EnemyTypeHuman} {}

Dwarf::Dwarf(EnemyType) : Enemy{EnemyTypeDwarf} {}

Elf::Elf(EnemyType) : Enemy(EnemyTypeElf) {}

Orcs::Orcs(EnemyType) : Enemy(EnemyTypeOrcs) {}

Merchant::Merchant(EnemyType) : Enemy(EnemyTypeMerchant) { Hostile = false; }

Dragon::Dragon(EnemyType, DragonHoard *d) : Enemy(EnemyTypeDragon), hoard(d) {
    HP = hpTable[EnemyTypeDragon];
    ATK = attackTable[EnemyTypeDragon];
    DEF = defendTable[EnemyTypeDragon];
}

Halfling::Halfling(EnemyType) : Enemy(EnemyTypeHalfling) {}


Human::~Human() {}

Dwarf::~Dwarf() {}

Elf::~Elf() {}

Orcs::~Orcs() {}

Merchant::~Merchant() {}

Dragon::~Dragon() {}

Halfling::~Halfling() {}


void Human::Attack(Hero *hero) {
    //cout << "attack true" << endl;  //test
    hero->takeDamage(this);
}


void Human::takeDamageFrom(Hero *hero) {
    int damage = Helpers::CalcDamage(hero->getAtk(), getDef());
    this->HP -= damage;
}

Treasure* Human::dropGold() {
    int x = this->getX();
    int y = this->getY();
    Normal* normal = new Normal(2, true);
    normal->setCell(&floor->getCell(x,y));
    normal->setX(x);
    normal->setY(y);

    return normal;
}


void Dwarf::Attack(Hero *hero) {
    //cout << "attack true" << endl;  //test
    hero->takeDamage(this);
}

void Dwarf::takeDamageFrom(Hero *hero) {
    int damage = Helpers::CalcDamage(hero->getAtk(), this->getDef());
    this->HP -= damage;
    if (!this->alive()) {
        int num = 0;
        int randomNum = Helpers::random(2);
        if (randomNum == 0) {
            num = 1;
        } else {
            num = 2;
        }
        addGold(num);
    }
}

void Dwarf::addGold(int num) {
    hero->addGold(num);
}


void Elf::Attack(Hero *hero) {
    //cout << "attack true" << endl;  //test
    if (hero->getTexture() == 'D') {
        hero->takeDamage(this);
    } else {
        hero->takeDamage(this);
        hero->takeDamage(this);
    }
}

void Elf::takeDamageFrom(Hero *hero) {
    int damage = Helpers::CalcDamage(hero->getAtk(), this->getDef());
    this->HP -= damage;
    if (!this->alive()) {
        int num = 0;
        int randomNum = Helpers::random(2);
        if (randomNum == 0) {
            num = 1;
        } else {
            num = 2;
        }
        addGold(num);
    }
}

void Elf::addGold(int num) {
    hero->addGold(num);
}

void Orcs::Attack(Hero *hero) {
    //cout << "attack true" << endl;  //test
    hero->takeDamage(this);
}


void Orcs::takeDamageFrom(Hero *hero) {
    int damage = Helpers::CalcDamage(hero->getAtk(), this->getDef());
    this->HP -= damage;
    if (!this->alive()) {
        int num = 0;
        int randomNum = Helpers::random(2);
        if (randomNum == 0) {
            num = 1;
        } else {
            num = 2;
        }
        addGold(num);
    }
}

void Orcs::addGold(int num) {
    hero->addGold(num);
}


Treasure* Merchant::dropGold() {
    int x = this->getX();
    int y = this->getY();
    MerchantHoard* mer = new MerchantHoard;
    mer->setCell(&floor->getCell(x,y));
    mer->setX(x);
    mer->setY(y);

    return mer;
}


void Merchant::Attack(Hero *hero) {
    if (!Hostile) { return; }

    hero->takeDamage(this);
}

void Merchant::takeDamageFrom(Hero *hero) {
    int damage =  Helpers::CalcDamage(hero->getAtk(), this->getDef());
    this->HP -= damage;
    Hostile = true;
}


void Dragon::Attack(Hero *hero) {
    hero->takeDamage(this);
}

void Dragon::setHoard(DragonHoard *h) {
    hoard = h;
}

void Dragon::takeDamageFrom(Hero *hero) {
    int damage =  Helpers::CalcDamage(hero->getAtk(), this->getDef());
    this->HP -= damage;
    if (!this->alive()) {
        hoard->setPickable(true);
    }
}

void Halfling::addGold(int num) {
    hero->addGold(num);
}


void Halfling::Attack(Hero *hero) {
    //cout << "attack true" << endl;  //test
    hero->takeDamage(this);
}

void Halfling::takeDamageFrom(Hero *hero) {
    int damage = Helpers::CalcDamage(hero->getAtk(), this->getDef());
    int random_num = Helpers::random(2);
    if (random_num == 1) { // hero miss the attact
        damage = 0;
    } else {
        //pass
    }
    this->HP -= damage;
    if (!this->alive()) {
        int num = 0;
        int randomNum = Helpers::random(2);
        if (randomNum == 0) {
            num = 1;
        } else {
            num = 2;
        }
        addGold(num);
    }
}


void Enemy::nextTurn() {
    if(get_action()) {
        if (abs(hero->getX() - this->getX()) < 2 &&
            abs(hero->getY() - this->getY()) < 2) { // we attack hero
            //cout << "HeroX " << hero->getX() << " HeroY " << hero->getY() <<" EnemyX " << this->getX() << " EnemyY " << this->getY()
             //                                                                                                       <<endl; // test
            this->Attack(hero);
            return;
        } else { // else the Enemy will random move

            if (this->getType() == EnemyTypeDragon) { return; }

            int currx = this->getX();
            int curry = this->getY();
            int oldx = currx;
            int oldy = curry;
            while (1) {
                int random_x = Helpers::random(3);
                int random_y = Helpers::random(3);
                if (random_x != 1 || random_y != 1) {
                    int x1 = currx + random_x - 1;
                    int y1 = curry + random_y - 1;

                    if (x1 < 0 || x1 > 78 || y1 < 0 || y1 > 24)
                        continue;

                    if (floor->getCell(x1, y1).canRandom()) {
                        currx = x1;
                        curry = y1;
                        break;
                    }
                }

            }
            this->x = currx;
            this->y = curry;
            this->cell = &floor->getCell(currx, curry);

            floor->getCell(currx, curry).setObject(this);
            floor->getCell(oldx, oldy).deleteObject();
        }
    }
}
Enemy::Enemy() {

}




/*enum HeroType {
    HeroTypeShade = 0,
    HeroTypeDrow,
    HeroTypeVampire,
    HeroTypeTroll,
    HeroTypeGoblin,
    HeroTypeMax
};
 */
