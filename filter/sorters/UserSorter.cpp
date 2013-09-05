/* 
 * File:   UserSorter.cpp
 * Author: radek
 * 
 * Created on 30 July 2013, 07:57
 */


#include "UserSorter.h"

UserSorter::UserSorter() {
}

UserSorter::~UserSorter() {
}

UserSorter::UserSorter(Sorter* subSorter) : Sorter(subSorter) {
}

vector<LfcCommand * > * UserSorter::Sort(vector<LfcCommand*> * commands) {

    if (commands->size() < 3) {
        return commands;
    }

    vector<LfcCommand *> * sortedCommands = new vector<LfcCommand *>;

    set<string> userNames = ExtractByString(commands);

    set<string>::iterator setIterator;
    for (setIterator = userNames.begin(); setIterator != userNames.end(); ++setIterator) {

        string userName = *setIterator;
        vector<LfcCommand *> * userCommands = new vector<LfcCommand *>;

        vector<LfcCommand *>::const_iterator iterator;
        for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
            LfcCommand * command = *iterator;

            if (command->GetUser()->GetName().compare(userName) == 0) {
                userCommands->push_back(command);
            }
        }

        if (subSorter != NULL) {
            userCommands = this->subSorter->Sort(userCommands);
        }

        sortedCommands->insert(sortedCommands->end(), userCommands->begin(), userCommands->end());
    }

    return sortedCommands;
}

set<string> UserSorter::ExtractByString(vector<LfcCommand *> * commands) {
    set<string> userNames;
    vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;
        string userName = command->GetUser()->GetName();
        userNames.insert(userName);
    }
    return userNames;
}


