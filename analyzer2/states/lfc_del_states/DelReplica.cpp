/* 
 * File:   DelReplica.cpp
 * Author: radek
 * 
 * Created on 19 July 2013, 13:28
 */

#include "DelReplica.h"

DelReplica::DelReplica() {
}

DelReplica::~DelReplica() {
}

LfcCommand * DelReplica::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    vector<Item *> itemsToAssigne;
    bool finish = false;
    string filePath = "";

    for (; *iterator != NULL; ++iterator) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            FunctionType command = item2->GetCommand()->getName();
            if (item->compareUserSiteTid(item2)) {
                if (command == GETLINKS and !finish) {
                    PrintMessage("DEL REP GETLINKS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetFilePath(item2->GetFilePath());
                } else if (command == ACCESS and !finish) {
                    PrintMessage("DEL REP ACCESS", item2);
                    itemsToAssigne.push_back(item2);
                    filePath = item2->GetFilePath();
                } else if (command == ENDSESS and !finish) {
                    PrintMessage("DEL REP ENDSESS 1", item2);
                    itemsToAssigne.push_back(item2);
                    finish = true;
                    AssignAllItems(itemsToAssigne);
                    itemsToAssigne.clear();

                } else if (command == DELREPLICA and finish) {
                    PrintMessage("DEL REP DELREPLICA", item2);
                    itemsToAssigne.push_back(item2);

                    if (!item2->compareUserSiteFirstPartOfFile(item)) {
                        PrintMessage("BAD SESSION", item2);
                        itemsToAssigne.clear();
                        item->SetTid(-1);
                        break;
                    }
                } else if (command == GETREPLICA and finish) {
                    PrintMessage("DEL REP GETREPLICA", item2);
                    itemsToAssigne.push_back(item2);
                } else if (command == GETLINKS and finish) {
                    PrintMessage("DEL REP GETLINKS", item2);
                    itemsToAssigne.push_back(item2);
                } else if (command == UNLINK and finish) {
                    PrintMessage("DEL REMAIN UNLINK", item2);
                    itemsToAssigne.push_back(item2);
                } else if (command == ENDSESS and finish) {
                    PrintMessage("DEL REP ENDSESS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetEndTime(item2->GetEndTime());
                    this->AssignAllItems(itemsToAssigne);
                    return new LfcDelReplicaCommand(
                            item->GetStartTime(),
                            item->GetEndTime(),
                            filePath,
                            item->GetUser(),
                            item->GetSite(),
                            false
                            );
                }
            }

            if (command == STARTSESS) {
                if (item->compareUserSite(item2)) {
                    PrintMessage("DEL REP STARTSESS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetTid(item2->GetTid());
                }
            }
        }

        if (*iterator == items.back()) {
            break;
        }
    }

    PrintMessage("DEL REP NULL", item);
    return NULL;
}
