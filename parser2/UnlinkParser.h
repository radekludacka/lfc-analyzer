/* 
 * File:   UnlinkParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 14:54
 */

#ifndef UNLINKPARSER_H
#define	UNLINKPARSER_H

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"

using namespace std;

class UnlinkParser : virtual public CommandParser {
public:

    UnlinkParser() {
        parseState1Start = 15;
        parseState2Start = 9;
        function = UNLINK;
    }
};


#endif	/* UNLINKPARSER_H */

