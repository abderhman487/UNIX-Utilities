#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]){
    if(argc < 2){
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    unsigned char previous_byte =0;
    int count = 0, first =1;

    for(int i=1; i< argc; i++){

        FILE *f = fopen(argv[i],"rb");
        if(f == NULL){
            printf("wcat: cannot open file\n");
            return 1;
        }
        
        unsigned char current_byte;
        while(fread(&current_byte,sizeof(unsigned char),1,f)==1){

            if(first){
                previous_byte = current_byte;
                count = 1;
                first = 0;
            }

            else if(previous_byte == current_byte){
                count++;
            }

            else{
                fwrite(&count,sizeof(int),1,stdout);
                fwrite(&previous_byte,sizeof(unsigned char),1,stdout);
                previous_byte = current_byte;
                count = 1;
            }

        }

        fclose(f);
    }

    if (!first) {
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&previous_byte, sizeof(unsigned char), 1, stdout);
    }
    
    return 0;
}