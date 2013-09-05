/* 
 * File:   LfcAACommand.h
 * Author: radek
 *
 * Created on 27 July 2013, 11:28
 */

#ifndef LFCAACOMMAND_H
#define	LFCAACOMMAND_H

#include "LfcCommand.h"

class LfcAACommand : public LfcCommand {
public:
    LfcAACommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
    virtual ~LfcAACommand();
private:

};

#endif	/* LFCAACOMMAND_H */

