/* 
 * File:   ServParser.h
 * Author: radek
 *
 * Created on 20 July 2013, 15:50
 */

#ifndef SERVABORTTRANSACTIONPARSER_H
#define	SERVABORTTRANSACTIONPARSER_H

using namespace std;

#include "../Functions.h"
#include "CommandParser.h"
#include "Command.h"

class ServAbortTransactionParser : public CommandParser {
public:

    ServAbortTransactionParser() {
        parseState1Start = 16;
        parseState2Start = 8;
        function = SERV_ABORTTRANS;
    }
    
    void parseState1(Row * parsedRow) {
        parseState2(parsedRow);
    }
};

#endif	/* SERVABORTTRANSACTIONPARSER_H */

