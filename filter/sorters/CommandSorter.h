/* 
 * File:   CommandSorter.h
 * Author: radek
 *
 * Created on 30 July 2013, 20:52
 */

#ifndef COMMANDSORTER_H
#define	COMMANDSORTER_H
#include "Sorter.h"

class CommandSorter : public Sorter {
public:
    CommandSorter();
    CommandSorter(Sorter * subSorter);
    virtual ~CommandSorter();
    virtual vector<LfcCommand*> * Sort(vector<LfcCommand *> * commands);
protected:
    virtual set<string> ExtractByString(vector<LfcCommand *> * commands);
};

#endif	/* COMMANDSORTER_H */

