/* 
 * File:   LfcCommandTable.h
 * Author: radek
 *
 * Created on 12 July 2013, 13:54
 */

#ifndef LFCCOMMANDTABLE_H
#define	LFCCOMMANDTABLE_H

#include "LfcCommand.h"

using namespace std;

class LfcCommandTable {
public:
    LfcCommandTable();
    LfcCommandTable(const LfcCommandTable& orig);
    virtual ~LfcCommandTable();
    vector<LfcCommand*>* GetCommandList() const;
    void add(LfcCommand * command);
private:
    vector<LfcCommand*> * commandList;
};

#endif	/* LFCCOMMANDTABLE_H */

