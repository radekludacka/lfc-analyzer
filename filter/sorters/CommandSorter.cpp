/* 
 * File:   CommandSorter.cpp
 * Author: radek
 * 
 * Created on 30 July 2013, 20:52
 */

#include "CommandSorter.h"

CommandSorter::CommandSorter() {
}

CommandSorter::CommandSorter(Sorter* subSorter) : Sorter(subSorter) {
}

CommandSorter::~CommandSorter() {
}

vector<LfcCommand * > * CommandSorter::Sort(vector<LfcCommand*> * commands) {

    if (commands->size() < 3) {
        return commands;
    }

    vector<LfcCommand *> * sortedCommands = new vector<LfcCommand *>;

    set<string> commandNames = ExtractByString(commands);

    set<string>::iterator setIterator;
    for (setIterator = commandNames.begin(); setIterator != commandNames.end(); ++setIterator) {

        string commandName = *setIterator;
        vector<LfcCommand *> * notSortedCommands = new vector<LfcCommand *>;

        vector<LfcCommand *>::const_iterator iterator;
        for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
            LfcCommand * command = *iterator;

            if (command->GetStringName().compare(commandName) == 0) {
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

set<string> CommandSorter::ExtractByString(vector<LfcCommand *> * commands) {
    set<string> commandNames;
    vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;
        string siteName = command->GetStringName();
        commandNames.insert(siteName);
    }
    return commandNames;
}