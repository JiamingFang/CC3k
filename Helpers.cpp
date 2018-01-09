#include <ctime>
#include <iostream>
#include "Helpers.h"

vector<vector<char> > Helpers::readMap(const char* filename) {
    vector<vector<char>> v;
    ifstream file{filename};
    string line; // read the floor map provided as input file.
    while(getline(file,line)) { // we have 25 rows coz we save 5 lines to display information.
        vector<char> eachrow;
        for (int j = 0; j < 79; ++j) {
            eachrow.emplace_back(line[j]);
        }
        v.emplace_back(eachrow);
    }
    return v;
}

int Helpers::CalcDamage(int Atk, int Def){
    return (int)ceil((100.0/(100+Def))*Atk);
}

int Helpers::random(int max) {
    return rand() % max;
}

