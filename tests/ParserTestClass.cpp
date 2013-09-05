/*
 * File:   newtestclass1.cpp
 * Author: radek
 *
 * Created on 12-Jul-2013, 19:26:56
 */

#include "newtestclass1.h"
#include "Parser.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass1);

newtestclass1::newtestclass1() {
}

newtestclass1::~newtestclass1() {
}

void newtestclass1::setUp() {
}

void newtestclass1::tearDown() {
}

void newtestclass1::testParseItems() {
    vector<Row*>* rows;
    Parser parser;
    LogTable* result = parser.parseItems(rows);
    if (true /*check result*/) {
        CPPUNIT_ASSERT(false);
    }
}

