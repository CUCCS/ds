CC       = cc
CFLAGS   = -Wall  -ggdb3 -Iinclude # debug: put -ggdb instead of -O3
LDFLAGS  =
LIBS     =
DEFS     =
GNUDEF   =
LPTHREAD =
EXENAME  = t_list.exe
OBJECTS  = list.o t_list.o
TESTFILS =
VPATH    = 

all:$(EXENAME)

2.1:2.1.c
		$(CC) $(LDFLAGS) $^ -o 2.1.exe

hanoi:hanoi.c
		$(CC) $(LDFLAGS) $^ -o hanoi.exe

$(EXENAME):$(OBJECTS)
		$(CC) $(LDFLAGS) $(LPTHREAD) $^ -o $(EXENAME)
			-rm -rf *.o

$(OBJECTS):%.o:%.c
		$(CC) -c $(CFLAGS) ${DEFS} ${GNUDEF} $^ -o $@

clean:
		-find . \( -name '*.o' -o -name '*.so' -o -name '*.bak' -o -name 'tags' -o -name '*.exe' -o \
			            -name '*.swp' -o -name '*.out' -o -name '*.gch' -o -name '*.*~' -o \
						           -name 'core.*' -o -name '*.gch' -o -name '*.files' -o -name '$(TESTFILS)' \) -type f -execdir rm -f '{}' \;

.PHONY: clean
