/* 
 * File:   LfcRmDirCommand.h
 * Author: radek
 *
 * Created on 27 July 2013, 14:06
 */

#ifndef LFCRMDIRCOMMAND_H
#define	LFCRMDIRCOMMAND_H

using namespace std;

#include "LfcCommand.h"

class LfcRmDirCommand : public LfcCommand {
public:
    LfcRmDirCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
    virtual ~LfcRmDirCommand();
private:

};

#endif	/* LFCRMDIRCOMMAND_H */

