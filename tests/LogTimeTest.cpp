/*
 * File:   LogTimeTest.cpp
 * Author: radek
 *
 * Created on 31-Oct-2013, 15:15:11
 */

#include "LogTimeTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(LogTimeTest);

LogTimeTest::LogTimeTest() {
}

LogTimeTest::~LogTimeTest() {
}

void LogTimeTest::setUp() {
    parser = new Parser();
    mockRows = new MockRows();
    mockItems = new MockItems();
}

void LogTimeTest::tearDown() {
}

void LogTimeTest::testPlus() {
//  "07/09 09:58:28.953",
//  "07/09 09:58:28.954",
    vector<Row*>* rows = mockRows->createMockOpenDir();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    LogTime * sum = item->GetEndTime()->plus(item->GetStartTime());
    LogTime * wellSum = new LogTime("01/00 01:56:57.907");
    
    CPPUNIT_ASSERT(sum->asString().compare(wellSum->asString()) == 0);
}

void LogTimeTest::testDivTwo() {
//            "07/18 14:54:29.048"

    LogTime * time = new LogTime("01/00 14:54:29.048");
    
    LogTime * divided = time->divTwo();
    LogTime * wellDivided = new LogTime("01/00 07:27:14.524");
    
    CPPUNIT_ASSERT(divided->asString().compare(wellDivided->asString()) == 0);
}
