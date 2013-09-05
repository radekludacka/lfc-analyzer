/* 
 * File:   PingDBState.h
 * Author: radek
 *
 * Created on 22 July 2013, 16:19
 */

#ifndef PINGDBSTATE_H
#define	PINGDBSTATE_H

#include "State.h"
#include "../LfcCpCommand.h"
#include "../LfcPingDBCommand.h"
#include "../Analyzer.h"

class PingDBState : public State {
public:
    PingDBState();
    virtual ~PingDBState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
private:

};

#endif	/* PINGDBSTATE_H */

