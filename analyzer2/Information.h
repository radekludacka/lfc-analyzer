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
    void SetInformation(string information);
    string GetInformation() const;
private:
    string info;
};

#endif	/* INFORMATION_H */

