/* 
 * File:   InformationSorter.cpp
 * Author: radek
 * 
 * Created on 11 December 2013, 12:27
 */

#include "InformationSorter.h"

InformationSorter::InformationSorter() {
}

InformationSorter::InformationSorter(Sorter* subSorter) : Sorter(subSorter) {
}

InformationSorter::~InformationSorter() {
}

string InformationSorter::GetItemToSort(LfcCommand * command) {
    Information * info = command->GetInformation();
    if (info == NULL) {
        return "";
    }
    return command->GetInformation()->GetInformation();
}

