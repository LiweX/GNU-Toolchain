#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myFuncs.h"

void cpuinfo(void){

    int modelFound=0,coresFound=0,siblingsFound=0;

    struct Cpuinfo{
        char model[50];
        int cores;
        int threads;
        int siblings;
    }cpuinfo;

    char buffer[100];
    char aux[10];
    FILE *file = openFile("/proc/cpuinfo");

    while((fgets(buffer,100,file))!=NULL){ 
           if(strstr(buffer,"model name")!=NULL && !modelFound){
               strcpy(cpuinfo.model,strchr(buffer,':'));
               modelFound=1;
           }
           if(strstr(buffer,"siblings")!=NULL && !siblingsFound){
               strcpy(aux,strchr(buffer,' '));
               //printf("%s\n",aux);
               cpuinfo.siblings = atoi(aux);
               //printf("%d\n",cpuinfo.siblings);
               siblingsFound=1;
           }
           if(strstr(buffer,"cpu cores")!=NULL && !coresFound){
               strcpy(aux,strchr(buffer,':'));
               strtok(aux," ");
               //printf("%s\n",strtok(NULL," "));
               cpuinfo.cores = atoi(strtok(NULL," "));
               //printf("%d\n",cpuinfo.cores);
               coresFound=1;
           }
           if(modelFound && coresFound && siblingsFound){
               cpuinfo.threads=cpuinfo.siblings/cpuinfo.cores;
               break;
           }     
    }

    printf("Modelo de CPU%s",cpuinfo.model);
    printf("Cantidad de cores: %d\n",cpuinfo.cores);
    printf("Cantidad de threads por core: %d\n",cpuinfo.threads);

    fclose(file);
}