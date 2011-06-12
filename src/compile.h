
// vi: tabstop=4:expandtab

#ifndef OCLC_COMPILE_H_INCLUDED
#define OCLC_COMPILE_H_INCLUDED 1

#include "config.h"


/** \fn    oclc_compile
 *  \brief Compile the input to the output
 *
 *  The function calls the OpenCL just-in-time compiler to
 *  create binary data.
 */
void oclc_compile(const char *input, size_t sz_input, void **output, size_t *sz_output);

#endif

