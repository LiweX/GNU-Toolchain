#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "myFuncs.h"
#include "cJSON.h"

void fileSystems(void){

    FILE* file = openFile("/proc/filesystems");

    char buffer[100];

    cJSON *json = cJSON_CreateObject();
    cJSON_AddStringToObject(json,"file","/proc/filesystems");

    while(fgets(buffer,100,file)!=NULL){
        char *token =strtok(buffer,"\t");
        if(strstr(buffer,"nodev")){
            token =strtok(NULL,"\n");
            cJSON_AddStringToObject(json,"filesystem",token);
        }else{
            token =strtok(NULL,"\n");
            cJSON_AddStringToObject(json,"filesystem",token);
        }
    }
    char *string = cJSON_Print(json);
    printf("%s\n",string);
    cJSON_Delete(json);

}