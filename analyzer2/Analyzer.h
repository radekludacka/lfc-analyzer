/* 
 * File:   Analyzer.h
 * Author: radek
 *
 * Created on 13 July 2013, 11:55
 */

#ifndef ANALYZER_H
#define	ANALYZER_H

using namespace std;

#include "../parser2/LogTable.h"
#include "LfcCommandTable.h"
#include "CommandName.h"
#include "states/State.h"
#include "LfcCommand.h"
#include "states/LstatState.h"
#include "LfcLsCommand.h"
#include <map>

class State;
class Analyzer {
public:
    Analyzer();
    virtual ~Analyzer();
    LfcCommandTable * Analyze(LogTable * logTable);
private:
    map<FunctionType, State *> createStateMap();
    State * currentState;
};

#endif	/* ANALYZER_H */

