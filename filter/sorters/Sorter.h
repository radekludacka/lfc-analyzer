/* 
 * File:   Sorter.h
 * Author: radek
 *
 * Created on 30 July 2013, 07:46
 */

#ifndef SORTER_H
#define	SORTER_H

#include "../../analyzer2/LfcCommand.h"
#include <vector>
#include <set>

using namespace std;

class Sorter {
public:
    Sorter();
    Sorter(Sorter * subSorter);
    virtual ~Sorter();
    virtual vector<LfcCommand*> * Sort(vector<LfcCommand *> * commands) = 0;
    
protected:
    Sorter * subSorter;
    
};

#endif	/* SORTER_H */

