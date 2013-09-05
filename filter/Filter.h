/* 
 * File:   Filter.h
 * Author: radek
 *
 * Created on 05 August 2013, 20:53
 */

#ifndef FILTER_H
#define	FILTER_H

#include <string>
#include <vector>
#include "../analyzer2/LfcCommand.h"
#include "../analyzer2/CommandName.h"

using namespace std;

class Filter {
public:
    Filter();
    virtual ~Filter();
    vector<LfcCommand*> * Filtrate(vector<LfcCommand*> * commands);
    void SetSearchedFileString(string pattern);
    void SetSearchedSiteString(string pattern);
    void SetSearchedUserString(string pattern);
    void SetSearchedCommand(LFCCommandName commandName);
    void SetSearchedSuccessValue(bool value);
private:
    bool filterFile;
    bool filterSite;
    bool filterUser;
    bool filterCommand;
    bool filterSuccessValue;
    
    string filteredValueFile;
    string filteredValueSite;
    string filteredValueUser;
    LFCCommandName filteredValueCommand;
    bool filteredValueSuccess;
};

#endif	/* FILTER_H */

