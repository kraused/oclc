
// vi: tabstop=4:expandtab

#include "args.h"
#include "macros.h"

#include "cmdline.h"


struct oclc_args args;

/** \var   args_info
 *  \brief Output of gengetopt
 *
 *  The structure args_info is created 
 */
struct gengetopt_args_info args_info;

void oclc_handle_args(int argc, char ** argv)
{
    int i;

    if(cmdline_parser(argc, argv, &args_info)) {
        OCLC_DIE("cmdline_parser failed");
    }

    if(1 != args_info.inputs_num) {
        cmdline_parser_print_help();
        OCLC_DIE("Need input file");
    }
    
    args.fn_i = args_info.inputs[0];

    if(args_info.output_given) {
        args.fn_o = args_info.output_arg;
    } else {
        args.fn_o = malloc(strlen(args.fn_i)+2);
        sprintf(args.fn_o, "%s", args.fn_i);

        i = strlen(args.fn_o);
        for(; i >= 0; --i) {
            if('.' == args.fn_o[i]) {
                ++i;
                break;
            }
        }

        if(0 >= i) {
            OCLC_DIE("Unknown file extension");
        }

        args.fn_o[i+0] = 'b';
        args.fn_o[i+1] = 'i';
        args.fn_o[i+2] = 'n';
        args.fn_o[i+3] = '\0';
    }
}

