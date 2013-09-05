/* 
 * File:   StartTransaction.h
 * Author: radek
 *
 * Created on 11 July 2013, 15:39
 */

#ifndef STARTTRANSACTION_H
#define	STARTTRANSACTION_H

//11/30 04:03:02.405 16392,2 Cns_srv_starttrans: NS092 - starttrans request by /DC=es/DC=irisgrid/O=ugr/CN=gines.rubio (491,117,104) from milky21.ncg.ingrid.pt
//11/30 04:03:02.405 16392,2 Cns_srv_starttrans: NS098 - starttrans (1.11.16-3)
//11/30 04:03:02.405 16392,2 Cns_srv_starttrans: returns 0

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

