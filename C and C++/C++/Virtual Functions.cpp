/*
A Virtual Function is a function in a Base Class that is declared using the keyword virtual. Defining in a base
class a virtual function, with another version in a derived class, signals to the compiler that we don't want static linkage
for this function.

What we do want is the selection of the function to be called at any given point in the program to be based on the kind 
of object for which it is called. This sort of operation is referred to as dynamic linkage, or late binding.

Pure Virtual Functions
It is possible that you want to include a virtual function in a base class so that it may be redefined in a derived class 
to suit the objects of that class, but that there is no meaningful definition you could give for the function in the base
class. We can change the virtual function area() in the base class to the following:
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>

using namespace std;

// class BaseClass{
//     private:
//         int lenth, width;
//     public:
//         virtual int area() = 0
// };


void add(int a, int b)
{
    cout << "Add 1";
}

void add(int a, int b, int c=0)
{
    cout << "Add 2";
}

void main()
{
    //add(1,2);//Error
}