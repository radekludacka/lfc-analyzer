/*
 * File:   PresenterTests.cpp
 * Author: radek
 *
 * Created on 03-Aug-2013, 14:37:03
 */

#include "PresenterTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(PresenterTests);

PresenterTests::PresenterTests() {
    this->presenter = new Presenter();
}

PresenterTests::~PresenterTests() {
}

void PresenterTests::setUp() {
}

void PresenterTests::tearDown() {
}

void PresenterTests::testMethod() {
    
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();

    this->presenter->Print(commands, 3, 1, 2, 0, -1);
}

