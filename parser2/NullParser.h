/* 
 * File:   NullParser.h
 * Author: radek
 *
 * Created on 10 July 2013, 10:37
 */

#ifndef NULLPARSER_H
#define	NULLPARSER_H

using namespace std;

#include "CommandParser.h"
#include "Row.h"

class NullParser : virtual public CommandParser {
public:

    virtual void parseState1(Row * parsedRow) {
        state = 1;
    }

    virtual void parseState2(Row * parsedRow) {
        state = 2;
    }
};

#endif	/* NULLPARSER_H */

