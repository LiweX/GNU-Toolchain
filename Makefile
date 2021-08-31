CFLAGS=-Wall -Werror -pedantic

lab3: lab3.o myStaticLib.a
	gcc $(CFLAGS) -o lab3 lab3.o -L. myStaticLib.a

myStaticLib.a: myFuncs.o meminfo.o cpuinfo.o version.o cJSON.o
	ar rcs myStaticLib.a myFuncs.o meminfo.o cpuinfo.o version.o cJSON.o

lab3.o: lab3.c
	gcc $(CFLAGS) -c lab3.c

myFuncs.o: myFuncs.c myFuncs.h
	gcc $(CFLAGS) -c myFuncs.c

meminfo.o: meminfo.c meminfo.h myFuncs.h
	gcc $(CFLAGS) -c meminfo.c

cpuinfo.o: cpuinfo.c cpuinfo.h myFuncs.h
	gcc $(CFLAGS) -c cpuinfo.c

version.o: version.c version.h myFuncs.h
	gcc $(CFLAGS) -c version.c

cJSON.o: cJSON.c cJSON.h
	gcc $(CFLAGS) -c cJSON.c

clean:
	rm -f *.o lab3