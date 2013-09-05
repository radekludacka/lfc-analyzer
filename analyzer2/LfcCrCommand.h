/* 
 * File:   LfcCrCommand.h
 * Author: radek
 *
 * Created on 15 July 2013, 17:59
 */

#ifndef LFCCRCOMMAND_H
#define	LFCCRCOMMAND_H

using namespace std;

#include "LfcCommand.h"

class LfcCrCommand : public LfcCommand {
public:
    LfcCrCommand(LogTime * startT, 
            LogTime * endT, 
            string fileName, 
            User * userName, 
            Site * site, 
            bool fail,
            Information * information);
    virtual ~LfcCrCommand();
private:

};

#endif	/* LFCCRCOMMAND_H */

