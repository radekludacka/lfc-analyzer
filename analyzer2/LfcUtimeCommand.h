/* 
 * File:   LfcUtimeCommand.h
 * Author: radek
 *
 * Created on 22 July 2013, 14:53
 */

#ifndef LFCUTIMECOMMAND_H
#define	LFCUTIMECOMMAND_H

#include "LfcCommand.h"

class LfcUtimeCommand : public LfcCommand {
public:
    virtual ~LfcUtimeCommand();
    LfcUtimeCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
private:

};

#endif	/* LFCUTIMECOMMAND_H */

