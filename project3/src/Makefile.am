## Process this file with automake to produce Makefile.in

INCLUDES = \
	-DPACKAGE_DATA_DIR=\""$(datadir)"\" \
	-DPACKAGE_LOCALE_DIR=\""$(prefix)/$(DATADIRNAME)/locale"\" \
	@PACKAGE_CFLAGS@

bin_PROGRAMS = project3

project3_SOURCES = \
	main.c \
	support.c support.h \
	interface.c interface.h \
	callbacks.c callbacks.h \
	fonctionm.c fonctionm.h \
	treeadh.c treeadh.h \
	treemed.c treemed.h \
	treediete.c treediete.h \
	treecoach.c treecoach.h \
	treekine.c treekine.h \
	treeusers.c treeusers.h \
	treeacceuil.c treeacceuil.h \
	treeplanning.c treeplanning.h \
	treedeal.c treedeal.h \
	treeevent.c treeevent.h

project3_LDADD = @PACKAGE_LIBS@ $(INTLLIBS)

