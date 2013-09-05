#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

using namespace std;

enum FunctionType { 
        LSTAT,     // 0
        ACCESS,    // 1
        OPENDIR,   // 2
        READDIR,   // 3
        STARTSESS, // 4
        ENDSESS,   // 5
        DELREPLICA,// 6
        GETREPLICA,// 7
        UNLINK,    // 8
        GETLINKS,  // 9
        STARTTRANS,// 10
        ENDTRANS,  // 11
        STATG,     // 12
        CREAT,     // 13
        ADDREPLICA,// 14
        SETFSIZEG, // 15
        MKDIR,     // 16
        STATR,     // 17
        SERV,      // 18
        CLOSEDIR,  // 19
        UTIME,     // 20
        PINGDB,    // 21
        SYMLINK,   // 22
        GETPATH,   // 23
        CHDIR,     // 24
        RMDIR,     // 25
        };

#endif	/* FUNCTIONS_H */

