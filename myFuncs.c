#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int validar_argumentos(char* argumentos){
    return 1;
}

FILE* openFile(char* path){
    FILE *file;
    file = fopen(path,"r");
    if(file==NULL){
        fprintf(stdout,"Error al abrir el archivo: %s",path);
        exit(EXIT_FAILURE);
    }
    return file;
}

char* toUpperCase(char* word){

    for(int i=0; word[i]!='\0'; i++)
    {
        if(word[i]>='a' && word[i]<='z')
        {
            word[i] = word[i] - 32;
        }
    }
    return word;
}