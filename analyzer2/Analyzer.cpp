/* 
 * File:   Analyzer.cpp
 * Author: radek
 * 
 * Created on 13 July 2013, 11:55
 */

using namespace std;

#include <boost/implicit_cast.hpp>

#include "Analyzer.h"
#include "states/StartSessState.h"
#include "states/MkDirState.h"
#include "states/ServState.h"
#include "states/UtimeState.h"
#include "states/PingDBState.h"
#include "states/ReplicaState.h"
#include "states/lfc_aa_states/StartTransStateAA.h"

Analyzer::Analyzer() {
    this->currentState = NULL;
}

Analyzer::~Analyzer() {
}

//07/18 10:24:03.822 20713,0 Cns_srv_aborttrans: NS092 - aborttrans request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz
//07/18 10:24:03.823 20713,0 Cns_srv_aborttrans: returns 0

LfcCommandTable * Analyzer::Analyze(LogTable * logTable) {
    vector<Item *> * items = logTable->getMyList();
    LfcCommandTable * commandList = new LfcCommandTable();

    map<FunctionType, State *> objectMap = createStateMap();

    int index = -1;

    std::vector<Item *>::const_iterator iterator;
    for (iterator = items->begin(); iterator != items->end(); ++iterator) {
        Item * item = *iterator;
        index++;

        if (!item->IsAssigned()) {
            FunctionType functionName = item->GetCommand()->getName();
            if (objectMap.find(functionName) != objectMap.end()) {

                item->SetAssigned(true);
                this->currentState = objectMap.at(functionName);

                int addition = index + 7000;
                if (addition > items->size()) {
                    addition = items->size();
                }

//                cout << "next item ";
//                item->GetStartTime()->toString();

                std::vector<Item *> subRows(items->begin() + index + 1, items->begin() + addition);
                std::vector<Item *>::const_iterator iterator = subRows.begin();
                LfcCommand * command = currentState->NextState(iterator, subRows, item);
                if (command != NULL) {
                    commandList->add(command);
                } else {
                    item->SetAssigned(false);
                }
            }
        } 
//        else {
//            cout << "ASSIGNED ";
//            item->GetStartTime()->toString();
//        }

    }

    map<FunctionType, string> funcMap;

    funcMap[LSTAT] = "LSTAT";
    funcMap[ACCESS] = "ACCESS";
    funcMap[OPENDIR] = "OPENDIR";
    funcMap[READDIR] = "READDIR";
    funcMap[STARTSESS] = "STARTSESS";
    funcMap[ENDSESS] = "ENDSESS";
    funcMap[DELREPLICA] = "DELREPLICA";
    funcMap[GETREPLICA] = "GETREPLICA";
    funcMap[UNLINK] = "UNLINK";
    funcMap[GETLINKS] = "GETLINKS";
    funcMap[STARTTRANS] = "STARTTRANS";
    funcMap[ENDTRANS] = "ENDTRANS";
    funcMap[STATG] = "STATG";
    funcMap[CREAT] = "CREAT";
    funcMap[ADDREPLICA] = "ADDREPLICA";
    funcMap[SETFSIZEG] = "SETFSIZEG";
    funcMap[MKDIR] = "MKDIR";
    funcMap[STATR] = "STATR";
    funcMap[SERV] = "SERV";
    funcMap[CLOSEDIR] = "CLOSEDIR";
    funcMap[UTIME] = "UTIME";
    funcMap[PINGDB] = "PINGDB";
    funcMap[SYMLINK] = "SYMLINK";
    funcMap[GETPATH] = "GETPATH";
    funcMap[CHDIR] = "CHDIR";
    funcMap[RMDIR] = "RMDIR";

    int notAssigned = 0;
    std::vector<Item *>::const_iterator iterator2;
    for (iterator2 = items->begin(); iterator2 != items->end(); ++iterator2) {
        Item * item = *iterator2;
        if (!item->IsAssigned()) {
            notAssigned++;

//#ifdef COUT
//            cout << endl;
//            item->GetStartTime()->toString();
//            cout << item->GetTid() << " ";
//            cout << funcMap[item->GetCommand()->getName()] << " ";
//            cout << item->GetUser()->GetName() << endl;
//            cout << item->GetFilePath() << endl;
//            cout << item->GetSite()->GetName() << endl;
//            cout << item->GetCommand()->getReturnCode() << endl;
//#endif
        }
    }

    //    delete logTable;

    cout << "not assigned items to command: " << notAssigned << endl;

    return commandList;
}

map<FunctionType, State *> Analyzer::createStateMap() {
    map<FunctionType, State *> stateMap;
    stateMap[STARTSESS] = new StartSessState();
    stateMap[LSTAT] = new LstatState();
    stateMap[MKDIR] = new MkDirState();
    stateMap[SERV] = new ServState();
    stateMap[UTIME] = new UtimeState();
    stateMap[PINGDB] = new PingDBState();
    stateMap[GETREPLICA] = new ReplicaState();
    stateMap[OPENDIR] = new OpenDirState();
    stateMap[STARTTRANS] = new StartTransStateAA();
    return stateMap;
}