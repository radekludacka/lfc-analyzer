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
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LCG_NONE;
    this->stringName = "SRV_ERR";
}
