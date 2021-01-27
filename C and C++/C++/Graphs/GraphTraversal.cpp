#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define N 6
vector<int> adj[N];
queue<int> q;
bool visited[N];
int dist[N];

void breathFirstSearch(int x)
{
    visited[x] = true;
    //dist[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        int s = q.front();
        q.pop();
        cout << s << " ";
        for (auto u : adj[s])
        {
            if (visited[u])
                continue;
            visited[u] = true;
            //dist[u] = dist[s] + 1;
            q.push(u);
        }
    }
}

void depthFirstSearch(int s)
{
    /*
    Time complexity: O(n + m) 
    where n is the number of nodes and m is the number of edges, because the algorithm 
    processes each node and edge once.
    */
    if (visited[s])
        return;
    visited[s] = true;
    cout << s << " ";
    for (int x : adj[s])
        depthFirstSearch(x);
}

// bool depthFirstSearch(int s)
// {
//     /*
//     Time complexity: O(n + m) 
//     where n is the number of nodes and m is the number of edges, because the algorithm 
//     processes each node and edge once.
//     */
//     if (visited[s])
//         return true;
//     visited[s] = true;
//     cout << s << " ";
//     for (int x : adj[s])
//         depthFirstSearch(x);
// }

int main()
{
    //Graph 1
    // adj[1].push_back(2);
    // adj[1].push_back(4);
    // adj[2].push_back(3);
    // adj[2].push_back(5);
    // adj[3].push_back(2);
    // adj[3].push_back(5);
    // adj[4].push_back(1);
    // adj[5].push_back(2);
    // adj[5].push_back(3);


    adj[1].push_back(3);
    adj[1].push_back(4);
    adj[2].push_back(3);
    adj[2].push_back(5);
    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[4].push_back(1);
    adj[4].push_back(3);
    adj[5].push_back(2);
    adj[5].push_back(3);

    //breathFirstSearch(1);
    depthFirstSearch(1);
}