/* 
 * File:   LstatParser.h
 * Author: radek
 *
 * Created on 10 July 2013, 10:25
 */

#ifndef LSTATPARSER_H
#define	LSTATPARSER_H

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"

using namespace std;

class LstatParser : virtual public CommandParser {
public:

    LstatParser() {
        parseState1Start = 16;
        parseState2Start = 8;
        function = LSTAT;
    }
};

#endif	/* LSTATPARSER_H */

