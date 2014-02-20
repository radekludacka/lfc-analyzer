/*
 * Row.h
 *
 *  Created on: 9 Jul 2013
 *      Author: radek
 */

#ifndef ROW_H_
#define ROW_H_

using namespace std;

#include "../LogTime.h"
#include <string>

class Row {

public:
	Row(LogTime * time, int jid, int tid, string function, string remain, bool parsed) {
		this->time = time;
		this->jid = jid;
		this->tid = tid;
		this->function = function;
		this->remain = remain;
		this->parsed = parsed;
	}
        
        void SetParsed(bool parsed) {
            this->parsed = parsed;
        }

        bool GetParsed() const {
            return parsed;
        }

        string GetRemain() const {
            return remain;
        }

        string GetFunction() const {
            return function;
        }

        int GetTid() const {
            return tid;
        }

        int GetJid() const {
            return jid;
        }

        LogTime * GetTime() const {
            return time;
        }

private:
	LogTime * time;
	int jid;
	int tid;
	string function;
	string remain;
	bool parsed;
};

#endif /* ROW_H_ */
