/*
This Project is made by Ayush Koul
Btech (CSE), 3rd Semester, Graphic Era Deemed University
*/

#include <iostream>
#include "DLL.h"
using namespace std;
typedef float dt;

template <typename T>
void display(T &v)
{
    cout << "Doubly Linked List: ";
    typeof(v.begin()) tmp = v.begin();
    if (tmp == NULL)
    {
        cout << "Empty\n";
        return;
    }
    cout << "NULL <- " << tmp->info;
    tmp = v.next(tmp);
    while (tmp != NULL)
    {
        cout << " <=> " << tmp->info;
        tmp = tmp->next;
    }
    cout << " -> NULL\n";
}

int main()
{
    //Declaring DLL Object
    DLL<dt> s;

    //Displaying
    display(s);

    //Insertion
    s.insertRight(6.2);
    display(s);
    s.insertLeft(8.4);
    display(s);
    s.insertLeft(5.1);
    display(s);

    //Checking Condition
    s.begin() == s.find(5.1) ? cout << "yes\n" : cout << "no\n";

    //Deletion and display
    s.deleteNode(s.find(8.4));
    display(s);
    s.deleteNode(s.find(6.2));
    display(s);
    s.deleteNode(s.find(5.1));
    display(s);
}