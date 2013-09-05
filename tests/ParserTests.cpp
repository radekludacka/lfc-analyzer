/*
 * File:   ParserTests.cpp
 * Author: radek
 *
 * Created on 12-Jul-2013, 19:28:13
 */

#include "ParserTests.h"
#include "../parser2/Parser.h"


CPPUNIT_TEST_SUITE_REGISTRATION(ParserTests);

ParserTests::ParserTests() {
    parser = NULL;
}

ParserTests::~ParserTests() {
}

void ParserTests::setUp() {
    parser = new Parser();
    mockRows = new MockRows();
    mockItems = new MockItems();
}

void ParserTests::tearDown() {
    delete parser;
    delete mockRows;
}

void ParserTests::testParseItemsLstat() {
    vector<Row*>* rows = mockRows->createMockLstatRows();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 09:58:28.883",
            "07/09 09:58:28.884",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/",
            LSTAT, 0, "", 0,
            item);
}

void ParserTests::testParseItemsAccess() {
    vector<Row*>* rows = mockRows->createMockAccess();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 04:02:20.747",
            "07/09 04:02:20.750",
            "/DC=es/DC=irisgrid/O=ugr/CN=Julio.Lozano.Bahilo",
            "grid-wn292.physik.rwth-aachen.de",
            "/grid/auger/prod/B2015IronQGSjetII_gr266_XHdSimv2r9p1/en19.800/th0.000/066317/DAT663174_01.offline-v2r9p1.AHdSimOffline.root",
            ACCESS, 0, "6", 1,
            item);
}

void ParserTests::testParseItemsOpenDir() {
    vector<Row*>* rows = mockRows->createMockOpenDir();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 09:58:28.953",
            "07/09 09:58:28.954",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/",
            OPENDIR, 0, "", 0,
            item);
}

void ParserTests::testParseItemsReadDir() {
    vector<Row*>* rows = mockRows->createMockReadDir();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 09:58:28.985",
            "07/09 09:58:28.994",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "",
            READDIR, 0, "", 0,
            item);
}

void ParserTests::testParseItemsStartSess() {
    vector<Row*>* rows = mockRows->createMockStartSess();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 04:05:51.024",
            "07/09 04:05:51.024",
            "/O=GRID-FR/C=FR/O=CNRS/OU=LAL/CN=Jean-Noel Albert",
            "ccwsge0246.in2p3.fr",
            "",
            STARTSESS, 0, "", 2,
            item);
}

void ParserTests::testParseItemsDelReplica() {
    vector<Row*>* rows = mockRows->createMockDelReplica();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 04:06:05.407",
            "07/09 04:06:05.414",
            "/DC=es/DC=irisgrid/O=ugr/CN=mdserrano",
            "gnet-74.lip.pt",
            "0d9d5dc9-0848-4789-b509-5e0ade8eef5c srm://prod-se-02.ct.infn.it/auger//grid/auger/prod/GenDisIronEpos_gr248/en20.000/th0.65/057161/DAT571611.tar.gz",
            DELREPLICA, 0, "", 1,
            item);
}

void ParserTests::testParseItemsGetReplica() {
    vector<Row*>* rows = mockRows->createMockGetReplica();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 04:06:05.583",
            "07/09 04:06:05.584",
            "/DC=es/DC=irisgrid/O=ugr/CN=mdserrano",
            "gnet-74.lip.pt",
            "0d9d5dc9-0848-4789-b509-5e0ade8eef5c",
            GETREPLICA, 0, "", 1,
            item);
}

void ParserTests::testParseItemsUnlink() {
    vector<Row*>* rows = mockRows->createMockUnlink();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 04:06:05.781",
            "07/09 04:06:05.794",
            "/DC=es/DC=irisgrid/O=ugr/CN=mdserrano",
            "gnet-74.lip.pt",
            "/grid/auger/prod/GenDisIronEpos_gr248/en20.000/th0.65/057161/DAT571611.tar.gz",
            UNLINK, 0, "", 1,
            item);
}

