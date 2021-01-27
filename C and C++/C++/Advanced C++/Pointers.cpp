#include <iostream>
using namespace std;

int main()
{
    int a[3][4];

    int (&p)[3][4] = a;
    int (*p)[4] = a;

    int *p = a[0];
    int (&p)[4] = a[0];
    int *p = a[0]+1;

    int (&ptr)[5] = *((int(*)[5])new int[5]);

}