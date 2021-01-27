/* Macro definition */

#define pi 3.1472

#include <stdio.h>

int main()

{

     float r, A;

     printf("enter the radius");

     scanf("%f", &r);

     A = pi * r * r;

     printf("Area is = % f", A);

     return 0;
}