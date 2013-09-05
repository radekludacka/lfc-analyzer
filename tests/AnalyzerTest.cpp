/*
 * File:   AnalyzerTest.cpp
 * Author: radek
 *
 * Created on 13-Jul-2013, 12:03:33
 */

#include "AnalyzerTest.h"
#include "../analyzer2/Analyzer.h"
#include "../parser2/LogTable.h"
#include "../parser2/Parser.h"
#include "ParserTests.h"


CPPUNIT_TEST_SUITE_REGISTRATION(AnalyzerTest);

AnalyzerTest::AnalyzerTest() {
    analyzer = new Analyzer();
    mockItems = new MockItems();
}

AnalyzerTest::~AnalyzerTest() {
    delete analyzer;
}

void AnalyzerTest::setUp() {
}

void AnalyzerTest::tearDown() {
}

void AnalyzerTest::testAnalyzer() {
    LogTable * logTable = mockItems->createMockLfcLsItems();
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcLsCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands("07/09 09:58:28.883",
            "07/09 09:58:29.034",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/",
            LFC_LS,
            false,
            lfcLsCommand
            );
}

void AnalyzerTest::testAnalyzer2() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-ls-several-readdir");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcLsCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands(
            "07/09 04:05:50.077",
            "07/09 04:05:50.536",
            "/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio",
            "131.154.200.195",
            "/grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en19.500/th0.65/058357",
            LFC_LS,
            false,
            lfcLsCommand
            );
}

void AnalyzerTest::testAnalyzerLstat() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-ls-2");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcLsCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands("07/12 11:22:40.421",
            "07/12 11:22:40.423",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/neexist",
            LFC_LS,
            true,
            lfcLsCommand
            );
}

void AnalyzerTest::testAnalyzerLstatBrokenPipe() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-ls-broken-pipe");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcLsCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands("07/18 12:55:28.768",
            "07/18 12:57:32.297",
            "/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio",
            "wario.univ-lille1.fr",
            "/grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en18.000/th0.65/057686",
            LFC_LS,
            true,
            lfcLsCommand
            );
}

void AnalyzerTest::testAnalyzerLfcCr() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-cr");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCrCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "07/10 14:25:22.109",
            "07/10 14:25:29.284",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka/text_file2.txt",
            LCG_CR,
            false,
            lfcCrCommand
            );
}

void AnalyzerTest::testAnalyzerLfcCrFail() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-cr-fail-already-exists");

    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCrCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands("07/16 15:52:05.000",
            "07/16 15:52:05.004",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka/text_file.txt",
            LFC_LS,
//            LCG_CR,
            false,
            lfcCrCommand
            );
}

void AnalyzerTest::testAnalyzerLfcRepDelFail() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-rep-del-cp-fail");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcRepCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands(
            "07/09 13:00:40.692",
            "07/09 13:00:40.750",
            "/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio",
            "wario.univ-lille1.fr",
            "/grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en19.500/th0.65/058357",
            LCG_REP,
            true,
            lfcRepCommand
            );
}

void AnalyzerTest::testAnalyzerLfcRep() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-rep");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcRepCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands(
            "07/16 16:01:30.251",
            "07/16 16:01:45.873",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "2045789b-6209-446f-83bc-ae32603b4ac7 se.polgrid.pl srm://se.polgrid.pl/dpm/polgrid.pl/home/voce/generated/2013-07-16/fileea0f5c07-9b32-45a8-8213-4f8c92b896b6",
            LCG_REP,
            false,
            lfcRepCommand
            );
}

void AnalyzerTest::testAnalyzerLfcMkDir() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-mkdir");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcMkDirCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands("07/10 19:21:50.736",
            "07/10 19:21:50.740",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka2",
            LFC_MKDIR,
            false,
            lfcMkDirCommand
            );
}

void AnalyzerTest::testAnalyzerLfcMkDirExistsYet() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-mkdir-exists-yet");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcMkDirCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands("07/17 13:43:58.752",
            "07/17 13:43:58.755",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka",
            LFC_MKDIR,
            true,
            lfcMkDirCommand
            );
}

void AnalyzerTest::testAnalyzerLfcCp() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-cp");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCpCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    cout << lfcCpCommand->GetFile() << endl;

    compareLfcCommands("07/09 16:12:11.803",
            "07/09 16:12:11.941",
            "/DC=es/DC=irisgrid/O=ugr/CN=mdserrano",
            "wn37.m3pec.u-bordeaux1.fr",
            "/grid/auger/prod/GenDisIronEpos_gr248/en20.000/th0.65/057105/DAT571058.tar.gz",
            LCG_CP,
            false,
            lfcCpCommand
            );
}

void AnalyzerTest::testAnalyzerLfcDelReplica() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-del-replica");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcDelCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands(
            "07/19 10:12:07.567",
            "07/19 10:12:11.280",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "a70321fd-1ebc-49e0-86b4-fe6a8f68b199 srm://dpm1.egee.cesnet.cz/dpm/cesnet.cz/home/voce/generated/2013-07-19/filebfec4476-acfd-4413-a7c9-6607cd6d535f",
            LCG_DEL,
            false,
            lfcDelCommand
            );
}

void AnalyzerTest::testAnalyzerLfcDelRemain() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-del-remain");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcDelCommand = *commands->begin();

    allItemsAssigned(logTable);

    compareLfcCommands(
            "07/18 15:46:24.732",
            "07/18 15:46:27.577",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka/text_file8.txt",
            LCG_DEL,
            false,
            lfcDelCommand
            );
}

void AnalyzerTest::testAnalyzerLfcDelAll() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-del-all");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcDelCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "07/19 10:43:07.460",
            "07/19 10:43:23.261",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka/text_file.txt",
            LCG_DEL,
            false,
            lfcDelCommand
            );
}

