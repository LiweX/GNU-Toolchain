CFLAGS=-Wall -Werror -pedantic

lab3: lab3.o 
	gcc $(CFLAGS) -o lab3 lab3.o

lab3.o: lab3.c
	gcc $(CFLAGS) -c lab3.c

clean:
	rm -f *.o lab3