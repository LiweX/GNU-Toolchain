Laboratorio N3
# GNU Toolchain y Linux Software
### SOI - FCEFyN - UNC - 2021


## Respuestas
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
