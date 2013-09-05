/* 
 * File:   DelReplica.h
 * Author: radek
 *
 * Created on 19 July 2013, 13:28
 */

#ifndef DELREPLICA_H
#define	DELREPLICA_H

#include "../State.h"
#include "../../LfcCommand.h"
#include "../../LfcDelReplicaCommand.h"
#include "../../Analyzer.h"
#include "DelRemain.h"

class DelReplica : public State {
public:
    DelReplica();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
    virtual ~DelReplica();
private:

};

#endif	/* DELREPLICA_H */

