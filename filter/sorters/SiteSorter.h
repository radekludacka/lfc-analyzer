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
protected:
    virtual string GetItemToSort(LfcCommand * command);
};

#endif	/* SITESORTER_H */

