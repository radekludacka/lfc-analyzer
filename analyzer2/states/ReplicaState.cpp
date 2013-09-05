/* 
 * File:   ReplicaState.cpp
 * Author: radek
 * 
 * Created on 24 July 2013, 16:26
 */

#include "ReplicaState.h"

ReplicaState::ReplicaState() {
}

ReplicaState::~ReplicaState() {
}

LfcCommand * ReplicaState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {
    
    PrintMessage("REPLICA", item);
    
    item->SetAssigned(true);
    return new LfcLrCommand(
            item->GetStartTime(),
            item->GetEndTime(),
            item->GetFilePath(),
            item->GetUser(),
            item->GetSite(),
            false);
}
