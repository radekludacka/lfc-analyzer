/* 
 * File:   DelReplicaCommand.h
 * Author: radek
 *
 * Created on 19 July 2013, 13:44
 */

#ifndef DELREPLICACOMMAND_H
#define	DELREPLICACOMMAND_H

#include "LfcCommand.h"

class LfcDelReplicaCommand : public LfcCommand {
public:
    LfcDelReplicaCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
    virtual ~LfcDelReplicaCommand();
private:

};

#endif	/* DELREPLICACOMMAND_H */

