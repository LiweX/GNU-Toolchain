#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myFuncs.h"

void meminfo(void){
    int totalFound=0,availableFound=0,freeFound=0;
    
    struct Meminfo{
        int total;
        int free;
        int available;
        int swap;
    }meminfo;

    char buffer[100];

    FILE* file = openFile("/proc/meminfo");

    while(fgets(buffer,100,file)!=NULL){
        if(strstr(buffer,"MemTotal:") && !totalFound){
            meminfo.total=atoi(strtok(strchr(buffer,' ')," "));
            totalFound=1;
        }
        if(strstr(buffer,"MemFree:")&& !availableFound){
            meminfo.free=atoi(strtok(strchr(buffer,' ')," "));
            availableFound=1;
        }
        if(strstr(buffer,"MemAvailable:")&& !freeFound){
            meminfo.available=atoi(strtok(strchr(buffer,' ')," "));
            freeFound=1;
        }
        if(totalFound && availableFound && freeFound){
            break;
        }
    }
    meminfo.swap=meminfo.total-meminfo.free;
    printf("Memoria Total: %d Mb\n",meminfo.total/1000);
    printf("Memoria Libre: %d Mb\n",meminfo.free/1000);
    printf("Memoria Disponible: %d Mb\n",meminfo.available/1000);
    printf("Memoria Ocupada: %d Mb\n",meminfo.swap/1000);
    fclose(file);
}