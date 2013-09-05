/* 
 * File:   MockItems.cpp
 * Author: radek
 * 
 * Created on 13 July 2013, 13:23
 */

#include "MockItems.h"

MockItems::MockItems() {
    mockRows = new MockRows();
    parser = new Parser();
}

MockItems::~MockItems() {
}

LogTable * MockItems::createMockLfcLsItems() {
    vector<Row *> * rows = mockRows->createMockLstatRows();
    vector<Row *> * openDirRows = mockRows->createMockOpenDir();
    vector<Row *> * readDirRows = mockRows->createMockReadDir();
    vector<Row *> * readDirCloseRows = mockRows->createMockReadCloseDir();

    rows->insert(rows->end(), openDirRows->begin(), openDirRows->end());
    rows->insert(rows->end(), readDirRows->begin(), readDirRows->end());
    rows->insert(rows->end(), readDirCloseRows->begin(), readDirCloseRows->end());

    return parser->parseItems(rows);
}

