/* 
 * File:   SiteSorter.cpp
 * Author: radek
 * 
 * Created on 30 July 2013, 14:42
 */

#include "SiteSorter.h"

SiteSorter::SiteSorter() {
}

SiteSorter::~SiteSorter() {
}

SiteSorter::SiteSorter(Sorter* subSorter) : Sorter(subSorter) {
}

vector<LfcCommand * > * SiteSorter::Sort(vector<LfcCommand*> * commands) {

    if (commands->size() < 3) {
        return commands;
    }

    vector<LfcCommand *> * sortedCommands = new vector<LfcCommand *>;

    set<string> siteNames = ExtractByString(commands);

    set<string>::iterator setIterator;
    for (setIterator = siteNames.begin(); setIterator != siteNames.end(); ++setIterator) {

        string siteName = *setIterator;
        vector<LfcCommand *> * siteCommands = new vector<LfcCommand *>;

        vector<LfcCommand *>::const_iterator iterator;
        for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
            LfcCommand * command = *iterator;

            if (command->GetSite()->GetName().compare(siteName) == 0) {
                siteCommands->push_back(command);
            }
        }

        if (subSorter != NULL) {
            siteCommands = this->subSorter->Sort(siteCommands);
        }

        sortedCommands->insert(sortedCommands->end(), siteCommands->begin(), siteCommands->end());
    }

    return sortedCommands;
}

set<string> SiteSorter::ExtractByString(vector<LfcCommand *> * commands) {
    set<string> siteNames;
    vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;
        string siteName = command->GetSite()->GetName();
        siteNames.insert(siteName);
    }
    return siteNames;
}

