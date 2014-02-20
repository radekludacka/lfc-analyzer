/* 
 * File:   StatrParser.h
 * Author: radek
 *
 * Created on 19 July 2013, 13:05
 */

#ifndef STATRPARSER_H
#define	STATRPARSER_H

using namespace std;

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"

class StatrParser : public CommandParser {
public:

    StatrParser() {
        parseState1Start = 14;
        parseState2Start = 8;
        function = STATR;
    }
private:

};

#endif	/* STATRPARSER_H */

