/* 
 * File:   OpenDirParser.h
 * Author: radek
 *
 * Created on 10 July 2013, 22:41
 */

#ifndef OPENDIRPARSER_H
#define	OPENDIRPARSER_H

using namespace std;

#include "../Functions.h"
#include "CommandParser.h"

class OpenDirParser : public CommandParser {

public:

    OpenDirParser() {
        parseState1Start = 16;
        parseState2Start = 8;
        function = OPENDIR;
    }
};

#endif	/* OPENDIRPARSER_H */

