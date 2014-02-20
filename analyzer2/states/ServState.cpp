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
    
    int errorStart = item->GetInformation().find(':');
    string info = item->GetInformation().substr(errorStart + 1);
    
    Information * information = new Information();
    information->SetInformation(info);
    
    if (item->GetUser()->GetName().length() != 0 && item->GetUser()->GetName().find('=') == std::string::npos) {
        item->GetStartTime()->print();
        return NULL;
    }
    
    return new LfcServCommand(
            item->GetStartTime(),
            item->GetEndTime(),
            item->GetFilePath(),
            new User("UNKNOWN"),
            item->GetSite(),
            true,
            information);
}
