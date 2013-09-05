/*
 * Site.h
 *
 *  Created on: 8 Jul 2013
 *      Author: radek
 */

#ifndef SITE_H_
#define SITE_H_

using namespace std;

#include <string>

class Site {
public:

    Site(string name) {
        this->name = name;
    }

    string GetName() const {
        return name;
    }

    bool operator==(Site& site)const {
        if (name.compare(site.GetName()) == 0) {
            return true;
        }
        return false;
    }

private:
    string name;
};

#endif /* SITE_H_ */
