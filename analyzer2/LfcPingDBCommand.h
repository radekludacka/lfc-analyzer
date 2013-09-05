/* 
 * File:   LfcPingDBCommand.h
 * Author: radek
 *
 * Created on 22 July 2013, 16:22
 */

#ifndef LFCPINGDBCOMMAND_H
#define	LFCPINGDBCOMMAND_H

#include "LfcCommand.h"

class LfcPingDBCommand : public LfcCommand {
public:
    LfcPingDBCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
    virtual ~LfcPingDBCommand();
private:

};

#endif	/* LFCPINGDBCOMMAND_H */

