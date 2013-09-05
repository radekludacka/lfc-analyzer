/* 
 * File:   UserInfo.h
 * Author: radek
 *
 * Created on 29 July 2013, 16:59
 */

#ifndef USERINFO_H
#define	USERINFO_H

#include "commands/CommandInfo.h"


class UserInfo : public CommandInfo {
public:
    UserInfo();
    virtual ~UserInfo();
    addCommand(LfcCommand * command);
};

#endif	/* USERINFO_H */

