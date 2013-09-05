/* 
 * File:   ChDirParser.h
 * Author: radek
 *
 * Created on 27 July 2013, 12:35
 */

#ifndef CHDIRPARSER_H
#define	CHDIRPARSER_H

#include "CommandParser.h"

class ChDirParser : public CommandParser {
public:

    ChDirParser() {
        parseState1Start = 14;
        function = CHDIR;
    }
};


#endif	/* CHDIRPARSER_H */

