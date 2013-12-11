/* 
 * File:   InformationSorter.h
 * Author: radek
 *
 * Created on 11 December 2013, 12:27
 */

#ifndef INFORMATIONSORTER_H
#define	INFORMATIONSORTER_H
#include "Sorter.h"

class InformationSorter : public Sorter {
public:
    InformationSorter();
    InformationSorter(Sorter * subSorter);
    virtual ~InformationSorter();
private:
    virtual string GetItemToSort(LfcCommand * command);
};

#endif	/* INFORMATIONSORTER_H */
