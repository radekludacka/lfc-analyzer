/* 
 * File:   SuccessSorter.h
 * Author: radek
 *
 * Created on 31 July 2013, 09:07
 */

#ifndef SUCCESSSORTER_H
#define	SUCCESSSORTER_H
#include "Sorter.h"

class SuccessSorter : public Sorter {
public:
    SuccessSorter();
    SuccessSorter(Sorter * subSorter);
    virtual ~SuccessSorter();
protected:
    virtual string GetItemToSort(LfcCommand * command);
    virtual set<string> ExtractByString(vector<LfcCommand *> * commands);
};

#endif	/* SUCCESSSORTER_H */

