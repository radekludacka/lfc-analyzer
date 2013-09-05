/* 
 * File:   UtimeState.h
 * Author: radek
 *
 * Created on 22 July 2013, 14:50
 */

#ifndef UTIMESTATE_H
#define	UTIMESTATE_H

using namespace std;

#include "State.h"
#include "../../Functions.h"
#include "../LfcUtimeCommand.h"

class UtimeState : public State {
public:
    UtimeState();
    virtual ~UtimeState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
            );
private:

};

#endif	/* UTIMESTATE_H */

