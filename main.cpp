/* 
 * File:   main.cpp
 * Author: radek
 *
 * Created on 09 July 2013, 09:01
 */

#include <cstdlib>
#include <iostream>
#include "parser2/LogTable.h"
#include "parser2/Command.h"
#include "parser2/Parser.h"
#include "filter/Filter.h"
#include "filter/Counter.h"
#include "Item.h"
#include "Functions.h"
#include "analyzer2/Analyzer.h"
#include "filter/Counter.h"
#include <unistd.h>
#include <ctype.h>
#include "stdio.h"
#include <getopt.h>
#include "filter/sorters/SuccessSorter.h"
#include "presenter/Presenter.h"
#include "filter/sorters/CommandSorter.h"
#include "filter/sorters/SiteSorter.h"
#include "filter/sorters/UserSorter.h"
#include "filter/sorters/FileSorter.h"

//#define COUT

using namespace std;

LFCCommandName CommandConverter(string commandName);
bool FailedConverter(string failedValue);
void PrintHelp();

int main(int argc, char** argv) {

    printf("Welcome in LFC analyzer.\n");

    int file = -1;
    int site = -1;
    int user = -1;
    int command = -1;
    int resultType = -1;

    const char* filteredSite = NULL;
    const char* filteredUser = NULL;
    const char* filteredFile = NULL;
    const char* filteredCommand = NULL;
    const char* filteredSuccess = NULL;
    Filter * filter = new Filter();
    Counter * counter = new Counter();
    string filePath;

    int index = -1;
    int next_option;

    opterr = 0;

    if (argc == 1) {
        cout << "Enter log file path please" << endl;
        return -1;
    }

    const char* const short_options = "hfsucrd:g:i:p:o:l:";
    static struct option long_options[] = {
        {"site", 1, 0, 'd'},
        {"user", 1, 0, 'g'},
        {"file", 1, 0, 'l'},
        {"command", 1, 0, 'p'},
        {"success", 1, 0, 'o'},
        {"input", 1, 0, 'i'},
        {0, 0, 0, 0}
    };

    do {

        next_option = getopt_long(argc, argv, short_options, long_options, NULL);

        //        cout << (char) next_option << endl;
        switch (next_option) {
            case 'f':
                file = ++index;
                break;
            case 's':
                site = ++index;
                break;
            case 'u':
                user = ++index;
                break;
            case 'c':
                command = ++index;
                break;
            case 'r':
                resultType = ++index;
                break;
            case 'h':
                PrintHelp();
                return 0;

            case 'd':
                filteredSite = optarg;
                break;
            case 'i':
                filePath = optarg;
                break;
            case 'g':
                filteredUser = optarg;
                break;
            case 'l':
                filteredFile = optarg;
                break;
            case 'p':
                filteredCommand = optarg;
                break;
            case 'o':
                filteredSuccess = optarg;
                break;
            case '?':
                fprintf(stderr, "Unknown option character `\\s%s'.\n", optopt);
                return 1;
            case -1:
                break;
            default:
                abort();
        }
    } while (next_option != -1);

    cout << "Analyzed log file is: " << filePath << endl;
    cout << "Analyzing could take several minutes, wait please." << endl;

    //    printf("f = %d, u = %d, s = %d, c = %d, r = %d\n", file, user, site, command, resultType);
    //    printf("logfile = %s\n", filePath.c_str());
    //    printf("site = %s, user = %s, file = %s, command = %s, success = %s\n",
    //            filteredSite, filteredUser, filteredFile, filteredCommand, filteredSuccess);

    Parser * parser = new Parser();
    LogTable * logTable = parser->parse(filePath);
    vector<Item*> * items = logTable->getMyList();

    cout << "number of items: ";
    cout << items->size() << endl;

    Analyzer * analyzer = new Analyzer();
    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    if (filteredCommand != NULL) {
        filter->SetSearchedCommand(CommandConverter(filteredCommand));
    }
    if (filteredFile != NULL) {
        filter->SetSearchedFileString(filteredFile);
    }
    if (filteredSite != NULL) {
        filter->SetSearchedSiteString(filteredSite);
    }
    if (filteredSuccess != NULL) {
        filter->SetSearchedSuccessValue(FailedConverter(filteredSuccess));
    }
    if (filteredUser != NULL) {
        filter->SetSearchedUserString(filteredUser);
    }

    //    vector<LfcCommand *> commands = commandTable->GetCommandList();
    //    std::vector<LfcCommand *>::const_iterator iterator;
    //    for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
    //        LfcCommand * command = *iterator;
    //        cout << command->
    //    }

    vector<LfcCommand *> * commandList = filter->Filtrate(commandTable->GetCommandList());

    cout << "number of commands: " << commandList->size() << endl;
    counter->FilterCommands(commandList);

    Sorter * previousSorter = NULL;
    Sorter * sorter = NULL;

    for (int i = 4; i > -1; i--) {
        previousSorter = sorter;
        if (file == i) {
            sorter = new FileSorter(previousSorter);
        } else if (user == i) {
            sorter = new UserSorter(previousSorter);
        } else if (site == i) {
            sorter = new SiteSorter(previousSorter);
        } else if (command == i) {
            sorter = new CommandSorter(previousSorter);
        } else if (resultType == i) {
            sorter = new SuccessSorter(previousSorter);
        }
    }

    if (sorter != NULL) {
        commandList = sorter->Sort(commandList);
        Presenter * presenter = new Presenter();
        presenter->Print(commandList, file, user, site, command, resultType);
    }

    delete parser;
    return 0;
}

bool FailedConverter(string failedValue) {
    if (failedValue.compare("true")) {
        return true;
    } else if (failedValue.compare("false")) {
        return false;
    } else {
        cout << "failed value " << failedValue << " is not allowed" << endl;
        return NULL;
    }
}

LFCCommandName CommandConverter(string commandName) {
    if (commandName.compare("lfc-ls")) {
        return LFC_LS;
    } else if (commandName.compare("lcg-cr")) {
        return LCG_CR;
    } else if (commandName.compare("lcg-rep")) {
        return LCG_REP;
    } else if (commandName.compare("lfc-mkdir")) {
        return LFC_MKDIR;
    } else if (commandName.compare("lcg-cp")) {
        return LCG_CP;
    } else if (commandName.compare("lcg-del")) {
        return LCG_DEL;
    } else if (commandName.compare("srv-err")) {
        return LCG_NONE;
    } else if (commandName.compare("lcg-utime")) {
        return LCG_UTIME;
    } else if (commandName.compare("lcg-pingdb")) {
        return LCG_PINGDB;
    } else if (commandName.compare("lcg-lr")) {
        return LCG_LR;
    } else if (commandName.compare("lcg-aa")) {
        return LCG_AA;
    } else if (commandName.compare("lcg-rm")) {
        return LCG_RM;
    } else {
        string exception = "command " + commandName + " is not allowed";
        throw exception;
    }
}

void PrintHelp() {
    cout << " -f: Destination file that have been accessed by LFC command." << endl;
    cout << " -s: User interface where LFC command have been invoked." << endl;
    cout << " -u: User name that invoked LFC command." << endl;
    cout << " -c: LFC command that have been invoked." << endl;
    cout << " -r: Result (Success) of invoked LFC command." << endl;

    cout << " -d UI : filter by user interface" << endl;
    cout << " -g USER : filter by user" << endl;
    cout << " -l FILE : filter by file name" << endl;
    cout << " -p COMMAND : filter by command name (lfc-ls, lcg-cr, lcg-rep, etc.)" << endl;
    cout << " -o ( true | false ) : filter by command result" << endl;
}
