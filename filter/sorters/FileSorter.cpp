/* 
 * File:   FileSorter.cpp
 * Author: radek
 * 
 * Created on 30 July 2013, 16:54
 */

#include "FileSorter.h"

FileSorter::FileSorter() {
}

FileSorter::FileSorter(Sorter* subSorter) : Sorter(subSorter) {
}

FileSorter::~FileSorter() {
}

vector<LfcCommand * > * FileSorter::Sort(vector<LfcCommand*> * commands) {

    if (commands->size() < 3) {
        return commands;
    }

    vector<LfcCommand *> * sortedCommands = new vector<LfcCommand *>;

    set<string> fileNames = ExtractByString(commands);

    set<string>::iterator setIterator;
    for (setIterator = fileNames.begin(); setIterator != fileNames.end(); ++setIterator) {

        string fileName = *setIterator;
        vector<LfcCommand *> * fileCommands = new vector<LfcCommand *>;

        vector<LfcCommand *>::const_iterator iterator;
        for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
            LfcCommand * command = *iterator;

            if (command->GetFile().compare(fileName) == 0) {
                fileCommands->push_back(command);
            }
        }

        if (subSorter != NULL) {
            fileCommands = this->subSorter->Sort(fileCommands);
        }

        sortedCommands->insert(sortedCommands->end(), fileCommands->begin(), fileCommands->end());
    }

    return sortedCommands;
}

set<string> FileSorter::ExtractByString(vector<LfcCommand *> * commands) {
    set<string> fileNames;
    vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;
        string siteName = command->GetFile();
        fileNames.insert(siteName);
    }
    return fileNames;
}
