/* 
 * File:   Sorter.cpp
 * Author: radek
 * 
 * Created on 30 July 2013, 07:46
 */

#include "Sorter.h"

Sorter::Sorter(){
    this->subSorter = NULL;
}

Sorter::Sorter(Sorter * subSorter) {
    this->subSorter = subSorter;
}

Sorter::~Sorter() {
    if (this->subSorter != NULL) {
        delete subSorter;
    }
}

vector<LfcCommand * > * Sorter::Sort(vector<LfcCommand*> * commands) {

    if (commands->size() < 3) {
        return commands;
    }

    vector<LfcCommand *> * sortedCommands = new vector<LfcCommand *>;

    set<string> extractedValues = this->ExtractByString(commands);

    set<string>::iterator setIterator;
    for (setIterator = extractedValues.begin(); setIterator != extractedValues.end(); ++setIterator) {

        string commandName = *setIterator;
        vector<LfcCommand *> * notSortedCommands = new vector<LfcCommand *>;

        vector<LfcCommand *>::const_iterator iterator;
        for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
            LfcCommand * command = *iterator;

            if (this->CompareCommandValue(command, commandName)) {
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

set<string> Sorter::ExtractByString(vector<LfcCommand *> * commands) {
    set<string> items;
    vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;
        string siteName = this->GetItemToSort(command);
        items.insert(siteName);
    }
    return items;
}

bool Sorter::CompareCommandValue(LfcCommand * command, string value) {
    if (this->GetItemToSort(command).compare(value) == 0) {
        return true;
    }
    return false;
}

