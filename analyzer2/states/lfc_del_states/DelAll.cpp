/* 
 * File:   DellAll.cpp
 * Author: radek
 * 
 * Created on 21 July 2013, 15:19
 */

#include "DelAll.h"

DellAll::DellAll() {
}

DellAll::~DellAll() {
}

LfcCommand * DellAll::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    vector<Item *> itemsToAssigne;
    bool startsess1 = false;
    bool getlinks = false;

    for (int i = 0; *iterator != NULL; i++, iterator++) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            FunctionType command = item2->GetCommand()->getName();

            if (item->compareUserSite(item2) and !startsess1 and !getlinks) {
                if (command == STARTSESS) {
                    PrintMessage("DEL ALL START SESS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetTid(item2->GetTid());
                    startsess1 = true;
                }
            }

            if (item->compareUserSiteTid(item2) and startsess1 and !getlinks) {
                if (command == GETREPLICA) {
                    PrintMessage("DEL ALL GETREPLICA", item2);
                    itemsToAssigne.push_back(item2);
                } else if (command == ENDSESS) {
                    PrintMessage("DEL ALL END SESS", item2);
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);
                    startsess1 = false;
                } else if (command == GETLINKS) {
                    PrintMessage("DEL ALL GETLINKS", item2);
                    itemsToAssigne.push_back(item2);
                    getlinks = true;
                } else if (command == DELREPLICA) {
                    PrintMessage("DEL ALL DEL REPLICA 2", item2);
                    itemsToAssigne.push_back(item2);
                    if (!item->compareUserSiteSecondAndFirstPartOfFile(item2)) {
                        itemsToAssigne.clear();
                        startsess1 = false;
                        item->SetTid(-1);
                    }
                }
            }

            if (item->compareUserSiteTid(item2) and getlinks) {
                if (command == UNLINK) {
                    PrintMessage("DEL ALL UNLINK 2", item2);
                    item->SetFilePath(item2->GetFilePath());
                    itemsToAssigne.push_back(item2);
                } else if (command == ENDSESS) {
                    PrintMessage("DEL ALL ENDSESS FINAL", item2);
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);

                    item->SetEndTime(item2->GetEndTime());

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

        if (*iterator == items.back()) {
            break;
        }
    }

    return NULL;
}

