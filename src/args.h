
// vi: tabstop=4:expandtab

#ifndef OCLC_ARGS_H_INCLUDED
#define OCLC_ARGS_H_INCLUDED 1

#include "config.h"

/** \struct oclc_args
 *  \brief  Collection of input arguments
 */
struct oclc_args
{
    char *fn_i;     /**< Name of input file */
    char *fn_o;     /**< Name of output file */
};

/** \var   args
 *  \brief Command line arguments to the executable
 *
 */
extern struct oclc_args args;


/** \fn    oclc_handle_args
 *  \brief Handle commandline arguments.
 *
 *  The function oclc_handle_args parses the command line
 *  arguments using gengetopt.
 */
void oclc_handle_args(int argc, char **argv);

#endif

