/* 
 * File:   NullSorter.h
 * Author: radek
 *
 * Created on 02 October 2013, 11:47
 */

#ifndef NULLSORTER_H
#define	NULLSORTER_H

#include "Sorter.h"

class NullSorter : public Sorter {
public:
    NullSorter();
    NullSorter(Sorter * subSorter);
    virtual ~NullSorter();
    virtual vector<LfcCommand*> * Sort(vector<LfcCommand *> * commands);
protected:
    virtual set<string> ExtractByString(vector<LfcCommand *> * commands);
    virtual bool CompareCommandValue(LfcCommand * command, string value);
    virtual string GetItemToSort(LfcCommand * command);
};

#endif	/* NULLSORTER_H */
