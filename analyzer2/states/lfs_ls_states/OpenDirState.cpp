/* 
 * File:   LfcOpenDirAnalyzerState.cpp
 * Author: radek
 * 
 * Created on 13 July 2013, 21:27
 */

#include "OpenDirState.h"

OpenDirState::OpenDirState() {
}

OpenDirState::~OpenDirState() {
}

LfcCommand * OpenDirState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    vector<Item *> itemsToAssigne;

    for (; iterator != items.end() and *iterator != NULL; ++iterator) {

        Item * item2 = *iterator;
        if (!item2->IsAssigned()) {

            if (item->compareUserSiteTid(item2)) {
                FunctionType function = item2->GetCommand()->getName();
                if (function == READDIR) {
                    itemsToAssigne.push_back(item2);
                    PrintMessage("OPEN DIR READDIR", item2);
                } else if (function == CLOSEDIR) {
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);

                    bool failed = false;
                    if (item2->GetInformation().size() > 0) {
                        failed = true;
                    }
                    PrintMessage("OPEN DIR CLOSEDIR", item2);
                    return new LfcLsCommand(item->GetStartTime(),
                            item2->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            failed);
                }
            }
        }

        if (*iterator == items.back()) {
            break;
        }
    }

    PrintMessage("OPENDIR NULL", item);
    return NULL;
}


