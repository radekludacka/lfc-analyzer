/* 
 * File:   Arguments.h
 * Author: radek
 *
 * Created on 26 September 2013, 12:28
 */

#ifndef ARGUMENTS_H
#define	ARGUMENTS_H

#include <string>
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>
#include <map>

#include "analyzer2/CommandName.h"

using namespace std;

class Arguments {
   
public:
    Arguments();
    Arguments(const Arguments& orig);
    virtual ~Arguments();

    int GetFileOrder();
    int GetSiteOrder();
    int GetUserOrder();
    int GetCommandOrder();
    int GetResultTypeOrder();
    int GetTimeOrder();

    const char* GetSiteValueToFilter();
    const char* GetUserValueToFilter();
    const char* GetFileValueToFilter();
    LFCCommandName GetCommmandValueToFilter();
    bool GetSuccessValueToFilter();
    bool IsSetSuccess();
    const char* GetFilePath();

    void SetFileOrder(int order);
    void SetSiteOrder(int order);
    void SetUserOrder(int order);
    void SetCommandOrder(int order);
    void SetResultTypeOrder(int order);
    void SetTimeOrder(int order);

    void SetSiteValueToFilter(const char* value);
    void SetUserValueToFilter(const char* value);
    void SetFileValueToFilter(const char* value);
    void SetCommmandValueToFilter(const char* value);
    void SetSuccessValueToFilter(const char* value);
    void SetFilePath(const char* value);
private:
    LFCCommandName CommandConverter(std::string commandName);
    bool FailedConverter(std::string failedValue);

    int fileOrder;
    int siteOrder;
    int userOrder;
    int commandOrder;
    int resultTypeOrder;
    int timeOrder;

    const char* filteredSiteValue;
    const char* filteredUserValue;
    const char* filteredFileValue;
    LFCCommandName filteredCommandValue;
    bool filteredSuccessValue;
    bool isSetSuccess;
    const char* filePath;
};

#endif	/* ARGUMENTS_H */

