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
#include <time.h> 
#include <sstream>
#include <limits.h>
#include <stdio.h>

class LogTime {
public:

    LogTime() {
    }

    LogTime(string time) {
        int month = atoi(time.substr(0, 2).c_str());
        int day = atoi(time.substr(3, 2).c_str());
        int hour = atoi(time.substr(6, 2).c_str());
        int minutes = atoi(time.substr(9, 2).c_str());
        int seconds = atoi(time.substr(12, 2).c_str());
        int microsec = atoi(time.substr(15, 3).c_str()) * 1000;

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

    void SetTime(tm time) {
        this->time = time;
    }

    void SetTimeMillis(timeval timeMillis) {
        this->timeMillis = timeMillis;
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

    LogTime * plus(LogTime * logTime2) {
        tm tm1 = this->time;
        tm tm2 = logTime2->GetTime();
        tm sumTime;
        timeval sumTimeMillis;

        sumTime.tm_hour = 0;
        sumTime.tm_mday = 0;
        sumTime.tm_isdst = 0;
        sumTime.tm_year = 1;

        sumTime.tm_min = tm1.tm_min + tm2.tm_min;
        if (sumTime.tm_min > 59) {
            sumTime.tm_min = tm1.tm_min + tm2.tm_min - 60;
            sumTime.tm_hour += 1;
        }

        sumTime.tm_sec = tm1.tm_sec + tm2.tm_sec;
        if (sumTime.tm_sec > 59) {
            sumTime.tm_sec = tm1.tm_sec + tm2.tm_sec - 60;
            sumTime.tm_min += 1;
        }

        sumTimeMillis.tv_usec = this->GetTimeMillis().tv_usec + logTime2->GetTimeMillis().tv_usec;
        if (sumTimeMillis.tv_usec > 1000000) {
            sumTimeMillis.tv_usec = logTime2->GetTimeMillis().tv_usec + this->GetTimeMillis().tv_usec - 1000000;
            sumTime.tm_sec += 1;
            if (sumTime.tm_sec > 59) {
                sumTime.tm_min += 1;
            }
        }

        LogTime * sum = new LogTime();
        sum->SetTime(sumTime);
        sum->SetTimeMillis(sumTimeMillis);
        return sum;
    }

    LogTime * divTwo() {
        tm resultTime;
        timeval resultMillisTime;

        resultTime.tm_mday = 0;
        resultTime.tm_isdst = 0;
        resultTime.tm_year = 1;

        int seconds = this->time.tm_sec;
        seconds += this->time.tm_hour * 60 * 60;
        seconds += this->time.tm_min * 60;

        int averageSeconds = seconds / 2;
        resultMillisTime.tv_usec = this->timeMillis.tv_usec / 2;
        if (averageSeconds * 2 != seconds) {
            resultMillisTime.tv_usec += 500000;
        }

        resultTime.tm_hour = averageSeconds / 3600;
        averageSeconds = averageSeconds % 3600;
        resultTime.tm_min = averageSeconds / 60;
        averageSeconds = averageSeconds % 60;
        resultTime.tm_sec = averageSeconds;

        LogTime * sum = new LogTime();
        sum->SetTime(resultTime);
        sum->SetTimeMillis(resultMillisTime);
        return sum;
    }

    LogTime * minus(LogTime * logTime2) {
        LogTime * difference = new LogTime();
        tm tm1 = this->time;
        tm tm2 = logTime2->GetTime();
        tm diffTime;
        timeval diffMillisTime;

        diffTime.tm_hour = 0;
        diffTime.tm_mday = 0;
        diffTime.tm_isdst = 0;
        diffTime.tm_year = 0;

        diffTime.tm_min = tm1.tm_min - tm2.tm_min;
        if (diffTime.tm_min < 0) {
            diffTime.tm_min = 59 - tm1.tm_min + tm2.tm_min;
        }

        diffTime.tm_sec = tm1.tm_sec - tm2.tm_sec;
        if (diffTime.tm_sec < 0) {
            diffTime.tm_sec = 59 - tm1.tm_sec + tm2.tm_sec;
            diffTime.tm_min -= 1;
        }

        diffMillisTime.tv_usec = this->GetTimeMillis().tv_usec - logTime2->GetTimeMillis().tv_usec;
        if (diffMillisTime.tv_usec < 0) {
            diffMillisTime.tv_usec = 1000000 - logTime2->GetTimeMillis().tv_usec + this->GetTimeMillis().tv_usec;
            diffTime.tm_sec -= 1;
            if (diffTime.tm_sec > 59) {
                diffTime.tm_min -= 1;
            }
        }

        difference->SetTime(diffTime);
        difference->SetTimeMillis(diffMillisTime);
        return difference;
    }

    string asStringShort() {
        char buffer[50];
        sprintf(buffer, "%02dm:%02ds.%06dus", time.tm_min, time.tm_sec, timeMillis.tv_usec);
        std::string result1(buffer);
        return result1;
    }

    string asString() {
        char buffer[50];
        sprintf(buffer, "%02dd.%02dmon %02dh:%02dm:%02ds.%06dus",
                time.tm_mday, time.tm_mon, time.tm_hour, time.tm_min, time.tm_sec, timeMillis.tv_usec);
        std::string result1(buffer);
        return result1;
    }

    int miliseconds() {
        int seconds = this->time.tm_sec;
        seconds += this->time.tm_hour * 60 * 60;
        seconds += this->time.tm_min * 60;
        return this->timeMillis.tv_usec / 1000 + seconds * 1000;
    }

    void print() {
        cout << this->asString() << endl;
    }

private:
    timeval timeMillis;
    tm time;
};


#endif /* LOGTIME_H_ */
