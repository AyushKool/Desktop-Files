#include <string>
#include <iostream>
using namespace std;
int isPal(string s)//Returns 1 if Palindrome, 0 otherwise
{
    int n = s.length();
    for (int i = 0; i < n / 2; i++)
        if (s[i] != s[n - 1 - i])
            return 0;
    return 1;
}
int main()
{
    string s, pal;
    cout << "Enter String: ";
    getline(cin, s);
    int n = s.length(), i = 0, j = n - 1, c = 1;
    pal = s;
    while (!isPal(pal))
    {
        if (j == n - 1)
            i = 0, j-=c, c++;
        else
            i++, j++;
        pal = s.substr(i, j - i + 1);
        cout << pal << endl;
    }
    cout << "\n\nOutput: " << pal;
}