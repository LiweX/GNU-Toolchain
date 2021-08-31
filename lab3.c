#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "version.h"
#include "cpuinfo.h"
#include "meminfo.h"
#include "filesystems.h"

int main(int argc,char* argv[]){

    int opt;
    int jFlag=0;
    int sFlag=0;
    int aFlag=0;
    int dFlag=0;
    if(argc<2) printf("Lista de argumentos validos:\n-s\n-a\n-s -j\n-a -j\n-d\n");
    while ((opt = getopt(argc,argv,"jsad")) != -1)
    {
        switch (opt)
        {
        case 'j': 
            jFlag=1;
            break;
        case 's':          
            sFlag=1;
            break;
        case 'a':
            aFlag=1;
            break;
        case 'd':
            dFlag=1;
            break;
        default:
            printf("Lista de argumentos validos:\n-s\n-a\n-s -j\n-a -j\n-d\n");
            exit(EXIT_FAILURE);
        }
    }
    if(sFlag){
        meminfo(jFlag);
        cpuinfo(jFlag);
    }
    if(aFlag) version(jFlag);
    if(dFlag) fileSystems();
    exit(EXIT_SUCCESS);
}