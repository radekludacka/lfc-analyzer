/* 
 * File:   BadReplicaState.h
 * Author: radek
 *
 * Created on 17 July 2013, 11:24
 */

#ifndef BADREPLICASTATE_H
#define	BADREPLICASTATE_H

#include "../State.h"
#include "../../LfcCommand.h"
#include "../../LfcRepCommand.h"
#include "../../Analyzer.h"


class BadReplicaState : public State {
public:
    BadReplicaState();
    virtual ~BadReplicaState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
private:

};

#endif	/* BADREPLICASTATE_H */

