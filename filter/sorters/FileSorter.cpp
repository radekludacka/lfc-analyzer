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

string FileSorter::GetItemToSort(LfcCommand * command) {
    return command->GetFile();
}
