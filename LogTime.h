/*
 * LogTime.h
 *
 *  Created on: 8 Jul 2013
 *      Author: radek
 */

#ifndef LOGTIME_H_
#define LOGTIME_H_

using namespace std;

#include <sys/time.h>
#include <string>
#include <cstdlib>
#include <iostream>

class LogTime {
public:

    LogTime(string time) {
        int month = atoi(time.substr(0, 2).c_str());
        int day = atoi(time.substr(3, 2).c_str());
        int hour = atoi(time.substr(6, 2).c_str());
        int minutes = atoi(time.substr(9, 2).c_str());
        int seconds = atoi(time.substr(12, 2).c_str());
        int microsec = atoi(time.substr(15, 3).c_str()) * 1000;

        //        cout << time.substr(0, 2) << endl;
        //        cout << time.substr(3, 2) << endl;
        //        cout << time.substr(6, 2) << endl;
        //        cout << time.substr(9, 2) << endl;
        //        cout << time.substr(12, 2) << endl;
        //        cout << time.substr(15, 3) << endl;

        //        if (time.substr(15, 1).compare("0") == 0) {
        //            //            cout << time.substr(15, 3).c_str() << endl;
        //            //            cout << time.substr(15, 1).c_str() << endl;
        //            //            cout << "deleno" << endl;
        //            microsec /= 10;
        //            //            cout << microsec << endl;
        //        }
        //
        //        if (time.substr(16, 1).compare("0") == 0) {
        //            microsec /= 10;
        //        }

        this->timeMillis.tv_usec = microsec;
        this->timeMillis.tv_sec = seconds;
        this->time.tm_year = 1970;
        this->time.tm_mon = month - 1;
        this->time.tm_mday = day;
        this->time.tm_hour = hour;
        this->time.tm_min = minutes;
        this->time.tm_sec = seconds;
    }

    tm GetTime() const {
        return time;
    }

    timeval GetTimeMillis() const {
        return timeMillis;
    }

    bool operator ==(const LogTime * logTime) const {
        if (logTime->time.tm_sec != time.tm_sec) {
            return false;
        }
        if (logTime->time.tm_min != time.tm_min) {
            return false;
        }
        if (logTime->time.tm_hour != time.tm_hour) {
            return false;
        }
        if (logTime->time.tm_mon != time.tm_mon) {
            return false;
        }
        if (logTime->time.tm_year != time.tm_year) {
            return false;
        }
        if (logTime->timeMillis.tv_sec != timeMillis.tv_sec) {
            return false;
        }
        if (logTime->timeMillis.tv_usec != timeMillis.tv_usec) {
            return false;
        }
        return true;
    }

    void toString() {
        cout << this->time.tm_mday << ".";
        cout << this->time.tm_mon << " ";
        if (time.tm_hour < 10) {
            cout << "0" << time.tm_hour << ":";
        } else {
            cout << time.tm_hour << ":";
        }
        if (time.tm_min < 10) {
            cout << "0" << time.tm_min << ":";
        } else {
            cout << time.tm_min << ":";
        }
        if (time.tm_sec < 10) {
            cout << "0" << time.tm_sec << ".";
        } else {
            cout << time.tm_sec << ".";
        }
        if (this->timeMillis.tv_usec / 1000 < 100) {
            if (this->timeMillis.tv_usec / 1000 < 10) {
                cout << "00" << this->timeMillis.tv_usec << endl;
            } else {
                cout << "0" << this->timeMillis.tv_usec << endl;
            }
        } else {
            cout << this->timeMillis.tv_usec << endl;
        }
    }

//    string numberNormalizer(int number) {
//        if (number < 10) {
//            return "0" + string(number);
//        }
//        return string(number);
//    }

private:
    timeval timeMillis;
    tm time;
};


#endif /* LOGTIME_H_ */
