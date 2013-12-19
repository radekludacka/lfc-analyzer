/*
 * File:   ParserTests.h
 * Author: radek
 *
 * Created on 12-Jul-2013, 19:28:13
 */

#ifndef PARSERTESTS_H
#define	PARSERTESTS_H

using namespace std;

#include <cppunit/extensions/HelperMacros.h>
#include <vector>
#include <string>
#include "../parser2/Parser.h"
#include <iostream>
#include "../MockRows.h"
#include "../MockItems.h"

class ParserTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ParserTests);

    CPPUNIT_TEST(testParseItemsLstat);
    CPPUNIT_TEST(testParseItemsAccess);
    CPPUNIT_TEST(testParseItemsOpenDir);
    CPPUNIT_TEST(testParseItemsReadDir);
    CPPUNIT_TEST(testParseItemsStartSess);
    CPPUNIT_TEST(testParseItemsDelReplica);
    CPPUNIT_TEST(testParseItemsGetReplica);
    CPPUNIT_TEST(testParseItemsUnlink);
    CPPUNIT_TEST(testParseItemsGetLinks);
    CPPUNIT_TEST(testParseItemsEndSess);
    CPPUNIT_TEST(testParseItemsStartTrans);
    CPPUNIT_TEST(testParseItemsStatg);
    CPPUNIT_TEST(testParseItemsCreat);
    CPPUNIT_TEST(testParseItemsAddReplica);
    CPPUNIT_TEST(testParseItemsSetfSizeg);
    CPPUNIT_TEST(testParseItemsEndTrans);
    CPPUNIT_TEST(testParseItemsMkdir);
    CPPUNIT_TEST(testParseItemsStatr);
    CPPUNIT_TEST(testParseItemsServ);
    CPPUNIT_TEST(testParseItemsReadDirConnectionClosed);
    CPPUNIT_TEST(testParseItemsBedProxy);
    CPPUNIT_TEST(testParseItemsTimedOut);
    CPPUNIT_TEST(testParseItemsUtime);
    CPPUNIT_TEST(testParseItemsServiceName);
    CPPUNIT_TEST(testParseItemsMySQLGoneAway);
    CPPUNIT_TEST(testParseItemsSymlink);
    CPPUNIT_TEST(testParseItemsGetPath);
    CPPUNIT_TEST(testParseItemsChangeDir);
    CPPUNIT_TEST(testParseItemsRmDir);
    CPPUNIT_TEST(testParseRow);
    CPPUNIT_TEST(testParseItemsServAbortTransaction);

    CPPUNIT_TEST_SUITE_END();

public:
    ParserTests();
    virtual ~ParserTests();
    void setUp();
    void tearDown();

private:
    void testParseItemsLstat();
    void testParseItemsAccess();
    void testParseItemsOpenDir();
    void testParseItemsReadDir();
    void testParseItemsStartSess();
    void testParseItemsDelReplica();
    void testParseItemsGetReplica();
    void testParseItemsUnlink();
    void testParseItemsGetLinks();
    void testParseItemsEndSess();
    void testParseItemsStartTrans();
    void testParseItemsStatg();
    void testParseItemsCreat();
    void testParseItemsAddReplica();
    void testParseItemsSetfSizeg();
    void testParseItemsEndTrans();
    void testParseItemsMkdir();
    void testParseItemsStatr();
    void testParseItemsServ();
    void testParseItemsReadDirConnectionClosed();
    void testParseItemsBedProxy();
    void testParseItemsTimedOut();
    void testParseItemsUtime();
    void testParseItemsServiceName();
    void testParseItemsMySQLGoneAway();
    void testParseItemsSymlink();
    void testParseItemsGetPath();
    void testParseItemsChangeDir();
    void testParseItemsRmDir();
    void testParseRow();
    void testParseItemsServAbortTransaction();

    void compareItems(string, string, string, string, string, FunctionType, int, string, int, Item *);

    Parser * parser;
    MockRows * mockRows;
    MockItems * mockItems;
};

#endif	/* PARSERTESTS_H */

