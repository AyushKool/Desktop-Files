/*
This Project is made by Ayush Koul
Btech (CSE), 3rd Semester, Graphic Era Deemed University
*/

#include <iostream>
#include "SLL.h"
using namespace std;
typedef float dt;

template <typename T>
void display(T &v)
{
    cout << "Singly Linked List: ";
    typeof(v.begin()) tmp = v.begin();

    if (tmp == NULL)
    {
        cout << "Empty\n";
        return;
    }
    while (tmp != NULL)
    {
        cout << tmp->info << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL\n";
}

int main()
{
    //Declaring SLL Object
    SLL<dt> s;

    //Displaying SLL (Initially Empty)
    display(s);

    //Insertion and display
    s.insertRight(6.2);
    display(s);
    s.insertLeft(8.4);
    display(s);
    s.insertRight(7.3);
    display(s);
    s.insertLeft(9.1);
    display(s);

    //Test Condition
    s.begin() == s.find(9.1) ? cout << "yes\n" : cout << "no\n";

    //Deletion
    s.deleteNode(6.2);
    s.deleteNode(s.find(8.4));
    s.deleteNode(s.find(5.1));
    display(s);
}