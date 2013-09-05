/* 
 * File:   LfcLsCommand.h
 * Author: radek
 *
 * Created on 12 July 2013, 13:29
 */

#ifndef LFCLSCOMMAND_H
#define	LFCLSCOMMAND_H

using namespace std;

#include "LfcCommand.h"

class LfcLsCommand : public LfcCommand {
public:
    LfcLsCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
    virtual ~LfcLsCommand();
private:

};

#endif	/* LFCLSCOMMAND_H */

