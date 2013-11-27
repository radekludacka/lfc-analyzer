#ifndef ITEM_H_
#define ITEM_H_

using namespace std;

#include "parser2/Command.h"
#include "User.h"
#include "Site.h"
#include <string>
#include "LogTime.h"
#include <string.h>

class Item {
public:

    Item(LogTime* startTime, LogTime* endTime, Command* command, User * user, Site * site, string filePath, string information, int tid) {
        if (user->GetName().length() != 0 && user->GetName().find('=') == std::string::npos) {
            cout << "1" << endl;
            cout << command->getName() << endl;
            startTime->print();
            cout << user->GetName() << endl;
            cout << filePath << endl;
            throw "user contains path";
        }
        
        this->startTime = startTime;
        this->endTime = endTime;
        this->command = command;
        this->user = user;
        this->site = site;
        this->filePath = filePath;
        this->information = information;
        this->assigned = false;
        this->tid = tid;
    }

    virtual ~Item() {
        //        delete startTime;
        //        delete endTime;
        delete command;
        //        delete user;
        //        delete site;
    }

    string GetFilePath() const {
        return filePath;
    }

    Site* GetSite() const {
        return site;
    }

    User* GetUser() const {
        return user;
    }

    Command* GetCommand() const {
        return command;
    }

    LogTime* GetEndTime() const {
        return endTime;
    }

    LogTime* GetStartTime() const {
        return startTime;
    }

    string GetInformation() const {
        return information;
    }

    void SetAssigned(bool assigned) {
        this->assigned = assigned;
    }

    bool IsAssigned() const {
        return assigned;
    }

    int GetTid() const {
        return tid;
    }

    bool compareUserSiteFile(Item * item) {
        if (*this->GetUser() == *item->GetUser() and
                *this->GetSite() == *item->GetSite() and
                strcmp(this->GetFilePath().c_str(), item->GetFilePath().c_str()) == 0) {
            return true;
        }
        return false;
    }

    bool compareUserSiteTid(Item * item) {
        if (this->GetTid() == item->GetTid() and
                *this->GetUser() == *item->GetUser() and
                *this->GetSite() == *item->GetSite()) {
            return true;
        }
        return false;
    }

    bool compareUserSite(Item * item) {
        if (*this->GetUser() == *item->GetUser() and
                *this->GetSite() == *item->GetSite()) {
            return true;
        }
        return false;
    }

    void SetInformation(string information) {

        this->information = information;
    }

    void SetEndTime(LogTime * endTime) {
        this->endTime = endTime;
    }

    void SetTid(int tid) {
        this->tid = tid;
    }

    void SetFilePath(string filePath) {
        this->filePath = filePath;
    }


private:
    LogTime * startTime;
    LogTime * endTime;
    Command * command;
    User * user;
    Site * site;
    string filePath;
    string information;
    bool assigned;
    int tid;
};

#endif /* ITEM_H_ */
