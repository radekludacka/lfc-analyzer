/* 
 * File:   LfcLrCommand.h
 * Author: radek
 *
 * Created on 24 July 2013, 16:28
 */

#ifndef LFCLRCOMMAND_H
#define	LFCLRCOMMAND_H

using namespace std;

#include "LfcCommand.h"

class LfcLrCommand  : public LfcCommand {
public:
    LfcLrCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
    virtual ~LfcLrCommand();
private:

};

#endif	/* LFCLRCOMMAND_H */

