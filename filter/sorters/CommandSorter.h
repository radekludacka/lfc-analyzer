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
protected:
    virtual string GetItemToSort(LfcCommand * command);
};

#endif	/* COMMANDSORTER_H */

