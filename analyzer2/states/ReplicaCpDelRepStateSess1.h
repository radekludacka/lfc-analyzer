/* 
 * File:   GoodReplicaState.h
 * Author: radek
 *
 * Created on 17 July 2013, 13:15
 */

#ifndef GOODREPLICASTATE_H
#define	GOODREPLICASTATE_H

#include "State.h"
#include "../LfcCpCommand.h"
#include "../LfcRepCommand.h"
#include "../Analyzer.h"
#include "lfc_del_states/DelAll.h"
#include "lfc_rep_states/ReplicateStateTransaction.h"
#include "ReplicaCpDelRepStateSess2.h"

class ReplicaCpState : public State {
public:
    ReplicaCpState();
    virtual ~ReplicaCpState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
private:

};

#endif	/* GOODREPLICASTATE_H */

