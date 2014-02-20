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
#include "filter/sorters/NullSorter.h"
#include "filter/sorters/TimeSorter.h"
#include "Arguments.h"
#include "filter/sorters/InformationSorter.h"
#include <time.h>

using namespace std;

Arguments * ExtractArguments(int argc, char** argv);
bool FailedConverter(string failedValue);
void PrintHelp();
Sorter * CreateSorterChain(Arguments * arguments);

int main(int argc, char** argv) {
    printf("Welcome in LFC analyzer.\n");

    Parser * parser = new Parser();
    Analyzer * analyzer = new Analyzer();
    Filter * filter = new Filter();
    Counter * counter = new Counter();

    Arguments * arguments = ExtractArguments(argc, argv);
    if (arguments == NULL) {
        return -1;
    }

    cout << "Analyzed log file is: " << arguments->GetFilePath() << endl;
    cout << "Analyzing could take several minutes, wait please." << endl;
    LogTable * logTable = parser->parse(arguments->GetFilePath());
    vector<Item*> * items = logTable->getMyList();

    cout << "number of items: ";
    cout << items->size() << endl;

    LfcCommandTable * commandTable = analyzer->Analyze(logTable);

    vector<LfcCommand *> * commandList = filter->Filtrate(commandTable->GetCommandList(), arguments);

    Sorter * sorter = CreateSorterChain(arguments);

    string message = "number of commands: ";
    if (sorter != NULL) {
        commandList = sorter->Sort(commandList);
        message = "number of filtered commands: ";
        cout << message << commandList->size() << endl;
        counter->FilterCommands(commandList);
        Presenter * presenter = new Presenter();
        presenter->Print(commandList, arguments);
        delete presenter;
    } else {
        cout << message << commandList->size() << endl;
        counter->FilterCommands(commandList);
    }

    commandList->clear();
    //    delete commandList;
    delete arguments;
    delete parser;
    delete filter;
    delete counter;
    delete analyzer;
    delete commandTable;
    delete sorter;
    return 0;
}

Sorter * CreateSorterChain(Arguments * arguments) {
    Sorter * previousSorter = NULL;
    Sorter * sorter = new NullSorter();

    for (int i = 4; i > -1; i--) {
        previousSorter = sorter;
        if (arguments->GetFileOrder() == i) {
            sorter = new FileSorter(previousSorter);
        } else if (arguments->GetUserOrder() == i) {
            sorter = new UserSorter(previousSorter);
        } else if (arguments->GetSiteOrder() == i) {
            sorter = new SiteSorter(previousSorter);
        } else if (arguments->GetCommandOrder() == i) {
            sorter = new CommandSorter(previousSorter);
        } else if (arguments->GetResultTypeOrder() == i) {
            sorter = new SuccessSorter(previousSorter);
        } else if (arguments->GetTimeOrder() == i) {
            sorter = new TimeSorter(previousSorter);
            if (arguments->GetPrintTimes()) {
                TimeSorter* ts = dynamic_cast<TimeSorter*>(sorter);
                ts->SetPrintCommandsOutput(true);
            }
        } else if (arguments->GetInformationOrder() == i) {
            sorter = new InformationSorter(previousSorter);
        }
    }
    return sorter;
}

Arguments * ExtractArguments(int argc, char** argv) {
    string filePath;
    int index = -1;
    int next_option;
    opterr = 0;
    Arguments * arguments = new Arguments();

    if (argc == 1) {
        cout << "Enter log file path please" << endl;
        return NULL;
    }

    const char* const short_options = "hftseucrmd:g:i:p:o:l:";
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

        switch (next_option) {
            case 'e':
                arguments->SetPrintTimes(true);
                break;
            case 'f':
                arguments->SetFileOrder(++index);
                break;
            case 's':
                arguments->SetSiteOrder(++index);
                break;
            case 'u':
                arguments->SetUserOrder(++index);
                break;
            case 'c':
                arguments->SetCommandOrder(++index);
                break;
            case 'r':
                arguments->SetResultTypeOrder(++index);
                break;
            case 't':
                arguments->SetTimeOrder(++index);
                break;
            case 'm':
                arguments->SetInformationOrder(++index);
                break;
            case 'h':
                PrintHelp();
                return 0;

            case 'd':
                arguments->SetSiteValueToFilter(optarg);
                break;
            case 'i':
                arguments->SetFilePath(optarg);
                break;
            case 'g':
                arguments->SetUserValueToFilter(optarg);
                break;
            case 'l':
                arguments->SetFileValueToFilter(optarg);
                break;
            case 'p':
                arguments->SetCommmandValueToFilter(optarg);
                break;
            case 'o':
                arguments->SetSuccessValueToFilter(optarg);
                break;
            case '?':
                fprintf(stderr, "Unknown option character `\\s%s'.\n", optopt);
                return NULL;
            case -1:
                break;
            default:
                abort();
        }
    } while (next_option != -1);

    return arguments;
}

void PrintHelp() {
    cout << " -f: Destination file that have been accessed by LFC command." << endl;
    cout << " -s: User interface where LFC command have been invoked." << endl;
    cout << " -u: User name that invoked LFC command." << endl;
    cout << " -c: LFC command that have been invoked." << endl;
    cout << " -r: Result (Success) of invoked LFC command." << endl;
    cout << " -t: Present average and std. deviation of time per command." << endl;
    cout << " -m: Present command information." << endl;
    cout << " -e: Show time duration for each command. Commands are grouped by name and success." << endl;

    cout << " -d UI : filter by user interface" << endl;
    cout << " -g USER : filter by user" << endl;
    cout << " -l FILE : filter by file name" << endl;
    cout << " -p COMMAND : filter by command name (lfc-ls, lcg-cr, lcg-rep, etc.)" << endl;
    cout << " -o ( true | false ) : filter by command result" << endl;
}
