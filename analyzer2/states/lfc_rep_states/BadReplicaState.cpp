/* 
 * File:   BadReplicaState.cpp
 * Author: radek
 * 
 * Created on 17 July 2013, 11:24
 */

#include "BadReplicaState.h"

BadReplicaState::BadReplicaState() {
}

BadReplicaState::~BadReplicaState() {
}

LfcCommand * BadReplicaState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    for (; *iterator != NULL ; iterator++) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            if (item->compareUserSiteTid(item2)) {
                FunctionType command = item2->GetCommand()->getName();
                if (command == ENDSESS) {
                    item2->SetAssigned(true);
                    PrintMessage("BAD REPLICA END SESS", item2);
                    item->SetEndTime(item2->GetEndTime());
                    return new LfcRepCommand(
                            item->GetStartTime(),
                            item->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            true);
                }
            }
        }

        if (*iterator == items.back()) {
            break;
        }
    }
    return NULL;
}
