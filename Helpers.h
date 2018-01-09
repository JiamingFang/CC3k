#ifndef CC5K_HELPERS_H
#define CC5K_HELPERS_H

#include "vector"
#include <fstream>
#include <cmath>

using namespace std;

class Helpers {
public:
    static vector<vector<char> > readMap(const char* filename);
    static int CalcDamage(int Atk, int Def);
    static int random(int max);
};


#endif //CC5K_HELPERS_H
