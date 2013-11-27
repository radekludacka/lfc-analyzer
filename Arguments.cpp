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
    timeOrder = -1;

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
    std::map<string, LFCCommandName> commandMap;
    
//    if(commandMap.find(commandName) == commandMap.end())
//    {
//        std::string exception = "command " + commandName + " is not allowed";
//        cout << exception << endl;
////        throw exception;
//    }
    
    commandMap["lfc-ls"] = LFC_LS;
    commandMap["lcg-cr"] = LCG_CR;
    commandMap["lcg-rep"] = LCG_REP;
    commandMap["lfc-mkdir"] = LFC_MKDIR;
    commandMap["lcg-cp"] = LCG_CP;
    commandMap["lcg-del"] = LCG_DEL;
    commandMap["srv-err"] = LCG_NONE;
    commandMap["lcg-utime"] = LCG_UTIME;
    commandMap["lcg-pingdb"] = LCG_PINGDB;
    commandMap["lcg-lr"] = LCG_LR;
    commandMap["lcg-aa"] = LCG_AA;
    commandMap["lcg-rm"] = LCG_RM;
    
    return commandMap.at(commandName);
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

int Arguments::GetTimeOrder(){
    return timeOrder;
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

void Arguments::SetTimeOrder(int order) {
    timeOrder = order;
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
