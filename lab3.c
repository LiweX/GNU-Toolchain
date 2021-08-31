#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char* argv[]){
    if(argc!=1){
        int jFlag=0;
        if(argc>2) jFlag=1;
        if(strstr(argv[1],"-s")){
            if(jFlag){
                printf("Show punto 1.1 stuff on JSON format\n");
            }else{
                printf("Show punto 1.1 stuff\n"); 
            }
        }

        if(strstr(argv[1],"-a")){
            if(jFlag){
                printf("Show punto 1.2 stuff on JSON format\n");
            }else{
                printf("Show punto 1.2 stuff\n"); 
            } 
        }

        if(strstr(argv[1],"-d")){
            printf("Show punto 3 stuff\n");
        }
    }else{
        printf("Lista de argumentos validos:\n-s\n-a\n-s -j\n-a -j\n-d\n");
    }
}