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

set<string> SuccessSorter::ExtractByString(vector<LfcCommand *> * commands) {
    set<string> commandNames;
    commandNames.insert("true");
    commandNames.insert("false");
    return commandNames;
}

string SuccessSorter::GetItemToSort(LfcCommand * command) {
    if (command->IsFailed()){
        return "true";
    }
    return "false";
}
