main: main.o list.o	
	cc -o main main.o list.o

main.o: main.c list.h
	cc -c main.c

list.o: list.c list.h
	cc -c list.c

clean: 
	-rm *.o

run: 
	./main