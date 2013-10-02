/* 
 * File:   Arguments.cpp
 * Author: radek
 * 
 * Created on 26 September 2013, 12:28
 */

#include "Arguments.h"

Arguments::Arguments() {
    fileOrder = -1;
    siteOrder = -1;
    userOrder = -1;
    commandOrder = -1;
    resultTypeOrder = -1;

    filteredSiteValue = NULL;
    filteredUserValue = NULL;
    filteredFileValue = NULL;
    filteredCommandValue = LCG_UNKNOWN;
    filteredSuccessValue = false;
    isSetSuccess = false;
}

Arguments::Arguments(const Arguments& orig) {
}

Arguments::~Arguments() {
}

LFCCommandName Arguments::CommandConverter(std::string commandName) {
    if (commandName.compare("lfc-ls") == 0) {
        return LFC_LS;
    } else if (commandName.compare("lcg-cr") == 0) {
        return LCG_CR;
    } else if (commandName.compare("lcg-rep") == 0) {
        return LCG_REP;
    } else if (commandName.compare("lfc-mkdir") == 0) {
        return LFC_MKDIR;
    } else if (commandName.compare("lcg-cp") == 0) {
        return LCG_CP;
    } else if (commandName.compare("lcg-del") == 0) {
        return LCG_DEL;
    } else if (commandName.compare("srv-err") == 0) {
        return LCG_NONE;
    } else if (commandName.compare("lcg-utime") == 0) {
        return LCG_UTIME;
    } else if (commandName.compare("lcg-pingdb") == 0) {
        return LCG_PINGDB;
    } else if (commandName.compare("lcg-lr") == 0) {
        return LCG_LR;
    } else if (commandName.compare("lcg-aa") == 0) {
        return LCG_AA;
    } else if (commandName.compare("lcg-rm") == 0) {
        return LCG_RM;
    } else {
        std::string exception = "command " + commandName + " is not allowed";
        throw exception;
    }
}

bool Arguments::FailedConverter(std::string failedValue) {
    if (failedValue.compare("true") == 0) {
        return true;
    } else if (failedValue.compare("false") == 0) {
        return false;
    } else {
        cout << "failed value " << failedValue << " is not allowed" << endl;
        return NULL;
    }
}

int Arguments::GetFileOrder() {
    return fileOrder;
}

int Arguments::GetSiteOrder() {
    return siteOrder;
}

int Arguments::GetUserOrder() {
    return userOrder;
}

int Arguments::GetCommandOrder() {
    return commandOrder;
}

int Arguments::GetResultTypeOrder() {
    return resultTypeOrder;
}

const char* Arguments::GetSiteValueToFilter() {
    return filteredSiteValue;
}

const char* Arguments::GetUserValueToFilter() {
    return filteredUserValue;
}

const char* Arguments::GetFileValueToFilter() {
    return filteredFileValue;
}

LFCCommandName Arguments::GetCommmandValueToFilter() {
    return filteredCommandValue;
}

bool Arguments::GetSuccessValueToFilter() {
    return filteredSuccessValue;
}

bool Arguments::IsSetSuccess() {
    return isSetSuccess;
}

const char* Arguments::GetFilePath() {
    return filePath;
}




void Arguments::SetFileOrder(int order) {
    fileOrder = order;
}

void Arguments::SetSiteOrder(int order) {
    siteOrder = order;
}

void Arguments::SetUserOrder(int order) {
    userOrder = order;
}

void Arguments::SetCommandOrder(int order) {
    commandOrder = order;
}

void Arguments::SetResultTypeOrder(int order) {
    resultTypeOrder = order;
}

void Arguments::SetSiteValueToFilter(const char* value) {
    filteredSiteValue = value;
}

void Arguments::SetUserValueToFilter(const char* value) {
    filteredUserValue = value;
}

void Arguments::SetFileValueToFilter(const char* value) {
    filteredFileValue = value;
}

void Arguments::SetCommmandValueToFilter(const char* value) {
    filteredCommandValue = this->CommandConverter(value);
}

void Arguments::SetSuccessValueToFilter(const char* value) {
    isSetSuccess = true;
    filteredSuccessValue = FailedConverter(value);
}

void Arguments::SetFilePath(const char* value) {
    filePath = value;
}
