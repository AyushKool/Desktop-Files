//https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int scores[n];
    for (int i = 0; i < n; i++)
        cin >> scores[i];
    cin >> m;
    int alice[m];
    for (int i = m - 1; i >= 0; i--)
        cin >> alice[i];

    // cout << endl;
    // for (int i=0; i<n; i++)
    //     cout << scores[i] << " ";
    // cout << endl;
    // for (int i=0; i<m; i++)
    //     cout << alice[i] << " ";
    // cout << endl;   

    int rank = 1, j = 0, ranks[m];
    while (alice[j] >= scores[0])
        ranks[j++] = 1;
    for (int i = 1; i < n && j < m; i++)
    {
        if (scores[i] != scores[i - 1])
            rank++;
        //cout << rank << " ";
        while (alice[j] >= scores[i])
            ranks[j++] = rank;
    }
    while (j < m)
    {
        ranks[j] = (alice[j] >= scores[n-1] ? rank : rank + 1);
        j++;
    }
    for (int i = m - 1; i >= 0; i--)
        cout << ranks[i] << endl;
}

/*
Inputs:
6
100 90 90 80 75 60
5
50 90 95 110 120

6
100 90 90 80 75 60
5
50 65 77 90 102

7
100 100 50 40 40 20 10
4
5 25 50 120
*/