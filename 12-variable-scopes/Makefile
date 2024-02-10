all: taskmanager.out processes.o

taskmanager.out: taskmanager.c processes.o processes.h
	gcc taskmanager.c -o taskmanager.out processes.o

processes.o: processes.c processes.h
	gcc processes.c -c

clean:
	rm -f *.out *.o