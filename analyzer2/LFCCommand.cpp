/* 
 * File:   LFCCommand.cpp
 * Author: radek
 * 
 * Created on 12 July 2013, 13:19
 */

#include "LfcCommand.h"

LfcCommand::LfcCommand(
        LogTime * startT, 
        LogTime * endT, 
        string fileName, 
        User * userName, 
        Site * siteName, 
        bool fail,
        Information * informationP=NULL) {
    startTime = startT;
    endTime = endT;
    file = fileName;
    user = userName;
    site = siteName;
    isFail = fail;
    information = informationP;
}

LfcCommand::LfcCommand(
        LogTime * startT, 
        LogTime * endT, 
        string fileName, 
        User * userName, 
        Site * siteName, 
        bool fail) {
    if (userName->GetName().compare("") == 0) {
        userName->SetName("UNKNOWN");
    }
    startTime = startT;
    endTime = endT;
    file = fileName;
    user = userName;
    site = siteName;
    isFail = fail;
    information = NULL;
}

LfcCommand::~LfcCommand() {
}

User* LfcCommand::GetUser() const {
    return user;
}

string LfcCommand::GetFile() const {
    return file;
}

LogTime* LfcCommand::GetEndTime() const {
    return endTime;
}

LogTime* LfcCommand::GetStartTime() const {
    return startTime;
}

LFCCommandName LfcCommand::GetName() const {
    return name;
}

Site* LfcCommand::GetSite() const {
    return site;
}

bool LfcCommand::IsFailed() const {
    return isFail;
}

Information* LfcCommand::GetInformation() const {
    return information;
}

string LfcCommand::GetStringName() const {
    return stringName;
}