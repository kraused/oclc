
// vi: tabstop=4:expandtab

#include "check.h"
#include "macros.h"


void oclc_check_err(cl_int err, const char *msg)
{
    if(CL_SUCCESS != err) {
        OCLC_DIE(msg);
    }
}

