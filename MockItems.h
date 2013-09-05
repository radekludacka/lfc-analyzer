/* 
 * File:   MockItems.h
 * Author: radek
 *
 * Created on 13 July 2013, 13:23
 */

#ifndef MOCKITEMS_H
#define	MOCKITEMS_H
#include "MockRows.h"
#include "parser2/Parser.h"

using namespace std;

class MockItems {
public:
    MockItems();
    virtual ~MockItems();
    LogTable * createMockLfcLsItems();
private:
    MockRows * mockRows;
    Parser * parser;
};

#endif	/* MOCKITEMS_H */

