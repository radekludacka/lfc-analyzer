/* 
 * File:   ReplicateState.cpp
 * Author: radek
 * 
 * Created on 25 July 2013, 13:02
 */

#include "ReplicateStateTransaction.h"

ReplicateStateTransaction::ReplicateStateTransaction() {
}

ReplicateStateTransaction::~ReplicateStateTransaction() {
}

LfcCommand * ReplicateStateTransaction::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    vector<Item *> itemsToAssigne;
    bool statg = false;
    bool addReplica = false;

    for (; *iterator != NULL; iterator++) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            if (item->compareUserSiteTid(item2)) {
                FunctionType command = item2->GetCommand()->getName();
                if (command == STATG and !statg) {
                    PrintMessage("CP1 STATG", item2);
                    itemsToAssigne.push_back(item2);
                    statg = true;
                } else if (command == ADDREPLICA and !addReplica) {
                    PrintMessage("CP1 ADDREPLICA", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetFilePath(item2->GetFilePath());
                    addReplica = true;
                } else if (command == ENDTRANS) {
                    PrintMessage("CP1 ENDTRANS", item2);
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);
                    item->SetEndTime(item2->GetEndTime());
                    return new LfcRepCommand(
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

    PrintMessage("NULL REPLICATE TRANSACTION", item);
    return NULL;
}
