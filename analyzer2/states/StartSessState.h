/* 
 * File:   StartSessState.h
 * Author: radek
 *
 * Created on 17 July 2013, 10:56
 */

#ifndef STARTSESSSTATE_H
#define	STARTSESSSTATE_H

using namespace std;

#include "State.h"
#include "../../Functions.h"
#include "ReplicaCpDelRepStateSess1.h"
#include "lfc_rep_states/BadReplicaState.h"
#include "lfc_del_states/DelReplica.h"
#include "GetReplica.h"

class StartSessState : public State {
public:
    StartSessState();
    virtual ~StartSessState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
            );
private:

};

#endif	/* STARTSESSSTATE_H */

