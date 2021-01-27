#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void display(const vector<int> &v)
{
    cout << "{";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ((i != v.size() - 1) ? ", " : "");
    cout << "}";
    cout << "\n";
}

vector<int> permutation;
bool chosen[3]; //by default, all 0
void search(int n = 3)
{
    extern vector<int> permutation;
    extern bool chosen[3];
    if (permutation.size() == n)
    {
        // process permutation
        display(permutation);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (chosen[i])
                continue;
            chosen[i] = true;
            //cout << endl << i+1 << "Chosen" << endl;
            permutation.push_back(i + 1);
            search();
            chosen[i] = false;
            //cout << endl << i+1 << "Removed" << endl;
            permutation.pop_back();
        }
    }
}
int main()
{
    int n = 4;
    search();

    //C++ next_permutation() in STL
    // for (int i = 1; i <= n; i++)
    //     permutation.push_back(i);
    // do
    // {
    //     // process permutation
    //     display(permutation);
    // } while (next_permutation(permutation.begin(),permutation.end()));
}