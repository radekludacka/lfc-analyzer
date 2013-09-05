/* 
 * File:   LFCCommand.h
 * Author: radek
 *
 * Created on 12 July 2013, 13:19
 */

#ifndef LFCCOMMAND_H
#define	LFCCOMMAND_H

using namespace std;

#include <string>
#include "../User.h"
#include "../LogTime.h"
#include "../Site.h"
#include "CommandName.h"
#include "Information.h"

class LfcCommand {
public:
    LfcCommand(LogTime *, 
            LogTime *, 
            string, 
            User *, 
            Site *, 
            bool);
    
    LfcCommand(LogTime *, 
            LogTime *, 
            string, 
            User *, 
            Site *, 
            bool, 
            Information * information);
    virtual ~LfcCommand();
    
    User* GetUser() const;
    string GetFile() const;
    LogTime* GetEndTime() const;
    LogTime* GetStartTime() const;
    LFCCommandName GetName() const;
    Site* GetSite() const;
    bool IsFailed() const;
    Information* GetInformation() const;
    string GetStringName() const;
protected:
    LogTime * startTime;
    LogTime * endTime;
    string file;
    User * user;
    Site * site;
    LFCCommandName name;
    bool isFail;
    Information * information;
    string stringName;
};

#endif	/* LFCCOMMAND_H */

