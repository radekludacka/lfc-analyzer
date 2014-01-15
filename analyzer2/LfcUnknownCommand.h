/* 
 * File:   LfcUnknownCommand.h
 * Author: radek
 *
 * Created on January 15, 2014, 2:37 PM
 */

#ifndef LFCUNKNOWNCOMMAND_H
#define	LFCUNKNOWNCOMMAND_H

#include "LfcCommand.h"

class LfcUnknownCommand : public LfcCommand {
public:
    virtual ~LfcUnknownCommand();
    LfcUnknownCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
private:

};

#endif	/* LFCUNKNOWNCOMMAND_H */

