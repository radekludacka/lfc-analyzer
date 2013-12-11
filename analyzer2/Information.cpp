/* 
 * File:   Information.cpp
 * Author: radek
 * 
 * Created on 23 July 2013, 15:38
 */

#include "Information.h"

Information::Information() {
    this->info = ""; 
}

Information::Information(const Information& orig) {
}

Information::~Information() {
}

void Information::SetInformation(string information){
    this->info = information;
}

string Information::GetInformation() const {
    return info;
}
