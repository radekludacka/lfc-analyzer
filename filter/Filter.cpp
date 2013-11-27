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

//    if (! SomeToFilter(arguments)) {
//        return commands;
//    }
//    
    vector<LfcCommand *> * filteredCommands = new vector<LfcCommand *>;

    vector<LfcCommand *>::const_iterator it1;
    for (it1 = commands->begin(); it1 != commands->end(); ++it1) {
        LfcCommand * command = *it1;
        if (this->Contains(command, arguments)) {
            filteredCommands->push_back(command);
        }
    }

    return filteredCommands;
}

//bool Filter::SomeToFilter(Arguments * arguments) {
//    if (arguments->GetCommmandValueToFilter() != LCG_UNKNOWN) {
//        return true;
//    }
//    if (arguments->GetSiteValueToFilter() != NULL) {
//        return true;
//    }
//    if (arguments->GetUserValueToFilter() != NULL) {
//        return true;
//    }
//    if (arguments->GetFileValueToFilter() != NULL) {
//        return true;
//    }
//    if (arguments->IsSetSuccess()) {
//        return true;
//    }
//    return false;
//}

bool Filter::Contains(LfcCommand * command, Arguments * arguments) {
    LFCCommandName commandName = arguments->GetCommmandValueToFilter();
    if (commandName != LCG_UNKNOWN and command->GetName() != commandName) {
        return false;
    }
    if (!IsIn(arguments->GetSiteValueToFilter(), command->GetSite()->GetName())) {
        return false;
    }
    if (!IsIn(arguments->GetUserValueToFilter(), command->GetUser()->GetName())) {
        return false;
    }
    if (!IsIn(arguments->GetFileValueToFilter(), command->GetFile())) {
        return false;
    }
    if (arguments->IsSetSuccess()) {
        if (command->IsFailed() != arguments->GetSuccessValueToFilter()) {
            return false;
        }
    }
    return true;
}

bool Filter::IsIn(const char* a, std::string b) {
    if (a != NULL) {
        if (std::string::npos == b.find(a)) {
            return false;
        }
    }
    return true;
}