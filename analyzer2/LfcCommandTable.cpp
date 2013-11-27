/* 
 * File:   LfcCommandTable.cpp
 * Author: radek
 * 
 * Created on 12 July 2013, 13:54
 */

#include <vector>

#include "LfcCommandTable.h"

LfcCommandTable::LfcCommandTable() {
    this->commandList = new vector<LfcCommand *>;
}

LfcCommandTable::LfcCommandTable(const LfcCommandTable& orig) {
}

LfcCommandTable::~LfcCommandTable() {
    for (vector<LfcCommand*>::const_iterator it = commandList->begin(); it != commandList->end(); it++) {
        delete *it;
    }
}

vector<LfcCommand*>* LfcCommandTable::GetCommandList() const {
    return commandList;
}

void LfcCommandTable::add(LfcCommand * command) {
    this->commandList->push_back(command);
}

