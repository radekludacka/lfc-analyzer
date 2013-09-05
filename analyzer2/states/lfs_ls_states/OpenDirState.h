/* 
 * File:   LfcOpenDirAnalyzerState.h
 * Author: radek
 *
 * Created on 13 July 2013, 21:27
 */

#ifndef LFCOPENDIRANALYZERSTATE_H
#define	LFCOPENDIRANALYZERSTATE_H

using namespace std;

#include "../State.h"
#include "../GeneralTerminalState.h"
#include <vector>

//class Analyzer;
class OpenDirState : public State {
public:
    OpenDirState();
    virtual ~OpenDirState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
//    virtual LfcCommand * GetResult(Item * item);
private:

};

#endif	/* LFCOPENDIRANALYZERSTATE_H */

