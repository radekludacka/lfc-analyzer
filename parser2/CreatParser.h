/* 
 * File:   CreatParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 16:36
 */

#ifndef CREATPARSER_H
#define	CREATPARSER_H

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"

using namespace std;

class CreatParser : virtual public CommandParser {
public:

    CreatParser() {
        parseState1Start = 14;
        parseState2Start = 8;
        function = CREAT;
    }

    virtual void parseState2(Row * parsedRow) {
        information = parsedRow->GetRemain();
        state = 2;
        parsedRow->SetParsed(true);
    }

    virtual void parseState3(Row * parsedRow) {
        CommandParser::parseState2(parsedRow);
    }
};

#endif	/* CREATPARSER_H */

