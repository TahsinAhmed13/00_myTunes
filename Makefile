main: main.o list.o	library.o
	cc -o main main.o list.o library.o

main.o: main.c list.h library.h
	cc -c main.c

list.o: list.c list.h
	cc -c list.c

library.o: library.c list.h library.h 
	cc -c library.c

clean: 
	-rm *.o

run: 
	./main