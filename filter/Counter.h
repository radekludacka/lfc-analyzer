/* 
 * File:   Filter.h
 * Author: radek
 *
 * Created on 15 July 2013, 17:25
 */

#ifndef COUNTER_H
#define	COUNTER_H

using namespace std;

#include <vector>
#include "../analyzer2/CommandName.h"
#include "../analyzer2/LfcCommandTable.h"
#include "../analyzer2/CommandName.h"
#include <iostream>
#include <iomanip>
#include <stdio.h>

class Counter {
public:
    Counter();
    virtual ~Counter();
    void FilterCommands(vector<LfcCommand *> * commands);
private:
    void PrintRow(string command, int numberOfFailedCommands, int numberOfSuccessCommands);
};

#endif	/* COUNTER_H */

