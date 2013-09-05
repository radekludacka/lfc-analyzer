/*
 * File:   FilterTest.cpp
 * Author: radek
 *
 * Created on 30-Jul-2013, 09:23:39
 */

#include "FilterTest.h"


CPPUNIT_TEST_SUITE_REGISTRATION(FilterTest);

FilterTest::FilterTest() {
}

FilterTest::~FilterTest() {
    delete filter;
}

void FilterTest::setUp() {
    filter = new Filter();
    mockCommands = new MockCommands();
}

void FilterTest::tearDown() {
}

void FilterTest::testFilterUser() {
    vector<string> users1;
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();
    filter->SetSearchedUserString("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");

    vector<LfcCommand *> * returnedCommands = filter->Filtrate(commands);

    vector<string> users2 = ExtractUserNames(returnedCommands);

    CompareStringVectors(users1, users2);
}

void FilterTest::testFilterFile() {
    vector<string> files1;
    files1.push_back("/grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en19.500/th0.65/058357");
    files1.push_back("/grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en19.500/th0.65/058357");
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();
    filter->SetSearchedFileString("/grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en19.500/th0.65/058357");

    vector<LfcCommand *> * returnedCommands = filter->Filtrate(commands);

    vector<string> files2 = ExtractFileNames(returnedCommands);

    CompareStringVectors(files1, files2);
}

void FilterTest::testFilterCommand() {
    vector<string> commands1;
    commands1.push_back("LFC_LS");
    commands1.push_back("LFC_LS");
    commands1.push_back("LFC_LS");
    commands1.push_back("LFC_LS");
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();
    filter->SetSearchedCommand(LFC_LS);

    vector<LfcCommand *> * returnedCommands = filter->Filtrate(commands);

    vector<string> commands2 = ExtractCommandNames(returnedCommands);

    CompareStringVectors(commands1, commands2);
}

void FilterTest::testFilterSite() {
    vector<string> sites1;
    sites1.push_back("wario.univ-lille1.fr");
    sites1.push_back("wario.univ-lille1.fr");
    sites1.push_back("wario.univ-lille1.fr");
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();
    filter->SetSearchedSiteString("wario.univ-lille1.fr");

    vector<LfcCommand *> * returnedCommands = filter->Filtrate(commands);

    vector<string> sites2 = ExtractSiteNames(returnedCommands);

    CompareStringVectors(sites1, sites2);
}

void FilterTest::testFilterSuccessValue() {
    vector<bool> successValue1;
    successValue1.push_back(true);
    successValue1.push_back(true);
    successValue1.push_back(true);
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();
    filter->SetSearchedSuccessValue(true);

    vector<LfcCommand *> * returnedCommands = filter->Filtrate(commands);

    vector<bool> successValue2 = ExtractResultTypes(returnedCommands);

    CompareBoolVectors(successValue1, successValue2);
}

void FilterTest::testSortByUser() {
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();

    vector<string> users1;
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520");

    sorter = new UserSorter();
    commands = sorter->Sort(commands);

    vector<string> users2 = ExtractUserNames(commands);

    CompareStringVectors(users1, users2);
}

void FilterTest::testSortByUserAndSite() {
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();

    vector<string> users1;
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=es/DC=irisgrid/O=ugr/CN=gines.rubio");
    users1.push_back("/DC=org/DC=terena/DC=tcs/C=CZ/O=Czech Technical University in Prague/CN=Radek Ludacka 364520");

    vector<string> sites1;
    sites1.push_back("131.154.200.195");
    sites1.push_back("wario.univ-lille1.fr");
    sites1.push_back("wario.univ-lille1.fr");
    sites1.push_back("wario.univ-lille1.fr");
    sites1.push_back("ui1.egee.cesnet.cz");

    sorter = new UserSorter(new SiteSorter());
    commands = sorter->Sort(commands);

    vector<string> users2 = ExtractUserNames(commands);
    vector<string> sites2 = ExtractSiteNames(commands);

    CPPUNIT_ASSERT(users1.size() == users2.size());
    CPPUNIT_ASSERT(sites1.size() == sites2.size());
    CompareStringVectors(users1, users2);
    CompareStringVectors(sites1, sites2);
}

