/* 
 * File:   ReplicaCpDelRepStateSess2.cpp
 * Author: radek
 * 
 * Created on January 16, 2014, 2:12 PM
 */

#include "ReplicaCpDelRepStateSess2.h"
#include "GetReplica.h"

ReplicaCpDelRepStateSess2::ReplicaCpDelRepStateSess2() {
}

ReplicaCpDelRepStateSess2::~ReplicaCpDelRepStateSess2() {
}

LfcCommand * ReplicaCpDelRepStateSess2::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item) {

    vector<Item *> itemsToAssigne;
    bool sess = false;
    bool endsess = false;
    bool statg = false;
    int numberOfFailsFileComparation = 0;
    bool startTrans = false;
    int backUpTid = item->GetTid();
    int itemsSize = items.size();

    for (int i = 0; i < itemsSize; i++, iterator++) {
        Item * item2 = *iterator;

        if (!item2->IsAssigned()) {
            FunctionType command = item2->GetCommand()->getName();

            if (item->compareUserSite(item2) && !sess && !endsess) {
                if (command == STARTTRANS) {
                    PrintMessage("CP2 START TRANS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetTid(item2->GetTid());
                    startTrans = true;
                } else if (command == STARTSESS && !sess && !startTrans) {
                    PrintMessage("CP2 START SESS", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetTid(item2->GetTid());
                    sess = true;
                    // dobehnout celou session

                    // tady se nesmi skoncit ale pokracovat ve for cyklu dokud
                    // se nenarazi na access, ktery obsahuje nazev souboru

                    // tady se skoci do nove session ale je to skutecne ta spravna ?
                    // musi se v dalsim for cyklu zkontrolovat jestli se 
                    // jedna skutecny soubor - skocit - udelat dalsi stav kde se
                    // najde replika a kdyz nebude souhlasit smaze se s oznacovani a bude
                    // se pokracovat - co kdyz se bude ale jednat o 
                    // dalsi lcg-cp na stejny soubor - to potom nebude fungovat
                    // nutno udelat dalsi stav a z tohoto dalsiho lcg-cp 
                    // udelat lcg-cp a ne lcg-del 
                    // udelat testy na takoveto veci !!!!!!
                    //                    State * state = new DellAll();
                    //                    return state->NextState(iterator, items, item);
                }
            }

            if (item->compareUserSiteTid(item2) && sess && !endsess && !startTrans) {
                if (command == GETREPLICA && statg) {
                    PrintMessage("CP2 GETREPLICA", item2);
                    itemsToAssigne.push_back(item2);
                    item->SetFilePath(item2->GetFilePath());
                } else if (command == ENDSESS && statg) {
                    PrintMessage("CP2 ENDSESS", item2);
                    itemsToAssigne.push_back(item2);
                    endsess = true;
                } else if (command == STATG && !statg) {
                    PrintMessage("CP2 STATG", item2);
                    itemsToAssigne.push_back(item2);
                    statg = true;
                    if (!item->compareUserSiteFirstPartOfFile(item2)) {
                        // interupt searching, when file name is not the same
                        // start in searching new correct session
                        PrintMessage("CP2 FAIL", item2);
                        itemsToAssigne.clear();
                        item->SetTid(backUpTid); 
                       sess = false;
                        statg = false;
                        if (numberOfFailsFileComparation > 4) {
                            break;
                        }
                        numberOfFailsFileComparation++;
                    }
                }
            }


            if (command == ACCESS && !startTrans) {
                if (item->compareUserSiteFirstPartOfFile(item2) && sess && endsess) {
                    PrintMessage("CP2 ACCESS", item2);
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);
                    State * state = new DellAll();
                    return state->NextState(iterator, items, item);
                }
            }

            if (command == STATG and !statg) {
                PrintMessage("CP2 STATG STR", item2);
                if (!item->compareUserSiteFile(item2)) {
                    PrintMessage("CP2 STATG FAIL STR", item2);
                    itemsToAssigne.clear();
                    item->SetTid(backUpTid);
                    startTrans = false;
                    if (numberOfFailsFileComparation > 4) {
                        break;
                    }
                    numberOfFailsFileComparation++;
                    // nekdy se ale musi tid obnovit kdyz se vrati lcg-cp - protoze se nastavuje session i u dalsich itemu
                } else {
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);
                    State * state = new ReplicateStateTransaction();
                    return state->NextState(iterator, items, item);
                }
            }

        }

        if (*iterator == items.back()) {
            break;
        }
    }

    PrintMessage("LCG CP", item);
    return new LfcCpCommand(
            item->GetStartTime(),
            item->GetEndTime(),
            item->GetFilePath(),
            item->GetUser(),
            item->GetSite(),
            false);
}


