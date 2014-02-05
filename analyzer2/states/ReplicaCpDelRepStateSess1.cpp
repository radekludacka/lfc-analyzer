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

        //      s st 1 gr 1+2 e - A
        //      s st 1 gr 1+2 e - B - zde udelat nejaky check ze se jedna o stejny soubor - pokud je tam i access na dany soubor pak je to lcg-del jinak je to 2x lcg-cp 
        //      a 1

        //      tedy zacina analyza tohoto stavu - ulozit 
        //      s d 2+3 gr 2 e - C - prvni je vzdycky stejna, druha kdyz bude obsahovat gl tak skocit do jineho ifu
        //      s d 2+4 gr 2 e - C
        //      s d 2+5 gr 2 gl 2 u 1 u 5 e  - stejne ale vicekrat u pokud je vice linku

        // muzou se tady vsechny itemy oznacovat - uz je prece jasne
        // ze k necemu pratri ?

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