void ParserTests::testParseItemsGetLinks() {
    vector<Row*>* rows = mockRows->createMockGetLinks();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 04:11:35.572",
            "07/09 04:11:35.575",
            "/DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec",
            "skurut19.grid.cesnet.cz",
            "df8aebb1-4fc5-45df-bf94-9c2d16c59b63",
            GETLINKS, 0, "", 0,
            item);
}

void ParserTests::testParseItemsEndSess() {
    vector<Row*>* rows = mockRows->createMockEndSess();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 04:11:35.625",
            "07/09 04:11:35.625",
            "/DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec",
            "skurut19.grid.cesnet.cz",
            "",
            ENDSESS, 0, "", 0,
            item);
}

void ParserTests::testParseItemsStartTrans() {
    vector<Row*>* rows = mockRows->createMockStartTrans();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 04:11:35.694",
            "07/09 04:11:35.695",
            "/DC=es/DC=irisgrid/O=ugr/CN=mdserrano",
            "wn-204-03-15-02-b.cr.cnaf.infn.it",
            "",
            STARTTRANS, 0, "", 1,
            item);
}

void ParserTests::testParseItemsStatg() {
    vector<Row*>* rows = mockRows->createMockStatg();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 04:11:35.717",
            "07/09 04:11:35.723",
            "/DC=es/DC=irisgrid/O=ugr/CN=mdserrano",
            "wn-204-03-15-02-b.cr.cnaf.infn.it",
            "/grid/auger/prod/GenDisIronEpos_gr248/en20.000/th0.65/057185/DAT571858.tar.gz 565a950a-2748-4159-8c71-7bbf53fed931",
            STATG, 2, "", 1,
            item);
}

void ParserTests::testParseItemsCreat() {
    vector<Row*>* rows = mockRows->createMockCreat();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();

    this->compareItems(
            "07/09 04:11:35.793",
            "07/09 04:11:35.798",
            "/DC=es/DC=irisgrid/O=ugr/CN=mdserrano",
            "wn-204-03-15-02-b.cr.cnaf.infn.it",
            "/grid/auger/prod/GenDisIronEpos_gr248/en20.000/th0.65/057185/DAT571858.tar.gz 565a950a-2748-4159-8c71-7bbf53fed931 664 22",
            CREAT, 0, "file 37337945 created", 1,
            item);
}

void ParserTests::testParseItemsAddReplica() {
    vector<Row*>* rows = mockRows->createMockAddReplica();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/12 04:02:09.473",
            "07/12 04:02:09.495",
            "/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio",
            "wn07-grid.obspm.fr",
            "48607b2d-9840-4d31-ac61-2d939fd52407 grid05.lal.in2p3.fr srm://grid05.lal.in2p3.fr/dpm/lal.in2p3.fr/home/auger//grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en20.500/th0.65/058744/DAT587449_01.offline-v2r9p3.HdSimRecADST.root",
            ADDREPLICA, 0, "", 8,
            item);
}

void ParserTests::testParseItemsSetfSizeg() {
    vector<Row*>* rows = mockRows->createMockSetfSizeg();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/12 04:02:10.325",
            "07/12 04:02:10.329",
            "/DC=es/DC=irisgrid/O=ugr/CN=mdserrano",
            "fnpc3046.fnal.gov",
            "3f1fa9b9-d0ab-45e4-a337-9d62d64e07d4 14220686",
            SETFSIZEG, 0, "", 9,
            item);
}

void ParserTests::testParseItemsEndTrans() {
    vector<Row*>* rows = mockRows->createMockEndTrans();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/12 04:02:27.936",
            "07/12 04:02:28.010",
            "/DC=es/DC=irisgrid/O=ugr/CN=Julio.Lozano.Bahilo",
            "wario.univ-lille1.fr",
            "",
            ENDTRANS, 0, "", 5,
            item);
}

