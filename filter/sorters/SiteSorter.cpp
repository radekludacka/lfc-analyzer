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

string SiteSorter::GetItemToSort(LfcCommand * command) {
    return command->GetSite()->GetName();
}

