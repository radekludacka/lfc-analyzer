/* 
 * File:   GeneralTerminalState.h
 * Author: radek
 *
 * Created on 13 July 2013, 21:18
 */

#ifndef GENERALTERMINALSTATE_H
#define	GENERALTERMINALSTATE_H

#include "State.h"
#include "../Analyzer.h"

class GeneralTerminalState : public State {
public:
    GeneralTerminalState();
    GeneralTerminalState(const GeneralTerminalState& orig);
    virtual ~GeneralTerminalState();
    virtual LfcCommand * NextState(Analyzer * analyzer, vector<Item *> items, Item * item);
private:

};

#endif	/* GENERALTERMINALSTATE_H */

