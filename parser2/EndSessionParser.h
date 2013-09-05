/* 
 * File:   EndSessionParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 15:14
 */

#ifndef ENDSESSIONPARSER_H
#define	ENDSESSIONPARSER_H

//11/30 04:03:00.825 16392,1 Cns_srv_endsess: NS092 - endsess request by /DC=es/DC=irisgrid/O=ugr/CN=gines.rubio (491,117,104) from wn-206-08-27-02-a.cr.cnaf.infn.it
//11/30 04:03:00.825 16392,1 Cns_srv_endsess: returns 0

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

