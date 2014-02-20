/* 
 * File:   StartSessState.cpp
 * Author: radek
 * 
 * Created on 17 July 2013, 10:56
 */

#include "StartSessState.h"

StartSessState::StartSessState() {
}

StartSessState::~StartSessState() {
}

LfcCommand * StartSessState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    int itemsSize = items.size();
    PrintMessage("START SESS", item);
    string statgFilePath = "";
    string fileBackUp = item->GetFilePath();

    for (int i = 0; i < itemsSize; i++, iterator++) {
        Item * item2 = *iterator;
        if (!item2->IsAssigned()) {

            PrintMessage("START SESS NOT ASSIGNED", item2);

            if (item->compareUserSiteTid(item2)) {
                FunctionType command = item2->GetCommand()->getName();
                if (command == STATG) {
                    int returnCode = item2->GetCommand()->getReturnCode();
                    if (returnCode == 2) {
                        item2->SetAssigned(true);
                        item->SetFilePath(item2->GetFilePath());
                        State * state = new BadReplicaState();

                        PrintMessage("START SESS STATG 2", item2);
                        return state->NextState(iterator, items, item);
                    } else if (returnCode == 0) {
                        item2->SetAssigned(true);
                        State * state = new ReplicaCpState();
                        item->SetFilePath(item2->GetFilePath());
                        statgFilePath = item2->GetFilePath();

                        PrintMessage("START SESS STATG 0", item2);
                        LfcCommand * command = state->NextState(iterator, items, item);
                        if (command != NULL && command->GetName() == LCG_CP) {
                            command->SetFile(statgFilePath);
                        }
                        
                        if (command == NULL) {
                            item->SetFilePath(fileBackUp);
                        }
                        return command;
                    }
                } else if (command == STATR) {
                    PrintMessage("START SESS STATR", item2);
                    item2->SetAssigned(true);
                    State * state = new DelReplica();
                    return state->NextState(iterator, items, item);
                } else if (command == GETLINKS) {
                    PrintMessage("START SESS GETLINKS", item2);
                    item2->SetAssigned(true);
                    item->SetFilePath(item2->GetFilePath());
                    State * state = new DelReplica();
                    return state->NextState(iterator, items, item);
                } else if (command == GETREPLICA) {
                    PrintMessage("START SESS GETREPLICA", item2);
                    item2->SetAssigned(true);
                    State * state = new GetReplica();
                    item->SetFilePath(item2->GetFilePath());
                    return state->NextState(iterator, items, item);
                }
            }
        } else {
            PrintMessage("START SESS ASSIGNED COMMAND", item2);
        }

        if (*iterator == items.back()) {
            break;
        }
    }

    PrintMessage("START SESS NULL", item);
    return NULL;
}