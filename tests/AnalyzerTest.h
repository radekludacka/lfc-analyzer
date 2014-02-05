/*
 * File:   AnalyzerTest.h
 * Author: radek
 *
 * Created on 13-Jul-2013, 12:03:32
 */

#ifndef ANALYZERTEST_H
#define	ANALYZERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../analyzer2/Analyzer.h"
#include "../MockItems.h"
#include "../analyzer2/CommandName.h"
#include "../analyzer2/LfcCommand.h"
#include "../analyzer2/LfcCommandTable.h"

class AnalyzerTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(AnalyzerTest);

    CPPUNIT_TEST(testAnalyzer);
    CPPUNIT_TEST(testAnalyzer2);
    CPPUNIT_TEST(testAnalyzerLstat);
    CPPUNIT_TEST(testAnalyzerLstatBrokenPipe);
    CPPUNIT_TEST(testAnalyzerLfcCr);
    CPPUNIT_TEST(testAnalyzerLfcCrFail);
    CPPUNIT_TEST(testAnalyzerLfcRepDelFail);
    CPPUNIT_TEST(testAnalyzerLfcRep);
    CPPUNIT_TEST(testAnalyzerLfcMkDir);
    CPPUNIT_TEST(testAnalyzerLfcMkDirExistsYet);
    CPPUNIT_TEST(testAnalyzerLfcCp);
    CPPUNIT_TEST(testAnalyzerLfcDelReplica);
    CPPUNIT_TEST(testAnalyzerLfcDelRemain);
    CPPUNIT_TEST(testAnalyzerLfcDelRemain2);
    CPPUNIT_TEST(testAnalyzerLfcDelAll);
    CPPUNIT_TEST(testAnalyzerLfcDelAll2);
    CPPUNIT_TEST(testAnalyzerLfcServ);
    CPPUNIT_TEST(testAnalyzerLfcServTimedOut);
    CPPUNIT_TEST(testAnalyzerLfcUtime);
    CPPUNIT_TEST(testAnalyzerLfcPingDB);
    CPPUNIT_TEST(testAnalyzerLfcCr2);
    CPPUNIT_TEST(testAnalyzerLfcCr3);
    CPPUNIT_TEST(testAnalyzerLfcLr);
    CPPUNIT_TEST(testAnalyzerLfcLsRecursive);
    CPPUNIT_TEST(testAnalyzerLfcAA);
    CPPUNIT_TEST(testAnalyzerLfcRmDir);
    CPPUNIT_TEST(testAnalyzerLfcAAFailed);
    CPPUNIT_TEST(testAnalyzeUnkownCommand1);

    CPPUNIT_TEST_SUITE_END();

public:
    AnalyzerTest();
    virtual ~AnalyzerTest();
    void setUp();
    void tearDown();

private:
    void allItemsAssigned(LogTable * logTable);
    void testAnalyzer();
    void testAnalyzer2();
    void testAnalyzerLstat();
    void testAnalyzerLstatBrokenPipe();
    void testAnalyzerLfcCr();
    void testAnalyzerLfcCrFail();
    void testAnalyzerLfcRepDelFail();
    void testAnalyzerLfcRep();
    void testAnalyzerLfcMkDir();
    void testAnalyzerLfcMkDirExistsYet();
    void testAnalyzerLfcCp();
    void testAnalyzerLfcDelReplica();
    void testAnalyzerLfcDelRemain();
    void testAnalyzerLfcDelRemain2();
    void testAnalyzerLfcDelAll();
    void testAnalyzerLfcDelAll2();
    void testAnalyzerLfcServ();
    void testAnalyzerLfcServTimedOut();
    void testAnalyzerLfcUtime();
    void testAnalyzerLfcPingDB();
    void testAnalyzerLfcCr2();
    void testAnalyzerLfcCr3();
    void testAnalyzerLfcLr();
    void testAnalyzerLfcLsRecursive();
    void testAnalyzerLfcAA();
    void testAnalyzerLfcRmDir();
    void testAnalyzerLfcAAFailed();
    void testAnalyzeUnkownCommand1();
    
    void compareLfcCommands(
            string start, string end, string userP, string siteP,
            string fileP, LFCCommandName name,  bool fail, LfcCommand * lfcCommand);
    
    Analyzer * analyzer;
    MockItems * mockItems;
};

#endif	/* ANALYZERTEST_H */

