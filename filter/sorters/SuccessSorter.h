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
    virtual vector<LfcCommand*> * Sort(vector<LfcCommand *> * commands);
protected:
    virtual set<bool> ExtractByString(vector<LfcCommand *> * commands);
};

#endif	/* SUCCESSSORTER_H */

