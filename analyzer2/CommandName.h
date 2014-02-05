/* 
 * File:   CommandName.h
 * Author: radek
 *
 * Created on 12 July 2013, 13:33
 */

#ifndef COMMANDNAME_H
#define	COMMANDNAME_H

enum LFCCommandName {
    LFC_LS,     // 0
    LCG_CR,     // 1
    LCG_REP,    // 2
    LFC_MKDIR,  // 3
    LCG_CP,     // 4
    LCG_DEL,    // 5
    LCG_SERV,   // 6
    LCG_ERR_TIMEOUT,    // 7
    LCG_ERR_PROXY,      // 8
    LCG_UTIME,  // 9
    LCG_PINGDB, // 10
    LCG_LR,     // 11
    LCG_AA,     // 12
    LCG_RM,     // 13
    LCG_UNKNOWN,// 14
};


#endif	/* COMMANDNAME_H */

