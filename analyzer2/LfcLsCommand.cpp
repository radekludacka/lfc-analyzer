/* 
 * File:   LfcLsCommand.cpp
 * Author: radek
 * 
 * Created on 12 July 2013, 13:29
 */

#include "LfcLsCommand.h"
#include "CommandName.h"

LfcLsCommand::LfcLsCommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LFC_LS;
    this->stringName = "LFC_LS";
}

LfcLsCommand::~LfcLsCommand() {
}

