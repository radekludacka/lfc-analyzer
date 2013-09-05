/* 
 * File:   LfcAACommand.cpp
 * Author: radek
 * 
 * Created on 27 July 2013, 11:28
 */

#include "LfcAACommand.h"

LfcAACommand::LfcAACommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LCG_AA;
    this->stringName = "LCG_AA";
}

LfcAACommand::~LfcAACommand() {
}

