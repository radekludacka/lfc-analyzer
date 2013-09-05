/* 
 * File:   SetfSizegParser.h
 * Author: radek
 *
 * Created on 16 July 2013, 09:04
 */

#ifndef SETFSIZEGPARSER_H
#define	SETFSIZEGPARSER_H

using namespace std;

#include "CommandParser.h"

class SetfSizegParser : public CommandParser {
public:

    SetfSizegParser() {
        parseState1Start = 18;
        parseState2Start = 8;
        function = SETFSIZEG;
    }
};


#endif	/* SETFSIZEGPARSER_H */
