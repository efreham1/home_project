SRCDIR = source
EXEDIR = executable
OBJDIR = objects
TESTDIR = test
DEMODIR = demo

CC = gcc

FLAGS = -I SRCDIR -Wall -g 

LIBS = -lpthread -lcunit

MODULES = find_stack heap linked_list stack

OBJS = $(patsubst %,$(OBJDIR)/%.o,$(MODULES))
