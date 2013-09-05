/*
 * File:   PresenterTests.h
 * Author: radek
 *
 * Created on 03-Aug-2013, 14:36:14
 */

#ifndef PRESENTERTESTS_H
#define	PRESENTERTESTS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../tests/FilterTest.h"
#include "../../presenter/Presenter.h"

using namespace std;

class PresenterTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(PresenterTests);

    CPPUNIT_TEST(testMethod);

    CPPUNIT_TEST_SUITE_END();

public:
    PresenterTests();
    virtual ~PresenterTests();
    void setUp();
    void tearDown();

private:
    void testMethod();
    
    FilterTest * filterTest;
    Presenter * presenter;
};

#endif	/* PRESENTERTESTS_H */

