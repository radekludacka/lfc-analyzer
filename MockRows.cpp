/* 
 * File:   MockRows.cpp
 * Author: radek
 * 
 * Created on 13 July 2013, 13:06
 */

#include "MockRows.h"

MockRows::MockRows() {
    parser = new Parser();
}

MockRows::~MockRows() {
}

vector<Row *> * MockRows::createMockLstatRows() {
    string inputLine1 = "07/09 09:58:28.883 20713,0 Cns_srv_lstat: NS092 - lstat request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz";
    string inputLine2 = "07/09 09:58:28.883 20713,0 Cns_srv_lstat: NS098 - lstat 0 /";
    string inputLine3 = "07/09 09:58:28.884 20713,0 Cns_srv_lstat: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockAccess() {

    string inputLine1 = "07/09 04:02:20.747 20713,1 Cns_srv_access: NS092 - access request by /DC=es/DC=irisgrid/O=ugr/CN=Julio.Lozano.Bahilo (432,117,104) from grid-wn292.physik.rwth-aachen.de";
    string inputLine2 = "07/09 04:02:20.747 20713,1 Cns_srv_access: "
            "NS098 - access 6 /grid/auger/prod/B2015IronQGSjetII_gr266_XHdSimv2r9p1/"
            "en19.800/th0.000/066317/DAT663174_01.offline-v2r9p1.AHdSimOffline.root";
    string inputLine3 = "07/09 04:02:20.750 20713,1 Cns_srv_access: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockOpenDir() {
    string inputLine1 = "07/09 09:58:28.953 20713,0 Cns_srv_opendir: NS092 - opendir request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz";
    string inputLine2 = "07/09 09:58:28.953 20713,0 Cns_srv_opendir: NS098 - opendir /";
    string inputLine3 = "07/09 09:58:28.954 20713,0 Cns_srv_opendir: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockReadDir() {

    string inputLine1 = "07/09 09:58:28.985 20713,0 Cns_srv_readdir: NS092 - readdir request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz";
    string inputLine2 = "07/09 09:58:28.994 20713,0 Cns_srv_readdir: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    return rows;
}

vector<Row *> * MockRows::createMockReadCloseDir() {

    string inputLine1 = "07/09 09:58:29.033 20713,0 Cns_srv_readdir: NS092 - closedir request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz";
    string inputLine2 = "07/09 09:58:29.034 20713,0 Cns_srv_readdir: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    return rows;
}

vector<Row *> * MockRows::createMockStartSess() {
    string inputLine1 = "07/09 04:05:51.024 20713,2 Cns_srv_startsess: NS092 - startsess request by /O=GRID-FR/C=FR/O=CNRS/OU=LAL/CN=Jean-Noel Albert (393,104) from ccwsge0246.in2p3.fr";
    string inputLine2 = "07/09 04:05:51.024 20713,2 Cns_srv_startsess: NS098 - startsess (1.14.0-1.el5)";
    string inputLine3 = "07/09 04:05:51.024 20713,2 Cns_srv_startsess: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockDelReplica() {
    string inputLine1 = "07/09 04:06:05.407 20713,1 Cns_srv_delreplica: NS092 - delreplica request by /DC=es/DC=irisgrid/O=ugr/CN=mdserrano (574,117,104) from gnet-74.lip.pt";
    string inputLine2 = "07/09 04:06:05.407 20713,1 Cns_srv_delreplica: NS098 - delreplica 0d9d5dc9-0848-4789-b509-5e0ade8eef5c srm://prod-se-02.ct.infn.it/auger//grid/auger/prod/GenDisIronEpos_gr248/en20.000/th0.65/057161/DAT571611.tar.gz";
    string inputLine3 = "07/09 04:06:05.414 20713,1 Cns_srv_delreplica: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockGetReplica() {
    string inputLine1 = "07/09 04:06:05.583 20713,1 Cns_srv_getreplica: NS092 - getreplica request by /DC=es/DC=irisgrid/O=ugr/CN=mdserrano (574,117,104) from gnet-74.lip.pt";
    string inputLine2 = "07/09 04:06:05.583 20713,1 Cns_srv_getreplica: NS098 - getreplica  0d9d5dc9-0848-4789-b509-5e0ade8eef5c";
    string inputLine3 = "07/09 04:06:05.584 20713,1 Cns_srv_getreplica: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockUnlink() {

    string inputLine1 = "07/09 04:06:05.781 20713,1 Cns_srv_unlink: NS092 - unlink request by /DC=es/DC=irisgrid/O=ugr/CN=mdserrano (574,117,104) from gnet-74.lip.pt";
    string inputLine2 = "07/09 04:06:05.781 20713,1 Cns_srv_unlink: NS098 - unlink /grid/auger/prod/GenDisIronEpos_gr248/en20.000/th0.65/057161/DAT571611.tar.gz";
    string inputLine3 = "07/09 04:06:05.794 20713,1 Cns_srv_unlink: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockGetLinks() {

    string inputLine1 = "07/09 04:11:35.572 20713,0 Cns_srv_getlinks: NS092 - getlinks request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec (557,101) from skurut19.grid.cesnet.cz";
    string inputLine2 = "07/09 04:11:35.572 20713,0 Cns_srv_getlinks: NS098 - getlinks  df8aebb1-4fc5-45df-bf94-9c2d16c59b63";
    string inputLine3 = "07/09 04:11:35.575 20713,0 Cns_srv_getlinks: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockEndSess() {
    string inputLine1 = "07/09 04:11:35.625 20713,0 Cns_srv_endsess: NS092 - endsess request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec (557,101) from skurut19.grid.cesnet.cz";
    string inputLine2 = "07/09 04:11:35.625 20713,0 Cns_srv_endsess: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    return rows;
}

