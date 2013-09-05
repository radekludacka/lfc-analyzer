/* 
 * File:   GetReplicaParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 13:43
 */

#ifndef GETREPLICAPARSER_H
#define	GETREPLICAPARSER_H

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"
#include "../Functions.h"

using namespace std;

class GetReplicaParser : virtual public CommandParser {
public:

    GetReplicaParser() {
        parseState1Start = 20;
        parseState2Start = 8;
        function = GETREPLICA;
    }
};

#endif	/* GETREPLICAPARSER_H */

