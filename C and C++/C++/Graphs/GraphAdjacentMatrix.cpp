#include <iostream>
using namespace std;

#define N 5

int main()
{
    int adj[N][N];//adj[a][b] is 1 if there is a node from a to b, 0 otherwise.
    /*
    Note:
    - undirected graphs have symmetric matrix because there is a edge from a to b and b to a
    - directed graphs are not neccessarily symmetric
    - weight graphs have the weight w of the edge connecting nodes a and b (instead of 1) at adj[a][b]
    */
}