#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

void unweighted()
{
    vector<pair<int, int>> edges; //each h pair (a, b) denotes that there is an edge from node a to node b
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({2, 4});
    edges.push_back({3, 4});
    edges.push_back({4, 1});
}

void weighted()
{
    vector<tuple<int, int, int>> edges;
    /*
    Each element in this list is of the form (a, b, w), which means that there is an edge
    from node a to node b with weight w
    */
    edges.push_back({1, 2, 5});
    edges.push_back({2, 3, 7});
    edges.push_back({2, 4, 6});
    edges.push_back({3, 4, 5});
    edges.push_back({4, 1, 2});
}

int main()
{
}