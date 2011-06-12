
// vi: tabstop=4:expandtab

#include "config.h"
#include "macros.h"
#include "check.h"
#include "compile.h"


void pfn_notify(cl_program program, void* user_data)
{
    cl_build_status status;
    char buffer[1024];
    
    OCLC_CL_CHECK(clGetProgramBuildInfo(program,*(cl_device_id* )user_data, CL_PROGRAM_BUILD_STATUS,
                  sizeof(status), &status, NULL));
    if(CL_BUILD_SUCCESS == status || CL_BUILD_IN_PROGRESS == status) {
        return;
    }

    OCLC_CL_CHECK(clGetProgramBuildInfo(program,*(cl_device_id* )user_data, CL_PROGRAM_BUILD_LOG,
                                sizeof(buffer), buffer, NULL));
    printf("%s", buffer);
}


void oclc_compile(const char *input, size_t sz_input, void **output, size_t *sz_output)
{
    cl_platform_id platform_id = NULL;
    cl_device_id device_id = NULL;
    cl_context context = NULL;
    cl_program program;
    cl_uint num_platforms, num_devices;
    cl_int errcode_ret;
    int i;
    char buffer[1024];

    OCLC_CL_CHECK(clGetPlatformIDs(0, NULL, &num_platforms));
    OCLC_INSIST(1 == num_platforms);
    OCLC_CL_CHECK(clGetPlatformIDs(1, &platform_id, NULL));

    OCLC_CL_CHECK(clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &num_devices));
    OCLC_INSIST(num_devices > 0);

    context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &errcode_ret);
    OCLC_CL_CHECK(errcode_ret);

    program = clCreateProgramWithSource(context, 1, (const char** )&input, &sz_input, &errcode_ret);
    OCLC_CL_CHECK(errcode_ret);

    OCLC_CL_CHECK(clBuildProgram(program, 1, &device_id, NULL, pfn_notify, &device_id));

    OCLC_CL_CHECK(clGetProgramInfo(program, CL_PROGRAM_BINARY_SIZES, sizeof(size_t), sz_output, NULL));

    *output = malloc(*sz_output);
    OCLC_CL_CHECK(clGetProgramInfo(program, CL_PROGRAM_BINARIES, *sz_output, output, NULL));
}

