/* 
 * File:   LfcMkdirCommand.cpp
 * Author: radek
 * 
 * Created on 17 July 2013, 13:54
 */

#include "LfcMkdirCommand.h"

LfcMkdirCommand::LfcMkdirCommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LFC_MKDIR;
    this->stringName = "LFC_MKDIR";
}

LfcMkdirCommand::~LfcMkdirCommand() {
}

