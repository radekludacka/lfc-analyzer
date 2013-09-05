/* 
 * File:   OpenDirRecursiveState.cpp
 * Author: radek
 * 
 * Created on 26 July 2013, 20:14
 */

#include "OpenDirRecursiveState.h"

OpenDirRecursiveState::OpenDirRecursiveState() {
}

OpenDirRecursiveState::~OpenDirRecursiveState() {
}

LfcCommand * OpenDirRecursiveState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    vector<Item *> itemsToAssigne;

    int itemsSize = items.size();
    for (int i = 0; i < itemsSize; i++, iterator++) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            FunctionType function = item2->GetCommand()->getName();
            if (item->compareUserSiteFile(item2)) {
                if (function == READDIR) {
                    itemsToAssigne.push_back(item2);
                } else if (function == CLOSEDIR) {
                    item->SetEndTime(item2->GetEndTime());
                    this->AssignAllItems(itemsToAssigne);
                    return new LfcLsCommand(
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
