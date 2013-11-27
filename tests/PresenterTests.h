/*
 * File:   PresenterTests.h
 * Author: radek
 *
 * Created on 03-Aug-2013, 14:37:02
 */

#ifndef PRESENTERTESTS_H
#define	PRESENTERTESTS_H

#include <cppunit/extensions/HelperMacros.h>
#include "../MockCommands.h"
#include "../presenter/Presenter.h"
#include "../filter/sorters/Sorter.h"
#include "../filter/sorters/UserSorter.h"
#include "../filter/sorters/SiteSorter.h"
#include "../filter/sorters/FileSorter.h"
#include "../filter/sorters/CommandSorter.h"
#include "../filter/sorters/SuccessSorter.h"
#include "../filter/sorters/TimeSorter.h"
#include "../filter/sorters/NullSorter.h"

using namespace std;

class PresenterTests : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(PresenterTests);

    CPPUNIT_TEST(testMethod);
    CPPUNIT_TEST(testMethod2);

    CPPUNIT_TEST_SUITE_END();

public:
    PresenterTests();
    virtual ~PresenterTests();
    void setUp();
    void tearDown();

private:
    void testMethod();
    void testMethod2();
    
    MockCommands * mockCommands;
    Presenter * presenter;
};

#endif	/* PRESENTERTESTS_H */

