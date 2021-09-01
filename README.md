Laboratorio N3
# GNU Toolchain y Linux Software
### SOI - FCEFyN - UNC - 2021


## Respuestas
## Parte practica
### Instrucciones de uso:
Clonar el repo, abrir una terminal en ese directorio y usar `make lab3`

Para correr el programa se usa `./lab3` seguido e los siguientes argumentos:
```
-s     //Imprime la info solicitada en el ejercicio 1 del laboratorio 2
-a     //Imprime la info solicitada en el ejercicio 2 del laboratorio 2
-j     //Si se usa en combinacion con alguno de los argumentos anteriores, se imprime en formato json
-d     //Imprime la info de los filesystems
```
El manejo de argumentos se resuelve por medio de `getopt`.
Los archivos *.o excepto los referidos a los del punto 3 se agruparon en una libreria estatica haciendo uso del makefile:
```
lib_static.a: myFuncs.o meminfo.o cpuinfo.o version.o cJSON.o
	ar rcs lib_static.a myFuncs.o meminfo.o cpuinfo.o version.o cJSON.o
```
Respecto al punto 3, la libreria dinamica se resuelve asi:
```
lib_dynamic.so: filesystems.o
	gcc filesystems.o -shared -o lib_dynamic.so
	sudo cp lib_dynamic.so /usr/lib
```
Si se usa `ldd lab3` se puede ver que el linker no encuentra la direccion de la libreria dinamica. 
```
        linux-vdso.so.1 (0x00007ffefcb99000)
        lib_dynamic.so => not found
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007fabc6d21000)
        /lib64/ld-linux-x86-64.so.2 (0x00007fabc6f3d000)
```
Para resolver dicho inconveniente se opto por copiar la libreria en el directorio por defecto donde el linker busca esas librerias: `/usr/lib` pero para esto hacen falta permisos de administrador.

## Parte teorica
### 4.1. ¿Cuáles son los tipos de type descriptors que podemos encontrar en /proc//fd?
### Tipos de file descriptors:
* **BLK**: Block device.
* **CHR**: Character device.
* **DIR**: Directory.
* **IFO**: FIFO / Pipe.
* **LNK**: Symlink.
* **REG**: Regular file.
* **SOCK**: Socket.
* **UNKNOWN**: Unknown.

### 4.2. Suponiendo que un usuario está ejecutando el proceso pid 1212, ¿Es válida la ejecución del siguiente comando desde una terminal nueva? % echo “Hello, world.” >> /proc/1212/fd/1

Es valido, se esta escribiendo el texto "Hello, world." en el stdout del proceso 1212. 

### 4.3. Qué diferencia hay entre hard y soft limits?

Respecto a la cantidad de files que puede abrir un proceso, existen dos limites:
* **hard limit:** es el valor maximo que puede tomar el soft limit. Solo se puede alterar con permisos de root.
* **soft limit:** el valor maximo que usa el SO para asignar los recursos. Los procesos pueden cambiar este valor pero nunca sera mas grande que el hard limit.
