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
}

