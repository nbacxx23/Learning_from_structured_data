# BaseNP Chunker, v. 1
# Copyright (C) 1995 University of Pennsylvania
# See file README_chunker for further information.

# CC should be defined as the name of your C++ compiler.
CC = g++

CFLAGS = -g
LDFLAGS = 
LOADLIBES = -lm

objs = methods.o init.o rules.o apply.o templates.o debug_assert.o

headers = init.H rules.H apply.H templates.H debug_assert.H

chunker: chunker.o $(objs) $(headers)
	$(CC) $(CFLAGS) -o $@ chunker.o $(objs) $(LDFLAGS) $(LOADLIBES)

$(objs): defns.H templ_enum.H types.H extern.H
chunker.o : defns.H templ_enum.H types.H extern.H

clean:
	/bin/rm -f *.o

.SUFFIXES: .C .cc

.c:
	gcc $(CFLAGS) $(LDFLAGS) $< $(LOADLIBES) -o $@ 

.C:
	$(CC) $(CFLAGS) $(LDFLAGS) $< $(LOADLIBES) -o $@ 

.cc:
	$(CC) $(CFLAGS) $(LDFLAGS) $< $(LOADLIBES) -o $@ 

.c.o:
	gcc $(CFLAGS) -c $< 

.C.o:
	$(CC) $(CFLAGS) -c $<

.cc.o:
	$(CC) $(CFLAGS) -c $< 

