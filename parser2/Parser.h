#ifndef PARSER_H
#define	PARSER_H

#include "LogTable.h"
#include <string>
#include <fstream>
#include "Row.h"
#include "../Site.h"
#include <stdio.h>
#include "../Functions.h"
#include "CommandParser.h"
#include "LstatParser.h"
#include "NullParser.h"
#include "AccessParser.h"
#include "OpenDirParser.h"
#include "ReadDirParser.h"
#include "StartSessionParser.h"
#include "DelReplicaParser.h"
#include "GetReplicaParser.h"
#include "UnlinkParser.h"
#include "GetlinkParser.h"
#include "EndSessionParser.h"
#include "StartTransactionParser.h"
#include "StatgParser.h"
#include "CreatParser.h"
#include "AddReplicaParser.h"
#include "SetfSizegParser.h"
#include "EndTransParser.h"
#include "MkdirParser.h"
#include "StatrParser.h"
#include "ServParser.h"
#include "UTimeParser.h"
#include "PingDBParser.h"
#include "SymlinkParser.h"
#include "GetPathParser.h"
#include "ChDirParser.h"
#include "RmDirParser.h"
#include <map>
#include <stdexcept>

class Parser {
public:

    LogTable * parse(string filePath) {
        vector<Row*> * rows = parseRows(filePath);
        LogTable * logTable = this->parseItems(rows);
        for (vector<Row*>::const_iterator it = rows->begin(); it != rows->end(); it++) {
            delete *it;
        }
        rows->clear();
        delete rows;
        return logTable;
    }

    vector<Row *> * parseRows(string filePath) {
        ifstream infile;
        infile.open(filePath.c_str());
        
        if (infile.is_open() == false) {
            throw "Input file not exists";
        }

        int mod = 0;
        string sLine = "";
        vector<Row*> * rows = new vector<Row*>;
        while (std::getline(infile, sLine)) {
            Row * row = this->parseRow(sLine);
            rows->push_back(row);
            //            3667763
//            if (mod++ == 100000) {
//                break;
//            }
        }
        infile.close();

        return rows;
    }

    Row * parseRow(string line) {
        int end = line.find(":", 27);
        LogTime * time = new LogTime(line.substr(0, 18));
        int tid = 0;
        string function = "";

        if (line.substr(26, 1).compare(" ") != 0) {
            tid = atoi(line.substr(25, 2).c_str());
            function = line.substr(28, end - 28);
        } else {
            tid = atoi(line.substr(25, 1).c_str());
            function = line.substr(27, end - 27);
        }

        return new Row(time, 0, tid, function, line.substr(end + 2), false);
    }

    LogTable * parseItems(vector<Row*> * rows) {
        LogTable * logTable = new LogTable();
        map<string, CommandParser *> objectMap = createParserMap();
        int index = -1;
        CommandParser * commandParser = NULL;
        std::vector<Row *>::const_iterator iterator;
        for (iterator = rows->begin(); iterator != rows->end(); ++iterator) {
            Row * row = *iterator;
            index++;

            int addition = index + 10000;
            if (addition > rows->size()) {
                addition = rows->size();
            }

            if (!row->GetParsed()) {
                if (objectMap.find(row->GetFunction()) != objectMap.end()) {
                    commandParser = objectMap.at(row->GetFunction());
                    
                    // important is to keep the same additional variable otherwise reallocation take much time
                    std::vector<Row *> subRows(rows->begin() + index, rows->begin() + addition);
                    try {
                        Item * item = commandParser->parse(subRows);
                        logTable->addItem(item);
//                        cout << "abd" << endl;
//                        item->GetStartTime()->toString();
                    } catch (std::out_of_range& e) {
                        std::cerr << "Row ";
                        row->GetTime()->toString();
                        std::cerr << "Caused: range error: " << e.what() << '\n';
                    }
                }
                //                row->SetParsed(true);
            }
        }

        int notParsed = 0;
        std::vector<Row *>::const_iterator iterator2;
        for (iterator2 = rows->begin(); iterator2 != rows->end(); ++iterator2) {
            Row * row = *iterator2;

            if (!row->GetParsed()) {
                //                row->GetTime()->toString();
                //                cout << row->GetFunction() << endl;
                //                cout << row->GetRemain() << endl;
                notParsed++;
            }

        }

        cout << "not parsed rows: " << notParsed << endl;

        return logTable;
    }

private:

    map<string, CommandParser *> createParserMap() {
        map<string, CommandParser *> objectMap;
        objectMap["Cns_srv_lstat"] = new LstatParser();
        objectMap["Cns_srv_access"] = new AccessParser();
        objectMap["Cns_srv_opendir"] = new OpenDirParser();
        objectMap["Cns_srv_readdir"] = new ReadDirParser();
        objectMap["Cns_srv_startsess"] = new StartSessionParser();
        objectMap["Cns_srv_delreplica"] = new DelReplicaParser();
        objectMap["Cns_srv_getreplica"] = new GetReplicaParser();
        objectMap["Cns_srv_unlink"] = new UnlinkParser();
        objectMap["Cns_srv_getlinks"] = new GetlinksParser();
        objectMap["Cns_srv_endsess"] = new EndSessionParser();
        objectMap["Cns_srv_starttrans"] = new StartTransactionParser();
        objectMap["Cns_srv_statg"] = new StatgParser();
        objectMap["Cns_srv_creat"] = new CreatParser();
        objectMap["Cns_srv_addreplica"] = new AddReplicaParser();
        objectMap["Cns_srv_setfsizeg"] = new SetfSizegParser();
        objectMap["Cns_srv_endtrans"] = new EndTransParser();
        objectMap["Cns_srv_mkdir"] = new MkdirParser();
        objectMap["Cns_srv_statr"] = new StatrParser();
        objectMap["Cns_serv"] = new ServParser();
        objectMap["Cns_srv_utime"] = new UTimeParser();
        objectMap["Cns_pingdb"] = new PingDBParser();
        objectMap["Cns_srv_symlink"] = new SymlinkParser();
        objectMap["Cns_srv_getpath"] = new GetPathParser();
        objectMap["Cns_srv_chdir"] = new ChDirParser();
        objectMap["Cns_srv_rmdir"] = new RmDirParser();
        return objectMap;
    }
};

#endif	/* PARSER_H */

