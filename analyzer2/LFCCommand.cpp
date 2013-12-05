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
        Information * informationP = NULL) {
    startTime = startT;
    endTime = endT;
    file = fileName;
    user = userName;
    site = siteName;
    isFail = fail;
    information = informationP;
    standardTimeErrorDuration = 0;
    averageTimeDuration = endTime->minus(startTime);
    minTimeDuration = new LogTime(averageTimeDuration->miliseconds());
    maxTimeDuration = new LogTime(averageTimeDuration->miliseconds());
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
    standardTimeErrorDuration = 0;
    averageTimeDuration = endTime->minus(startTime);
    minTimeDuration = new LogTime(averageTimeDuration->miliseconds());
    maxTimeDuration = new LogTime(averageTimeDuration->miliseconds());
}

LfcCommand::~LfcCommand() {
    //    delete startTime;
    //    if (endTime != NULL) {
    //        delete endTime;
    //    }
    if (user != NULL) {
        delete user;
    }
    if (site != NULL) {
        delete site;
    }
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

void LfcCommand::SetStandardTimeErrorDuration(double standardTimeErrorDuration) {
    this->standardTimeErrorDuration = standardTimeErrorDuration;
}

double LfcCommand::GetStandardTimeErrorDuration() const {
    return standardTimeErrorDuration;
}

void LfcCommand::SetAverageTimeDuration(LogTime* averageTimeDuration) {
    this->averageTimeDuration = averageTimeDuration;
}

LogTime* LfcCommand::GetAverageTimeDuration() const {
    return averageTimeDuration;
}

void LfcCommand::SetMinTimeDuration(LogTime* minTimeDuration) {
    this->minTimeDuration = minTimeDuration;
}

LogTime* LfcCommand::GetMinTimeDuration() const {
    return minTimeDuration;
}

void LfcCommand::SetMaxTimeDuration(LogTime* maxTimeDuration) {
    this->maxTimeDuration = maxTimeDuration;
}

LogTime* LfcCommand::GetMaxTimeDuration() const {
    return maxTimeDuration;
}