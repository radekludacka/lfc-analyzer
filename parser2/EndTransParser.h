/* 
 * File:   EndTransParser.h
 * Author: radek
 *
 * Created on 16 July 2013, 10:32
 */

#ifndef ENDTRANSPARSER_H
#define	ENDTRANSPARSER_H

using namespace std;

#include "../Functions.h"
#include "CommandParser.h"

class EndTransParser : public CommandParser {
public:

    EndTransParser() {
        function = ENDTRANS;
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

#endif	/* ENDTRANSPARSER_H */

