/* 
 * File:   MockCommands.cpp
 * Author: radek
 * 
 * Created on 03 August 2013, 15:22
 */

#include "MockCommands.h"
#include "analyzer2/Analyzer.h"

MockCommands::MockCommands() {
}

MockCommands::~MockCommands() {
//    delete analyzer;
}

vector<LfcCommand *> * MockCommands::CreateMockLfcCommands() {

    Analyzer * analyzer = new Analyzer();
    Parser * parser = new Parser();
    vector<LfcCommand *> * commands = new vector<LfcCommand *>;

    LogTable * logTable = parser->parse("./tests/resources/lfc-ls-several-readdir");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);
    vector<LfcCommand *> * commandsLs1 = commandTable->GetCommandList();

    logTable = parser->parse("./tests/resources/lfc-ls-2");
    commandTable = analyzer->Analyze(logTable);
    vector<LfcCommand *> * commandsLs2 = commandTable->GetCommandList();

    logTable = parser->parse("./tests/resources/lfc-ls-broken-pipe");
    commandTable = analyzer->Analyze(logTable);
    vector<LfcCommand *> * commandsLs3 = commandTable->GetCommandList();

    logTable = parser->parse("./tests/resources/lfc-ls-recursive");
    commandTable = analyzer->Analyze(logTable);
    vector<LfcCommand *> * commandsLs4 = commandTable->GetCommandList();

    logTable = parser->parse("./tests/resources/lfc-rep-del-cp-fail");
    commandTable = analyzer->Analyze(logTable);
    vector<LfcCommand *> * commandsLs5 = commandTable->GetCommandList();


    commands->push_back(commandsLs1->at(0));
    commands->push_back(commandsLs2->at(0));
    commands->push_back(commandsLs3->at(0));
    commands->push_back(commandsLs4->at(0));
    commands->push_back(commandsLs5->at(0));

    return commands;
}
