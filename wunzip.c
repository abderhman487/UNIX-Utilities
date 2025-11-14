#include <stdio.h>

int main(int argc, char *argv[]){
    if(argc < 2){
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }

    for(int i=1; i< argc; i++){
        FILE *f = fopen(argv[i],"rb");
        if(f == NULL){
            printf("wunzip: cannot open file\n");
            return 1;
        }

        unsigned char ch;
        int count;

        while(
            fread(&count,sizeof(int),1,f) == 1 &&
            fread(&ch,sizeof(char),1,f) == 1
        )
        {
            for (int i = 0; i < count; i++) {
                putc(ch,stdout);
            }
        }
        fclose(f);
    }
    return 0;
}