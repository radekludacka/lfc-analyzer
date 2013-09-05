/* 
 * File:   UtimeState.cpp
 * Author: radek
 * 
 * Created on 22 July 2013, 14:50
 */

#include "UtimeState.h"

UtimeState::UtimeState() {
}

UtimeState::~UtimeState() {
}

LfcCommand * UtimeState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {
    
    PrintMessage("UTIME", item);

    item->SetAssigned(true);
    return new LfcUtimeCommand(
            item->GetStartTime(),
            item->GetEndTime(),
            item->GetFilePath(),
            item->GetUser(),
            item->GetSite(),
            false);
}
