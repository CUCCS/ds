CC       = cc
CFLAGS   = -DDEBUG=0 -Wall  -ggdb3 -Iinclude # debug: put -ggdb instead of -O3
LDFLAGS  =
LIBS     =
DEFS     =
GNUDEF   =
LPTHREAD =
EXENAME  = t_list.exe
OBJECTS  = stack.o list.o t_list.o
TESTFILS =
VPATH    = 

all:$(EXENAME)

t_sort:t_sort.c sort.o
		$(CC) $(CFLAGS) $(LDFLAGS) $^ -o t_sort.exe
			-rm -rf *.o

t_hashtable:t_hashtable.c hashtable.o
		$(CC) $(CFLAGS) $(LDFLAGS) $^ -o t_hashtable.exe
			-rm -rf *.o

t_hashtable_chained:t_hashtable.c chained_hashtable.o
		$(CC) $(CFLAGS) $(LDFLAGS) -DCHAINED_HASH $^ -o t_hashtable_chained.exe
			-rm -rf *.o

chained_hashtable.o:hashtable.c
		$(CC) -c $(CFLAGS) $(LDFLAGS) -DCHAINED_HASH $^ -o chained_hashtable.o

t_dijkstra:t_dijkstra.c dijkstra.o dijkstra_graph.o
		$(CC) $(CFLAGS) $(LDFLAGS) $^ -o t_dijkstra.exe
			-rm -rf *.o

dijkstra_graph.o:graph.c
		$(CC) -c $(CFLAGS) $(LDFLAGS) -DDIJSKTRA $^ -o dijkstra_graph.o


t_graph:t_graph.c graph.o
		$(CC) $(CFLAGS) $(LDFLAGS) $^ -o t_graph.exe
			-rm -rf *.o

t_BTree:t_BTree.c BTree.o
		$(CC) $(CFLAGS) $(LDFLAGS) $^ -o t_BTree.exe
			-rm -rf *.o

3.2:t_3.2.c 3.2.o
		$(CC) $(CFLAGS) $(LDFLAGS) $^ -o t_3.2.exe

3.1:3.1.c stack.o
		$(CC) $(LDFLAGS) $^ -o t_3.1.exe

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
		-find . -iname '*.dSYM' -type d -execdir rm -rf '{}' 2>/dev/null \;

.PHONY: clean
