/* 
 * File:   GetlinkParser.h
 * Author: radek
 *
 * Created on 11 July 2013, 15:03
 */

#ifndef GETLINKPARSER_H
#define	GETLINKPARSER_H

class GetlinksParser : virtual public CommandParser {
public:

    GetlinksParser() {
        parseState1Start = 18;
        parseState2Start = 8;
        function = GETLINKS;
    }
};

#endif	/* GETLINKPARSER_H */

