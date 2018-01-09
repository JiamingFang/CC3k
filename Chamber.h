#ifndef CHAMBER_H
#define CHAMBER_H

#include "BaseObject.h"
#include <vector>
#include "Cell.h"
using namespace std;


class Chamber {
    vector<Cell> group;
public:
    int Chamber_size();
    vector<Cell> getGroup();
    Chamber();
    ~Chamber(); // edit it
    void ChamberAddCell(Cell); // edit it to ChamberAddCell

};


#endif
