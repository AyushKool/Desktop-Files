#include <bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
using namespace std;

vector<long> bitwiseEquations(const vector<long> &a, const vector<long> &b)
{
    size_t n = a.size();
    vector<long> res(n, 0);
    for (size_t i = 0; i < n; ++i)
    {
        for (long j = 0; j < a[i] / 2; ++j)
        {
            auto x = j;
            auto y = a[i] - x;
            if(x^y == b[i]){
                res[i] = 2*x + 3*y;
                break;
            }
        }
    }
    return res;
}

int main()
{
    return 0;
}