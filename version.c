#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myFuncs.h"
#include "cJSON.h"

void version(int json){

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
    if(!json){
        for(int j=0;j<i;j++) printf("%s\n",palabras[j]);
    }else{
        cJSON *json = cJSON_CreateObject();
        cJSON_AddStringToObject(json,"file","/proc/version");
        cJSON *words = cJSON_CreateArray();
        for(int j=0;j<i;j++){
            cJSON *word = cJSON_CreateString(palabras[j]);
            cJSON_AddItemToArray(words,word);
        }
        cJSON_AddItemToObject(json,"palabras",words);
        char *string = cJSON_Print(json);
        printf("%s\n",string);
        cJSON_Delete(json);
    }
    
    
    fclose(file);
    free(palabras);
}