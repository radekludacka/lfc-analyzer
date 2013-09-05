/* 
 * File:   StartTransState.h
 * Author: radek
 *
 * Created on 16 July 2013, 12:41
 */

#ifndef STARTTRANSSTATE_H
#define	STARTTRANSSTATE_H

#include "../State.h"
#include "../../LfcCommand.h"
#include "../../LfcCrCommand.h"
#include "../../Analyzer.h"

class StartTransState : public State {
public:
    StartTransState();
    virtual ~StartTransState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
private:
};

#endif	/* STARTTRANSSTATE_H */

