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

void Presenter::Print(vector<LfcCommand*> * commands, int file, int user, int site, int commandType, int resultType) {

    vector<LfcCommand *>::const_iterator it1;
    vector<string *> * rows = new vector<string *>;

    int realNumberOfValues = 0;
    for (int i = 0; i < numberOfValues; i++) {
        if (file == i) {
            realNumberOfValues++;
        } else if (user == i) {
            realNumberOfValues++;
        } else if (site == i) {
            realNumberOfValues++;
        } else if (commandType == i) {
            realNumberOfValues++;
        } else if (resultType == i) {
            realNumberOfValues++;
        }
    }


    cout << realNumberOfValues << endl;
    numberOfValues = realNumberOfValues;

    for (it1 = commands->begin(); it1 != commands->end(); ++it1) {
        LfcCommand * command = *it1;

        string * row = this->ExtractValuesFromCommand(command, file, user, site, commandType, resultType);
        rows->push_back(row);
    }

    this->PrintValues(rows);
}

string * Presenter::ExtractValuesFromCommand(LfcCommand* command, int file, int user, int site, int commandType, int resultType) {

    string * row = new string[numberOfValues];

    for (int i = 0; i < numberOfValues; i++) {
        row[i] = "";
    }

    for (int i = 0; i < numberOfValues; i++) {
        string next = "";
        if (file == i) {
            next = command->GetFile();
        } else if (user == i) {
            next = command->GetUser()->GetName();
        } else if (site == i) {
            next = command->GetSite()->GetName();
        } else if (commandType == i) {
            next = command->GetStringName();
        } else if (resultType == i) {
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
