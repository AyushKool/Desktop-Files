#include <iostream>
#include <vector>
using namespace std;

#define N 5

void directed()
{
    //Directed Graph
    vector<int> adj[N];
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(4);
    adj[4].push_back(1);
}

void weighted()
{
    //Weighted graph
    vector<pair<int, int>> adj[N]; //adj[i] contains pair (b,w) if there is a edge from note adj[i] to b with weight w
    adj[1].push_back({2, 5});
    adj[2].push_back({3, 7});
    adj[2].push_back({4, 6});
    adj[3].push_back({4, 5});
    adj[4].push_back({1, 2});
}

int main()
{
    
}