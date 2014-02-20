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

void LogTimeTest::testMillisecondsConstructor() {
    LogTime * time = new LogTime(1235467);
    
    string wellResult("00/00 03:25:45.678");
    string formatedTime = time->asString();
    
    CPPUNIT_ASSERT(wellResult.compare(formatedTime));
}
