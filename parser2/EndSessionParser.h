/* 
 * File:   EndSessionParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 15:14
 */

#ifndef ENDSESSIONPARSER_H
#define	ENDSESSIONPARSER_H

using namespace std;

#include "../Functions.h"
#include "CommandParser.h"

class EndSessionParser : public CommandParser {
public:

    EndSessionParser() {
        function = ENDSESS;
    }

protected:

    virtual void parseState1(Row * parsedRow) {
        endTime = parsedRow->GetTime();
        int returnCode = atoi(parsedRow->GetRemain().substr(8, 1).c_str());
        command = new Command(function, returnCode);
        parsedRow->SetParsed(true);
        state = finishState;
    }
};

#endif	/* ENDSESSIONPARSER_H */

