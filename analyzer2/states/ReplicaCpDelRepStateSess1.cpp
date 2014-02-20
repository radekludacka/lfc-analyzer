/* 
 * File:   GoodReplicaState.cpp
 * Author: radek
 * 
 * Created on 17 July 2013, 13:15
 */

#include "ReplicaCpDelRepStateSess1.h"

ReplicaCpState::ReplicaCpState() {
}

ReplicaCpState::~ReplicaCpState() {
}

LfcCommand * ReplicaCpState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item) {

    vector<Item *> itemsToAssigne;
    bool getReplica = false;
    bool statg = false;
    int itemsSize = items.size();
    string backupFile = item->GetFilePath();
    int backupId = item->GetTid();
    LogTime * backUpEndTime = item->GetEndTime();

    for (int i = 0; i < itemsSize; i++, iterator++) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            FunctionType command = item2->GetCommand()->getName();

            if (item->compareUserSiteTid(item2)) {
                if (command == GETREPLICA and !getReplica) {
                    PrintMessage("CP GETREPLICA", item2);
                    item->SetFilePath(item2->GetFilePath());
                    itemsToAssigne.push_back(item2);
                    getReplica = true;
                } else if (command == ENDSESS) {
                    PrintMessage("CP END SESS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetEndTime(item2->GetEndTime());
                    State * state = new ReplicaCpDelRepStateSess2();
                    LfcCommand * command = state->NextState(iterator, items, item);
                    if (command == NULL) {
                        PrintMessage("RETURNED NULL", item2);
                        item->SetFilePath(backupFile);
                        item->SetTid(backupId);
                        item->SetEndTime(backUpEndTime);
                        return command;
                    }
                    this->AssignAllItems(itemsToAssigne);
                    return command;
                } else if (command == STATG and !statg) {
                    PrintMessage("CP STATG", item2);
                    itemsToAssigne.push_back(item2);
                    statg = true;
                }
            }
        }

        if (*iterator == items.back()) {
            break;
        }
    }

    PrintMessage("REPLICA CP DEL REP NULL", item);
    return NULL;
}
