#include <bits/stdc++.h>
using namespace std;

void print(const vector<int> &t)
{
    for (int i = 0; i < t.size(); i++)
        cout << t[i] << " ";
    cout << endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> t(m);
    for (int i = 0; i < m; i++)
        cin >> t[i];
    sort(t.rbegin(), t.rend());
    // print(t);
    if (n - m == 0)
    {
        cout << t[0];
        return 0;
    }
    int c = n - m;
    while (c--)
    {
        int max = t[0];
        int a = max - max / 2, b = max/2;
        t.erase(t.begin());
        auto curr = t.begin();

        while (curr != t.end() && *curr > a)
            curr++;
        t.insert(curr, a);
        // print(t);

        while (curr != t.end() && *curr > b) curr++;
        t.insert(curr, b);
        // print(t);
        // cout << endl << endl;
    }
    cout << t[0];

    return 0;
}