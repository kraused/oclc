
CC      = gcc
CFLAGS  = -I/opt/gpucomp/3.2/OpenCL/common/inc -I.
LDFLAGS = -lOpenCL

#
# Default target
#
all: oclc


#
# Create command line parser using gengetopt
#
src/cmdline.h src/cmdline.c: src/oclc.ggo
	gengetopt --unamed-opts -F src/cmdline < $<

oclc: src/cmdline.c src/cmdline.h
	$(CC) $(CFLAGS) -o $@ src/*.c $(LDFLAGS)

#
# Clean up
#
clean:
	rm src/cmdline.h src/cmdline.c oclc

#
# Create the documentation
#
gendoc:
	doxygen doc/oclc.dox

