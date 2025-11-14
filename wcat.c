#include <stdio.h>
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]){

    if(argc<2) return 0;
    
    for(int i=1; i<argc; i++){

        FILE *f = fopen(argv[i], "r");
        if(f == NULL){
            printf("wcat: cannot open file\n");
            return 1;
        }

        char buffer[BUFFER_SIZE];
        while (fgets(buffer, BUFFER_SIZE, f)){
            printf("%s",buffer);
        }
        
        fclose(f);
    }
    return 0;
}