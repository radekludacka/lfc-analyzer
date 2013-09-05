/* 
 * File:   LfcLrCommand.cpp
 * Author: radek
 * 
 * Created on 24 July 2013, 16:28
 */

#include "LfcLrCommand.h"

LfcLrCommand::LfcLrCommand(
        LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail)
: LfcCommand(startT, endT, fileName, userName, site, fail) {
    this->name = LCG_LR;
    this->stringName = "LCG_LR";
}

LfcLrCommand::~LfcLrCommand() {
}

