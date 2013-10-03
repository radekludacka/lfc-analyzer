/* 
 * File:   Filter.h
 * Author: radek
 *
 * Created on 05 August 2013, 20:53
 */

#ifndef FILTER_H
#define	FILTER_H

#include <string>
#include <vector>
#include "../analyzer2/LfcCommand.h"
#include "../analyzer2/CommandName.h"
#include "../Arguments.h"
#include "../analyzer2/CommandName.h"

using namespace std;

class Filter {
public:
    Filter();
    virtual ~Filter();
    vector<LfcCommand*> * Filtrate(vector<LfcCommand*> * commands, Arguments * arguments);
private:
    bool Contains(LfcCommand * command, Arguments * arguments);
    bool IsIn(const char* a, std::string b) ;
};

#endif	/* FILTER_H */

