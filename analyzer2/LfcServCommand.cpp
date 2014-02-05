/* 
 * File:   LfcServCommand.cpp
 * Author: radek
 * 
 * Created on 22 July 2013, 12:36
 */

#include "LfcServCommand.h"

LfcServCommand::~LfcServCommand() {
}

LfcServCommand::LfcServCommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail, Information * info)
: LfcCommand(startT, endT, fileName, userName, site, fail, info) {
    this->name = LCG_SERV;
    this->stringName = "SRV_ERR";
}
