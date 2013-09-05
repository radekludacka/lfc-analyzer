/* 
 * File:   Information.h
 * Author: radek
 *
 * Created on 23 July 2013, 15:38
 */

#ifndef INFORMATION_H
#define	INFORMATION_H

using namespace std;

#include <string>
#include <vector>

class Information {
public:
    Information();
    Information(const Information& orig);
    virtual ~Information();
    void addInformation(string information);
private:
    vector<string> * informations;
};

#endif	/* INFORMATION_H */

