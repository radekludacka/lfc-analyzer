/* 
 * File:   SiteSorter.h
 * Author: radek
 *
 * Created on 30 July 2013, 14:42
 */

#ifndef SITESORTER_H
#define	SITESORTER_H

#include "Sorter.h"

class SiteSorter : public Sorter {
public:
    SiteSorter();
    SiteSorter(Sorter * subSorter);
    virtual ~SiteSorter();
    virtual vector<LfcCommand*> * Sort(vector<LfcCommand *> * commands);
protected:
    virtual set<string> ExtractByString(vector<LfcCommand *> * commands);
};

#endif	/* SITESORTER_H */

