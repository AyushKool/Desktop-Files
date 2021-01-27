/*
This Project is made by Ayush Koul
Btech (CSE), 3rd Semester, Graphic Era Deemed University
*/

#include <iostream>
#include "ArrayList.h"
using namespace std;
typedef float dt;

//This function displays the Array List in a good format
template <typename T>
void display(T &v)
{
    cout << "Array List: ";
    if (!v.size())
    {
        cout << "Empty\n";
        return;
    }
    cout << "[";
    int count = 1;
    for (auto x : v)
        cout << x << (count == v.size() ? "" : ", "), count++;
    cout << "]\n";
}

int main()
{
    ArrayList<dt> s;
    display(s);

    //Inserting
    s.insert(5.3);
    s.insert(17);
    s.insert(-5);
    s.insert(2);
    display(s);
    s.insert(41, 0);
    display(s);

    //Sorting
    s.sort();
    display(s);

    //Deleting
    s.del();
    display(s);
    s.del(s.size() - 1);
    display(s);

    //Swapping
    s.swap(1, 2);
    display(s);

    //Changing List
    s[2] = 88;
    display(s);
}

// int main()
// {
//     //Declaring variables
//     int op, pos, a;
//     dt num;
//     ArrayList<dt> s;
//     do
//     {
//         //Inputting option for operation
//         cout << "Options:\n1: Insertion\n2: Deletion\n3: Display\n4: Change Value\n5: Sort\n6: Swap\n7: Exit\nEnter: ";
//         cin >> op;
//         cout << endl;
//         switch (op)
//         {
//         case 1:
//             cout << "Insertion:\n";
//             cout << "Enter value: ";
//             cin >> num;
//             cout << "Enter position: ";
//             cin >> pos;
//             s.insert(num, pos);
//             break;
//         case 2:
//             cout << "Deletion:\n";
//             if (s.size())
//             {
//                 cout << "Enter position: ";
//                 cin >> pos;
//                 s.del(pos);
//             }
//             else
//                 cout << "Deletion not possible\n";
//             break;
//         case 3:
//             cout << "Display:\n";
//             display(s);
//             break;
//         case 4:
//             cout << "Change Value:\n";
//             cout << "Enter position: ";
//             cin >> pos;
//             if (pos >= s.size())
//                 cout << "Change not possible\n";
//             else
//             {
//                 cout << "Enter new value: ";
//                 cin >> num;
//                 s[pos] = num;
//             }
//             break;
//         case 5:
//             s.sort();
//             break;
//         case 6:
//             cout << "Enter positions to be swapped: ";
//             cin >> a >> pos;
//             if (a >= s.size() || pos >= s.size())
//                 cout << "Swap not possible\n";
//             else
//                 s.swap(a, pos);
//             break;
//         }
//         cout << endl;
//     } while (op != 7);
// }