void ParserTests::testParseItemsMkdir() {
    vector<Row*>* rows = mockRows->createMockMkDir();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/17 08:31:37.774",
            "07/17 08:31:37.780",
            "/DC=es/DC=irisgrid/O=ugr/CN=Julio.Lozano.Bahilo",
            "d0cs3048.fnal.gov",
            "/grid/auger/prod/B2015IronQGSjetII_gr277_XHdSimv2r9p1/en18.900/th0.60/068276  777 22",
            MKDIR, 0, "", 1,
            item);
}

void ParserTests::testParseItemsStatr() {
    vector<Row*>* rows = mockRows->createMockStatr();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/18 15:46:24.733",
            "07/18 15:46:24.734",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "srm://dpm1.egee.cesnet.cz/dpm/cesnet.cz/home/voce/generated/2013-07-18/fileda937a3c-4112-4d56-a34e-9866967cfe44",
            STATR, 0, "", 1,
            item);
}

void ParserTests::testParseItemsServ() {
    vector<Row*>* rows = mockRows->createMockServ();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/18 12:59:27.527",
            "07/18 12:59:27.642",
            "/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio",
            "wario.univ-lille1.fr",
            "",
            CLOSEDIR, 0, "Connection reset by peer Broken pipe", 4,
            item);
}

void ParserTests::testParseItemsReadDirConnectionClosed() {
    vector<Row*>* rows = mockRows->createMockReadDirClosed();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/18 07:26:16.595",
            "07/18 07:26:16.634",
            "/DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec",
            "nagios.egee.cesnet.cz",
            "",
            CLOSEDIR, 0, "Connection closed by remote end", 1,
            item);
}

void ParserTests::testParseItemsBedProxy() {
    vector<Row*>* rows = mockRows->createMockBadProxy();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "11/30 04:21:25.095",
            "11/30 04:21:25.095",
            "",
            "wn083.pleiades.uni-wuppertal.de",
            "",
            SERV, 
            0,
            "Could not establish an authenticated connection: server_establish_context_ext: The client itself detected a problem with the user proxy, it was probably missing or expired !",
            1,
            item);
}

void ParserTests::testParseItemsTimedOut() {
    vector<Row*>* rows = mockRows->createMockTimedOut();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "11/30 05:07:09.707",
            "11/30 05:07:09.707",
            "",
            "nat105.farm.particle.cz",
            "",
            SERV,
            0,
            "Failure getting the request: Timed out",
            1,
            item);
}

//11/30 07:30:30.424 16392,2 Cns_srv_utime: NS092 - utime request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec (557,120,138,143) from nagios.egee.cesnet.cz
//11/30 07:30:30.424 16392,2 Cns_srv_utime: NS098 - utime /grid/ops/file-lfc-probe-lfc1.egee.cesnet.cz 0
//11/30 07:30:30.427 16392,2 Cns_srv_utime: returns 0

void ParserTests::testParseItemsUtime() {
    vector<Row*>* rows = mockRows->createMockUtime();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "11/30 07:30:30.424",
            "11/30 07:30:30.427",
            "/DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec",
            "nagios.egee.cesnet.cz",
            "/grid/ops/file-lfc-probe-lfc1.egee.cesnet.cz 0",
            UTIME,
            0,
            "",
            2,
            item);
}

void ParserTests::testParseItemsServiceName() {
    vector<Row*>* rows = mockRows->createMockServiceName();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "11/30 04:59:57.058",
            "11/30 04:59:57.059",
            "",
            "unknown",
            "",
            SERV,
            0,
            "Could not establish an authenticated connection: _Csec_recv_token: Connection closed; _Csec_recv_token: Error reading token header: Could not set service name; Csec_server_set_service_name: Could not set service name; Csec_get_peer_service_name: Could not Cgetnetaddress: Host not known !",
            0,
            item);
}

//11/30 07:58:36.747 16392,20 Cns_pingdb: mysql_query error: MySQL server has gone away
//11/30 07:58:36.747 16392,20 Cns_pingdb: Trying to reconnect

void ParserTests::testParseItemsMySQLGoneAway() {
    vector<Row*>* rows = mockRows->createMockMySQLGoneAway();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "11/30 07:58:36.747",
            "11/30 07:58:36.747",
            "",
            "",
            "",
            PINGDB,
            0,
            "MySQL server has gone away Trying to reconnect",
            20,
            item);
}


