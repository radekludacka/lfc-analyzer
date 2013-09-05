/* 
 * File:   DelReplicaCommand.cpp
 * Author: radek
 * 
 * Created on 19 July 2013, 13:44
 */

#include "LfcDelReplicaCommand.h"

LfcDelReplicaCommand::LfcDelReplicaCommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LCG_DEL;
    this->stringName = "LCG_DEL";
}

LfcDelReplicaCommand::~LfcDelReplicaCommand() {
}

