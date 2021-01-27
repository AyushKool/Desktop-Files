#include<stdio.h>
#include<math.h>
float sigmoid(float x)
{
    return 1.0f/(1 + exp(-x));
}

int main()
{
    // char *p;
    // printf("%d %d", sizeof(*p), sizeof(p));
    // printf("\n%d %d", sizeof(char), sizeof(int));
    for(float i = -10.0f; i <= 10.0f; i += 1.0f)
    {
        printf("Sigmoid(%.1f) = %.4f\n", i, sigmoid(i));
    }
    return 0;
}