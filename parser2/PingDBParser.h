/* 
 * File:   PingDBParser.h
 * Author: radek
 *
 * Created on 22 July 2013, 15:53
 */

#ifndef PINGDBPARSER_H
#define	PINGDBPARSER_H

using namespace std;

#include "../Functions.h"
#include "CommandParser.h"
#include "Command.h"

//11/30 07:58:36.747 16392,20 Cns_pingdb: mysql_query error: MySQL server has gone away
//11/30 07:58:36.747 16392,20 Cns_pingdb: Trying to reconnect

class PingDBParser : public CommandParser {
protected:

    virtual void parseState0(Row * parsedRow) {
        startTime = parsedRow->GetTime();

        string remain = parsedRow->GetRemain();
        int startInfo = remain.find(':') + 2;
        information = remain.substr(startInfo);

        site = new Site("");
        user = new User("");
        command = new Command(PINGDB, 0);

        tid = parsedRow->GetTid();
        
        parsedRow->SetParsed(true);
        state = 0;
    }

    virtual void parseState1(Row * parsedRow) {
        endTime = parsedRow->GetTime();
        
        string remain = parsedRow->GetRemain();
        information.append(" ");
        information.append(remain);
        state = finishState;
    }
};

#endif	/* PINGDBPARSER_H */

