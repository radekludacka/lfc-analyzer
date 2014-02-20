/* 
 * File:   StartSessionParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 13:09
 */

#ifndef STARTSESSIONPARSER_H
#define	STARTSESSIONPARSER_H

using namespace std;

#include "../Functions.h"
#include "CommandParser.h"

class StartSessionParser : public CommandParser {
public:

    StartSessionParser() {
        parseState1Start = 16;
        parseState2Start = 8;
        function = STARTSESS;
    }

protected:

    virtual void parseState1(Row * parsedRow) {
        parsedRow->SetParsed(true);
        state = 1;
    }
};

#endif	/* STARTSESSIONPARSER_H */

