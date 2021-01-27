#include <iostream>
using namespace std;

void fu(int (&a)[5][4])
{
}

void f(int (*a)[5][4])
{
}

void fuc(int (*a)[4])
{
}

// void fuc(int *a)
// {

// }

void fuc(int (&a)[4])
{
    cout << "hi";
}

void fuc(int (&a)[5])
{
    cout << "hello";
}

int main()
{
    int a[5][4];
    // fu(a);
    // f(&a);
    // fuc(a[0]);
    fuc((int(&)[5])a[0]);
}