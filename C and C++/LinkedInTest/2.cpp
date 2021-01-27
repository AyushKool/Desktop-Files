#include <bits/stdc++.h>
#define all(c) (c).begin(), (c).end()
using namespace std;

bool dfs(vector<string> &grid, int i, int j, int k, int maxTime, int n, int m)
{
	if(k > maxTime)
		return false;
	if(i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == '#')
		return false;
	if(i == n - 1 && j == m - 1)
		return true;
	if(dfs(grid, i - 1, j, k + 1, maxTime, n, m))
		return true;
	if(dfs(grid, i, j + 1, k + 1, maxTime, n, m))
		return true;
	if(dfs(grid, i + 1, j, k + 1, maxTime, n, m))
		return true;
	if(dfs(grid, i, j - 1, k + 1, maxTime, n, m))
		return true;
	return false;
}

int main()
{
	
	int n, m;
	cin >> n;
	vector<string> grid(n);
	for(int i = 0; i < n; ++i)
		cin >> grid[i];
	m = grid[0].size();
	int maxTime;
	cin >> maxTime;
	if(dfs(grid, 0, 0, 0, maxTime, n, m))
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
	return 0;
}