//07/18 14:54:29.016 20713,0 Cns_srv_symlink: NS092 - symlink request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz
//07/18 14:54:29.016 20713,0 Cns_srv_symlink: NS098 - symlink /grid/voce/ludacka/text_file.txt /grid/voce/ludacka/text_file10.txt
//07/18 14:54:29.048 20713,0 Cns_srv_symlink: returns 0

void ParserTests::testParseItemsSymlink() {
    vector<Row*>* rows = mockRows->createMockSymlink();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/18 14:54:29.016",
            "07/18 14:54:29.048",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka/text_file.txt /grid/voce/ludacka/text_file10.txt",
            SYMLINK,
            0,
            "",
            0,
            item);
}

//07/18 14:54:28.976 20713,0 Cns_srv_getpath: NS092 - getpath request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz
//07/18 14:54:28.978 20713,0 Cns_srv_getpath: returns 0

void ParserTests::testParseItemsGetPath() {
    vector<Row*>* rows = mockRows->createMockGetPath();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/18 14:54:28.976",
            "07/18 14:54:28.978",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "",
            GETPATH,
            0,
            "",
            0,
            item);
}

void ParserTests::testParseItemsChangeDir() {
    vector<Row*>* rows = mockRows->createMockChangeDir();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/10 19:28:40.160",
            "07/10 19:28:40.163",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/voce/ludacka2",
            CHDIR,
            0,
            "",
            4,
            item);
}

void ParserTests::testParseItemsRmDir() {
    vector<Row*>* rows = mockRows->createMockRmDir();

    LogTable * result = parser->parseItems(rows);
    Item * item = *result->getMyList()->begin();
    
    this->compareItems(
            "07/09 10:19:52.293",
            "07/09 10:19:52.297",
            "/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520",
            "ui1.egee.cesnet.cz",
            "/grid/ludacka",
            RMDIR,
            0,
            "",
            0,
            item);
}

void ParserTests::compareItems(
        string start, string end, string userP, string siteP, string fileP,
        FunctionType func, int retCode, string information, int tid, Item * item) {

    LogTime * startTime = new LogTime(start);
    LogTime * endTime = new LogTime(end);
    User * user = new User(userP);
    Site * site = new Site(siteP);
    Command * command = new Command(func, retCode);
    
    CPPUNIT_ASSERT(*startTime == (item->GetStartTime()));
    CPPUNIT_ASSERT(*command == (*item).GetCommand());
    CPPUNIT_ASSERT(*endTime == (item->GetEndTime()));
    CPPUNIT_ASSERT(*user == *item->GetUser());
    CPPUNIT_ASSERT(*site == *item->GetSite());
    CPPUNIT_ASSERT(information.compare(item->GetInformation()) == 0);
    CPPUNIT_ASSERT(fileP.compare(item->GetFilePath()) == 0);
    CPPUNIT_ASSERT(tid == item->GetTid());

}

void ParserTests::testParseRow() {
    string inputLine = "07/09 04:02:08.399 20713,0 Cns_srv_lstat: NS092 - "
            "lstat request by /DC=es/DC=irisgrid/O=ugr/CN=mdserrano (574,117,104)"
            " from wn145.bordeaux.inra.fr";

    Row * row = parser->parseRow(inputLine);

    LogTime * logTime = new LogTime("07/09 04:02:08.399");

    CPPUNIT_ASSERT(*logTime == (row->GetTime()));
    CPPUNIT_ASSERT(0 == row->GetTid());
    CPPUNIT_ASSERT(0 == row->GetJid());
    CPPUNIT_ASSERT("Cns_srv_lstat" == row->GetFunction());
    CPPUNIT_ASSERT("NS092 - lstat request by /DC=es/DC=irisgrid/O=ugr/CN="
            "mdserrano (574,117,104) from wn145.bordeaux.inra.fr" == row->GetRemain());
}

