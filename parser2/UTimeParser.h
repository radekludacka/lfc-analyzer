/* 
 * File:   UTimeParser.h
 * Author: radek
 *
 * Created on 22 July 2013, 14:39
 */

#ifndef UTIMEPARSER_H
#define	UTIMEPARSER_H

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"
#include "../Functions.h"

using namespace std;

//11/30 07:30:30.424 16392,2 Cns_srv_utime: NS092 - utime request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec (557,120,138,143) from nagios.egee.cesnet.cz
//11/30 07:30:30.424 16392,2 Cns_srv_utime: NS098 - utime /grid/ops/file-lfc-probe-lfc1.egee.cesnet.cz 0
//11/30 07:30:30.427 16392,2 Cns_srv_utime: returns 0

class UTimeParser : virtual public CommandParser {
public:

    UTimeParser() {
        parseState1Start = 14;
        parseState2Start = 8;
        function = UTIME;
    }
};

#endif	/* UTIMEPARSER_H */

