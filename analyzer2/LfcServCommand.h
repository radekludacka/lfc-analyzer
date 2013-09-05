/* 
 * File:   LfcServCommand.h
 * Author: radek
 *
 * Created on 22 July 2013, 12:36
 */

#ifndef LFCSERVCOMMAND_H
#define	LFCSERVCOMMAND_H

#include "LfcCommand.h"

class LfcServCommand : public LfcCommand {
public:
    LfcServCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
    virtual ~LfcServCommand();
private:

};

#endif	/* LFCSERVCOMMAND_H */

