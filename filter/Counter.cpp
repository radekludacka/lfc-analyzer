/* 
 * File:   Filter.cpp
 * Author: radek
 * 
 * Created on 15 July 1213, 17:25
 */

#include "Counter.h"

Counter::Counter() {
}

Counter::~Counter() {
}

void Counter::FilterCommands(vector<LfcCommand *> * commands) {

    int numberOfBadLfcLs = 0;
    int nubmerOfGoodLfcLs = 0;

    int nubmerOfGoodLfcCr = 0;
    int nubmerOfBadLfcCr = 0;

    int numberOfGoodReplicate = 0;
    int numberOfBadReplicate = 0;

    int numberOfGoodMkDir = 0;
    int numberOfBadMkDir = 0;

    int numberOfCP = 0;

    int numberOfGoodDelReplica = 0;
    int numberOfBadDelReplica = 0;

    int numberOfServErrors = 0;
    int numberPingDB = 0;
    int numberOfUTimes = 0;

    int numberOfSymlinks = 0;
    int numberOfRmDir = 0;

    std::vector<LfcCommand *>::const_iterator iterator;
    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
        LfcCommand * command = *iterator;

        if (command != NULL) {
            LFCCommandName function = command->GetName();
            if (function == LFC_LS) {
                if (command->IsFailed()) {
                    numberOfBadLfcLs++;
                } else {
                    nubmerOfGoodLfcLs++;
                }
            }
            if (function == LCG_CR) {
                if (command->IsFailed()) {
                    nubmerOfBadLfcCr++;
                } else {
                    nubmerOfGoodLfcCr++;
                }
            } else if (function == LCG_REP) {
                if (command->IsFailed()) {
                    numberOfBadReplicate++;
                } else {
                    numberOfGoodReplicate++;
                }

            } else if (function == LFC_MKDIR) {
                if (command->IsFailed()) {
                    numberOfBadMkDir++;
                } else {
                    numberOfGoodMkDir++;
                }
            } else if (function == LCG_CP) {
                numberOfCP++;
            } else if (function == LCG_DEL) {
                if (command->IsFailed()) {
                    numberOfBadDelReplica++;
                } else {
                    numberOfGoodDelReplica++;
                }
            } else if (function == LCG_NONE) {
                numberOfServErrors++;
            } else if (function == LCG_PINGDB) {
                numberPingDB++;
            } else if (function == LCG_UTIME) {
                numberOfUTimes++;
            } else if (function == LCG_AA) {
                numberOfSymlinks++;
            } else if (function == LCG_RM) {
                numberOfRmDir++;
            }
        }
    }

    printf("|%-12s |%10s |%10s |\n", "command", "failed", "good");
    PrintRow("lfc-ls", numberOfBadLfcLs, nubmerOfGoodLfcLs);
    PrintRow("lcg-cr", nubmerOfBadLfcCr, nubmerOfGoodLfcCr);
    PrintRow("lcg-rep", numberOfBadReplicate, numberOfGoodReplicate);
    PrintRow("lfc-mkdir", numberOfBadMkDir, numberOfGoodMkDir);
    PrintRow("lcg-cp", -1, numberOfCP);
    PrintRow("lcg-pingdb", numberPingDB, 0);
    PrintRow("lcg-del", -1, numberOfGoodDelReplica);
    PrintRow("srv-err", numberOfServErrors, 0);
    PrintRow("utimes", 0, numberOfUTimes);
    PrintRow("lcg-aa", -1, numberOfSymlinks);
    PrintRow("lcg-rm", -1, numberOfRmDir);
    cout << "lcg-rep failed v sobe zahrnuje lcg-cp failed a lcg-del failed" << endl;

    // bad cp jsou schovany v bad replica - stejny vysledek v logu pro
    // oboje operace
}

void Counter::PrintRow(string command, int numberOfFailedCommands, int numberOfSuccessCommands) {
    if (numberOfFailedCommands == -1) {
        printf("|%-12s |%10s |%10d |\n", command.c_str(), "?", numberOfSuccessCommands);
    } else {
        printf("|%-12s |%10d |%10d |\n", command.c_str(), numberOfFailedCommands, numberOfSuccessCommands);
    }
}
