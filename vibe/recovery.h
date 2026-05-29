#ifndef RECOVERY_H
#define RECOVERY_H

#include "account.h"

class Recovery {
public:
    static void fix_after_crash(Account& acc);
};

#endif
