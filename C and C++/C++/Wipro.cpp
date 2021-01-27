#include <bits/stdc++.h>
using namespace std;
int isort(int a)
{
    multiset<int> digits;
    do
    {
        digits.insert(a % 10);
        a /= 10;
    } while (a != 0);
    int ans = 0;
    for (int i : digits)
        ans = ans * 10 + i;
    return ans;
}

int anaDiff(int a[], int n)
{
    unordered_map<int, int> anag;
    int max = -1, min = -1;
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        auto r = anag.emplace(isort(a[i]), a[i]);
        if (!r.second)
        {
            if (f)
            {
                max = std::max(r.first->second, a[i]);
                min = std::min(r.first->second, a[i]);
                f = false;
            }
            else
            {
                max = std::max(max, a[i]);
                min = std::min(min, a[i]);
            }
        }
    }
    // for (auto p : anag)
    //     cout << p.first << " ";
    // cout << endl;
    // cout << max << " " << min << endl;
    if (max == -1 || min == -1)
        return -1;
    if (max == min)
        return max;
    return max - min;
}

int main(int argc, char const *argv[])
{
    int a[] = {89017, 12321, 56780, 32112, 31221, 52315, 31122};
    int n = sizeof(a) / sizeof(a[0]);
    cout << anaDiff(a, n);
    return 0;
}
