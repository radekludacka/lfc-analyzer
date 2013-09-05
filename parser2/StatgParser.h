/* 
 * File:   StatgParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 15:46
 */

#ifndef STATGPARSER_H
#define	STATGPARSER_H

//11/30 04:03:02.510 16392,2 Cns_srv_statg: NS092 - statg request by /DC=es/DC=irisgrid/O=ugr/CN=gines.rubio (491,117,104) from milky21.ncg.ingrid.pt
//11/30 04:03:02.510 16392,2 Cns_srv_statg: NS098 - statg /grid/auger/prod/GenDisIronEpos_gr213_simADSTv2r7p7/en19.000/th0.65/027265 
//11/30 04:05:56.209 16392,2 sendrep: GUID mismatch
//11/30 04:05:56.209 16392,2 Cns_srv_statg: returns 22

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

