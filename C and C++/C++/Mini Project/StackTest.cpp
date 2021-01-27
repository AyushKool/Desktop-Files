/*
This Project is made by Ayush Koul
Btech (CSE), 3rd Semester, Graphic Era Deemed University
*/

#include <iostream>
#include "Stack.h"
using namespace std;
typedef float dt;

//This function displays the Stack in a good format
template <typename T>
void display(T& v)
{
    cout << "   Stack: ";
    int n = v.size();
    if (!n)
    {
        cout << "Empty\n";
        return;
    }
    cout << "\nTop: ";
    while (n--)
        cout << v[n] << "\n     ";
    cout << endl;
}

int main()
{
    //Declaring Stack object
    Stack<dt> s;

    //Displaying stack (Initially Empty)
    display(s);

    //Pushing values
    s.push(4.2f);
    s.push(5.1f);
    s.push(8.2f);
    s.push(7.3f);
    s.push(6.8f);
    s.push(1.5f);

    //Display
    display(s);

    //Popping
    s.pop();
    s[0] = 10;
    display(s);

    //Outputtinh Top and Size of Stack
    cout << "Top = " << s.top() << endl;
    cout << "Size = " << s.size() << endl;
}