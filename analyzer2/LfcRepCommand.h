/* 
 * File:   LfcRepCommand.h
 * Author: radek
 *
 * Created on 17 July 2013, 11:09
 */

#ifndef LFCREPCOMMAND_H
#define	LFCREPCOMMAND_H

using namespace std;

#include "LfcCommand.h"

class LfcRepCommand : public LfcCommand {
public:
    LfcRepCommand(LogTime * startT, LogTime * endT, string fileName, User * userName, Site * site, bool fail);
    virtual ~LfcRepCommand();
private:

};

#endif	/* LFCREPCOMMAND_H */

