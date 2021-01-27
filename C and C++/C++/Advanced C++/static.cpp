#include <iostream>
using namespace std;

//https://www.studytonight.com/cpp/static-keyword.php#:~:text=Static%20is%20a%20keyword%20in,Static%20variable%20in%20functions

struct A
{
    A() { cout << "Constructor\n"; }
    ~A() { cout << "Destructor\n"; }
};

void f()
{
    static A a;
    // A b;
    cout << "End of f().\n";
}

int main()
{
    int x = 0;
    if(!x)
    {
        f();
        cout << "End of if.\n";
    }
    cout << "End of program.\n";
}