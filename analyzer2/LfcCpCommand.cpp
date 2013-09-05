/* 
 * File:   LfcCpCommand.cpp
 * Author: radek
 * 
 * Created on 17 July 2013, 15:34
 */

#include "LfcCpCommand.h"

LfcCpCommand::LfcCpCommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LCG_CP;
    this->stringName = "LCG_CP";
}

LfcCpCommand::~LfcCpCommand() {
}

