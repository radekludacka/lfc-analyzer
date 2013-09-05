/* 
 * File:   MockCommands.h
 * Author: radek
 *
 * Created on 03 August 2013, 15:22
 */

#ifndef MOCKCOMMANDS_H
#define	MOCKCOMMANDS_H

#include "analyzer2/Analyzer.h"
#include "parser2/LogTable.h"
#include "parser2/Parser.h"
#include <vector>
#include <iostream>

using namespace std;

class MockCommands {
public:
    MockCommands();
    virtual ~MockCommands();
    vector<LfcCommand *> * CreateMockLfcCommands();
};

#endif	/* MOCKCOMMANDS_H */

