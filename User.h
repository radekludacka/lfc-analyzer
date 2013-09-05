/*
 * User.h
 *
 *  Created on: 8 Jul 2013
 *      Author: radek
 */

#ifndef USER_H_
#define USER_H_

using namespace std;

#include <string>
#include <iostream>

class User {
public:

    User(string name) {
        this->name = name;
    }

    string GetName() const {
        return name;
    }

    void SetName(string name) {
        this->name = name;
    }
    
    bool operator==(User& rhs)const {
        if (name.compare(rhs.GetName()) == 0){
            return true;
        }
        return false;
    }


private:
    string name;
};

#endif /* USER_H_ */
