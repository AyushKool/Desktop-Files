#include <iostream>
using namespace std;

void f(int (*f)(char, int))
{
    (*f)('a', 3);

    // f('a', 3);
}



int main()
{
    // f([](char a, int b)->int{
    //     cout << "Hello";
    //     return 1;
    // });


    cout << sizeof(bool);
}