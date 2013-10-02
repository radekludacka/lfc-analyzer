/* 
 * File:   NullSorter.cpp
 * Author: radek
 * 
 * Created on 02 October 2013, 11:47
 */

#include "NullSorter.h"

NullSorter::NullSorter() {
}

NullSorter::NullSorter(Sorter* subSorter) : Sorter(subSorter) {
}

NullSorter::~NullSorter() {
}

vector<LfcCommand * > * NullSorter::Sort(vector<LfcCommand*> * commands) {
    return commands;
}

bool NullSorter::CompareCommandValue(LfcCommand * command, string value) {
    throw "Not implemented method";
}

set<string> NullSorter::ExtractByString(vector<LfcCommand *> * commands){
    throw "Not implemented method";
}

string NullSorter::GetItemToSort(LfcCommand * command) {
    throw "Not implemented method";
}

