/* 
 * File:   StatgParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 15:46
 */

#ifndef STATGPARSER_H
#define	STATGPARSER_H

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"

using namespace std;

class StatgParser : virtual public CommandParser {
public:

    StatgParser() {
        parseState1Start = 14;
        parseState2Start = 8;
        function = STATG;
    }

    virtual void parseState2(Row * parsedRow) {
        if (parsedRow->GetRemain().find("return") != 0){
            information = parsedRow->GetRemain();
            state = 2;
            parsedRow->SetParsed(true);
        } else {
            CommandParser::parseState2(parsedRow);
        }
    }

    virtual void parseState3(Row * parsedRow) {
        CommandParser::parseState2(parsedRow);
    }
};

#endif	/* STATGPARSER_H */

