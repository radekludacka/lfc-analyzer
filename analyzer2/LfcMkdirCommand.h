/* 
 * File:   LfcMkdirCommand.h
 * Author: radek
 *
 * Created on 17 July 2013, 13:54
 */

#ifndef LFCMKDIRCOMMAND_H
#define	LFCMKDIRCOMMAND_H

#include "states/State.h"

class LfcMkdirCommand : public LfcCommand {
public:
    LfcMkdirCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
    virtual ~LfcMkdirCommand();
private:

};

#endif	/* LFCMKDIRCOMMAND_H */

