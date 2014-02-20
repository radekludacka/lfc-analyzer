/* 
 * File:   TimeSorter.h
 * Author: radek
 *
 * Created on 23 October 2013, 16:27
 */

#ifndef TIMESORTER_H
#define	TIMESORTER_H

#include "Sorter.h"
#include <math.h>
#include <assert.h>
#include <limits.h>

using namespace std;

class TimeSorter : public Sorter  {
public:
    TimeSorter();
    TimeSorter(Sorter * subSorter);
    virtual ~TimeSorter();
    void SetPrintCommandsOutput(bool printCommandsOutput);
    bool IsPrintCommandsOutput() const;
protected:
    virtual string GetItemToSort(LfcCommand * command);
    vector<LfcCommand * > * Sort(vector<LfcCommand*> * commands);
    double CalculateStandardDeviation(vector<LfcCommand*> * commands, double mean);
private:
    bool printCommandsOutput;
};

#endif	/* TIMESORTER_H */

