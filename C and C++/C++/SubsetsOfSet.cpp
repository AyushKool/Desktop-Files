#include <iostream>
#include <vector>

using namespace std;

void display(const vector<int> &v)
{
    cout << "{";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ((i != v.size()-1) ? ", " : "");
    cout << "}";
    cout << "\n";
}

vector<int> subset;
void search(int k, int n = 3)
{
    extern vector<int> subset;
    if (k == n + 1)
    {
        // process subset
        display(subset);
    }
    else
    {
        // include k in the subset
        subset.push_back(k);
        search(k + 1);

        // don’t include k in the subset
        subset.pop_back();
        search(k + 1);
    }
}

int main()
{
    search(1);
}