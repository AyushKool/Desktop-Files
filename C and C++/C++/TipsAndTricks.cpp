#include <bits/stdc++.h>
using namespace std;

/* Function to check if x is power of 2 -> returns 1 if true*/
bool isPowerOfTwo (int x) 
{ 
  /* First x in the below expression is  
    for the case when x is 0 */
  return x && (!(x&(x-1))); 
}

main()
{
    //check even/odd
    int x = 4;
    if (x & 1)
        cout << "odd";
    else
        cout << "even";

    //fast multiplication/division by 2
    x <<= 1; //multiply by 2
    cout << x;
    x >>= 1; //divide by 2
    cout << x;

    //swapping 2 numbers using XOR
    int a = 4, b = 5;
    a ^= b;
    b ^= a;
    a ^= b;
    cout << endl << a << " " << b << endl;

    //avoid strlen
    string s = "hello world!";
    for(int i=0; s[i]; i++)
        cout << s[i];

    //use emplace_back instead of push_back

    //use _gcd(int x, int y) for gcd (built-in)

    //use inline fuctions

    //Maximum size of the array: We must be knowing that the maximum size of array 
    //declared inside the main function is of the order of 10^6 but if you declare 
    //array globally then you can declare its size upto 10^7.

    //calculating msd
    x = 3456;
    double msb = log10(x);
    msb = msb - floor(msb);
    msb = pow(10, msb);
    cout << msb;

    //number of digits
    int N = log10(x) + 1;
    cout << endl << N;
    cout << endl << isPowerOfTwo(0);
}