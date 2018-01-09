#include "Chamber.h"
using namespace std;

Chamber::Chamber() = default;

void Chamber::ChamberAddCell(Cell c) {
    group.push_back(c);
}

int Chamber::Chamber_size() {
    return group.size();
}

Chamber::~Chamber(){
    this->group.clear();
};

vector<Cell>Chamber::getGroup() {
    return group;
}