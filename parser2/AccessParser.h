/* 
 * File:   AccessParser.h
 * Author: radek
 *
 * Created on 10 July 2013, 22:06
 */

#ifndef ACCESSPARSER_H
#define	ACCESSPARSER_H

#include "CommandParser.h"

class AccessParser : public CommandParser {
public:

    AccessParser() {
        parseState1Start = 17;
        parseState2Start = 9;
        function = ACCESS;
    }

    virtual void parseState1(Row * parsedRow) {
        filePath = parsedRow->GetRemain().substr(parseState1Start);
        filePath = this->trim(filePath);
        parsedRow->SetParsed(true);
        
        information = parsedRow->GetRemain().substr(15, 1);
        state = 1;
    }

};

#endif	/* ACCESSPARSER_H */

