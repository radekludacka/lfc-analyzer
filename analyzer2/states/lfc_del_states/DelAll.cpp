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

    //      s st 1 gr 1+2 e - A
    //      s st 1 gr 1+2 e - B - zde udelat nejaky check ze se jedna o stejny soubor - pokud je tam i access na dany soubor pak je to lcg-del jinak je to 2x lcg-cp 
    //      a 1

    //      tedy zacina analyza tohoto stavu - ulozit 
    //      s d 2+3 gr 2 e - C - prvni je vzdycky stejna, druha kdyz bude obsahovat gl tak skocit do jineho ifu
    //      s d 2+4 gr 2 e - C
    //      s d 2+5 gr 2 gl 2 u 1 u 5 e  - stejne ale vicekrat u pokud je vice linku

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
                        cout << "clear" << endl;
                        cout << "f1" << item->GetFilePath() << endl;
                        cout << "f2" << item2->GetFilePath() << endl;
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

