/* 
 * File:   ReplicaState.h
 * Author: radek
 *
 * Created on 24 July 2013, 16:26
 */

#ifndef REPLICASTATE_H
#define	REPLICASTATE_H

#include "State.h"
#include "../LfcLrCommand.h"

class ReplicaState : public State {
public:
    ReplicaState();
    virtual ~ReplicaState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
            );
private:

};

#endif	/* REPLICASTATE_H */

