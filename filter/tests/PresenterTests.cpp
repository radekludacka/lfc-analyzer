/*
 * File:   PresenterTests.cpp
 * Author: radek
 *
 * Created on 03-Aug-2013, 14:36:14
 */

#include "PresenterTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(PresenterTests);

PresenterTests::PresenterTests() {
    this->filterTest = new FilterTest();
    this->presenter = new Presenter();
}

PresenterTests::~PresenterTests() {
}

void PresenterTests::setUp() {
}

void PresenterTests::tearDown() {
}

void PresenterTests::testMethod() {
    
    vector<LfcCommand *> * commands = filterTest->CreateMockLfcCommands();
 
    this->presenter->Print(commands, 0, -1, -1, -1, -1);
}

