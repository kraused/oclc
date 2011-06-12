
// vi: tabstop=4:expandtab

#include "config.h"
#include "rw.h"
#include "macros.h"


void oclc_read(const char *fn, char **input, size_t *sz_input)
{
    FILE* fh;

    fh = fopen(fn, "r");
    if(!fh) {
        OCLC_DIE("Could not open input file");
    }

    if(0 != fseek(fh, 0, SEEK_END)) {
        OCLC_DIE("fseek failed");
    }
    *sz_input = ftell(fh);
    if(0 != fseek(fh, 0, SEEK_SET)) {
        OCLC_DIE("fseek failed");
    }

    *input = malloc(*sz_input);
    if(*sz_input != fread(*input, 1, *sz_input, fh)) {
        OCLC_DIE("fread failed");
    }

    if(0 != fclose(fh)) {
        OCLC_DIE("fclose failed");
    }
}

void oclc_write(const char *fn, void *output, size_t sz_output)
{
    FILE* fh;

    fh = fopen(fn, "w");
    if(!fh) {
        OCLC_DIE("Could not open output file");
    }

    if(sz_output != fwrite(output, 1, sz_output, fh)) {
        OCLC_DIE("fwrite failed"); 
    }

    if(0 != fclose(fh)) {
        OCLC_DIE("fclose failed");
    }
}

