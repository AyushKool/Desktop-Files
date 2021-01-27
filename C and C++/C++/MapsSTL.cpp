#include <bits/stdc++.h>
using namespace std;
#define tr(c) for (typeof(c.begin()) i = c.begin(); i != c.end(); i++)

template <typename T>
void display(const T &c)
{
    tr(c) cout << i->first << ": " << i->second << "\n";
}

void f(const map<string, int> &M)
{
    // if (M["the meaning"] == 42) Error! Cannot use [] on const map objects!

    //Correct
    if (M.find("the meaning") != M.end() && M.find("the meaning")->second == 42)
        cout << "Don't Panic!" << endl;
}

main()
{
    //map is sorted in ascending order according the keys
    map<string, int> M;
    M["Top"] = 1;
    M["coder"] = 2;
    M["SRM"] = 10;

    int x = M["Top"] + M["coder"];

    if (M.find("SRM") != M.end())
        M.erase(M.find("SRM")); // or even M.erase("SRM")
    display<map<string, int>>(M);
}