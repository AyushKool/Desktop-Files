#include <bits/stdc++.h>
#define NL cout << endl
using namespace std;

void subset()
{
    //{0,1,2,3,4}
    int n = 5, x;
    for (int b = 0; b < (1 << n); b++)
    {
        cout << "{";
        // process subset b
        for (int i = 0; i < n; i++)
        {
            if (b & (1 << i))
                cout << i << (__builtin_popcount(b >> i + 1) ? ", " : "");
        }
        cout << "}" << endl;
    }

    int k;
    //the following code goes through the subsets with exactly k elements:
    for (int b = 0; b < (1 << n); b++)
    {
        if (__builtin_popcount(b) == k)
        {
            // process subset b
        }
    }

    //	Finally, the following code goes through the subsets of a set x:
    int st = 0;
    do
    {
        // process subset b
    } while (st = (st - x) & x);

    bitset<10> s;
    s[1] = 1;
    s[3] = 1;
    s[4] = 1;
    s[7] = 1;
    cout << s[4] << "\n"; // 1
    cout << s[5] << "\n"; // 0

    //The function count returns the number of one bits in the bitset:
    cout << s.count() << "\n"; // 4
    //Also bit operations can be directly used to manipulate bitsets:
    bitset<10> a, b;    
    // ...
    bitset<10> c = a&b;
    bitset<10> d = a | b;
    bitset<10> e = a ^ b;
}

int main()
{
    int x = 5;
    if ((~x + 1) == -x)
        cout << ~x + 1;

    NL;

    x = 2147483647;
    cout << x << "\n"; // 2147483647
    x++;
    cout << x << "\n"; // -2147483648

    NL;

    x = -43;
    unsigned int y = x;
    cout << x << "\n"; // -43
    cout << y << "\n"; // 4294967253

    NL;

    x = -7;
    //x = (x&(1<<32) ? ~x + 1 : x);    //doesn't let you access the MSB bit for sign
    //x = (x < 0 ? ~x + 1 : x);
    if (x < 0)
    {
        cout << '-';
        x = ~x + 1; //same as x = -x;
    }
    for (int k = 31; k >= 0; k--)
    {
        //cout << (x & (1 << k)) << ' '; //doesn't work because returns 1<<k, not 1
        if (x & (1 << k))
            cout << "1";
        else
            cout << "0";
    }

    NL;

    int k = 2;
    x = (x | (1 << k)); //sets kth bit to 1
    cout << x;
    NL;
    x = (x & ~(1 << k)); //sets kth bit to 0
    cout << x;
    NL;
    x = (x ^ (1 << k)); //inverts the kth bit
    cout << x;
    NL;
    x = (x & (x - 1)); //sets last one bit of x to zero
    cout << x;
    NL;
    x = (x & -x); //sets all the one bits to zero, except for the last one bit
    cout << x;
    NL;
    x = (x | (x - 1)); //inverts all the bits after the last one bit
    cout << x;
    x &(x - 1) == 0; //true if x is positive and a power of two

    NL;

    x = 5328;                              // 00000000000000000001010011010000
    cout << __builtin_clz(x) << "\n";      // 19
    cout << __builtin_ctz(x) << "\n";      // 4
    cout << __builtin_popcount(x) << "\n"; // 5
    cout << __builtin_parity(x) << "\n";   // 1

    NL;

    //{1,3,4,8}
    x = 0;
    x |= (1 << 1);
    x |= (1 << 3);
    x |= (1 << 4);
    x |= (1 << 8);
    cout << __builtin_popcount(x) << "\n"; // 4

    for (int i = 0; i < 32; i++)
    {
        if (x & (1 << i))
            cout << i << " ";
    }
    // output:1 3 4 8

    NL;

    x = (1 << 1) | (1 << 3) | (1 << 4) | (1 << 8);
    y = (1 << 3) | (1 << 6) | (1 << 8) | (1 << 9);
    int z = x | y;
    cout << "z size: " << __builtin_popcount(z) << "\nz:\n"; // 6

    for (int i = 0; i < 32; i++)
    {
        if (z & (1 << i))
            cout << i << " ";
    }

    NL;

    //subset();
}