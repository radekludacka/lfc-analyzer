/* 
 * File:   CommandInfo.h
 * Author: radek
 *
 * Created on 29 July 2013, 16:00
 */

#ifndef COMMANDINFO_H
#define	COMMANDINFO_H

using namespace std;

#include "../analyzer2/CommandName.h"
#include <map>
#include <string>

class CommandInfo {
public:
    CommandInfo();
    virtual ~CommandInfo();
    virtual map<string, CommandInfo *> getSubItems() = 0;
    virtual void addCommand(LfcCommand * lfcCommand) = 0;
    virtual LFCCommandName getType();
protected:
    LFCCommandName commandName;
    map<string, CommandInfo *> subItems;
    string value;
};

#endif	/* COMMANDINFO_H */
