/* 
 * File:   MkdirParser.h
 * Author: radek
 *
 * Created on 17 July 2013, 14:11
 */

#ifndef MKDIRPARSER_H
#define	MKDIRPARSER_H

#include "CommandParser.h"
#include "../LogTime.h"
#include "Row.h"

using namespace std;
class MkdirParser : public CommandParser {
public:

    MkdirParser() {
        parseState1Start = 14;
        parseState2Start = 8;
        function = MKDIR;
    }
private:

};

#endif	/* MKDIRPARSER_H */

