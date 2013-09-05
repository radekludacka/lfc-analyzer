/* 
 * File:   UnlinkParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 14:54
 */

#ifndef UNLINKPARSER_H
#define	UNLINKPARSER_H

//11/30 04:03:00.758 16392,1 Cns_srv_unlink: NS092 - unlink request by /DC=es/DC=irisgrid/O=ugr/CN=gines.rubio (491,117,104) from wn-206-08-27-02-a.cr.cnaf.infn.it
//11/30 04:03:00.758 16392,1 Cns_srv_unlink: NS098 - unlink /grid/auger/prod/GenDisProtonQGSjetII_gr218_simADSTv2r7p7/en18.500/th0.65/032867/DAT328678_05.offline-v2r7p7.HdSimRecADST.root
//11/30 04:03:00.764 16392,1 Cns_srv_unlink: returns 0

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"

using namespace std;

class UnlinkParser : virtual public CommandParser {
public:

    UnlinkParser() {
        parseState1Start = 15;
        parseState2Start = 9;
        function = UNLINK;
    }
};


#endif	/* UNLINKPARSER_H */

