#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    if (argc != 2)
        printf("Invalid Arguments");
    else
    {
        FILE *f = fopen(argv[1], "r");
        char ch;

        while ((ch = fgetc(f)) != EOF)
            printf("%c", ch);
        fclose(f);
    }
}