void FilterTest::testSortByFile() {
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();

    vector<string> files1;
    files1.push_back("/grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en18.000/th0.65/057686");
    files1.push_back("/grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en19.500/th0.65/058357");
    files1.push_back("/grid/auger/prod/GenDisProtonQGSjetII_gr249_simADSTv2r9p3/en19.500/th0.65/058357");
    files1.push_back("/grid/voce/ludacka/dir3");
    files1.push_back("/grid/voce/neexist");

    sorter = new FileSorter();
    commands = sorter->Sort(commands);

    vector<string> files2 = ExtractFileNames(commands);

    CompareStringVectors(files1, files2);
}

void FilterTest::testSortByCommand() {
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();

    vector<string> commands1;
    commands1.push_back("LCG_REP");
    commands1.push_back("LFC_LS");
    commands1.push_back("LFC_LS");
    commands1.push_back("LFC_LS");
    commands1.push_back("LFC_LS");

    sorter = new CommandSorter();
    commands = sorter->Sort(commands);

    vector<string> commands2 = ExtractCommandNames(commands);

    cout << commands2.size() << endl;
    CPPUNIT_ASSERT(commands1.size() == commands2.size());
    CompareStringVectors(commands1, commands2);
}

void FilterTest::testSortByResultType() {
    vector<LfcCommand *> * commands = mockCommands->CreateMockLfcCommands();

    vector<bool> resultTypes1;
    resultTypes1.push_back(false);
    resultTypes1.push_back(false);
    resultTypes1.push_back(true);
    resultTypes1.push_back(true);
    resultTypes1.push_back(true);

    sorter = new SuccessSorter();
    commands = sorter->Sort(commands);

    vector<bool> commands2 = ExtractResultTypes(commands);

    CPPUNIT_ASSERT(resultTypes1.size() == commands2.size());
    CompareBoolVectors(resultTypes1, commands2);
}

vector<bool> FilterTest::ExtractResultTypes(vector<LfcCommand *> * commands) {
    vector<bool> sites;

    std::vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;
        sites.push_back(command->IsFailed());
    }

    return sites;
}

vector<string> FilterTest::ExtractCommandNames(vector<LfcCommand *> * commands) {
    vector<string> sites;

    std::vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;
        sites.push_back(command->GetStringName());
    }

    return sites;
}

vector<string> FilterTest::ExtractFileNames(vector<LfcCommand *> * commands) {
    vector<string> sites;

    std::vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;
        sites.push_back(command->GetFile());
    }

    return sites;
}

vector<string> FilterTest::ExtractSiteNames(vector<LfcCommand *> * commands) {
    vector<string> sites;

    std::vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;
        sites.push_back(command->GetSite()->GetName());
    }

    return sites;
}

vector<string> FilterTest::ExtractUserNames(vector<LfcCommand *> * commands) {
    vector<string> names;

    std::vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;
        names.push_back(command->GetUser()->GetName());
    }

    return names;
}

void FilterTest::CompareStringVectors(vector<string> vector1, vector<string> vector2) {

    CPPUNIT_ASSERT(vector1.size() == vector2.size());

    for (unsigned int i = 0; i < vector1.size(); i++) {
        string value1 = vector1.at(i);
        string value2 = vector2.at(i);

        cout << endl;
        cout << value1 << endl;
        cout << value2 << endl;


        CPPUNIT_ASSERT(value1.compare(value2) == 0);
    }
}

void FilterTest::CompareBoolVectors(vector<bool> vector1, vector<bool> vector2) {

    CPPUNIT_ASSERT(vector1.size() == vector2.size());

    for (unsigned int i = 0; i < vector1.size(); i++) {

        bool value1 = vector1.at(i);
        bool value2 = vector2.at(i);

        CPPUNIT_ASSERT(value1 == value2);
    }
}

