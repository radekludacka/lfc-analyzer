/*
 * File:   LogTimeTest.h
 * Author: radek
 *
 * Created on 31-Oct-2013, 15:15:11
 */

#ifndef LOGTIMETEST_H
#define	LOGTIMETEST_H

using namespace std;

#include <cppunit/extensions/HelperMacros.h>
#include <vector>
#include <string>
#include "../parser2/Parser.h"
#include <iostream>
#include "../MockRows.h"
#include "../MockItems.h"

#include <cppunit/extensions/HelperMacros.h>

class LogTimeTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(LogTimeTest);

    CPPUNIT_TEST(testPlus);
    CPPUNIT_TEST(testDivTwo);

    CPPUNIT_TEST_SUITE_END();

public:
    LogTimeTest();
    virtual ~LogTimeTest();
    void setUp();
    void tearDown();

private:
    void testPlus();
    void testDivTwo();
    
    Parser * parser;
    MockRows * mockRows;
    MockItems * mockItems;
};

#endif	/* LOGTIMETEST_H */

