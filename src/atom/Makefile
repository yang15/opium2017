# Makefile for src/atom

SHELL=/bin/sh

include ../../makevars

fobjects =  ykf.o zkf.o excorr.o pbe.o corpz.o corvwn.o

cobjects = do_ae.o 

all_objects = $(fobjects) $(cobjects)

this_dir = atom

.F.o:
	$(FC) $(FFLAGS) $(OPTIONS)  -I../include $*.F -c 

all: $(all_objects)
	-rm -f objects
	for i in $(all_objects); do echo $(this_dir)/$$i >> objects; done

clean:
	rm -f $(fobjects) $(cobjects) libatom.a core* *~ *.f.f objects

distclean: clean


