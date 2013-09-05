/* 
 * File:   RmDirParser.h
 * Author: radek
 *
 * Created on 27 July 2013, 12:52
 */

#ifndef RMDIRPARSER_H
#define	RMDIRPARSER_H

class RmDirParser: public CommandParser {
    
public:
    RmDirParser(){
        parseState1Start = 14;
        function = RMDIR;
    }
};

#endif	/* RMDIRPARSER_H */

