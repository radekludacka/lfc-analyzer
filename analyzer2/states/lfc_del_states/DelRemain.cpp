/* 
 * File:   DelRemain.cpp
 * Author: radek
 * 
 * Created on 21 July 2013, 14:24
 */

#include "DelRemain.h"

DelRemain::DelRemain() {
}

DelRemain::~DelRemain() {
}

LfcCommand * DelRemain::NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
) {

    vector<Item *> itemsToAssigne;

    for (; iterator != items.end() and *iterator != NULL; ++iterator) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            if (item->compareUserSiteTid(item2)) {
                FunctionType command = item2->GetCommand()->getName();
                if (command == UNLINK){
                    PrintMessage("DEL REMAIN UNLINK", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetFilePath(item2->GetFilePath());
                } else if (command == ENDSESS) {
                    PrintMessage("DEL REMAIN ENDSES", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetEndTime(item2->GetEndTime());
                    this->AssignAllItems(itemsToAssigne);
                    return new LfcDelReplicaCommand(
                            item->GetStartTime(),
                            item->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            false
                            );
                }
            }
        }
    }
    return NULL;
}

