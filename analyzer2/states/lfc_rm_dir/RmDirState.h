/* 
 * File:   RmDirState.h
 * Author: radek
 *
 * Created on 27 July 2013, 13:20
 */

#ifndef RMDIRSTATE_H
#define	RMDIRSTATE_H

using namespace std;

#include "../State.h"
#include "../../../Functions.h"
#include "../../LfcRmDirCommand.h"

class RmDirState : public State {
public:
    RmDirState();
    virtual ~RmDirState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
            );

private:

};

#endif	/* RMDIRSTATE_H */

