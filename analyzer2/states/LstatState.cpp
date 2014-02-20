/* 
 * File:   LfcLstatAnalyzerState.cpp
 * Author: radek
 * 
 * Created on 13 July 2013, 19:48
 */

#include "LstatState.h"

LstatState::LstatState() : State() {
}

LstatState::~LstatState() {
}

LfcCommand * LstatState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    vector<Item *> itemsToAssigne;

    int itemsSize = items.size();
    Item * end = NULL;

    for (int i = 0; i < itemsSize; i++, iterator++) {
        Item * item2 = *iterator;
        end = *iterator;
        
        if (!item2->IsAssigned()) {
            FunctionType function = item2->GetCommand()->getName();                
             if (function == ACCESS) {
                int accessType = atoi(item2->GetInformation().c_str());
                if (item->compareUserSiteFile(item2) and accessType == 2) {
                    PrintMessage("LSTAT ACCESS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetTid(item2->GetTid());
                    this->AssignAllItems(itemsToAssigne);
                    State * state = new RmDirState();
                    return state->NextState(iterator, items, item);
                }
            } 
        }

        if (*iterator == items.back()) {
            break;
        }
    }


    if (item->GetCommand()->getReturnCode() == 2) {
        PrintMessage("LSTAT LFC-LS 2", item);

        return new LfcLsCommand(
                item->GetStartTime(),
                item->GetEndTime(),
                item->GetFilePath(),
                item->GetUser(),
                item->GetSite(),
                true);
    }

    if (item->GetCommand()->getReturnCode() == 0) {
        PrintMessage("LSTAT LFC-LS 3", item);
        return new LfcLsCommand(
                item->GetStartTime(),
                item->GetEndTime(),
                item->GetFilePath(),
                item->GetUser(),
                item->GetSite(),
                false);
    }

    PrintMessage("LSTAT STATE NULL", item);
    return NULL;
}
