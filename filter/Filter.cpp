/* 
 * File:   Filter.cpp
 * Author: radek
 * 
 * Created on 05 August 2013, 20:53
 */

#include "Filter.h"

Filter::Filter() {
    filterFile = false;
    filterSite = false;
    filterUser = false;
    filterCommand = false;
    filterSuccessValue = false;
}

Filter::~Filter() {
}

vector<LfcCommand*> * Filter::Filtrate(vector<LfcCommand*> * commands) {

    vector<LfcCommand *> * filteredCommands = new vector<LfcCommand *>;

    vector<LfcCommand *>::const_iterator it1;
    for (it1 = commands->begin(); it1 != commands->end(); ++it1) {
        LfcCommand * command = *it1;

        if (filterFile) {
            if (std::string::npos == command->GetFile().find(filteredValueFile)) {
                continue;
            }
        } 
        if (filterSite) {
            string siteName = command->GetSite()->GetName();
            if (std::string::npos == siteName.find(filteredValueSite)) {
                continue;
            }
        } 
        if (filterCommand) {
            LFCCommandName commandName = command->GetName();
            if (commandName != filteredValueCommand) {
                continue;
            }
        } 
        if (filterSuccessValue) {
            bool successValue = command->IsFailed();
            if (successValue != filteredValueSuccess) {
                continue;
            }
        } 
        if (filterUser) {
            string userName = command->GetUser()->GetName();
            if (std::string::npos == userName.find(filteredValueUser)) {
                continue;
            }
        }

        filteredCommands->push_back(command);
    }

    return filteredCommands;
}

void Filter::SetSearchedCommand(LFCCommandName commandName) {
    filterCommand = true;
    filteredValueCommand = commandName;
}

void Filter::SetSearchedFileString(string pattern) {
    filterFile = true;
    filteredValueFile = pattern;
}

void Filter::SetSearchedSiteString(string pattern) {
    filterSite = true;
    filteredValueSite = pattern;
}

void Filter::SetSearchedSuccessValue(bool value) {
    filterSuccessValue = true;
    filteredValueSuccess = value;
}

void Filter::SetSearchedUserString(string pattern) {
    filterUser = true;
    filteredValueUser = pattern;
}