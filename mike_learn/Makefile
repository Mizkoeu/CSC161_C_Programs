# Generic Makefile for compiling a single C program and linking with relevant
# MyroC, bluetooth, jpeg, etc. libraries for CSC 161
#
# Written by Jerod Weinman, 14 January 2015
# Extended by Henry M. Walker, 15 January 2015
# Preprocessor flags added by Jerod Weinman, 19 January 2015

# Type "make foo". 
# We rely on the implicit  rules foo.c -> foo.o for compiling and
# foo.o --> foo for linking

# Use the gcc compiler
CC = gcc

# Set preprocessor flags
CPPFLAGS=-I/home/walker/MyroC/include

# Set appropriate compiling flags
CFLAGS=-Wall -std=gnu99

# include the location of the MyroC shared library object file #
LIBRARY_PATH=$LIBRARY_PATH:/home/walker/MyroC/lib

# Set linker flags to include the relevant libraries
LDFLAGS=-L/home/walker/MyroC/lib -lMyroC -lbluetooth -ljpeg -leSpeakPackage -lm 

#----------------------------------------------------------------------------
# cleanup rules: To invoke this command, type "make clean".
# Use this target to clean up your directory, deleting (without warning) 
#   object files, old emacs source versions, and core dumps.

clean: 
	rm -f *.o *~ core*
