/* 
 * File:   StartTransaction.h
 * Author: radek
 *
 * Created on 11 July 2013, 15:39
 */

#ifndef STARTTRANSACTION_H
#define	STARTTRANSACTION_H

#include "CommandParser.h"
#include "../Functions.h"
#include "../LogTime.h"
#include "Row.h"

using namespace std;

class StartTransactionParser : virtual public CommandParser {
public:

    StartTransactionParser() {
        parseState1Start = 16;
        parseState2Start = 8;
        function = STARTTRANS;
    }

    virtual void parseState1(Row * parsedRow) {
        parsedRow->SetParsed(true);
        state = 1;
    }
};

#endif	/* STARTTRANSACTION_H */

