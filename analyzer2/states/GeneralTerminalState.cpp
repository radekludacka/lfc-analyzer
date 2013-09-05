/* 
 * File:   GeneralTerminalState.cpp
 * Author: radek
 * 
 * Created on 13 July 2013, 21:18
 */

#include "GeneralTerminalState.h"

GeneralTerminalState::GeneralTerminalState() {
    final = true;
    command = NULL;
}

GeneralTerminalState::GeneralTerminalState(const GeneralTerminalState& orig) {
}

GeneralTerminalState::~GeneralTerminalState() {
}

void GeneralTerminalState::NextState(Analyzer * analyzer, vector<Item *> items, Item * item){
}
