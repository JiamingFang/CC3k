#include "Floor.h"
#include "Treasure.h"
#include "Helpers.h"
#include <algorithm>

using namespace std;


Floor::Floor(Hero *hero) : map{0}, enemies{0}, potions{0}, treasures{0}, floorNumber{1}, hero(hero) {}

Floor::~Floor() {
    clear();
}

void Floor::setHero(Hero *h) {
    hero = h;
}

int Floor::GetFloorNum() {
    return this->floorNumber;
}

void Floor::chang_action_for_enemies() {
    for(Enemy* enemy : enemies){
        if (enemy)
            enemy->chang_action();
    }
}


void Floor::clear() {
    for (Enemy* enemy : enemies) {
        if (enemy)
            delete enemy;
    }
    for (Treasure* treasure : treasures) {
        delete treasure;
    }
    for (Potion* potion : potions) {
        delete potion;
    }
    map.clear();
    enemies.clear();
    treasures.clear();
    potions.clear();
    //delete Chamber0;
    //delete Chamber1;
    //delete Chamber2;
    //delete Chamber3;
    //delete Chamber4;
}

void Floor::initHero(int Chamber_num) {

    int x;
    int y;

    while (true) {
        int len_chamber = this->Chambers[Chamber_num]->Chamber_size();
        int random_Pos = Helpers::random(len_chamber);
        x = this->Chambers[Chamber_num]->getGroup()[random_Pos].getX();
        y = this->Chambers[Chamber_num]->getGroup()[random_Pos].getY();
        Cell &cell = getCell(x, y);
        if (cell.canRandom()) {
            hero->setX(x);       // correct form???
            hero->setY(y);
            cell.setObject(hero);
            hero->setCell(&cell);
            break;
        }
    }
}


void Floor::initStair(int Chamber_num) { // change like above
    while (true) {
        int len_chamber = this->Chambers[Chamber_num]->Chamber_size();
        int random_Pos = Helpers::random(len_chamber);
        int x = this->Chambers[Chamber_num]->getGroup()[random_Pos].getX();
        int y = this->Chambers[Chamber_num]->getGroup()[random_Pos].getY();
        if (getCell(x, y).canRandom()) {
            getCell(x, y).setTexture('/');
            break;
        }
    }
}


void Floor::initEnemies() {
    for (int i = 0; i < 20; ++i) {


        int x;
        int y;

        while (true) {
            int Chamber_num;
            Chamber_num = Helpers::random(5); // random one number from 0,1,2,3,4
            int len_chamber = this->Chambers[Chamber_num]->Chamber_size();
            int random_Pos = Helpers::random(len_chamber);


            x = this->Chambers[Chamber_num]->getGroup()[random_Pos].getX();
            y = this->Chambers[Chamber_num]->getGroup()[random_Pos].getY();

            if (getCell(x, y).canRandom()) {
                int type_num = Helpers::random(18);
                EnemyType type;

                if (type_num == 0 || type_num == 1 || type_num == 2 || type_num == 3) {
                    type = EnemyTypeHuman;
                } else if (type_num == 4 || type_num == 5 || type_num == 6) {
                    type = EnemyTypeDwarf;
                } else if (type_num == 7 || type_num == 8) {
                    type = EnemyTypeElf;
                } else if (type_num == 9 || type_num == 10) {
                    type = EnemyTypeOrcs;
                } else if (type_num == 11 || type_num == 12) {
                    type = EnemyTypeMerchant;
                } else {
                    type = EnemyTypeHalfling;
                }

                Enemy *enemy = Enemy::builder(type);
                enemy->setFloor(this);
                enemy->setHero(hero);
                enemy->setX(x);
                enemy->setY(y);
                Cell &cell = getCell(x, y);
                enemy->setCell(&cell);

                cell.setObject(enemy);

                enemies.push_back(enemy);
                break;
            }
        }
    }
}

