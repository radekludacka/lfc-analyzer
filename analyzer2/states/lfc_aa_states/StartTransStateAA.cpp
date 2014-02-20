/* 
 * File:   StatgState.cpp
 * Author: radek
 * 
 * Created on 27 July 2013, 11:02
 */

#include "StartTransStateAA.h"

StartTransStateAA::StartTransStateAA() {
}

StartTransStateAA::~StartTransStateAA() {
}

LfcCommand * StartTransStateAA::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    bool statg = false;
    bool getPath = false;
    bool symLink = false;

    vector<Item *> itemsToAssigne;
    int itemsSize = items.size();

    for (int i = 0; i < itemsSize; i++, iterator++) {
        Item * item2 = *iterator;
        
        if (!item2->IsAssigned()) {
            PrintMessage("START TRANSAA", item2);
            
            FunctionType function = item2->GetCommand()->getName();
            if (item->compareUserSiteTid(item2)) {
                if (function == STATG and !statg) {
                    PrintMessage("START TRANSAA STATG", item2);
                    
                    if (item2->GetCommand()->getReturnCode() == 2) {

                        itemsToAssigne.push_back(item2);
                        this->AssignAllItems(itemsToAssigne);
                        State * state = new StartTransState2();
                        return state->NextState(iterator, items, item);
                    }
                    itemsToAssigne.push_back(item2);
                    statg = true;
                } else if (function == GETPATH and !getPath) {
                    PrintMessage("START TRANS GETPATH", item2);
                    itemsToAssigne.push_back(item2);
                    getPath = true;
                } else if (function == SYMLINK and !symLink) {
                    PrintMessage("START TRANS AA SYMLINK", item2);
                    itemsToAssigne.push_back(item2);
                    symLink = true;
                    // pokud je symplink 17 - neco je spatne
                    item->SetFilePath(item2->GetFilePath());
                } else if (function == SERV_ABORTTRANS) {
                    PrintMessage("START TRANS AA ABORT", item2);
                    item->SetEndTime(item2->GetEndTime());
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);
                    return new LfcAACommand(
                            item->GetStartTime(),
                            item->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            true);
                } else if (function == ENDTRANS) {
                    PrintMessage("START TRANS AA ENDTRANS", item2);
                    item->SetEndTime(item2->GetEndTime());
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);
                    return new LfcAACommand(
                            item->GetStartTime(),
                            item->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            false);
                }
            }
        }
    }

    return NULL;
}
