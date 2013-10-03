/* 
 * File:   Analyzer.cpp
 * Author: radek
 * 
 * Created on 13 July 2013, 11:55
 */

using namespace std;

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
    }

    int notAssigned = 0;
    std::vector<Item *>::const_iterator iterator2;
    for (iterator2 = items->begin(); iterator2 != items->end(); ++iterator2) {
        Item * item = *iterator2;
        if (!item->IsAssigned()) {
            notAssigned++;
        }
    }
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