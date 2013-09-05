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
    bool state = false;
    bool state1 = false;
    bool canBeLcgCp = false;

    bool statg1 = false;
    bool getreplica1 = false;
    bool endsess1 = false;

    for (int i = 0; *iterator != NULL; i++, iterator++) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {

            FunctionType command = item2->GetCommand()->getName();

            if (item->compareUserSiteTid(item2) and !state and !state1) {
                if (command == STATG and !statg1) {
                    PrintMessage("DELL ALL STATG 0", item2);
                    item->SetFilePath(item2->GetFilePath());
                    itemsToAssigne.push_back(item2);
                    statg1 = true;
                } else if (command == GETREPLICA and !getreplica1) {
                    PrintMessage("DEL ALL GETREPLICA 0", item2);
                    itemsToAssigne.push_back(item2);
                    getreplica1 = true;
                } else if (command == ENDSESS and !endsess1) {
                    PrintMessage("DEL ALL ENDSESS 0", item2);
                    itemsToAssigne.push_back(item2);
                    endsess1 = true;
                    canBeLcgCp = true;
                    // prvni byl del -a neexistuji 
                    // pokud nema v sobe get replica

                    if (!getreplica1) {
                        PrintMessage("DEL ALL FAIL", item2);

                        this->AssignAllItems(itemsToAssigne);
                        return new LfcRepCommand(
                                item->GetStartTime(),
                                item->GetEndTime(),
                                item->GetFilePath(),
                                item->GetUser(),
                                item->GetSite(),
                                true);


                        // druhy vracim DEL -a ale co kdy
                        // se tam vloudil jedne lcg-del -a fail
                        // mezi del -a uspesny ?
                    }
                }
            }

            if (item->compareUserSite(item2)) {
                if (command == ACCESS and !state) {
                    PrintMessage("DEL ACCESS 1", item2);
                    itemsToAssigne.push_back(item2);
                    state = true;
                    canBeLcgCp = false;
                }
            }

            if (item->compareUserSite(item2) and state) {
                FunctionType command = item2->GetCommand()->getName();
                if (command == STARTSESS) {
                    PrintMessage("DEL ALL START SESS 2", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetTid(item2->GetTid());
                }
            }

            if (item->compareUserSiteTid(item2) and
                    state and !state1 and !canBeLcgCp) {

                if (command == DELREPLICA) {
                    PrintMessage("DEL ALL DEL REPLICA 2", item2);
                    itemsToAssigne.push_back(item2);
                } else if (command == GETREPLICA) {
                    PrintMessage("DEL ALL GETREPLICA 2", item2);
                    itemsToAssigne.push_back(item2);
                } else if (command == ENDSESS) {
                    PrintMessage("DEL ALL END SESS 2", item2);
                    itemsToAssigne.push_back(item2);
                } else if (command == GETLINKS) {
                    PrintMessage("DEL ALL GETLINKS 2", item2);
                    itemsToAssigne.push_back(item2);
                    state1 = true;
                }
            }

            if (item->compareUserSiteTid(item2) and state and state1
                    and !canBeLcgCp) {

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

    // POZOR - tady nebudou 1 GET REPLICA FAIL
    // ale boudo to DVE - prvni session a druha session
    // nejak se to musi predat ?

    if (canBeLcgCp) {
        PrintMessage("DEL ALL LCG CP 2", item);

        this->AssignAllItems(itemsToAssigne);
        return new LfcCpCommand(item->GetStartTime(),
                item->GetEndTime(),
                item->GetFilePath(),
                item->GetUser(),
                item->GetSite(),
                false);
    }
    return NULL;
}

