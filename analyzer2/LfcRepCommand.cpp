/* 
 * File:   LfcRepCommand.cpp
 * Author: radek
 * 
 * Created on 17 July 2013, 11:09
 */

#include "LfcRepCommand.h"

LfcRepCommand::LfcRepCommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LCG_REP;
    this->stringName = "LCG_REP";
}

LfcRepCommand::~LfcRepCommand() {
}

