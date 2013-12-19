/* 
 * File:   StatgState.cpp
 * Author: radek
 * 
 * Created on 27 July 2013, 11:02
 */

#include "StartTransStateAA.h"

StartTransStateAA::StartTransStateAA() {
}

StartTransStateAA::~StartTransStateAA() {
}

LfcCommand * StartTransStateAA::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    bool statg = false;
    bool getPath = false;
    bool symLink = false;

    vector<Item *> itemsToAssigne;
    int itemsSize = items.size();

    for (int i = 0; i < itemsSize; i++, iterator++) {
        Item * item2 = *iterator;

//11/09 21:28:31.596 20713,0 Cns_srv_starttrans: NS092 - starttrans request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of Materials of the Academy of Sciences of the CR/CN=Tomas Kana (608,101) from skurut15.grid.cesnet.cz
//11/09 21:28:31.596 20713,0 Cns_srv_starttrans: NS098 - starttrans (1.16.0-1.el6)
//11/09 21:28:31.596 20713,0 Cns_srv_starttrans: returns 0
//11/09 21:28:31.597 20713,0 Cns_srv_statg: NS092 - statg request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of Materials of the Academy of Sciences of the CR/CN=Tomas Kana (608,101) from skurut15.grid.cesnet.cz
//11/09 21:28:31.597 20713,0 Cns_srv_statg: NS098 - statg  9bd768ff-bd79-495b-aeb2-c410da1107ab
//11/09 21:28:31.598 20713,0 Cns_srv_statg: returns 0
//11/09 21:28:31.598 20713,0 Cns_srv_getpath: NS092 - getpath request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of Materials of the Academy of Sciences of the CR/CN=Tomas Kana (608,101) from skurut15.grid.cesnet.cz
//11/09 21:28:31.600 20713,0 Cns_srv_getpath: returns 0
//11/09 21:28:31.602 20713,0 Cns_srv_symlink: NS092 - symlink request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of Materials of the Academy of Sciences of the CR/CN=Tomas Kana (608,101) from skurut15.grid.cesnet.cz
//11/09 21:28:31.602 20713,0 Cns_srv_symlink: NS098 - symlink /grid/voce/generated/2013-11-09/file-190eba40-2372-4258-89f5-4503b44f179c /grid/voce/manik/Pd/HCP/plane0001/a5.254670.tar.gz
//11/09 21:28:31.606 20713,0 Cns_srv_symlink: returns 17
//11/09 21:28:31.663 20713,1 Cns_serv: [150.214.37.125] (cream-cafpegrid.ugr.es): Could not establish an authenticated connection: server_establish_context_ext: The client itself detected a problem with the user proxy, it was probably missing or expired !
//11/09 21:28:31.698 20713,0 Cns_srv_aborttrans: NS092 - aborttrans request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of Materials of the Academy of Sciences of the CR/CN=Tomas Kana (608,101) from skurut15.grid.cesnet.cz
//11/09 21:28:31.698 20713,0 Cns_srv_aborttrans: returns 0
        
        if (!item2->IsAssigned()) {
            PrintMessage("START TRANSAA", item2);
            
            FunctionType function = item2->GetCommand()->getName();
            if (item->compareUserSiteTid(item2)) {
                if (function == STATG and !statg) {
                    PrintMessage("START TRANSAA STATG", item2);
                    
                    if (item2->GetCommand()->getReturnCode() == 2) {

                        itemsToAssigne.push_back(item2);
                        this->AssignAllItems(itemsToAssigne);
                        State * state = new StartTransState2();
                        return state->NextState(iterator, items, item);
                    }
                    itemsToAssigne.push_back(item2);
                    statg = true;
                } else if (function == GETPATH and !getPath) {
                    PrintMessage("START TRANS GETPATH", item2);
                    itemsToAssigne.push_back(item2);
                    getPath = true;
                } else if (function == SYMLINK and !symLink) {
                    PrintMessage("START TRANS AA SYMLINK", item2);
                    itemsToAssigne.push_back(item2);
                    symLink = true;
                    // pokud je symplink 17 - neco je spatne
                    item->SetFilePath(item2->GetFilePath());
                } else if (function == SERV_ABORTTRANS) {
                    PrintMessage("START TRANS AA ABORT", item2);
                    item->SetEndTime(item2->GetEndTime());
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);
                    return new LfcAACommand(
                            item->GetStartTime(),
                            item->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            true);
                } else if (function == ENDTRANS) {
                    PrintMessage("START TRANS AA ENDTRANS", item2);
                    item->SetEndTime(item2->GetEndTime());
                    itemsToAssigne.push_back(item2);
                    this->AssignAllItems(itemsToAssigne);
                    return new LfcAACommand(
                            item->GetStartTime(),
                            item->GetEndTime(),
                            item->GetFilePath(),
                            item->GetUser(),
                            item->GetSite(),
                            false);
                }
            }
        }
    }

    return NULL;
}
