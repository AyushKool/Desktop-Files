//https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=2145

#include <iostream>
using namespace std;

bool isKPal(string s, int k)
{
    int c = 0, n = s.length();
    for (int i = 0; i < n/2; i++)
    {
        if (s[i] != s[n - 1 - i])
            c++;
        if (c > k)
            return false;
    }
    return c == k;
}

int substring(string s, int k)
{
    int n = s.length(), i = 0, j = n - 1, c=1;
    string temp = s;
    while (!isKPal(temp, k))
    {
        if (j == n - 1)
            i = 0, j-=c, c++;
        else
            i++, j++;
        temp = s.substr(i, j - i + 1);
    }
    return temp.length();
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        int k;
        cin.ignore(1,'\n');;
        cin >> s >> k;
        cout << substring(s, k) << endl;
    }
}