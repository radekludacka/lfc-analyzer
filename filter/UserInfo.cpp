/* 
 * File:   UserInfo.cpp
 * Author: radek
 * 
 * Created on 29 July 2013, 16:59
 */

#include "UserInfo.h"
#include "ItemType.h"

UserInfo::UserInfo( nextType) {
    
}

UserInfo::~UserInfo() {
}

UserInfo::addCommand(LfcCommand* command) {

    if (subItems.find(command) != objectMap.end()) {
        item->SetAssigned(true);
        this->currentState = objectMap.at(functionName);
    }
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