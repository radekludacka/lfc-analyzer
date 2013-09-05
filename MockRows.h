/* 
 * File:   MockRows.h
 * Author: radek
 *
 * Created on 13 July 2013, 13:06
 */

#ifndef MOCKROWS_H
#define	MOCKROWS_H

using namespace std;

#include <vector>
#include "parser2/Parser.h"

class MockRows {
public:
    MockRows();
    virtual ~MockRows();

    vector<Row *> * createMockLstatRows();
    vector<Row *> * createMockAccess();
    vector<Row *> * createMockOpenDir();
    vector<Row *> * createMockReadDir();
    vector<Row *> * createMockReadCloseDir();
    vector<Row *> * createMockStartSess();
    vector<Row *> * createMockDelReplica();
    vector<Row *> * createMockGetReplica();
    vector<Row *> * createMockUnlink();
    vector<Row *> * createMockGetLinks();
    vector<Row *> * createMockEndSess();
    vector<Row *> * createMockStartTrans();
    vector<Row *> * createMockStatg();
    vector<Row *> * createMockCreat();
    vector<Row *> * createMockAddReplica();
    vector<Row *> * createMockSetfSizeg();
    vector<Row *> * createMockEndTrans();
    vector<Row *> * createMockMkDir();
    vector<Row *> * createMockStatr();
    vector<Row *> * createMockServ();
    vector<Row *> * createMockReadDirClosed();
    vector<Row *> * createMockBadProxy();
    vector<Row *> * createMockTimedOut();
    vector<Row *> * createMockUtime();
    vector<Row *> * createMockServiceName();
    vector<Row *> * createMockMySQLGoneAway();
    vector<Row *> * createMockSymlink();
    vector<Row *> * createMockGetPath();
    vector<Row *> * createMockChangeDir();
    vector<Row *> * createMockRmDir();
private:
    Parser * parser;
};

#endif	/* MOCKROWS_H */

