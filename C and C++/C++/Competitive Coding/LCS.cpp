#include <bits/stdc++.h>
using namespace std;
//https://www.hackerrank.com/challenges/common-child/problem
void print(const vector<size_t> & v, const int& r, const int&c)
{
    cout << endl;
    int i = 0;
    for(auto x : v) {
        cout << x << ' ';
        i++;
        if(i==c) cout << endl, i=0;
        }
}

string LCS(const string &a, const string &b)
{
    if(!a.length() || !b.length()) return "";
    if (a.at(0) == b.at(0)) return a.at(0) + LCS(a.substr(1), b.substr(1));
    auto x = LCS(a, b.substr(1));
    auto y = LCS(a.substr(1), b);
    return x.length() > y.length() ? x : y;
}

size_t LCS_Length(const string &a, const string &b)
{
    if(!a.length() || !b.length()) return 0;

    if (a.at(0) == b.at(0)) return 1 + LCS_Length(a.substr(1), b.substr(1));
    auto x = LCS_Length(a, b.substr(1));
    auto y = LCS_Length(a.substr(1), b);
    return max(x, y);
}

size_t LCS_LengthDP(const string &s1, const string &s2)
{
    const char *a = s1.c_str(), *b = s2.c_str();
    if(*a=='\0' || *b=='\0') return 0;
    size_t n = s1.length() +1, m = s2.length() +1;
    vector<size_t> table(n*m, 0);
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 1; j < m; j++)
        {
            table[i*m + j] = a[i-1]==b[j-1] ? 1+table[(i-1)*m + j-1] : max(table[(i-1)*m + j], table[i*m + j-1]);
        }
        
    }
    print(table, n, m);
    return table[(n-1) * n + m-1];
}

string LCS_DP(const string &a, const string &b)
{
    int n = a.size(), m = b.size();
    
}

int main()
{
    string a, b;
    cout << "Enter String 1: ";
    cin >> a;
    cout << "Enter String 2: ";
    cin >> b;
    cout << endl << "LCS: " << LCS(a, b) << " Length: " << LCS_LengthDP(a, b);
    return 0;
}