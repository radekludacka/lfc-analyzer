/* 
 * File:   StatgState.h
 * Author: radek
 *
 * Created on 27 July 2013, 11:02
 */

#ifndef STARTTRANS_H
#define	STARTTRANS_H

using namespace std;

#include "../State.h"
#include "../../../Functions.h"
#include "../../LfcAACommand.h"
#include "../lfc_cr_states/StartTransState2.h"

class StartTransStateAA : public State {
public:
    StartTransStateAA();
    virtual ~StartTransStateAA();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
private:

};

#endif	/* STARTTRANS_H */
