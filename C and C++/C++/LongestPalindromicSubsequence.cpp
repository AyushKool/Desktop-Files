#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi look;
int lps(const string &s, int i, int j)
{
    if (look[i][j]!=-1)
        return look[i][j];
    if (i == j)
        look[i][j] = 1 ;
    else if (s[i] == s[j])
    {
        if (i + 1 == j)
            look[i][j] = 2;
        else
            look[i][j] = 2 + lps(s, i + 1, j - 1);
    }
    else
        look[i][j] = max(lps(s, i+1, j), lps(s, i, j-1));
    return look[i][j];
}

int main()
{
    string s = "underqualified";
    look = vvi(s.length(), vi(s.length(), -1));
    cout << lps(s, 0, s.length()-1);
}