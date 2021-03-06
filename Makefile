# Makefile to compile Umix Programming Assignment 2 (pa2)

LIBDIR = $(UMIXPUBDIR)/lib
# LIBDIR = $(UMIXROOTDIR)/sys

CC 	= cc 
FLAGS 	= -g -L$(LIBDIR) -lumix2

PA2 =	pa2a pa2b pa2c
LIFO_TESTS	= lifo_tc1
FIFO_TESTS	= fifo_tc1
RR_TESTS	= rr_tc1 rr_tc2 rr_tc3
PROP_TESTS	= prop_tc1 prop_tc2 prop_tc3 prop_tc4 prop_tc5 prop_tc6

TESTS	= $(LIFO_TESTS) $(FIFO_TESTS) $(RR_TESTS) $(PROP_TESTS)

pa2:	$(PA2)

pa2a:	pa2a.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o pa2a pa2a.c mycode2.o

pa2b:	pa2b.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o pa2b pa2b.c mycode2.o

pa2c:	pa2c.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o pa2c pa2c.c mycode2.o

fifo_tc1:	fifo_tc1.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o fifo_tc1 fifo_tc1.c mycode2.o

lifo_tc1:	lifo_tc1.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o lifo_tc1 lifo_tc1.c mycode2.o

rr_tc1:	rr_tc1.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o rr_tc1 rr_tc1.c mycode2.o

rr_tc2:	rr_tc2.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o rr_tc2 rr_tc2.c mycode2.o

rr_tc3:	rr_tc3.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o rr_tc3 rr_tc3.c mycode2.o

prop_tc1:	prop_tc1.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o prop_tc1 prop_tc1.c mycode2.o

prop_tc2:	prop_tc2.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o prop_tc2 prop_tc2.c mycode2.o

prop_tc3:	prop_tc3.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o prop_tc3 prop_tc3.c mycode2.o

prop_tc4:	prop_tc4.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o prop_tc4 prop_tc4.c mycode2.o

prop_tc5:	prop_tc5.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o prop_tc5 prop_tc5.c mycode2.o

prop_tc6:	prop_tc6.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o prop_tc6 prop_tc6.c mycode2.o

prop_tc7:	prop_tc7.c aux.h umix.h mycode2.o
	$(CC) $(FLAGS) -o prop_tc7 prop_tc7.c mycode2.o

mycode2.o:	mycode2.c aux.h sys.h mycode2.h
	$(CC) $(FLAGS) -c mycode2.c

clean:
	rm -f *.o $(PA2) $(TESTS)
