/* 
 * File:   LfcAnalyzerState.cpp
 * Author: radek
 * 
 * Created on 13 July 2013, 23:18
 */

#include "State.h"

State::State() {
}

State::~State() {
}

void State::AssignAllItems(vector<Item*> items) {
    std::vector<Item *>::const_iterator iterator1 = items.begin();

    for (iterator1 = items.begin(); iterator1 != items.end(); ++iterator1) {
        Item * item = *iterator1;
        PrintMessage("ASSIGN", item);
        item->SetAssigned(true);
    }
}

void State::PrintMessage(string msg, Item* item) {
//    cout << msg << endl;
//    item->GetStartTime()->toString();
}