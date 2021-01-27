#include <iostream>
using namespace std;

int foo(int a)
{
    return a;
}

void function(int a, int b, int (*foo)(int a) = foo)
{
    cout << (*foo)(245);
}

int main()
{
    // cout << foo << endl;
    // cout << (void *)foo << endl;
    // cout << reinterpret_cast<void *>(foo) << endl;
    // cout << foo() << endl;

    // int a = 2, *p = &a;
    // cout << "a = " << a << ", p = " << p << endl;
    // cout << "a = " << a << ", p = " << p << endl;

    // fcnPtr is a pointer to a function that takes no arguments and returns an integer
    int (*fptr)(int) {foo};
    function(4, 5, fptr);


    /*
    In the above snippet, fptr is a pointer to a function that has no parameters and returns an integer. 
    fptr can point to any function that matches this type.

    The parenthesis around *fptr are necessary for precedence reasons, as int *fptr() would be interpreted 
    as a forward declaration for a function named fcnPtr that takes no parameters and returns a pointer to an integer.
    */

   //To make a const function pointer, the const goes after the asterisk:
    // int (*const fptr2)() = foo;
    //If you put the const before the int, then that would indicate the function being pointed to would return a const int.
    // cout << *fptr2 << endl;
}