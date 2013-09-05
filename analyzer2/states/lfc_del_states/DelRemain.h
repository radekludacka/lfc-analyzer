/* 
 * File:   DelRemain.h
 * Author: radek
 *
 * Created on 21 July 2013, 14:24
 */

#ifndef DELREMAIN_H
#define	DELREMAIN_H

#include "../State.h"
#include "../../LfcCommand.h"
#include "../../LfcDelReplicaCommand.h"
#include "../../Analyzer.h"

class DelRemain : public State {
public:
    DelRemain();
    virtual ~DelRemain();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
private:

};

#endif	/* DELREMAIN_H */

