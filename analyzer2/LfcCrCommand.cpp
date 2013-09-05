/* 
 * File:   LfcCrCommand.cpp
 * Author: radek
 * 
 * Created on 15 July 2013, 17:59
 */

#include "LfcCrCommand.h"

LfcCrCommand::LfcCrCommand(
        LogTime * startT, 
        LogTime * endT, 
        string fileName, 
        User * userName, 
        Site * site, 
        bool fail,
        Information * information)
: LfcCommand(startT, endT, fileName, userName, site, fail, information) {
    this->name = LCG_CR;
    this->stringName = "LCG_CR";
}

LfcCrCommand::~LfcCrCommand() {
}

