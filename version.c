#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myFuncs.h"

void version(void){

    FILE* file = openFile("/proc/version");
    char buffer[300];
    char **palabras = (char**)malloc(sizeof(char*));
    int i=0;
    if(palabras == NULL){
        printf("Memory allocation error");
        exit(EXIT_FAILURE);
    }

    fgets(buffer,300,file);
    char* token = strtok(buffer," ");
    while(token!=NULL){
        if(i!=0) palabras = (char**)realloc(palabras,sizeof(char*)*(i+1)); //se va incrementando el tamanio del arreglo dinamico en tantos punteros a char como palabras se vayan agregando
        palabras[i]=toUpperCase(token); //se guarda la direccion de la palabra en el lugar correspondiente
        i++; //se incrementa la cuenta de la cantidad de palabras
        token=strtok(NULL," "); //se toma la direccion de memoria de la siguiente palabra obtenida despues del espacio en blanco
    }
    
    for(int j=0;j<i;j++) printf("%s\n",palabras[j]);
    fclose(file);
    free(palabras);
}