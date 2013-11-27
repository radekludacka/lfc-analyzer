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

        string commandName = *setIterator;
        vector<LfcCommand *> * sameCommands = new vector<LfcCommand *>;

        vector<LfcCommand *>::const_iterator iterator;
        iterator = commands->begin();
        LfcCommand * command = *iterator;
        sameCommands->push_back(command);
        LogTime * avgLogTime = command->GetEndTime()->minus(command->GetStartTime());
        ++iterator;

        for (; iterator != commands->end(); ++iterator) {
            LfcCommand * command = *iterator;

            if (CompareCommandValue(command, commandName)) {
                LogTime * timeDuration = command->GetEndTime()->minus(command->GetStartTime());
                avgLogTime = avgLogTime->plus(timeDuration);
                avgLogTime = avgLogTime->divTwo();
                sameCommands->push_back(command);
            }
        }

        double mean = (double) avgLogTime->miliseconds();
        double stdErr = this->CalculateStandardDeviation(sameCommands, mean);

        for (int i = 0; i < (int) commands->size(); i++) {
            LfcCommand * command = commands->at(i);
            command->SetAverageTimeDuration(avgLogTime);
            command->SetStandardTimeErrorDuration(stdErr);
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
