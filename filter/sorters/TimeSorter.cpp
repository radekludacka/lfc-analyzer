/* 
 * File:   TimeSorter.cpp
 * Author: radek
 * 
 * Created on 23 October 2013, 16:27
 */

#include "TimeSorter.h"

TimeSorter::TimeSorter() {
}

TimeSorter::~TimeSorter() {
}

TimeSorter::TimeSorter(Sorter* subSorter) : Sorter(subSorter) {
}

string TimeSorter::GetItemToSort(LfcCommand * command) {
    return command->GetStringName();
}

vector<LfcCommand * > * TimeSorter::Sort(vector<LfcCommand*> * commands) {

    if (commands->size() < 3) {
        return commands;
    }

    vector<LfcCommand *> * sortedCommands = new vector<LfcCommand *>;

    set<string> extractedValues = ExtractByString(commands);
    assert(extractedValues.size() == 1);

    set<string>::iterator setIterator;
    for (setIterator = extractedValues.begin(); setIterator != extractedValues.end(); ++setIterator) {
        unsigned long long sum = 0;
        string commandName = *setIterator;
        vector<LfcCommand *> * sameCommands = new vector<LfcCommand *>;
        vector<LfcCommand *>::const_iterator iterator;

        int max = 0;
        int min = INT_MAX;
//        string failed = "Good";
//        string user = commands->at(0)->GetUser()->GetName();
//        bool fail = commands->at(0)->IsFailed();
//        if (commands->at(0)->IsFailed()) {
//            failed = "Failed";
//        }
        
//        cout << string("*") + commandName + string("-") + failed << endl;
        for (iterator = commands->begin(); iterator != commands->end(); ++iterator) {
            LfcCommand * command = *iterator;
            
//            if (!CompareCommandValue(command, commandName)){
//                cout << "BLE" << endl;
//            }
//
//            if (command->IsFailed() != fail){
//                cout << "BLE2" << endl;
//            }
            
            if (CompareCommandValue(command, commandName)) {
                LogTime * timeDuration = command->GetEndTime()->minus(command->GetStartTime());
                int timeMillis = timeDuration->miliseconds();
//                cout << command->GetStartTime()->asStringShortHours() << " | " << timeMillis << endl;
                unsigned long long sumBackup = sum;
                sum += timeMillis;

                if (sum < sumBackup) {
                    throw "Sum overflowed";
                }

                if (timeMillis > max) {
                    max = timeMillis;
                }

                if (timeMillis < min) {
                    min = timeMillis;
                }

                sameCommands->push_back(command);
            }
        }

        double mean = (double) sum / sameCommands->size();
        double stdErr = this->CalculateStandardDeviation(sameCommands, mean);

        for (int i = 0; i < (int) commands->size(); i++) {
            LfcCommand * command = commands->at(i);
            command->SetAverageTimeDuration(new LogTime(mean));
            command->SetStandardTimeErrorDuration(stdErr);
            command->SetMaxTimeDuration(new LogTime(max));
            command->SetMinTimeDuration(new LogTime(min));
        }

        if (subSorter != NULL) {
            commands = subSorter->Sort(commands);
        }

        sortedCommands->insert(sortedCommands->end(), commands->begin(), commands->end());
    }

    return sortedCommands;
}

double TimeSorter::CalculateStandardDeviation(vector<LfcCommand*> * commands, double mean) {
    double numberOfCommands = (double) commands->size();
    double sum = 0.0;

    vector<LfcCommand *>::const_iterator iterator1;
    for (iterator1 = commands->begin(); iterator1 != commands->end(); ++iterator1) {
        LfcCommand * command = *iterator1;
        LogTime * timeDuration = command->GetEndTime()->minus(command->GetStartTime());
        double floatPointTimeDuration = (double) timeDuration->miliseconds();
        double diff = (floatPointTimeDuration - mean) * (floatPointTimeDuration - mean);
        sum += diff;

    }
    return sqrt(sum / numberOfCommands);
}
