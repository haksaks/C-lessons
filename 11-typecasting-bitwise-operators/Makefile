all: main.out quadraticroots.o

main.out: main.c quadraticroots.o quadraticroots.h
	gcc main.c -o main.out quadraticroots.o -lm

quadraticroots.o: quadraticroots.c quadraticroots.h
	gcc quadraticroots.c -c

clean:
	rm -f *.o *.out