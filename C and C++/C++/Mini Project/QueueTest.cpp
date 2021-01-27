/*
This Project is made by Ayush Koul
Btech (CSE), 3rd Semester, Graphic Era Deemed University
*/

#include <iostream>
#include "Queue.h"
using namespace std;
typedef int dt;

template <typename T>
void display(T &v)
{
    cout << "Queue (Front --> Rear): ";
    if (!v.size())
    {
        cout << "Empty\n";
        return;
    }
    for (auto x : v)
        cout << x << " ";
    cout << endl;
}

int main()
{
    //Declaring Queue with default size and values
    Queue<dt> s(5, 1);
    display(s);

    //Initializing Queue
    for (int i = 0; i != s.size(); i++)
        s[i] = i;
    
    //Pushing
    s.push(10);
    display(s);

    //Serving
    s.serve();
    s.serve();
    s.serve();
    s.serve();

    //Displaying
    cout << "After serving: " << endl;
    display(s);

    //Displaying Queue Properties
    cout << "Size: " << s.size() << endl;
    cout << "First element: " << s[0];
}
