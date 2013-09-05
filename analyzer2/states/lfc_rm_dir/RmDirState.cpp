/* 
 * File:   RmDirState.cpp
 * Author: radek
 * 
 * Created on 27 July 2013, 13:20
 */

#include "RmDirState.h"

RmDirState::RmDirState() {
}

RmDirState::~RmDirState() {
}

LfcCommand * RmDirState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    bool startReadDir = false;
    bool openDir = false;
    bool chdir = false;
    bool chdir1 = false;
    bool closeDir = false;
    vector<Item *> itemsToAssigne;
    int itemsSize = items.size();

    for (int i = 0; i < itemsSize and
            *iterator != NULL
            ; i++, iterator++) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            FunctionType function = item2->GetCommand()->getName();
            if (item->compareUserSiteFile(item2) and !startReadDir) {
                if (function == OPENDIR and !openDir) {
                    PrintMessage("RMDIR OPENDIR", item2);
                    itemsToAssigne.push_back(item2);
                    openDir = true;
                } else if (function == CHDIR and !chdir) {
                    PrintMessage("RMDIR CHDIR", item2);
                    itemsToAssigne.push_back(item2);
                    chdir = true;
                }
            }

            if (item->compareUserSite(item2) and !startReadDir) {
                if (function == READDIR) {
                    PrintMessage("RMDIR READDIR", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetTid(item2->GetTid());
                    startReadDir = true;
                }
            }

            if (item->compareUserSiteTid(item2) and startReadDir) {
                if (function == CLOSEDIR and !closeDir) {
                    PrintMessage("RMDIR CLOSEDIR", item2);
                    itemsToAssigne.push_back(item2);
                    closeDir = false;
                } else if (function == CHDIR and !chdir1) {
                    PrintMessage("RMDIR CHDIR", item2);
                    itemsToAssigne.push_back(item2);
                    chdir1 = true;
                } else if (function == RMDIR) {
                    PrintMessage("RMDIR RMDIR", item2);
                    item->SetEndTime(item2->GetEndTime());
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);
                    return new LfcRmDirCommand(
                            item->GetStartTime(),
                            item->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            false);
                }
            }
        }

        if (*iterator == items.back()) {
            break;
        }
    }

    PrintMessage("RMDIR NULL", item);
    return NULL;
}


