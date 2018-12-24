SOURCES	= calculator.c pemdas.c
OBJECTS	= calculator.o pemdas.o
HEADERS = calculator.h pemdas.h
COMPILE	= gcc -c -Wall -w
LINK	= gcc -o

calculator : $(OBJECTS)
	$(LINK) Calculator $(OBJECTS)

calculator.o : $(SOURCES) $(HEADERS)
	$(COMPILE) calculator.c

pemdas.o : pemdas.c pemdas.h
	$(COMPILE) pemdas.c

clean :
	rm -f Calculator $(OBJECTS)
