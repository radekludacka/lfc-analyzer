/* 
 * File:   Information.cpp
 * Author: radek
 * 
 * Created on 23 July 2013, 15:38
 */

#include "Information.h"

Information::Information() {
    this->informations = new vector<string>;
}

Information::Information(const Information& orig) {
}

Information::~Information() {
}

void Information::addInformation(string information){
    this->informations->push_back(information);
}
