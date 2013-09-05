/* 
 * File:   AddReplicaParser.h
 * Author: radek
 *
 * Created on 16 July 2013, 08:28
 */

#ifndef ADDREPLICAPARSER_H
#define	ADDREPLICAPARSER_H

class AddReplicaParser : public CommandParser {
    
public:
    AddReplicaParser(){
        parseState1Start = 18;
        parseState2Start = 8;
        function = ADDREPLICA;
    }
};

#endif	/* ADDREPLICAPARSER_H */
