/* 
 * File:   StartTransState.cpp
 * Author: radek
 * 
 * Created on 16 July 2013, 12:41
 */

#include "StartTransState.h"

StartTransState::StartTransState() {
}

StartTransState::~StartTransState() {
}

LfcCommand * StartTransState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    bool firstStatg = false;
    bool secondStatg = false;
    bool mkdir = false;
    bool creat = false;
    bool setfsizeg = false;
    bool addreplica = false;

    vector<Item *> itemsToAssigne;

    for (; iterator != items.end() and *iterator != NULL; ++iterator) {
        Item * item2 = *iterator;
        if (!item2->IsAssigned()) {
            if (item->compareUserSiteTid(item2)) {
                FunctionType function = item2->GetCommand()->getName();

                if (function == STATG) {
                    PrintMessage("START TRANS STATG 0", item2);
//                    cout << "STARTTRANS STATG X" << endl;
//                    item2->GetStartTime()->toString();

                    int retCommand = item2->GetCommand()->getReturnCode();
                    if (retCommand == 2 and !firstStatg) {
                        firstStatg = true;
                        itemsToAssigne.push_back(item2);
                        PrintMessage("START TRANS STATG 2", item2);
                    } else if (retCommand == 0 and !secondStatg) {
                        secondStatg = true;
                        PrintMessage("START TRANS STATG 0", item2);
                        itemsToAssigne.push_back(item2);
                    }
                } else if (function == MKDIR and !mkdir) {
                    mkdir = true;
                    PrintMessage("START TRANS MKDIR", item2);
                    itemsToAssigne.push_back(item2);
                } else if (function == CREAT and !creat) {
                    creat = true;
                    itemsToAssigne.push_back(item2);

                    string::size_type pos;
                    pos = item2->GetFilePath().find(' ', 0);
                    string second = item2->GetFilePath().substr(pos + 1);
                    string first = item2->GetFilePath().substr(0, pos);

                    item->SetFilePath(first);
                } else if (function == SETFSIZEG and !setfsizeg) {
                    setfsizeg = true;
                    itemsToAssigne.push_back(item2);
                    PrintMessage("START TRANS SETFSIZEG", item2);
                } else if (function == ADDREPLICA and !addreplica) {
                    addreplica = true;
                    itemsToAssigne.push_back(item2);
                    PrintMessage("START TRANS ADDREPLICA", item2);
                } else if (function == ENDTRANS) {
                    PrintMessage("START TRANS END TRANS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetEndTime(item2->GetEndTime());
                    this->AssignAllItems(itemsToAssigne);
                    return new LfcCrCommand(
                            item->GetStartTime(),
                            item->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            false,
                            NULL);
                }
            }
        }

        if (*iterator == items.back()) {
            break;
        }
    }

    PrintMessage("START TRANS NULL", item);
    return NULL;
}
