/* 
 * File:   LfcUnknownCommand.cpp
 * Author: radek
 * 
 * Created on January 15, 2014, 2:37 PM
 */

#include "LfcUnknownCommand.h"

LfcUnknownCommand::LfcUnknownCommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LCG_UNKNOWN;
    this->stringName = "LCG_UNKNOWN";
}

LfcUnknownCommand::~LfcUnknownCommand() {
}


