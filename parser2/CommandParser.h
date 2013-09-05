/* 
 * File:   CommandParser.h
 * Author: Radek Ludacka
 *
 * Created on 10 July 2013, 10:28
 */

#ifndef COMMANDPARSER_H
#define	COMMANDPARSER_H

using namespace std;

#include "Row.h"
#include "../Functions.h"

class CommandParser {
public:

    CommandParser() {
        endTime = NULL;
        command = NULL;
        startTime = NULL;
        user = NULL;
        site = NULL;
        filePath = "";
        end = 0;
        state = 0;
        parseState1Start = 0;
        parseState2Start = 0;
        function = ACCESS;
        information = "";
        tid = 0;
        finishState = 4;
    }

    virtual Item * parse(std::vector<Row*> rows) {
        state = -1; // state in needed set to default value all the time

        std::vector<Row *>::iterator iterator = rows.begin();
        Row * row = *iterator;
        int max = rows.size();
        int index = 0;

        while (state != finishState) {
            Row * parsedRow = *iterator;

            if (parsedRow == NULL or max == index) {
                break;
            }

            if (parsedRow->GetTid() == row->GetTid()
                    and parsedRow->GetParsed() == false) {
                if (state == 3) {
                    parseState4(parsedRow);
                } else if (state == 2) {
                    parseState3(parsedRow);
                } else if (state == 1) {
                    parseState2(parsedRow);
                } else if (state == 0) {
                    parseState1(parsedRow);
                } else if (state == -1) {
                    parseState0(parsedRow);
                }
            }

            ++iterator;
            index++;
        }

        return new Item(startTime, endTime, command, user, site, filePath, information, tid);
    }

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

        //        int startInfo = remain.find('-') + 2;
        //        int endInfo = remain.find(' ', startInfo);
        //        information = remain.substr(startInfo, endInfo - startInfo);
        parsedRow->SetParsed(true);
        state = 0;
    }

    virtual void parseState1(Row * parsedRow) {
        filePath = parsedRow->GetRemain().substr(parseState1Start);
        filePath = this->trim(filePath);
        parsedRow->SetParsed(true);
        state = 1;
    }

    virtual void parseState2(Row * parsedRow) {
        int returnCode = 0;
        if (parsedRow->GetRemain().substr(parseState2Start, 2).compare("\n") != 0) {
            returnCode = atoi(parsedRow->GetRemain().substr(parseState2Start, 2).c_str());
        } else {
            returnCode = atoi(parsedRow->GetRemain().substr(parseState2Start, 1).c_str());
        }

        endTime = parsedRow->GetTime();
        command = new Command(function, returnCode);
        parsedRow->SetParsed(true);
        state = finishState;
    }

    virtual void parseState3(Row * parsedRow) {
        throw "parseState3";
    }

    virtual void parseState4(Row * parsedRow) {
        throw "parseState4";
    }

    inline std::string trim(std::string& str) {
        str.erase(0, str.find_first_not_of(' ')); //prefixing spaces
        str.erase(str.find_last_not_of(' ') + 1); //surfixing spaces
        return str;
    }

    LogTime * endTime;
    Command * command;
    LogTime * startTime;
    User * user;
    Site * site;
    string filePath;
    int start;
    int end;
    int state;
    int parseState1Start;
    int parseState2Start;
    FunctionType function;
    string information;
    int tid;
    int finishState;
};

#endif	/* COMMANDPARSER_H */

