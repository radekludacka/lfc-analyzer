/* 
 * File:   OpenDirRecursiveState.h
 * Author: radek
 *
 * Created on 26 July 2013, 20:14
 */

#ifndef OPENDIRRECURSIVESTATE_H
#define	OPENDIRRECURSIVESTATE_H

using namespace std;

#include "../State.h"
#include "../GeneralTerminalState.h"
#include <vector>


class OpenDirRecursiveState : public State {
public:
    OpenDirRecursiveState();
    virtual ~OpenDirRecursiveState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
private:

};

#endif	/* OPENDIRRECURSIVESTATE_H */

