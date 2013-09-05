/* 
 * File:   ReplicateState.h
 * Author: radek
 *
 * Created on 25 July 2013, 13:02
 */

#ifndef REPLICATESTATE_H
#define	REPLICATESTATE_H

#include "../State.h"
#include "../../LfcCommand.h"
#include "../../LfcRepCommand.h"
#include "../../Analyzer.h"

class ReplicateStateTransaction  : public State {
public:
    ReplicateStateTransaction();
    virtual ~ReplicateStateTransaction();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
private:

};

#endif	/* REPLICATESTATE_H */

