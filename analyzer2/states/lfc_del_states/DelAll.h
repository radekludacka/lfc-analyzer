/* 
 * File:   DellAll.h
 * Author: radek
 *
 * Created on 21 July 2013, 15:19
 */

#ifndef DELLALL_H
#define	DELLALL_H

#include "../State.h"
#include "../../LfcCommand.h"
#include "../../LfcDelReplicaCommand.h"
#include "../../LfcRepCommand.h"
#include "../../Analyzer.h"
#include "../../LfcCpCommand.h"

class DellAll : public State {
public:
    DellAll();
    virtual ~DellAll();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
private:

};

#endif	/* DELLALL_H */

