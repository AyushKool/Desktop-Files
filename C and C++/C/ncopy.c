#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    if (argc==3)
    {
        char *path;

        path = (char *) malloc(sizeof(argv[2]) + sizeof(argv[1]) + sizeof("/"));
        sprintf(path, "%s/%s", argv[2], argv[1]);

        //printf("%s\n", path);
        FILE *f1 = fopen(argv[1], "r"), *f2 = fopen(path, "w");//path name cant be too long
        char ch;
        while((ch=fgetc(f1)) != EOF)
            fputc(ch, f2);
            
        fclose(f1);
        fclose(f2);
    }
    else
        printf("Invalid Command.");
}