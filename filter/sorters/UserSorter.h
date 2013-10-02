/* 
 * File:   UserSorter.h
 * Author: radek
 *
 * Created on 30 July 2013, 07:57
 */

#ifndef USERSORTER_H
#define	USERSORTER_H

#include "Sorter.h"

using namespace std;

class UserSorter : public Sorter {
public:
    UserSorter();
    UserSorter(Sorter * subSorter);
    virtual ~UserSorter();
protected:
    virtual string GetItemToSort(LfcCommand * command);
};

#endif	/* USERSORTER_H */

