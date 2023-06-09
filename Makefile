SRCDIR = source
EXEDIR = exe
OBJDIR = objects
TESTDIR = test
DEMODIR = demo

CC = gcc

FLAGS = -I SRCDIR -Wall -g 

LIBS =  -lcunit

MODULES = find_stack heap linked_list stack

OBJS = $(patsubst %,$(OBJDIR)/%.o,$(MODULES))

TESTS = $(patsubst %,$(EXEDIR)/test_%,$(MODULES))

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(SRCDIR)/%.h
	$(CC) $(FLAGS) $< -c -o $@ $(LIBS)

$(EXEDIR)/%: $(SRCDIR)/%.c $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ $(LIBS)

$(EXEDIR)/test_%: $(TESTDIR)/test_%.c $(OBJS)
	$(CC) $(FLAGS) $^ -o $@ $(LIBS)'
	
test_%: $(EXEDIR)/test_%
	valgrind --gen-suppressions=all --error-exitcode=1 --leak-check=full --suppressions=./test/valgrind_supp.supp --track-origins=yes --show-leak-kinds=all ./$^

test: $(TESTS)
	$(patsubst %,make test_% && ,$(MODULESTEST)) true

clean:
	rm -rf $(EXEDIR)/*
	rm -rf $(OBJDIR)/*

.PHONY: clean test_%

.PRECIOUS: $(ODIR)/% $(EDIR)/%