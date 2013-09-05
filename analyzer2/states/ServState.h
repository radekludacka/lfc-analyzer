/* 
 * File:   ServState.h
 * Author: radek
 *
 * Created on 22 July 2013, 12:33
 */

#ifndef SERVSTATE_H
#define	SERVSTATE_H

#include "State.h"
#include "../LfcServCommand.h"

class ServState : public State {
public:
    ServState();
    virtual ~ServState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
    
private:

};

#endif	/* SERVSTATE_H */

