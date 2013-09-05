/* 
 * File:   LfcCpCommand.h
 * Author: radek
 *
 * Created on 17 July 2013, 15:34
 */

#ifndef LFCCPCOMMAND_H
#define	LFCCPCOMMAND_H

#include "LfcCommand.h"

class LfcCpCommand : public LfcCommand {
public:
    LfcCpCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
    virtual ~LfcCpCommand();
private:

};

#endif	/* LFCCPCOMMAND_H */

