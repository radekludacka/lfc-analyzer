/* 
 * File:   GetPathParser.h
 * Author: radek
 *
 * Created on 27 July 2013, 11:14
 */

#ifndef GETPATHPARSER_H
#define	GETPATHPARSER_H

#include "CommandParser.h"

class GetPathParser : public CommandParser {
public:

    GetPathParser() {
        parseState2Start = 8;
        function = GETPATH;
    }

    virtual void parseState1(Row * parsedRow) {
        endTime = parsedRow->GetTime();
        int returnCode = atoi(parsedRow->GetRemain().substr(8, 1).c_str());
        command = new Command(function, returnCode);
        parsedRow->SetParsed(true);
        state = finishState;
    }
};

#endif	/* GETPATHPARSER_H */

