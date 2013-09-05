/* 
 * File:   StatrParser.h
 * Author: radek
 *
 * Created on 19 July 2013, 13:05
 */

#ifndef STATRPARSER_H
#define	STATRPARSER_H

//07/18 15:46:24.733 20713,1 Cns_srv_statr: NS092 - statr request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz
//07/18 15:46:24.733 20713,1 Cns_srv_statr: NS098 - statr srm://dpm1.egee.cesnet.cz/dpm/cesnet.cz/home/voce/generated/2013-07-18/fileda937a3c-4112-4d56-a34e-9866967cfe44
//07/18 15:46:24.734 20713,1 Cns_srv_statr: returns 0

using namespace std;

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"

class StatrParser : public CommandParser {
public:

    StatrParser() {
        parseState1Start = 14;
        parseState2Start = 8;
        function = STATR;
    }
private:

};

#endif	/* STATRPARSER_H */

