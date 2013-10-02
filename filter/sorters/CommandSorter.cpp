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

string CommandSorter::GetItemToSort(LfcCommand * command) {
    return command->GetStringName();
}