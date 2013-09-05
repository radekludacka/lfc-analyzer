/* 
 * File:   PingDBState.cpp
 * Author: radek
 * 
 * Created on 22 July 2013, 16:19
 */

#include "PingDBState.h"

PingDBState::PingDBState() {
}

PingDBState::~PingDBState() {
}

LfcCommand * PingDBState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {
    
    PrintMessage("PING DB", item);

    item->SetAssigned(true);
    return new LfcPingDBCommand(
            item->GetStartTime(),
            item->GetEndTime(),
            item->GetFilePath(),
            item->GetUser(),
            item->GetSite(),
            true);
}