void Floor::initPotions() {
    for (int i = 0; i < 10; ++i) {
        int x;
        int y;
        while (true) {
            int Chamber_num;
            Chamber_num = Helpers::random(5); // random one number from 0,1,2,3,4
            int len_chamber = this->Chambers[Chamber_num]->Chamber_size();
            int random_Pos = Helpers::random(len_chamber);
             x = this->Chambers[Chamber_num]->getGroup()[random_Pos].getX();
             y = this->Chambers[Chamber_num]->getGroup()[random_Pos].getY();
            if (getCell(x, y).canRandom()) {

                int type_num = Helpers::random(6);   // randrom from 0, 1, 2, 3, 4, 5
                string type;

                if (type_num == 0) {
                    type = "RH";
                } else if (type_num == 1) {
                    type = "BA";
                } else if (type_num == 2) {
                    type = "BD";
                } else if (type_num == 3) {
                    type = "PH";
                } else if (type_num == 4) {
                    type = "WA";
                } else {
                    type = "WD";
                }

                Potion* potion = new Potion(type);
                potion->setX(x);
                potion->setY(y);
                Cell &cell = getCell(x, y);
                potion->setCell(&cell);
                potions.push_back(potion);
                cell.setObject(potion);
                break;
            }
        }
    }
}

void Floor::initTreasures() {
    for (int i = 0; i < 10; ++i) {

        int x;
        int y;

        while (true) {
            int Chamber_num;
            Chamber_num = Helpers::random(5); // random one number from 0,1,2,3,4
            int len_chamber = this->Chambers[Chamber_num]->Chamber_size();
            int random_Pos = Helpers::random(len_chamber);
            x = this->Chambers[Chamber_num]->getGroup()[random_Pos].getX();
            y = this->Chambers[Chamber_num]->getGroup()[random_Pos].getY();
            if (getCell(x, y).canRandom()) {
                int type_num = Helpers::random(8);
                string type;

                if (type_num == 0 || type_num == 1 || type_num == 2 || type_num == 3 || type_num == 4) {
                    type = "Normal";
                } else if (type_num == 5) {
                    type = "DragonHoard";
                } else {
                    type = "SmallHoard";
                }

                if (type == "Normal") {
                    Treasure *ptr = new Normal(1, true);
                    ptr->setX(x);
                    ptr->setY(y);
                    Cell &cell = getCell(x, y);
                    ptr->setCell(&cell);
                    treasures.push_back(ptr);
                    cell.setObject(treasures[treasures.size() - 1]);

                    break;
                } else if (type == "SmallHoard") {
                    Treasure *ptr = new Small;
                    ptr->setX(x);
                    ptr->setY(y);
                    Cell &cell = getCell(x, y);
                    ptr->setCell(&cell);
                    treasures.push_back(ptr);
                    cell.setObject(treasures[treasures.size() - 1]);
                    break;

                } else { // dragon hoard
                    DragonHoard *ptr = new DragonHoard;
                    ptr->setX(x);
                    ptr->setY(y);
                    Cell &cell = getCell(x, y);
                    ptr->setCell(&cell);
                    treasures.push_back((Treasure *) ptr);
                    cell.setObject(treasures[treasures.size() - 1]);
                    int dragonx = cell.getX();
                    int dragony = cell.getY();

                    while (1) { // random location for dragon
                        int random_x = Helpers::random(3);
                        int random_y = Helpers::random(3);
                        if (random_x != 1 || random_y != 1) {
                            int x1 = dragonx + random_x - 1;
                            int y1 = dragony + random_y - 1;

                            if (x1 < 0 || x1 > 78 || y1 < 0 || y1 > 24)
                                continue;

                            if (this->getCell(x1, y1).canRandom()) {
                                dragonx = x1;
                                dragony = y1;
                                break;
                            }
                        }
                    }

                    Enemy *enemy = new Dragon(EnemyTypeDragon, ptr);
                    enemy->setFloor(this);
                    enemy->setHero(hero);
                    enemy->setX(dragonx);
                    enemy->setY(dragony);
                    Cell &cella = getCell(dragonx, dragony);
                    enemy->setCell(&cella);
                    cella.setObject(enemy);
                    Dragon *dragon = dynamic_cast<Dragon *>(enemy);
                    enemies.push_back(enemy);
                    ptr->setDragon(dragon);
                    dragon->setHoard(ptr);
                    break;
                }
            }
        }
    }
}

