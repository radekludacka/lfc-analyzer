/* 
 * File:   UTimeParser.h
 * Author: radek
 *
 * Created on 22 July 2013, 14:39
 */

#ifndef UTIMEPARSER_H
#define	UTIMEPARSER_H

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"
#include "../Functions.h"

using namespace std;

class UTimeParser : virtual public CommandParser {
public:

    UTimeParser() {
        parseState1Start = 14;
        parseState2Start = 8;
        function = UTIME;
    }
};

#endif	/* UTIMEPARSER_H */

