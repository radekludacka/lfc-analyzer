/* 
 * File:   ServState.cpp
 * Author: radek
 * 
 * Created on 22 July 2013, 12:33
 */

#include "ServState.h"

ServState::ServState() {
}

ServState::~ServState() {
}

LfcCommand * ServState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    PrintMessage("SERV", item);

    item->SetAssigned(true);
    return new LfcServCommand(
            item->GetStartTime(),
            item->GetEndTime(),
            item->GetFilePath(),
            item->GetUser(),
            item->GetSite(),
            true);
}
