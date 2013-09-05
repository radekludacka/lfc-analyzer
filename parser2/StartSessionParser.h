/* 
 * File:   StartSessionParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 13:09
 */

#ifndef STARTSESSIONPARSER_H
#define	STARTSESSIONPARSER_H

//11/30 04:03:00.488 16392,1 Cns_srv_startsess: NS092 - startsess request by /DC=es/DC=irisgrid/O=ugr/CN=gines.rubio (491,117,104) from wn-206-08-27-02-a.cr.cnaf.infn.it
//11/30 04:03:00.488 16392,1 Cns_srv_startsess: NS098 - startsess ()
//11/30 04:03:00.488 16392,1 Cns_srv_startsess: returns 0

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
        //            filePath = parsedRow->GetRemain().substr(16);
        parsedRow->SetParsed(true);
        state = 1;
    }
};

#endif	/* STARTSESSIONPARSER_H */

