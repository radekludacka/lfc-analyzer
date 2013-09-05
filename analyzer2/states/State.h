/* 
 * File:   LfcAnalyzerState.h
 * Author: radek
 *
 * Created on 13 July 2013, 23:18
 */

#ifndef LFCANALYZERSTATE_H
#define	LFCANALYZERSTATE_H

using namespace std;

#include <vector>
#include "../../Item.h"
#include "../LfcCommand.h"

#define COUT

class Analyzer;

class State {
public:
    State();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
            ) = 0;
protected:
    void AssignAllItems(vector<Item*> items);
    void PrintMessage(string, Item * item);
};

#endif	/* LFCANALYZERSTATE_H */

