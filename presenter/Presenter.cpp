/* 
 * File:   Presenter.cpp
 * Author: radek
 * 
 * Created on 31 July 2013, 09:46
 */

#include "Presenter.h"

Presenter::Presenter() {
    this->numberOfValues = 5;
}

Presenter::~Presenter() {
}

void Presenter::Print(vector<LfcCommand*> * commands, Arguments * arguments) {

    vector<LfcCommand *>::const_iterator it1;
    vector<string *> * rows = new vector<string *>;

    int realNumberOfValues = 0;
    for (int i = 0; i < numberOfValues; i++) {
        if (arguments->GetFileOrder() == i) {
            realNumberOfValues++;
        } else if (arguments->GetUserOrder() == i) {
            realNumberOfValues++;
        } else if (arguments->GetSiteOrder() == i) {
            realNumberOfValues++;
        } else if (arguments->GetCommandOrder() == i) {
            realNumberOfValues++;
        } else if (arguments->GetResultTypeOrder() == i) {
            realNumberOfValues++;
        } else if (arguments->GetTimeOrder() == i) {
            realNumberOfValues++;
        }
    }

    numberOfValues = realNumberOfValues;
    for (it1 = commands->begin(); it1 != commands->end(); ++it1) {
        LfcCommand * command = *it1;
        string * row = this->ExtractValuesFromCommand(command, arguments);
        rows->push_back(row);
    }

    this->PrintValues(rows);
    for (vector<string*>::const_iterator it = rows->begin(); it != rows->end(); it++) {
        delete[] (*it);
    }
    rows->clear();
    delete rows;
}

string * Presenter::ExtractValuesFromCommand(LfcCommand* command, Arguments * arguments) {

    string * row = new string[numberOfValues];

    for (int i = 0; i < numberOfValues; i++) {
        row[i] = "";
    }

    for (int i = 0; i < numberOfValues; i++) {
        string next = "";
        if (arguments->GetFileOrder() == i) {
            next = command->GetFile();
        } else if (arguments->GetUserOrder() == i) {
            next = command->GetUser()->GetName();
        } else if (arguments->GetSiteOrder() == i) {
            next = command->GetSite()->GetName();
        } else if (arguments->GetCommandOrder() == i) {
            next = command->GetStringName();
        } else if (arguments->GetTimeOrder() == i) {
            string time = command->GetAverageTimeDuration()->asStringShort();
            std::ostringstream oss;
            oss << command->GetStandardTimeErrorDuration();
            string stderror = oss.str();
            std::ostringstream sMin;
            std::ostringstream sMax;
            sMin << command->GetMinTimeDuration()->miliseconds();
            sMax << command->GetMaxTimeDuration()->miliseconds();
            string min = sMin.str();
            string max = sMax.str();
            row[i] = time + string(" +- ") + stderror + string(" ms <") + min + string(",") + max + ">";
        } else if (arguments->GetResultTypeOrder() == i) {
            if (command->IsFailed()) {
                next = "failed";
            } else {
                next = "succeed";
            }
        }

        if (next.compare("") != 0) {
            row[i] = next;
        }
    }

    return row;
}

void Presenter::PrintValues(vector<string*> * rows) {

    int * itemWidths = this->FindOutMaxStringWidths(rows);

    string previousRow1[numberOfValues];
    string * previousRow = previousRow1;

    for (int i = 0; i < numberOfValues; i++) {
        previousRow[i] = "";
    }

    vector<string *>::const_iterator iterator;
    for (iterator = rows->begin(); rows->end() != iterator; ++iterator) {

        string * row = *iterator;

        bool sameRows = true;
        for (int i = 0; i < numberOfValues; i++) {
            if (row[i].compare(previousRow[i]) != 0) {
                sameRows = false;
            }
        }

        if (sameRows) {
            continue;
        }

        for (int i = 0; i < numberOfValues; i++) {

            int numberOfSameValues = 0;
            string numberOfSameValuesString = "";

            if (previousRow[i].compare(row[i]) != 0 or
                    (i > 0 and previousRow[i - 1].compare(row[i - 1]) != 0)) {
                vector<string *>::const_iterator iterator2;
                iterator2 = iterator;

                numberOfSameValues = 0;
                while (rows->end() != iterator2 and (*iterator2)[i].compare((*iterator)[i]) == 0) {
                    if (i > 0) {
                        if ((*iterator2)[i - 1].compare((*iterator)[i - 1]) == 0) {
                            numberOfSameValues++;
                        }
                    } else {
                        numberOfSameValues++;
                    }
                    iterator2++;
                }

                numberOfSameValuesString = this->IntToString(numberOfSameValues);

                int width = itemWidths[i] - row[i].size() - numberOfSameValuesString.size() + 1;
                printf("%s %*s : %s |", row[i].c_str(), width, " ", numberOfSameValuesString.c_str());
            } else {
                printf("%*s      |", itemWidths[i], " ");
            }
        }
        cout << endl;
        previousRow = row;
    }

    delete[] itemWidths;
}

int * Presenter::FindOutMaxStringWidths(vector<string*> * rows) {
    int * itemWidths = new int[numberOfValues];

    for (int i = 0; i < numberOfValues; i++) {
        itemWidths[i] = 0;
    }

    for (int i = 0; i < numberOfValues; i++) {
        int maxNumberOfSameValue = 0;
        vector<int> maxValuesNumbers;

        string previousRow1[numberOfValues];
        string * previousRow = previousRow1;
        for (int j = 0; j < numberOfValues; j++) {
            previousRow[j] = "";
        }

        vector<string *>::const_iterator iterator;
        for (iterator = rows->begin(); rows->end() != iterator; ++iterator) {
            string * row = *iterator;

            if (row[i].compare(previousRow[i]) != 0) {
                maxValuesNumbers.push_back(maxNumberOfSameValue);
                maxNumberOfSameValue = 0;
                if ((int) row[i].length() > itemWidths[i]) {
                    itemWidths[i] = row[i].length();
                }
            } else {
                maxNumberOfSameValue++;
            }

            previousRow = row;
        }

        maxValuesNumbers.push_back(maxNumberOfSameValue);

        int maxValueNumber = 0;
        vector<int>::const_iterator iterator1;
        for (iterator1 = maxValuesNumbers.begin(); maxValuesNumbers.end() != iterator1; ++iterator1) {
            if (maxValueNumber < *iterator1) {
                maxValueNumber = *iterator1;
            }
        }

        itemWidths[i] += this->IntToString(maxValueNumber).size();
    }
    return itemWidths;
}

string Presenter::IntToString(const int& port) {
    stringstream ss;
    ss << port;
    return ss.str();
}
