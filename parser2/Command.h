/*
 * Command.h
 *
 *  Created on: 8 Jul 2013
 *      Author: radek
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include "../Functions.h"
#include <iostream>

using namespace std;

class Command {
public:

    Command(FunctionType name, int returnCode) {
        this->name = name;
        this->returnCode = returnCode;
    }

    FunctionType getName() const {
        return name;
    }

    int getReturnCode() const {
        return returnCode;
    }

    bool operator ==(const Command * command) const {
        if (name != command->getName()){
            return false;
        }
        if (returnCode != command->getReturnCode()){
            return false;
        }
        return true;
    }

    void setReturnCode(int returnCode) {
        this->returnCode = returnCode;
    }

private:
    FunctionType name;
    int returnCode;
};

#endif /* COMMAND_H_ */
