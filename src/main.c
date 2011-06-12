
// vi: tabstop=4:expandtab

#include "config.h"
#include "args.h"
#include "rw.h"
#include "compile.h"


int main(int argc, char **argv)
{
    char *input;
    size_t sz_input;
    void *output;
    size_t sz_output;

    oclc_handle_args(argc, argv);

    oclc_read(args.fn_i, 
              &input, 
              &sz_input);
    oclc_compile(input,
                 sz_input,
                 &output,
                 &sz_output);
    oclc_write(args.fn_o, 
               output, 
               sz_output);

    return 0;
}