vector<Row *> * MockRows::createMockStartTrans() {

    string inputLine1 = "07/09 04:11:35.694 20713,1 Cns_srv_starttrans: NS092 - starttrans request by /DC=es/DC=irisgrid/O=ugr/CN=mdserrano (574,117,104) from wn-204-03-15-02-b.cr.cnaf.infn.it";
    string inputLine2 = "07/09 04:11:35.694 20713,1 Cns_srv_starttrans: NS098 - starttrans (1.14.0-1.el5)";
    string inputLine3 = "07/09 04:11:35.695 20713,1 Cns_srv_starttrans: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockStatg() {
    string inputLine1 = "07/09 04:11:35.717 20713,1 Cns_srv_statg: NS092 - statg request by /DC=es/DC=irisgrid/O=ugr/CN=mdserrano (574,117,104) from wn-204-03-15-02-b.cr.cnaf.infn.it";
    string inputLine2 = "07/09 04:11:35.717 20713,1 Cns_srv_statg: NS098 - statg /grid/auger/prod/GenDisIronEpos_gr248/en20.000/th0.65/057185/DAT571858.tar.gz 565a950a-2748-4159-8c71-7bbf53fed931";
    string inputLine3 = "07/09 04:11:35.723 20713,1 Cns_srv_statg: returns 2";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockCreat() {

    string inputLine1 = "07/09 04:11:35.793 20713,1 Cns_srv_creat: NS092 - creat request by /DC=es/DC=irisgrid/O=ugr/CN=mdserrano (574,117,104) from wn-204-03-15-02-b.cr.cnaf.infn.it";
    string inputLine2 = "07/09 04:11:35.793 20713,1 Cns_srv_creat: NS098 - creat /grid/auger/prod/GenDisIronEpos_gr248/en20.000/th0.65/057185/DAT571858.tar.gz 565a950a-2748-4159-8c71-7bbf53fed931 664 22";
    string inputLine3 = "07/09 04:11:35.798 20713,1 Cns_srv_creat: file 37337945 created";
    string inputLine4 = "07/09 04:11:35.798 20713,1 Cns_srv_creat: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    rows->push_back(parser->parseRow(inputLine4));
    return rows;
}

vector<Row *> * MockRows::createMockAddReplica() {

    string inputLine1 = "07/12 04:02:09.473 20713,8 Cns_srv_addreplica: NS092 - addreplica request by /DC=es/DC=irisgrid/O=ugr/CN=gines.rubio (491,117,104) from wn07-grid.obspm.fr";
    string inputLine2 = "07/12 04:02:09.473 20713,8 Cns_srv_addreplica: NS098 - addreplica 48607b2d-9840-4d31-ac61-2d939fd52407 grid05.lal.in2p3.fr srm://grid05.lal.in2p3.fr/dpm/lal.in2p3.fr/home/auger//grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en20.500/th0.65/058744/DAT587449_01.offline-v2r9p3.HdSimRecADST.root";
    string inputLine3 = "07/12 04:02:09.495 20713,8 Cns_srv_addreplica: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockSetfSizeg() {

    string inputLine1 = "07/12 04:02:10.325 20713,9 Cns_srv_setfsizeg: NS092 - setfsizeg request by /DC=es/DC=irisgrid/O=ugr/CN=mdserrano (574,117,104) from fnpc3046.fnal.gov";
    string inputLine2 = "07/12 04:02:10.325 20713,9 Cns_srv_setfsizeg: NS098 - setfsizeg 3f1fa9b9-d0ab-45e4-a337-9d62d64e07d4 14220686";
    string inputLine3 = "07/12 04:02:10.329 20713,9 Cns_srv_setfsizeg: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockEndTrans() {

    string inputLine1 = "07/12 04:02:27.936 20713,5 Cns_srv_endtrans: NS092 - endtrans request by /DC=es/DC=irisgrid/O=ugr/CN=Julio.Lozano.Bahilo (432,117,104) from wario.univ-lille1.fr";
    string inputLine2 = "07/12 04:02:28.010 20713,5 Cns_srv_endtrans: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    return rows;
}

vector<Row *> * MockRows::createMockMkDir() {

    string inputLine1 = "07/17 08:31:37.774 20713,1 Cns_srv_mkdir: NS092 - mkdir request by /DC=es/DC=irisgrid/O=ugr/CN=Julio.Lozano.Bahilo (432,117,104) from d0cs3048.fnal.gov";
    string inputLine2 = "07/17 08:31:37.774 20713,1 Cns_srv_mkdir: NS098 - mkdir /grid/auger/prod/B2015IronQGSjetII_gr277_XHdSimv2r9p1/en18.900/th0.60/068276  777 22";
    string inputLine3 = "07/17 08:31:37.780 20713,1 Cns_srv_mkdir: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockStatr() {

    string inputLine1 = "07/18 15:46:24.733 20713,1 Cns_srv_statr: NS092 - statr request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz";
    string inputLine2 = "07/18 15:46:24.733 20713,1 Cns_srv_statr: NS098 - statr srm://dpm1.egee.cesnet.cz/dpm/cesnet.cz/home/voce/generated/2013-07-18/fileda937a3c-4112-4d56-a34e-9866967cfe44";
    string inputLine3 = "07/18 15:46:24.734 20713,1 Cns_srv_statr: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockServ() {

    string inputLine1 = "07/18 12:59:27.527 20713,4 Cns_serv: NS002 - netread error : Connection reset by peer";
    string inputLine2 = "07/18 12:59:27.527 20713,4 Cns_srv_readdir: NS092 - closedir request by /DC=es/DC=irisgrid/O=ugr/CN=gines.rubio (491,117,104) from wario.univ-lille1.fr";
    string inputLine3 = "07/18 12:59:27.529 20713,4 sendrep: NS002 - send error : Broken pipe";
    string inputLine4 = "07/18 12:59:27.529 20713,4 Cns_srv_readdir: returns 0";
    string inputLine5 = "07/18 12:59:27.642 20713,4 sendrep: NS002 - send error : Broken pipe";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    rows->push_back(parser->parseRow(inputLine4));
    rows->push_back(parser->parseRow(inputLine5));
    return rows;
}

vector<Row *> * MockRows::createMockReadDirClosed() {

    string inputLine1 = "07/18 07:26:16.595 20713,1 Cns_srv_readdir: NS092 - closedir request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec (557,120,138,143) from nagios.egee.cesnet.cz";
    string inputLine2 = "07/18 07:26:16.597 20713,1 Cns_srv_readdir: returns 0";
    string inputLine3 = "07/18 07:26:16.634 20713,1 sendrep: NS002 - send error : Connection closed by remote end";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockBadProxy() {

    string inputLine1 = "11/30 04:21:25.095 16392,1 Cns_serv: [132.195.125.93] (wn083.pleiades.uni-wuppertal.de): Could not establish an authenticated connection: server_establish_context_ext: The client itself detected a problem with the user proxy, it was probably missing or expired !";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    return rows;
}

vector<Row *> * MockRows::createMockTimedOut() {

    string inputLine1 = "11/30 05:07:09.707 16392,1 Cns_serv: NS002 - netread error : Timed out";
    string inputLine2 = "11/30 05:07:09.707 16392,1 Cns_serv: [147.231.25.105] (nat105.farm.particle.cz): Failure getting the request: Timed out";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    return rows;
}

vector<Row *> * MockRows::createMockUtime() {

    string inputLine1 = "11/30 07:30:30.424 16392,2 Cns_srv_utime: NS092 - utime request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of the Academy of Sciences of the CR/CN=Jan Svec (557,120,138,143) from nagios.egee.cesnet.cz";
    string inputLine2 = "11/30 07:30:30.424 16392,2 Cns_srv_utime: NS098 - utime /grid/ops/file-lfc-probe-lfc1.egee.cesnet.cz 0";
    string inputLine3 = "11/30 07:30:30.427 16392,2 Cns_srv_utime: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockServiceName() {

    string inputLine1 = "11/30 04:59:57.058 16392,0 Cns_serv: [84.21.168.171] (unknown): Could not establish an authenticated connection: _Csec_recv_token: Connection closed; _Csec_recv_token: Error reading token header: Could not set service name; Csec_server_set_service_name: Could not set service name; Csec_get_peer_service_name: Could not Cgetnetaddress: Host not known !";
    string inputLine2 = "11/30 04:59:57.059 16392,0 sendrep: NS002 - send error : Could not set service name";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    return rows;
}

vector<Row *> * MockRows::createMockMySQLGoneAway() {

    string inputLine1 = "11/30 07:58:36.747 16392,20 Cns_pingdb: mysql_query error: MySQL server has gone away";
    string inputLine2 = "11/30 07:58:36.747 16392,20 Cns_pingdb: Trying to reconnect";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    return rows;
}

vector<Row *> * MockRows::createMockSymlink() {

    string inputLine1 = "07/18 14:54:29.016 20713,0 Cns_srv_symlink: NS092 - symlink request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz";
    string inputLine2 = "07/18 14:54:29.016 20713,0 Cns_srv_symlink: NS098 - symlink /grid/voce/ludacka/text_file.txt /grid/voce/ludacka/text_file10.txt";
    string inputLine3 = "07/18 14:54:29.048 20713,0 Cns_srv_symlink: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockGetPath() {

    string inputLine1 = "07/18 14:54:28.976 20713,0 Cns_srv_getpath: NS092 - getpath request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz";
    string inputLine2 = "07/18 14:54:28.978 20713,0 Cns_srv_getpath: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));

    return rows;
}



vector<Row *> * MockRows::createMockChangeDir() {
    
    string inputLine1 = "07/10 19:28:40.160 20713,4 Cns_srv_chdir: NS092 - chdir request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz";
    string inputLine2 = "07/10 19:28:40.160 20713,4 Cns_srv_chdir: NS098 - chdir /grid/voce/ludacka2";
    string inputLine3 = "07/10 19:28:40.163 20713,4 Cns_srv_chdir: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockRmDir() {
    
    string inputLine1 = "07/09 10:19:52.293 20713,0 Cns_srv_rmdir: NS092 - rmdir request by /DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520 (613,101) from ui1.egee.cesnet.cz";
    string inputLine2 = "07/09 10:19:52.293 20713,0 Cns_srv_rmdir: NS098 - rmdir /grid/ludacka";
    string inputLine3 = "07/09 10:19:52.297 20713,0 Cns_srv_rmdir: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    rows->push_back(parser->parseRow(inputLine3));
    return rows;
}

vector<Row *> * MockRows::createMockServAbortTransaction() {
    
    string inputLine1 = "11/09 21:28:31.698 20713,0 Cns_srv_aborttrans: NS092 - aborttrans request by /DC=cz/DC=cesnet-ca/O=Institute of Physics of Materials of the Academy of Sciences of the CR/CN=Tomas Kana (608,101) from skurut15.grid.cesnet.cz";
    string inputLine2 = "11/09 21:28:31.698 20713,0 Cns_srv_aborttrans: returns 0";

    vector<Row*> * rows = new vector<Row*>;

    rows->push_back(parser->parseRow(inputLine1));
    rows->push_back(parser->parseRow(inputLine2));
    return rows;
}