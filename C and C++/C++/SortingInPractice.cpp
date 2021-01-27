#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void display(const  vector<int> &v)
{
    for(int x : v)
        cout << x << " ";
}

int main()
{
    vector<int> v = {2, -8, 36, 8, 1, 51};
    sort(v.begin(), v.end());
    display(v);
}