/* 
 * File:   StartTransState2.h
 * Author: radek
 *
 * Created on 29 July 2013, 13:08
 */

#ifndef STARTTRANSSTATE2_H
#define	STARTTRANSSTATE2_H

#include "../State.h"
#include "../../LfcCommand.h"
#include "../../LfcCrCommand.h"
#include "../../Analyzer.h"

class StartTransState2 : public State {
public:
    StartTransState2();
    virtual ~StartTransState2();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
            );
private:

};

#endif	/* STARTTRANSSTATE2_H */

