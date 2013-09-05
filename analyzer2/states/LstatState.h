/* 
 * File:   LfcLstatAnalyzerState.h
 * Author: radek
 *
 * Created on 13 July 2013, 19:48
 */

#ifndef LFCLSTATANALYZERSTATE_H
#define	LFCLSTATANALYZERSTATE_H

using namespace std;

#include "State.h"
#include "lfs_ls_states/OpenDirState.h"
#include "../../Functions.h"
#include "lfc_cr_states/StartTransState.h"
#include "lfc_rm_dir/RmDirState.h"

class LstatState : public State {
public:
    LstatState();
    virtual ~LstatState();
    virtual LfcCommand * NextState(
            std::vector<Item *>::const_iterator & iterator,
            vector<Item*> items,
            Item* item
    );
};

#endif	/* LFCLSTATANALYZERSTATE_H */

