/* 
 * File:   CreatParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 16:36
 */

#ifndef CREATPARSER_H
#define	CREATPARSER_H

//11/30 04:03:02.655 16392,2 Cns_srv_creat: NS092 - creat request by /DC=es/DC=irisgrid/O=ugr/CN=gines.rubio (491,117,104) from milky21.ncg.ingrid.pt
//11/30 04:03:02.655 16392,2 Cns_srv_creat: NS098 - creat /grid/auger/prod/GenDisIronEpos_gr213_simADSTv2r7p7/en19.000/th0.65/027265/DAT272656_04.offline-v2r7p7.small.tar 78ab5ae4-e323-4c76-b45f-a0f11ebb915f 664 22
//11/30 04:03:02.660 16392,2 Cns_srv_creat: file 27140642 created
//11/30 04:03:02.661 16392,2 Cns_srv_creat: returns 0

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"

using namespace std;

class CreatParser : virtual public CommandParser {
public:

    CreatParser() {
        parseState1Start = 14;
        parseState2Start = 8;
//        function = STATG;
        function = CREAT;
    }

    virtual void parseState2(Row * parsedRow) {
        information = parsedRow->GetRemain();
        state = 2;
        parsedRow->SetParsed(true);
//        function = CREAT;
    }

    virtual void parseState3(Row * parsedRow) {
        CommandParser::parseState2(parsedRow);
//        state = finishState;
    }
};

#endif	/* CREATPARSER_H */

