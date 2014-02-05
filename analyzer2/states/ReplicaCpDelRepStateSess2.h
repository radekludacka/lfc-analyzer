/* 
 * File:   ReplicaCpDelRepStateSess2.h
 * Author: radek
 *
 * Created on January 16, 2014, 2:12 PM
 */

#ifndef REPLICACPDELREPSTATESESS2_H
#define	REPLICACPDELREPSTATESESS2_H

#include "State.h"
#include "../LfcCpCommand.h"
#include "../LfcRepCommand.h"
#include "../Analyzer.h"
#include "lfc_del_states/DelAll.h"
#include "lfc_rep_states/ReplicateStateTransaction.h"

class ReplicaCpDelRepStateSess2 : public State {
public:
    ReplicaCpDelRepStateSess2();
    virtual ~ReplicaCpDelRepStateSess2();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
            );
private:

};

#endif	/* REPLICACPDELREPSTATESESS2_H */

