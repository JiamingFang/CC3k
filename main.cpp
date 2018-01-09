#include <string>
#include "Hero.h"
#include "Display.h"
#include <iostream>
#include <time.h>
#include "Floor.h"
#include "Helpers.h" //for testing , delete after use

using namespace std;

int main() {
    bool restart = true;
    while(restart) {
         static bool revealed[6] = {false, false, false,false,false,false};
        restart = false;

        srand(time(NULL));

        Hero *hero;
        cout <<  "________  ________ ________  ___  __" << endl;
        cout << "|\\   ____\\|\\   ____|\\_____  \\|\\  \\|\\  \\     " << endl;
        cout << "\\ \\  \\___|\\ \\  \\___\\|____|\\ /\\ \\  \\/  /|_   " << endl;
        cout << " \\ \\  \\    \\ \\  \\        \\|\\  \\ \\   ___  \\  " << endl;
        cout << "  \\ \\  \\____\\ \\  \\____  __\\_\\  \\ \\  \\\\ \\  \\ " << endl;
        cout << "   \\ \\_______\\ \\_______|\\_______\\ \\__\\\\ \\__\\" << endl;
        cout << "    \\|_______|\\|_______\\|_______|\\|__| \\|__|" << endl << endl;

        cout << "INSTRUCTIONS" << endl;

        cout << "no,so,ea,we,ne,nw,se,sw: moves thecharacter one block in the appropriate cardinal direction.\n"
                "u <direction>: uses the potion indicated by the direction\n"
                "a <direction>: attacks the enemy in the specified direction\n"
                "f: stops enemies from moving until this key is pressed again.\n"
                "r: restarts the game. All stats, inventory, and gold are reset.\n"
                "q: admit defeat and exit the game." << endl << endl
                ;

        cout << "please select your hero!" << endl << "options: shade(s), drow(d), vampire(v), troll(t), goblin(g)"
             << endl;
        string race;
        cin >> race;
        if (race == "s") {
            hero = new Shade;
        } else if (race == "d") {
            hero = new Drow;
        } else if (race == "v") {
            hero = new Vampire;
        } else if (race == "t") {
            hero = new Troll;
        } else if (race == "g") {
            hero = new Goblin;
        } else {
            cout << "wrong race!!!" << endl;
            return 0;
        }

        Floor f(hero);
        hero->setFloor(&f);
        int floorNum = 1;

        f.setHero(hero);
        Display display;
        f.init();
        display.setFloor(&f);
        display.update(hero);
        string action = "Player has spawned!";
        display.updateAction(action);
        display.render();


        string command;

        while (cin >> command) {
            action = "";
            if (command == "no" || command == "so" || command == "ea" || command == "we" || command == "ne" ||
                command == "nw" || command == "se" || command == "sw") {
                if (hero->move(command)) {

                    if(f.GetFloorNum() == 6){
                        cout << "Congratulations!!! You have defeated the game!!!" << endl;
                        cout << "Your points are " << hero->getGold();
                        break;
                    }
                    if(f.GetFloorNum() != floorNum){
                        action = "PC moves to next floor";
                        floorNum++;
                    }else {
                        string dir;
                        if(command == "no"){
                            dir = "North";
                        }else if(command == "so"){
                            dir = "South";
                        }else if(command == "ea"){
                            dir = "East";
                        }else if(command == "we"){
                            dir = "West";
                        }else if(command == "ne"){
                            dir = "Northeast";
                        }else if(command == "nw"){
                            dir = "Northwest";
                        }else if(command == "se"){
                            dir = "Southeast";
                        }else if(command == "sw"){
                            dir = "Southwest";
                        }
                        action = "PC moves to the " + dir;
                        string e = "";
                        if(f.getCell(hero->getX()+1,hero->getY()).getObject() && f.getCell(hero->getX()+1,hero->getY()).getObject()->getTexture() == 'P'){
                            Potion *p = dynamic_cast<Potion*>(f.getCell(hero->getX()+1,hero->getY()).getObject());
                            e = p->getEffect();

                        }else if(f.getCell(hero->getX()-1,hero->getY()).getObject() && f.getCell(hero->getX()-1,hero->getY()).getObject()->getTexture() == 'P'){
                            Potion *p = dynamic_cast<Potion*>(f.getCell(hero->getX()-1,hero->getY()).getObject());
                            e = p->getEffect();
                        }else if(f.getCell(hero->getX(),hero->getY()+1).getObject() && f.getCell(hero->getX(),hero->getY()+1).getObject()->getTexture() == 'P'){
                            Potion *p = dynamic_cast<Potion*>(f.getCell(hero->getX(),hero->getY()+1).getObject());
                            e = p->getEffect();
                        }else if(f.getCell(hero->getX(),hero->getY()-1).getObject() && f.getCell(hero->getX(),hero->getY()-1).getObject()->getTexture() == 'P'){
                            Potion *p = dynamic_cast<Potion*>(f.getCell(hero->getX(),hero->getY()-1).getObject());
                            e = p->getEffect();
                        }else if(f.getCell(hero->getX()+1,hero->getY()+1).getObject() && f.getCell(hero->getX()+1,hero->getY()+1).getObject()->getTexture() == 'P'){
                            Potion *p = dynamic_cast<Potion*>(f.getCell(hero->getX()+1,hero->getY()+1).getObject());
                            e = p->getEffect();
                        }else if(f.getCell(hero->getX()+1,hero->getY()-1).getObject() && f.getCell(hero->getX()+1,hero->getY()-1).getObject()->getTexture() == 'P'){
                            Potion *p = dynamic_cast<Potion*>(f.getCell(hero->getX()+1,hero->getY()-1).getObject());
                            e = p->getEffect();
                        }else if(f.getCell(hero->getX()-1,hero->getY()+1).getObject() && f.getCell(hero->getX()-1,hero->getY()+1).getObject()->getTexture() == 'P'){
                            Potion *p = dynamic_cast<Potion*>(f.getCell(hero->getX()-1,hero->getY()+1).getObject());
                            e = p->getEffect();
                        }else if(f.getCell(hero->getX()-1,hero->getY()-1).getObject() && f.getCell(hero->getX()-1,hero->getY()-1).getObject()->getTexture() == 'P'){
                            Potion *p = dynamic_cast<Potion*>(f.getCell(hero->getX()-1,hero->getY()-1).getObject());
                            e = p->getEffect();
                        }

                        if(e == "RH" && revealed[0] == true){
                            action += " and sees a RH potion";
                        }else if(e == "BA" && revealed[1] == true){
                            action += " and sees a BA potion";
                        }else if(e == "BD"  && revealed[2] == true){
                            action += " and sees a BD potion";
                        }else if(e == "PH" && revealed[3] == true){
                            action += " and sees a PH potion";
                        }else if(e == "WA" && revealed[4] == true){
                            action += " and sees a WA potion";
                        }else if(e == "WD" && revealed[5] == true){
                            action += " and sees a WD potion";
                        }else if(e != ""){
                            action += " and sees an unknown potion";
                        }

                    }
                } else {
                    action = "PC cannot move in that direction!";
                }

            } else if (command == "f") {
                f.chang_action_for_enemies();
                continue;
            } else if (command == "u") {
                string direction;
                cin >> direction;
                string potionType;
                if(hero->pickPotion(direction)){
                    potionType = hero->usePotion(direction);
                    action = "PC used a " + potionType + " potion!";
                    if(potionType == "RH"){
                        revealed[0] = true;
                    }else if(potionType == "BA"){
                        revealed[1] = true;
                    }else if(potionType == "BD"){
                        revealed[2] = true;
                    }else if(potionType == "PH"){
                        revealed[3] = true;
                    }else if(potionType == "WA"){
                        revealed[4] = true;
                    }else if(potionType == "WD"){
                        revealed[5] = true;
                    }
                }else{
                    action = "There is no potion in the direction!";
                }
            }else if(command == "a"){
                string direction;
                cin >> direction;
                if(hero->attack(direction)){
                    action = "You attacked the enemy in the direction";
                }else{
                    action = "There is no enemy in the direction";
                }
            }

            else if (command == "r") {
                restart = true;
                break;
            }else if(command == "q"){
                cout << "You Quit!!!" << endl << "You are a loser!!!" << endl;
                break;
            }


            f.nextTurn();


            display.updateAction(action);
            display.update(hero);
            if(hero->alive() == false){
                cout << "You died!!";
                break;
            }
            display.render();
        }
        int x = hero->getX();
        int y = hero->getY();
        f.getCell(x,y).deleteObject();
        delete hero;

    }
};

