#include<bits/stdc++.h>
using namespace std;

/*
This is for 63 coins max
*/

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, k;
//         cin >> n >> k;
//         long long coins = (1 << n) - 1; //1 means it is a fake --> start with assuming all are fake
//         while (k--)
//         {
//             int amount, tmp;
//             cin >> amount;
//             amount *= 2;
//             long long inp = 0;
//             while (amount--)
//             {
//                 cin >> tmp;
//                 inp = (inp | (1 << tmp - 1)); //sets tmp-1 bit to 1
//             }

//             //cout << "inp: " << inp << endl;
//             char op;
//             cin >> op;
//             if (op == '=')
//                 coins = (coins & ~inp); //0 means that number is not the false coin
//             else
//                 coins = (coins | inp);
//         }
//         cout << "\nAnswer: ";
//         if (__builtin_popcount(coins) == 1)
//             cout << __builtin_popcount(coins - 1) + 1;
//         else
//             cout << 0;
//     }
// }


/*
This is for 128 coins max
*/
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        bitset<100> coins ((1 << n) - 1); //1 means it is a fake --> start with assuming all are fake
        while (k--)
        {
            int amount, tmp;
            cin >> amount;
            amount *= 2;
            bitset<100> inp;
            
            while (amount--)
            {
                cin >> tmp;
                inp = (inp | bitset<100>(1 << tmp - 1)); //sets tmp-1 bit to 1
            }
            char op;
            cin >> op;
            if (op == '=')
                coins = (coins & ~inp); //0 means that number is not the false coin
            else
                coins = (coins | inp);
        }
        cout << "\nAnswer: ";
        if (coins.count() == 1)
            cout << bitset<100>(coins.to_ulong()-1).count() + 1;
        else
            cout << 0;
    }
}