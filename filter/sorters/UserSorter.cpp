/* 
 * File:   UserSorter.cpp
 * Author: radek
 * 
 * Created on 30 July 2013, 07:57
 */


#include "UserSorter.h"

UserSorter::UserSorter() {
}

UserSorter::~UserSorter() {
}

UserSorter::UserSorter(Sorter* subSorter) : Sorter(subSorter) {
}

string UserSorter::GetItemToSort(LfcCommand * command) {
    return command->GetUser()->GetName();
}

