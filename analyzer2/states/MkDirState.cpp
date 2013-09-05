/* 
 * File:   MkDirState.cpp
 * Author: radek
 * 
 * Created on 17 July 2013, 13:58
 */

#include "MkDirState.h"

MkDirState::MkDirState() {
}

MkDirState::~MkDirState() {
}

LfcCommand * MkDirState::NextState(
        std::vector<Item *>::const_iterator & iterator,
        vector<Item*> items,
        Item* item
        ) {

    bool failed = false;
    if (item->GetCommand()->getReturnCode() == 17) {
        failed = true;
    }

    string::size_type pos;
    pos = item->GetFilePath().find(' ', 0);
    string second = item->GetFilePath().substr(pos + 1);
    string first = item->GetFilePath().substr(0, pos);

    PrintMessage("MKDIR", item);

    return new LfcMkdirCommand(item->GetStartTime(),
            item->GetEndTime(),
            first,
            item->GetUser(),
            item->GetSite(),
            failed);
}