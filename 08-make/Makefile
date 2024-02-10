all: help.out strlength.out strconcat.out strcompare.out mystrings.o

help.out: help.c
	gcc help.c -o help.out

strlength.out: strlength.c mystrings.o mystrings.h
	gcc strlength.c -o strlength.out mystrings.o

strconcat.out: strconcat.c mystrings.o mystrings.h
	gcc strconcat.c -o strconcat.out mystrings.o

strcompare.out: strcompare.c mystrings.o mystrings.h
	gcc strcompare.c -o strcompare.out mystrings.o

mystrings.o: mystrings.c mystrings.h
	gcc mystrings.c -c -o mystrings.o

clean:
	rm -f *.out *.o