void Floor::init() {
    clear();


    const vector<vector<char>> m(Helpers::readMap("C:\\Users\\Jimmy\\Desktop\\cc3k\\1.txt"));

    const vector<vector<char>> m2(Helpers::readMap("C:\\Users\\Jimmy\\Desktop\\cc3k\\2.txt"));


    {
        for (int i = 0; i < COL; ++i) { // COL = 25 , ROW = 79
            for (int j = 0; j < ROW; ++j) {
                if (m2[i][j] == '0') {
                    Chamber0.ChamberAddCell(Cell{'.', j, i});
                }
            }
        }

    }

    //test
    //

    {
        for (int i = 0; i < COL; ++i) { // COL = 25 , ROW = 79
            for (int j = 0; j < ROW; ++j) {
                if (m2[i][j] == '1') {
                    Chamber1.ChamberAddCell(Cell{'.', j, i});
                }
            }
        }

    }

    {
        for (int i = 0; i < COL; ++i) { // COL = 25 , ROW = 79
            for (int j = 0; j < ROW; ++j) {
                if (m2[i][j] == '2') {
                    Chamber2.ChamberAddCell(Cell{'.', j, i});
                }
            }
        }
    }


    {
        for (int i = 0; i < COL; ++i) { // COL = 25 , ROW = 79
            for (int j = 0; j < ROW; ++j) {
                if (m2[i][j] == '3') {
                    Chamber3.ChamberAddCell(Cell{'.', j, i});
                }
            }
        }
    }


    {
        for (int i = 0; i < COL; ++i) { // COL = 25 , ROW = 79
            for (int j = 0; j < ROW; ++j) {
                if (m2[i][j] == '4') {
                    Chamber4.ChamberAddCell(Cell{'.', j, i});
                }
            }
        }

    }


    map.reserve(ROW * COL);   // map is vector of Cellc . Reserve space for map (vector of vector of cell)

    for (int i = 0; i < COL; ++i) {
        vector<Cell> eachrow;
        for (int j = 0; j < ROW; ++j) {
            Cell cell{m[i][j], j, i}; // from 1.1 2.1 . .... 79.1
            eachrow.push_back(cell); // consist of each row of the map
        }
        map.push_back(eachrow); // push each row to build the whole map..
    }

    // Random generate born point, stair point, enemies(20), potions and treasures..

    // Hero
    {
        int hero_chamber = Helpers::random(5); // random one number from 0,1,2,3,4
        initHero(hero_chamber);

    // Stair
        while (true) {
            int stair_chamber = Helpers::random(5); // random one number from 0,1,2,3,4
            if (stair_chamber != hero_chamber) {
                initStair(stair_chamber);
                break;
            }
        }
    }

    // Enemies
    {
        initEnemies();
    }


    //potions..
    {
        initPotions();
    }


    { // treasure
        initTreasures();
    }

}


void Floor::nextTurn() { // attack or random move..
    // remove died enmey
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i] && !enemies[i]->alive()) {
            enemies[i]->getCell()->deleteObject();

            Treasure *treasure = enemies[i]->dropGold();
            if (treasure) {
                treasure->getCell()->setObject(treasure);
                treasures.push_back(treasure);
            }
            
            delete enemies[i];
            enemies[i] = nullptr;
            break;
        }
    }
    
    for (Enemy* enemy : enemies) {
        if (enemy)
            enemy->nextTurn();
    }
}

Cell &Floor::getCell(int x, int y) {
    return map[y][x];
}

void Floor::plusFloorNum() {
    floorNumber++;
}


//ostream &Floor::operator<<(ostream &out){}
