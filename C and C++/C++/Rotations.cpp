#include <iostream>
using namespace std;

void ashu()
{
    int *a, n, rot, *b, newt, oldt, newind, oldind;
    cout << "Enter size: ";
    cin >> n;
    cout << "\nEnter rotations: ";
    cin >> rot;
    cout << "\nEnter array: ";
    a = (int*) calloc(n, sizeof(int));

    for(int i=0; i<n; i++)
        cin >> a[i];
    oldind = 0;
    oldt = a[oldind];
    for(int i=0; i<n; i++)
    {
        newind = (oldind+rot)%n;
        newt = a[newind];
        a[newind] = oldt;
        oldt = newt;
        oldind = newind;
    }

    for(int i=0; i<n; i++)
        cout << a[i];
}

void swap(int &a, int &b)
{
    a += b;
    b = a - b;
    a -= b;
}

int main()
{
    // int *a, n, rot, *b;
    // cout << "Enter size: ";
    // cin >> n;
    // cout << "\nEnter rotations: ";
    // cin >> rot;
    // cout << "\nEnter array: ";
    // a = (int*) calloc(n , sizeof(int));
    // b = (int*) calloc(n , sizeof(int));
    // for(int i=0; i<n; i++)
    //     cin >> a[i];
    // for(int i=0; i<n; i++)
    //     b[(i+rot)%n] = a[i];
    
    // free(a);
    // cout << "\nFinal array: ";
    // for(int i=0; i<n; i++)
    //     cout << b[i] << ' ';
    //ashu();
}