/* 
 * File:   DelReplicaParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 13:22
 */

#ifndef DELREPLICAPARSER_H
#define	DELREPLICAPARSER_H

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"
#include "../Functions.h"

using namespace std;

class DelReplicaParser : virtual public CommandParser {
public:

    DelReplicaParser() {
        parseState1Start = 19;
        parseState2Start = 8;
        function = DELREPLICA;
    }
};

#endif	/* DELREPLICAPARSER_H */

