/* 
 * File:   LfcPingDBCommand.cpp
 * Author: radek
 * 
 * Created on 22 July 2013, 16:22
 */

#include "LfcPingDBCommand.h"

LfcPingDBCommand::LfcPingDBCommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LCG_PINGDB;
    this->stringName = "LCG_PINGDB";
}


LfcPingDBCommand::~LfcPingDBCommand() {
}

