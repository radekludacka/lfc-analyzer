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
    Arguments * arguments = new Arguments();
    arguments->SetFileOrder(3);
    arguments->SetUserOrder(1);
    arguments->SetSiteOrder(2);
    arguments->SetCommandOrder(0);
    arguments->SetResultTypeOrder(-1);

    this->presenter->Print(commands, arguments);
}

void PresenterTests::testMethod2() {

    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();
    Arguments * arguments = new Arguments();
    arguments->SetCommandOrder(0);
    arguments->SetTimeOrder(1);

    Sorter* sorter = new CommandSorter(new TimeSorter(NULL));
    commands = sorter->Sort(commands);

    this->presenter->Print(commands, arguments);
}


