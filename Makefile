CFLAGS=-Wall -Werror -pedantic

lab3: lab3.o lib_static.a lib_dynamic.so
	gcc $(CFLAGS) -o lab3 lab3.o -L. lib_static.a lib_dynamic.so
	sudo cp lib_dynamic.so /usr/lib

lib_static.a: myFuncs.o meminfo.o cpuinfo.o version.o cJSON.o
	ar rcs lib_static.a myFuncs.o meminfo.o cpuinfo.o version.o cJSON.o

lib_dynamic.so: filesystems.o
	gcc filesystems.o -shared -o lib_dynamic.so

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

filesystems.o: filesystems.c filesystems.h
	gcc $(CFLAGS) -c filesystems.c 

clean:
	rm -f *.o lab3 lib_static.a lib_dynamic.so
	sudo rm /usr/lib/lib_dynamic.so