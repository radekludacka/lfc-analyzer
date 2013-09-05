/* 
 * File:   ReadDirParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 09:22
 */

#ifndef READDIRPARSER_H
#define	READDIRPARSER_H

using namespace std;

#include "../Functions.h"
#include "CommandParser.h"
#include "Command.h"

class ReadDirParser : public CommandParser {
protected:

    virtual void parseState0(Row * parsedRow) {
        string remain = parsedRow->GetRemain();

        startTime = parsedRow->GetTime();
        start = remain.find('/', 20);
        end = remain.find('(', start);

        user = new User(remain.substr(start, end - start - 1));

        int startSite = remain.find(')', end - start - 1);
        site = new Site(remain.substr(startSite + 7));

        tid = parsedRow->GetTid();

        int startInfo = remain.find('-') + 2;
        int endInfo = remain.find(' ', startInfo);
        string functionType = remain.substr(startInfo, endInfo - startInfo);

        FunctionType function = READDIR;
        if (functionType.compare("closedir") == 0) {
            function = CLOSEDIR;
        }
        command = new Command(function, 0);
        parsedRow->SetParsed(true);
        state = 0;
    }

    virtual void parseState1(Row * parsedRow) {
        int returnCode = atoi(parsedRow->GetRemain().substr(8, 1).c_str());
        endTime = parsedRow->GetTime();
        command->setReturnCode(returnCode);
        parsedRow->SetParsed(true);
        state = 1;
    }

    virtual void parseState2(Row * parsedRow) {
        string remain = parsedRow->GetRemain();

        if (command->getName() != CLOSEDIR) {
            state = finishState;
            return;
        }

        int endInfo = remain.find(' ', 0);
        string nsFunction = remain.substr(0, endInfo);

        if (nsFunction.compare("NS002") != 0) {
            state = finishState;
            return;
        }

        int startInfo = remain.find(':') + 2;
        information = remain.substr(startInfo);
        endTime = parsedRow->GetTime();
        parsedRow->SetParsed(true);
        state = finishState;
    }
};

#endif	/* READDIRPARSER_H */