void AnalyzerTest::testAnalyzerLfcDelAll2() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-del-all-2");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcDelCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "11/30 13:29:22.362",
            "11/30 13:29:30.238",
            "/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio",
            "cream-cafpegrid.ugr.es",
            "/grid/auger/prod/GenDisProtonQGSjetII_gr218/en20.500/th0.65/033630/DAT336303.small.tar",
            LCG_DEL,
            false,
            lfcDelCommand
            );
}

void AnalyzerTest::testAnalyzerLfcServ() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-serv-bad-auth");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "11/30 04:21:25.123",
            "11/30 04:21:25.123",
            "UNKNOWN",
            "wn083.pleiades.uni-wuppertal.de",
            "",
            LCG_NONE,
            true,
            lfcCommand
            );
}

void AnalyzerTest::testAnalyzerLfcServTimedOut() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-serv-timed-out");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "11/30 05:07:09.707",
            "11/30 05:07:09.707",
            "UNKNOWN",
            "nat105.farm.particle.cz",
            "",
            LCG_NONE,
            true,
            lfcCommand
            );
}

void AnalyzerTest::testAnalyzerLfcUtime() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-utime");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "11/30 07:45:39.237",
            "11/30 07:45:39.240",
            "/DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec",
            "nagios.egee.cesnet.cz",
            "/grid/ops/file-lfc-probe-lfc1.egee.cesnet.cz 0",
            LCG_UTIME,
            false,
            lfcCommand
            );
}

void AnalyzerTest::testAnalyzerLfcCr2() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-cr-2");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "07/24 14:26:10.630",
            "07/24 14:26:27.806",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/generated/2013-07-24/file-eaccd6a3-786e-4c91-a660-39e717be4ecd",
            LCG_CR,
            false,
            lfcCommand
            );
}

void AnalyzerTest::testAnalyzerLfcCr3() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-cr-3");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "07/24 14:26:27.673",
            "07/24 14:26:27.806",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/generated/2013-07-24/file-eaccd6a3-786e-4c91-a660-39e717be4ecd",
            LCG_CR,
            false,
            lfcCommand
            );
}

void AnalyzerTest::testAnalyzerLfcPingDB() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-pingdb");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "11/30 07:58:36.747",
            "11/30 07:58:36.747",
            "UNKNOWN",
            "",
            "",
            LCG_PINGDB,
            true,
            lfcCommand
            );
}

//07/18 09:50:16.492 20713,1 Cns_srv_getreplica: NS092 - getreplica request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz
//07/18 09:50:16.492 20713,1 Cns_srv_getreplica: NS098 - getreplica /grid/voce/ludacka/text_file.txt 
//07/18 09:50:16.495 20713,1 Cns_srv_getreplica: returns 0

void AnalyzerTest::testAnalyzerLfcLr() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-lr");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    cout << lfcCommand->GetFile() << endl;
    
    compareLfcCommands(
            "07/18 09:50:16.492",
            "07/18 09:50:16.495",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka/text_file.txt",
            LCG_LR,
            false,
            lfcCommand
            );
}

void AnalyzerTest::testAnalyzerLfcLsRecursive() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-ls-recursive");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    cout << lfcCommand->GetFile() << endl;
    
    compareLfcCommands(
            "07/26 16:35:46.739",
            "07/26 16:35:46.830",
            "/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio",
            "wario.univ-lille1.fr",
            "/grid/voce/ludacka/dir3",
            LFC_LS,
            false,
            lfcCommand
            );
}

void AnalyzerTest::testAnalyzerLfcAA() {
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-aa");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "07/18 14:54:28.939",
            "07/18 14:54:29.134",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka/text_file.txt /grid/voce/ludacka/text_file10.txt",
            LCG_AA,
            false,
            lfcCommand
            );
}

void AnalyzerTest::testAnalyzerLfcRmDir() {
    // TODO: How is it with directories ?
    
    Parser * parser = new Parser();
    LogTable * logTable = parser->parse("tests/resources/lfc-rm-dir");
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commands = commandTable->GetCommandList();
    LfcCommand * lfcCommand = *commands->begin();

    allItemsAssigned(logTable);
    
    compareLfcCommands(
            "07/10 19:28:38.919",
            "07/10 19:28:41.426",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka2",
            LCG_RM,
            false,
            lfcCommand
            );
}

void AnalyzerTest::compareLfcCommands(
        string start, string end, string userP, string siteP,
        string fileP, LFCCommandName name, bool failed, LfcCommand * lfcCommand) {

    LogTime * startTime = new LogTime(start);
    LogTime * endTime = new LogTime(end);
    User * user = new User(userP);
    Site * site = new Site(siteP);

    CPPUNIT_ASSERT(*startTime == (lfcCommand->GetStartTime()));
    CPPUNIT_ASSERT(*endTime == (lfcCommand->GetEndTime()));
    CPPUNIT_ASSERT(*user == *lfcCommand->GetUser());
    CPPUNIT_ASSERT(*site == *lfcCommand->GetSite());
    CPPUNIT_ASSERT(fileP.compare(lfcCommand->GetFile()) == 0);
    CPPUNIT_ASSERT(name == lfcCommand->GetName());
    CPPUNIT_ASSERT(failed == lfcCommand->IsFailed());
}

void AnalyzerTest::allItemsAssigned(LogTable* logTable) {
    vector<Item *> * items = logTable->getMyList();

    vector<Item *>::iterator iterator = items->begin();
    for (iterator = items->begin(); iterator != items->end(); ++iterator) {
        Item * item = *iterator;
        
        CPPUNIT_ASSERT(true == item->IsAssigned());
    }
}


