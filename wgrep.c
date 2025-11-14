#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){

    if(argc < 2){
        printf("wgrep: searchterm [file ...]\n");
        return 1;
    }

    if(argc == 2){
        char *line = NULL;
        size_t size = 0;
        while( getline(&line, &size, stdin) != -1){
            if(strstr(line, argv[1])) printf("%s", line);
        }
        return 0;
    }
    for(int i=2; i<argc; i++){

        FILE *f = fopen(argv[i],"r");
        if(f == NULL){
            printf("wgrep: cannot open file\n");
            return 1;
        }

        char *line = NULL;
        size_t size = 0;
        while( getline(&line, &size, f) != -1){
            if(strstr(line, argv[1])) printf("%s", line);
        }

        free(line);
        fclose(f);
    }

    return 0;
}