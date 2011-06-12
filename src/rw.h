
#ifndef OCLC_RW_H_INCLUDED
#define OCLC_RW_H_INCLUDED 1

#include "config.h"


/** \fn    oclc_read
 *  \brief Read input source file
 *
 *  The function reads the input OpenCL file written
 *  in C.
 */
void oclc_read(const char *fn, char **input, size_t *sz_input);


/** \fn    oclc_write
 *  \brief Write binary output
 *
 *  The function writes the compiled binary to an 
 *  output file
 */
void oclc_write(const char *fn, void *output, size_t sz_output);

#endif

