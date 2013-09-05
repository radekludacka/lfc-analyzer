/* 
 * File:   DelReplica.cpp
 * Author: radek
 * 
 * Created on 19 July 2013, 13:28
 */

#include "DelReplica.h"

DelReplica::DelReplica() {
}

DelReplica::~DelReplica() {
}

LfcCommand * DelReplica::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    vector<Item *> itemsToAssigne;
    bool finish = false;
    bool access = false;
    bool endSess = false;
    bool delReplica = false;
    bool getReplica = false;
    bool getLinks = false;

    for (; *iterator != NULL; ++iterator) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            if (item->compareUserSiteTid(item2)) {
                FunctionType command = item2->GetCommand()->getName();

                if (command == GETLINKS and !finish) {
                    itemsToAssigne.push_back(item2);
                } else if (command == ACCESS and !access) {
                    PrintMessage("DEL REP ACCESS", item2);
                    itemsToAssigne.push_back(item2);
                } else if (command == ENDSESS and !finish and !endSess) {
                    PrintMessage("DEL REP ENDSESS 1", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetFilePath(item2->GetFilePath());
                    finish = true;
                } else if (command == DELREPLICA and !delReplica) {
                    PrintMessage("DEL REP DELREPLICA", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetFilePath(item2->GetFilePath());
                } else if (command == GETREPLICA and !getReplica) {
                    PrintMessage("DEL REP GETREPLICA", item2);
                    itemsToAssigne.push_back(item2);
                } else if (command == GETLINKS and finish and !getLinks) {
                    PrintMessage("DEL REP GETLINKS", item2);
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);
                    State * state = new DelRemain();
                    return state->NextState(iterator, items, item);
                } else if (command == ENDSESS and finish) {
                    PrintMessage("DEL REP ENDSESS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetEndTime(item2->GetEndTime());
                    this->AssignAllItems(itemsToAssigne);
                    return new LfcDelReplicaCommand(
                            item->GetStartTime(),
                            item->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            false
                            );
                }
            }

            if (item->compareUserSiteFile(item2)) {
                FunctionType command = item2->GetCommand()->getName();
                if (command == STARTSESS) {
                    PrintMessage("DEL REP STARTSESS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetTid(item2->GetTid());
                }
            }
        }

        if (*iterator == items.back()) {
            break;
        }
    }
    
    PrintMessage("DEL REP NULL", item);
    return NULL;
}
