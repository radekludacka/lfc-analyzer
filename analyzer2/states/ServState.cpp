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
    
    Information * information = new Information();
    information->addInformation(item->GetInformation());

    if (item->GetUser()->GetName().length() != 0 && item->GetUser()->GetName().find('=') == std::string::npos) {
        cout << "2" << endl;
        item->GetStartTime()->print();
        cout << item->GetUser()->GetName() << endl;
        cout << item->GetFilePath() << endl;
        return NULL;
    }
    
    return new LfcServCommand(
            item->GetStartTime(),
            item->GetEndTime(),
            item->GetFilePath(),
            item->GetUser(),
            item->GetSite(),
            true);
}
