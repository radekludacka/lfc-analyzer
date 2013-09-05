/* 
 * File:   GoodReplicaState.cpp
 * Author: radek
 * 
 * Created on 17 July 2013, 13:15
 */

#include "ReplicaCpDelRepState.h"

ReplicaCpState::ReplicaCpState() {
}

ReplicaCpState::~ReplicaCpState() {
}

LfcCommand * ReplicaCpState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item) {

    vector<Item *> itemsToAssigne;
    bool canBeLcgCp = false;
    bool getReplica = false;
    bool endSess = false;
    bool statg = false;
    string file;

    int itemsSize = items.size();

    for (int i = 0; i < itemsSize; i++, iterator++) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            FunctionType command = item2->GetCommand()->getName();

            if (item->compareUserSite(item2)) {
                if (command == STARTTRANS and endSess) {
                    PrintMessage("CP START TRANS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetTid(item2->GetTid());
                    this->AssignAllItems(itemsToAssigne);
                    State * state = new ReplicateStateTransaction();
                    return state->NextState(iterator, items, item);
                } else if (command == STARTSESS and endSess) {
                    PrintMessage("CP DEL ALL START SESS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetTid(item2->GetTid());
                    this->AssignAllItems(itemsToAssigne);
                    State * state = new DellAll();
                    return state->NextState(iterator, items, item);
                }
            }

            if (item->compareUserSiteTid(item2)) {
                if (command == GETREPLICA and !getReplica and !endSess) {
                    PrintMessage("CP GETREPLICA", item2);
                    itemsToAssigne.push_back(item2);
                    file = item->GetFilePath();
                    getReplica = true;
                } else if (command == ENDSESS and !endSess) {
                    PrintMessage("CP END SESS", item2);
                    itemsToAssigne.push_back(item2);
                    canBeLcgCp = true;
                    item->SetFilePath(item2->GetFilePath());
                    item->SetEndTime(item2->GetEndTime());
                    endSess = true;
                } else if (command == STATG and !statg and !endSess) {
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

    if (canBeLcgCp and endSess) {
        PrintMessage("LCG CP", item);
        this->AssignAllItems(itemsToAssigne);
        return new LfcCpCommand(item->GetStartTime(),
                item->GetEndTime(),
                file,
                item->GetUser(),
                item->GetSite(),
                false);
    }

    PrintMessage("REPLICA CP DEL REP NULL", item);
    return NULL;
}
