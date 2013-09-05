/*
 * File:   FilterTest.h
 * Author: radek
 *
 * Created on 30-Jul-2013, 09:23:38
 */

#ifndef FILTERTEST_H
#define	FILTERTEST_H

#include "../Filter.h"
#include "../../analyzer2/CommandName.h"
#include "../Counter.h"
#include "../sorters/Sorter.h"
#include "../sorters/UserSorter.h"
#include "../sorters/SiteSorter.h"
#include "../sorters/FileSorter.h"
#include "../sorters/CommandSorter.h"
#include "../sorters/SuccessSorter.h"
#include "../../MockCommands.h"
#include <vector>
#include <cppunit/extensions/HelperMacros.h>

using namespace std;

class FilterTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(FilterTest);

    CPPUNIT_TEST(testFilterFile);
    CPPUNIT_TEST(testFilterUser);
    CPPUNIT_TEST(testFilterCommand);
    CPPUNIT_TEST(testFilterSuccessValue);
    CPPUNIT_TEST(testFilterSite);
    
    CPPUNIT_TEST(testSortByUser);
    CPPUNIT_TEST(testSortByUserAndSite);
    CPPUNIT_TEST(testSortByFile);
    CPPUNIT_TEST(testSortByCommand);
    CPPUNIT_TEST(testSortByResultType);

    CPPUNIT_TEST_SUITE_END();

public:
    FilterTest();
    virtual ~FilterTest();
    void setUp();
    void tearDown();
    
private:
    void testFilterFile();
    void testFilterUser();
    void testFilterCommand();
    void testFilterSuccessValue();
    void testFilterSite();
    
    void testSortByUser();
    void testSortByUserAndSite();
    void testSortByFile();
    void testSortByCommand();
    void testSortByResultType();
    
    vector<string> ExtractUserNames(vector<LfcCommand *> * commands);
    vector<string> ExtractSiteNames(vector<LfcCommand *> * commands);
    vector<string> ExtractFileNames(vector<LfcCommand *> * commands);
    vector<string> ExtractCommandNames(vector<LfcCommand *> * commands);
    vector<bool> ExtractResultTypes(vector<LfcCommand *> * commands);
    void CompareStringVectors(vector<string> vector1, vector<string> vector2);
    void CompareBoolVectors(vector<bool> vector1, vector<bool> vector2);

    Filter * filter;
    Sorter * sorter;
    MockCommands * mockCommands;
};

#endif	/* FILTERTEST_H */

