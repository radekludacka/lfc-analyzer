/* 
 * File:   GetReplica.cpp
 * Author: radek
 * 
 * Created on January 15, 2014, 2:22 PM
 */

#include "GetReplica.h"

GetReplica::GetReplica() {
}

GetReplica::~GetReplica() {
}

LfcCommand * GetReplica::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    int itemsSize = items.size();
    PrintMessage("GETREPLICA STATE", item);

    for (int i = 0; i < itemsSize; i++, iterator++) {
        Item * item2 = *iterator;
        if (!item2->IsAssigned()) {
            
            PrintMessage("GETREPLICA STATE not assigned", item2);
            
            if (item->compareUserSiteTid(item2)) {
                FunctionType command = item2->GetCommand()->getName();
                if (command == ENDSESS) {
                    PrintMessage("GETREPLICA STATE ENDSESS", item2);
                    item2->SetAssigned(true);
                    return new LfcUnknownCommand(
                            item->GetStartTime(),
                            item2->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            false);
                } else {
                    // ukladat to zpet do prvni item je asi prasarna
                    // zkusit to ulozit do jine item - nove vytvorene
                    // chyba ?? - nasel se jiny prikaz - doimplementovat
                    // toto rozpoznavat i u jinych prikazu
                    // return null
                    // udelat null command a ten ukladat pokud se nepovede
                    // analyza
                }
            }
        } else {
            PrintMessage("GETREPLICA STATE ASSIGNED", item2);
        }

        if (*iterator == items.back()) {
            break;
        }
    }

    PrintMessage("GETREPLICA STATE NULL", item);
    return NULL;
}

