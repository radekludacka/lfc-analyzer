/* 
 * File:   FileSorter.h
 * Author: radek
 *
 * Created on 30 July 2013, 16:54
 */

#ifndef FILESORTER_H
#define	FILESORTER_H
#include "Sorter.h"

class FileSorter : public Sorter {
public:
    FileSorter();
    FileSorter(Sorter * subSorter);
    virtual ~FileSorter();
protected:
    virtual string GetItemToSort(LfcCommand * command);
};

#endif	/* FILESORTER_H */

