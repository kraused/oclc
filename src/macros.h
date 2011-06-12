
// vi: tabstop=4:expandtab

#ifndef OCLC_MACROS_H_INCLUDED
#define OCLC_MACROS_H_INCLUDED 1

/** \def   OCLC_DIE
 *  \brief Print an error message and kill the application
 *
 *  The OCLC_DIE macro is intended for handling fatal errors
 *  in the execution.
 */
#undef  OCLC_DIE
#define OCLC_DIE(MSG) do { printf(" [ERR] %s\n", MSG); exit(128); } while(0)

// The famout STR macro to stringify macros and other statements
#undef  XSTR
#define XSTR(S) #S
#undef  STR
#define STR(S)  XSTR(S)

#endif

