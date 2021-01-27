#include <iostream>
#include <math.h>
#include <string>

using namespace std;

void p1()
{
    int n;
    cout << endl
         << "Problem 1:" << endl
         << "Enter Limit: ";
    cin >> n;
    n = 2 * n - 1;
    char ch;
    for (int i = 0; i <= n / 2; i++, cout << endl)
    {
        for (int j = 0; j < n; j++)
        {
            if (j >= n / 2 - i && j <= n / 2 + i)
            {
                if (j <= n / 2)
                    ch = char(65 + j - (n / 2 - i));
                else
                    ch--;
                cout << ch;
            }
            else
                cout << " ";
        }
    }
}

void p2()
{
    int n;
    cout << endl
         << "Problem 2:" << endl
         << "Enter Limit: ";
    cin >> n;
    for (int i = 1; i <= n; i++, cout << endl)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j < n)
                cout << i + j;
            else
                cout << n;
        }
    }
}

void p3()
{
    int a, b, c;
    cout << "Enter value of a, b, c: ";
    cin >> a >> b >> c;
    double det = b * b - 4 * a * c;

    if (det >= 0)
    {
        det = sqrt(det);
        cout << "Roots: " << (-b + det) / (2 * a) << ", " << (-b - det) / (2 * a);
    }
    else
        cout << "No real roots";
}

void p4()
{
    float total = 5000;
    int units;
    cout << "Enter No. of units: ";
    cin >> units;

    if(units <=100)
        total += units*60;
    else if (units <=300)
        total += (units-100)*80 + 6000;
    else
    {
        total += (units-300)*90 + 22000;
        total *= 1.15;
    }

    cout << "Total = Rs. " << total/100;
}

//DS

int main()
{
    // int op;
    // void (*fptr[])() = {p1, p2, p3};
    // cout << "Enter 1, 2, 3 or 4: ";
    // cin >> op;
    // fptr[op - 1]();
    p4();
}