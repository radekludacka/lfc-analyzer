/* 
 * File:   SymlinkParser.h
 * Author: radek
 *
 * Created on 27 July 2013, 09:56
 */

#ifndef SYMLINKPARSER_H
#define	SYMLINKPARSER_H

#include "CommandParser.h"

class SymlinkParser : public CommandParser {
    
public:
    SymlinkParser(){
        parseState1Start = 16;
        parseState2Start = 8;
        function = SYMLINK;
    }
};


#endif	/* SYMLINKPARSER_H */

