/* 
 * File:   MkDirState.h
 * Author: radek
 *
 * Created on 17 July 2013, 13:58
 */

#ifndef MKDIRSTATE_H
#define	MKDIRSTATE_H

#include "State.h"
#include "../LfcMkdirCommand.h"

class MkDirState  : public State {
public:
    MkDirState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
    virtual ~MkDirState();
private:

};

#endif	/* MKDIRSTATE_H */

