CXX = gcc
CCFLAGS = -g -Wall -Werror -ansi -pedantic -fpic

LIBFILES = int2letter letter2int puissance1000 translate
SOURCELIBFILES = $(LIBFILES:=.c)
OBJECTLIBFILES = $(LIBFILES:=.o)
HEADERLIBFILES = $(LIBFILES:=.h)

TARGETFILES = main

all: clean $(TARGETFILES)
	@echo "\n*******************************\nYou have also the following command:\n- clean: Remove temp files and libraries\n- launch: Launch directly the project after the compilation with default files (fichier_1 with input numbers and resultat_1 for output numbers) (include the 'all' command)\n- open: Open in Gedit all the files needed by the program before compilation (Makefile, *.c & *.h)\n"

$(TARGETFILES): $(TARGETFILES).o $(OBJECTLIBFILES)
	@echo "\n"
	$(CXX) $(CCFLAGS) -o $@ $^

.c.o:
	@echo "\nGeneration of " $@ " from " $<
	$(CXX) $(CCFLAGS) -c -o $@ $<

clean:
	@echo "\nCleaning current directory"
	rm -f *.o *~

launch: all
	./$(TARGETFILES) ./fichier_1 ./resultat_1

open:
	gedit ./$(TARGETFILES).c ./$(HEADERLIBFILES) ./$(SOURCELIBFILES) ./Makefile&
