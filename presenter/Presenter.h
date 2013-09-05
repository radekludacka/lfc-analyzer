/* 
 * File:   Presenter.h
 * Author: radek
 *
 * Created on 31 July 2013, 09:46
 */

#ifndef PRESENTER_H
#define	PRESENTER_H

#include <vector>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <sstream>
#include "../analyzer2/LfcCommand.h"

using namespace std;

class Presenter {
public:
    Presenter();
    virtual ~Presenter();
    virtual void Print(vector<LfcCommand *> * commands, int file, int user, int site, int commandType, int resultType);
private:
    string * ExtractValuesFromCommand(LfcCommand * command, int file, int user, int site, int commandType, int resultType);
    void PrintValues(vector<string *> * rows);
    int * FindOutMaxStringWidths(vector<string *> * rows);
    string IntToString(const int& port);
    
    int numberOfValues;
};

#endif	/* PRESENTER_H */

