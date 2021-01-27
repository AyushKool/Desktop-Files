#include <stdio.h>

void main()
{
    int i, j, n;
    printf("Enter limit: ");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        for(j=0; j<i; j++)
            printf("   ");
        for(j=0; j<(n-i); j++)
        {
            if(j<n-i)
                printf("%02d*", (i*i - 11*i - 2)/-2 + j);
            // else
            //     printf("%02d*", (i*i - 5*i + 13)/2 + j);
        }
        printf("\n");
    }
}