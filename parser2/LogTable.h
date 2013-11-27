/*
 * LogTable.h
 *
 *  Created on: 8 Jul 2013
 *      Author: radek
 */

#ifndef LOGTABLE_H_
#define LOGTABLE_H_

using namespace std;

#include <vector>
#include "../Item.h"

class LogTable {
public:

    LogTable() {
        myList = new vector<Item*>;
    }

    void addItem(Item * item) {
        myList->push_back(item);
    }

    vector<Item*> * getMyList() const {
        return myList;
    }

    virtual ~LogTable() {
        cout << "SADASFAGFASGFASGAS \n\n\n" << endl;
//        for (vector<Item*>::const_iterator it = myList->begin(); it != myList->end(); it++) {
//            delete *it;
//        }
//        myList->clear();
//        delete myList;
    }

private:
    vector<Item*> * myList;
};

#endif /* LOGTABLE_H_ */
