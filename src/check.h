
// vi: tabstop=4:expandtab

#ifndef OCLC_CHECK_H_INCLUDED
#define OCLC_CHECK_H_INCLUDED 1

#include "config.h"
#include "macros.h"


/** \def   OCLC_CL_CHECK
 *  \brief Check return value of an OpenCL function
 *
 *  The OCLC_CL_CHECK checks the error code returned by
 *  an OpenCL function
 */ 
#undef  OCLC_CL_CHECK
#define OCLC_CL_CHECK(F) oclc_check_err(F, #F " failed at " __FILE__ ":" STR(__LINE__))

/** \def   OCLC_INSIST
 *  \brief Insist on a condition
 */
#undef  OCLC_INSIST
#define OCLC_INSIST(C) if(!(C)) { OCLC_DIE("Condition " #C " not fulfilled at " __FILE__ ":" STR(__LINE__)); }


/** \fn    oclc_check_err
 *  \brief Check error codes returned by OpenCL functions
 *
 *  The function checks for the error code err and kills the
 *  application if err is not equal to CL_INT.
 */
void oclc_check_err(cl_int err, const char *msg);

#endif

