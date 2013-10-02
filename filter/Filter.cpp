/* 
 * File:   Filter.cpp
 * Author: radek
 * 
 * Created on 05 August 2013, 20:53
 */

#include "Filter.h"

Filter::Filter() {
}

Filter::~Filter() {
}

vector<LfcCommand*> * Filter::Filtrate(vector<LfcCommand*> * commands, Arguments * arguments) {

    vector<LfcCommand *> * filteredCommands = new vector<LfcCommand *>;

    vector<LfcCommand *>::const_iterator it1;
    for (it1 = commands->begin(); it1 != commands->end(); ++it1) {
        LfcCommand * command = *it1;

        LFCCommandName commandName = arguments->GetCommmandValueToFilter();
        if (commandName != LCG_UNKNOWN and command->GetName() != commandName) {
            continue;
        }
        if (!isIn(arguments->GetSiteValueToFilter(), command->GetSite()->GetName())) {
            continue;
        }
        if (!isIn(arguments->GetUserValueToFilter(), command->GetUser()->GetName())) {
            continue;
        }
        if (!isIn(arguments->GetFileValueToFilter(), command->GetFile())) {
            continue;
        }
        if (arguments->IsSetSuccess()) {
            if (command->IsFailed() != arguments->GetSuccessValueToFilter()) {
                continue;
            }
        }
        filteredCommands->push_back(command);
    }

    return filteredCommands;
}

bool Filter::isIn(const char* a, std::string b) {
    if (a != NULL) {
        if (std::string::npos == b.find(a)) {
            return false;
        }
    }
    return true;
}