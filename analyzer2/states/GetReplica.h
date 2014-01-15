/* 
 * File:   GetReplica.h
 * Author: radek
 *
 * Created on January 15, 2014, 2:22 PM
 */

#ifndef GETREPLICA_H
#define	GETREPLICA_H

using namespace std;

#include "State.h"
#include "../../Functions.h"
#include "../LfcUnknownCommand.h"

class GetReplica : public State {
public:
    GetReplica();
    virtual ~GetReplica();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
            );
private:

};

#endif	/* GETREPLICA_H */

