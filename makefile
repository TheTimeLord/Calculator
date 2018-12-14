SOURCES	= calculator.c
HEADERS	= none
OBJECTS	= calculator.o
COMPILE	= gcc -c -Wall -w
LINK	= gcc -o

calculator : $(OBJECTS)
	$(LINK) Calculator $(OBJECTS)

calculator.o : $(SOURCES)
	$(COMPILE) calculator.c

clean :
	rm -f Calculator $(OBJECTS)
