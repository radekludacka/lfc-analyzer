/* 
 * File:   SuccessSorter.cpp
 * Author: radek
 * 
 * Created on 31 July 2013, 09:07
 */

#include "SuccessSorter.h"

SuccessSorter::SuccessSorter() {
}

SuccessSorter::SuccessSorter(Sorter* subSorter) : Sorter(subSorter) {
}

SuccessSorter::~SuccessSorter() {
}

vector<LfcCommand * > * SuccessSorter::Sort(vector<LfcCommand*> * commands) {

    if (commands->size() < 3) {
        return commands;
    }

    vector<LfcCommand *> * sortedCommands = new vector<LfcCommand *>;

    set<bool> resultTypes = ExtractByString(commands);

    set<bool>::iterator setIterator;
    for (setIterator = resultTypes.begin(); setIterator != resultTypes.end(); ++setIterator) {

        bool resultType = *setIterator;
        
        vector<LfcCommand *> * notSortedCommands = new vector<LfcCommand *>;

        vector<LfcCommand *>::const_iterator iterator;
        for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
            LfcCommand * command = *iterator;

            if (command->IsFailed() == resultType) {
                notSortedCommands->push_back(command);
            }
        }

        if (subSorter != NULL) {
            notSortedCommands = this->subSorter->Sort(notSortedCommands);
        }

        sortedCommands->insert(sortedCommands->end(), notSortedCommands->begin(), notSortedCommands->end());
    }

    return sortedCommands;
}

set<bool> SuccessSorter::ExtractByString(vector<LfcCommand *> * commands) {
    set<bool> commandNames;
    commandNames.insert(true);
    commandNames.insert(false);
    return commandNames;
}