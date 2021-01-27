#include <iostream>
#include <string>
using namespace std;
int main()
{
    int lim;
    cout << "Enter limit: ";
    cin >> lim;
    while (lim--)
    {
        int n, sum;
        string s;
        cout << "Enter a string:";
        cin >> s;
        n = sum = s.length();
        for (int i = 1; i < n; i++)
            for (int j = 0; j < n && s[i + j] == s[j]; j++, sum++);
        cout << "Sum = " << sum << endl;
    }
}