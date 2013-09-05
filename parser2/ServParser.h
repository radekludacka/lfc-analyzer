/* 
 * File:   ServParser.h
 * Author: radek
 *
 * Created on 20 July 2013, 15:50
 */

#ifndef SERVPARSER_H
#define	SERVPARSER_H

using namespace std;

#include "../Functions.h"
#include "CommandParser.h"
#include "Command.h"

class ServParser : public CommandParser {
public:

    ServParser() {
        parseState1Start = 16;
        parseState2Start = 8;
        function = CLOSEDIR;
    }

    void parseState0(Row * parsedRow) {
        startTime = parsedRow->GetTime();

        string remain = parsedRow->GetRemain();
        int startInfo = remain.find(':') + 2;
        information = remain.substr(startInfo);
        parsedRow->SetParsed(true);
        state = 0;

        int infoStart = remain.find(':') + 2;

        if (remain.substr(infoStart, 1).compare("T") == 0) {
            parsedRow->SetParsed(true);
            state = -1;
        }

        if (remain.substr(0, 1).compare("[") == 0) {
            parsedRow->SetParsed(true);
            function = SERV;
            endTime = parsedRow->GetTime();

            int startSite = remain.find('(') + 1;
            int endSite = remain.find(')');

            site = new Site(remain.substr(startSite, endSite - startSite));
            user = new User("");
            command = new Command(function, 0);
            tid = parsedRow->GetTid();
            state = finishState;

            if (remain.find("Could not set service name") != -1) {
                state = 3;
            }
        }

    }

    void parseState1(Row * parsedRow) {
        string remain = parsedRow->GetRemain();
        start = remain.find('/', 20);
        end = remain.find('(', start);

        user = new User(remain.substr(start, end - start - 1));

        int startSite = remain.find(')', end - start - 1);
        site = new Site(remain.substr(startSite + 7));

        tid = parsedRow->GetTid();
        parsedRow->SetParsed(true);
        state = 1;
    }

    void parseState2(Row * parsedRow) {
        if (parsedRow->GetFunction().compare("Cns_srv_readdir") == 0) {
            return parseState3(parsedRow);
        }
        string remain = parsedRow->GetRemain();
        int startInfo = remain.find(':') + 1;
        information.append(remain.substr(startInfo));

        parsedRow->SetParsed(true);
        state = 2;
    }

    void parseState3(Row * parsedRow) {
        int returnCode = 0;
        string remain = parsedRow->GetRemain();
        if (remain.substr(parseState2Start, 2).compare("\n") != 0) {
            returnCode = atoi(remain.substr(parseState2Start, 2).c_str());
        } else {
            returnCode = atoi(remain.substr(parseState2Start, 1).c_str());
        }

        command = new Command(function, returnCode);
        parsedRow->SetParsed(true);
        state = 3;
    }

    void parseState4(Row * parsedRow) {
        if (parsedRow->GetFunction().compare("sendrep") == 0) {
            endTime = parsedRow->GetTime();
            parsedRow->SetParsed(true);
            state = finishState;
        }
    }
};

#endif	/* SERVPARSER_H */

