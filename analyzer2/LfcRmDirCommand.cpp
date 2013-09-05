/* 
 * File:   LfcRmDirCommand.cpp
 * Author: radek
 * 
 * Created on 27 July 2013, 14:06
 */

#include "LfcRmDirCommand.h"

LfcRmDirCommand::LfcRmDirCommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LCG_RM;
    this->stringName = "LCG_RM";
}

LfcRmDirCommand::~LfcRmDirCommand() {
}

