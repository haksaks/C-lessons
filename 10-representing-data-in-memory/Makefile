all: safeadd.out safesubstract.out safemultiply.out safedivide.out safeint.o

safeadd.out: safeadd.c safeint.o safeint.h
	gcc safeadd.c -o safeadd.out safeint.o

safesubstract.out: safesubstract.c safeint.o safeint.h
	gcc safesubstract.c -o safesubstract.out safeint.o

safemultiply.out: safemultiply.c safeint.o safeint.h
	gcc safemultiply.c -o safemultiply.out safeint.o

safedivide.out: safedivide.c safeint.o safeint.h
	gcc safedivide.c -o safedivide.out safeint.o

safeint.o: safeint.c safeint.h
	gcc safeint.c -c

clean:
	rm -f *.out *.o