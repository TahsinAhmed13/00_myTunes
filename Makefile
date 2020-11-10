main: main.o list.o	library.o
	gcc -o main main.o list.o library.o

main.o: main.c list.h library.h
	gcc -c main.c

list.o: list.c list.h
	gcc -c list.c

library.o: library.c list.h library.h 
	gcc -c library.c

clean: 
	-rm *.o

run: 
	./main